all:
	for f in ./*.c; do gcc -lm -std=c99 -o ${f::-2} $f;done

allW64:
	for f in ./*.c; do
		x86_64-w64-mingw32-gcc -std=c99 -lm -o ${f::-2} $f
	done
	rm t0.exe

clean: 
	