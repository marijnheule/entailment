all: entail-encode

entail-encode: entail-encode.c
	gcc entail-encode.c -std=c99 -O2 -o entail-encode

clean:
	rm entail-encode
