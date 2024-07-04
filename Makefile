all:
	g++ main.cc src/* -IC:\SFML-2.6.1\include -lsfml-system -lsfml-window -lsfml-graphics -o bin/Ajedrez
	bin/Ajedrez.exe
