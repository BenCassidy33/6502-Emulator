all:
	clang -o build/main src/main.c -std=c23

run: all
	build/main
