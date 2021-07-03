#bin/bash

rm obj/*.o

g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include

mv *.o ./obj/

g++ ./obj/*.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image

./bin/debug/main