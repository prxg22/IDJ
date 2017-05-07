#include "State.hpp"

#include "Face.hpp"
#include "Vec2.hpp"
#include "Game.hpp"

State::State() : _quitRequested(false), bg("ocean.jpg"), tilemap(Game::getInstance().resources.getTilemap("tileMap.txt")) {}
State::~State() {}

bool State::quitRequested() const {
	return _quitRequested;
}

void State::update(float dt){
	auto& input = Game::getInstance().input;
	
	_quitRequested = input.quitRequested();
	
	if(input.isMouseDown(SDL_BUTTON_LEFT)) {
        for(auto it = objectList.rbegin(); it != objectList.rend(); it++) {
            // Obtem o ponteiro e casta pra Face.
            Face* face = (Face*) it->get();
            // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
            // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
            // ao usar get(), violamos esse princípio e estamos menos seguros.
            // Esse código, assim como a classe Face, é provisório. Futuramente, para
            // chamar funções de GameObjects, use (*it)->função() direto.
            if(face->box.isInside((float)input.getMouseX(), (float)input.getMouseY())) {
                // Aplica dano
                face->damage(rand() % 10 + 10);
                // Sai do loop (só queremos acertar um)
                break;
            }
        }
	}
	
	if(input.keyPress(SDLK_SPACE)){
		addObject((float)input.getMouseX(), (float)input.getMouseY());
	}
	
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
	tilemap->renderLayer(0);
	for (auto& obj : objectList)
	{
		obj->render();
	}
	tilemap->renderLayer(1);
}

void State::addObject(float mouseX, float mouseY) {
	Vec2f v(0, 200);
	v = v.rotate(rand() % 360);
	v += Vec2f(mouseX, mouseY);
	objectList.emplace_back(new Face(v.x, v.y));
}