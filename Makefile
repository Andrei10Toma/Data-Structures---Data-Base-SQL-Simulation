all: build run clean

build:
	gcc main.c functii.c -o tema1 -Wall -lm

run:
	./tema1

clean:
	rm -rf tema1


