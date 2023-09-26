CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -g 


mensaje : 
	echo "mensaje por Make"

ejecutarGame : bin/game 
	./bin/game

bin/game : src/game.cpp  include/Agua.hpp include/Aire.hpp include/Animacion.hpp include/Area.hpp include/Atmosfera.hpp

	echo "Copilando game"
	rm bin/game
	$(CXX) src/game.cpp -o bin/game -I include

copilarGame : src/game.cpp
	g++ src/game.cpp -o bin/game -I include