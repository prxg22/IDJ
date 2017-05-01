#include "State.hpp"

#include "Face.hpp"
#include "Vec2.hpp"

State::State() : _quitRequested(false), bg("ocean.jpg") {}
State::~State() {}

bool State::quitRequested() const {
	return _quitRequested;
}

void State::update(float dt){
	input();
	
	for(auto it = objectList.begin(); it != objectList.end(); ) {
		if((*it)->isDead()){
			it = objectList.erase(it);
		} else {
			it++;
		}
	}
}

void State::render() {
	bg.render(0, 0);
	
	for (auto& obj : objectList)
	{
		obj->render();
	}
}

void State::input(){
	SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            _quitRequested = true;
        }
        
        // Se o evento for clique...
        else if(event.type == SDL_MOUSEBUTTONDOWN) {
            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(auto it = objectList.rbegin(); it != objectList.rend(); it++) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) it->get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use (*it)->função() direto.

                if(face->box.isInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
            }
        }
        else if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                _quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                addObject((float)mouseX, (float)mouseY);
            }
        }
    }
}

void State::addObject(float mouseX, float mouseY) {
	Vec2f v(0, 200);
	v = v.rotate(rand() % 360);
	v += Vec2f(mouseX, mouseY);
	objectList.emplace_back(new Face(v.x, v.y));
}