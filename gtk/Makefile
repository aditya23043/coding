all: src/main.c
	gcc `pkg-config --cflags gtk4` -o bin/main src/main.c `pkg-config --libs gtk4`

run: bin/main
	./bin/main
