# -*- MakeFile -*-

all:
	g++ src/*.cpp -I. -Iinclude -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -o build/app
	.\build\app.exe

compile:
	g++ -Wall src/*.cpp -I. -Iinclude -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -o build/app

debug:
	g++ -g src/*.cpp -I. -Iinclude -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -o build/app
