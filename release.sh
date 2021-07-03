#bin/bash

rm obj/*.o

g++ -c src/*.cpp -std=c++14 -m64 -O3 -g -Wall -I include

mv *.o ./obj/

g++ ./obj/*.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image

./bin/release/main