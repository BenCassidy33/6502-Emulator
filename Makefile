all:
	clang -o build/main src/main.c -std=c23

run: all
	build/main

format-check:
	clang-format --dry-run --Werror $(shell find . -name '*.c' -or -name '*.h')
