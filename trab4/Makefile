# ==============================================================================
# BEGIN template
# ==============================================================================

# flag para tirar o console na versao final: -mwindows

# parameters
EXE      = trab4.exe
LIBS     = -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2

CXX      = g++ -std=c++11
SRCS     = $(shell find src -name '*.cpp')
HEADERS  = $(shell find src -name '*.hpp')
OBJS     = $(addprefix obj/,$(notdir $(SRCS:%.cpp=%.o)))

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

obj/%.o: src/%.cpp $(HEADERS)
	mkdir -p obj
	$(CXX) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(EXE) obj

# ==============================================================================
# END template
# ==============================================================================
