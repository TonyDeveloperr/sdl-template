all: ; g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o main $(wildcard src/*.cpp src/rendering/*.cpp) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

clean: ; rm -f main $(wildcard src/*.o src/rendering/*.o)
