all: main mainW64

main: 
	gcc main.c -lm -std=c99 -I./include -o main

mainW64:
	x86_64-w64-mingw32-gcc main.c -std=c99 -I./include -o main.exe

clean:
	rm main main.exe