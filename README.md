# C++/SDL2 RPG Platformer

## Linux install

```bash
sudo apt-get install g++

sudo apt-get install libsdl2-2.0

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-image-dev
```

## Create Directories

```bash
mkdir bin bin/debug bin/release res src include
```

## Copy files

- Enter in directory `/usr/lib/x86_64-linux-gnu`

- Copy files:
  - `libSDL2-2.0.so.0.10.0` to `./bin/debug`
  - Rename `libSDL2-2.0.so.0.10.0` to `libSDL2.so`
  - `libSDL2_image-2.0.so.0.2.3` to `./bin/debug`
  - Rename `libSDL2_image-2.0.so.0.2.3` to `libSDL2_image.so`
  - Copy `libSDL2.so` and `libSDL2_image.so` to `./bin/release`

## References

https://www.youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS

https://rodrigorgs.github.io/aulas/mata37/sdl/#7