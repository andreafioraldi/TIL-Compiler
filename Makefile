all:
	flex scanner.l
	bison parser.y
	gcc -shared -fPIC `xml2-config --cflags` *.c `xml2-config --libs` -o libtilcompiler.so

clean:
	rm scanner.c
	rm parser.c
	rm parser.h
	rm libtilcompiler.so
