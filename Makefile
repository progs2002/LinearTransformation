# -*- MakeFile -*-

all:
	g++ -Wfatal-errors src/*.cpp -I "\include\SDL2" -L "/lib" -lmingw32 -lSDL2main -lSDL2 -o build/app 

