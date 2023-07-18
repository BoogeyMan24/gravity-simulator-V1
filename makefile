# This is the configuration for me (mac with sdl frameworks)
# There is a 99.99% chance this won't work for you, but if you want to make it work just provide your own path to the sdl header files. 

all:
	clang++ -std=c++17 -o main src/*.cpp -Iinclude/headers -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image