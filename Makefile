SDL_INCLUDE = -IC:\msys64\mingw64\include\SDL2 -LC:\msys64\mingw64\lib
CXXFLAGS = $(SDL_INCLUDE) -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

bin/game : src/game.cpp include2*
	g++ $< -o $@ -I include2 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

runGame : bin/game
	./$<