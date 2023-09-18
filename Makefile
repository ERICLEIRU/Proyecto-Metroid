mensaje : 
	echo "mensaje por Make"

ejecutarGame : bin/game 
	./bin/game

bin/game : src/main.cpp  include/Agua.hpp include/Aire.hpp include/Animacion.hpp include/Area.hpp include/Atmosfera.hpp

	echo "Copilando game"
	rm bin/game
	g++ src/main.cpp -o bin/game -I include

copilarGame : src/main.cpp
	g++ src/main.cpp -o bin/game -I include