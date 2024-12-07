#include "cpu.h"
#include "parser.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *FILE_EXT = ".asm";

char *get_program_file(int argc, char **argv) {
	char *file_name;

	for (int i = 0; i < argc; i++) {
		if (strstr(argv[i], FILE_EXT) != NULL) {
			file_name = argv[i];
		}
	}

	return file_name;
}

char *read_file(char *filename) {

	char *filepath = realpath(filename, NULL);
	/*printf("\nRunning File: %s\n", filepath);*/

	FILE *fptr = fopen(filepath, "r");

	if (fptr == NULL) {
		printf("Could not find specified file. Exiting");
		exit(1);
	};

	fseek(fptr, 0, SEEK_END);
	long filesize = ftell(fptr);
	rewind(fptr);

	char *buffer = malloc(filesize + 1);

	if (buffer == NULL) {
		/*printf("Memory allocation failed. Exiting\n");*/
		exit(1);
	}

	/*printf("Read: %ld bytes from file\n", filesize);*/
	fread(buffer, 1, filesize, fptr);
	fclose(fptr);

	return buffer;
}

int main(int argc, char **argv) {
	/*printf("ARGC: %d\n", argc);*/

	for (int i = 0; i < argc; i++) {
		/*printf("argv[%d]: %s\n", i, argv[i]);*/
	}

	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		printf("\n\n==========Running Tests==========\n\n\n");
		return run_unit_tests();
	}

	char *filename = get_program_file(argc, argv);
	char *file = read_file(filename);
	parse_file(file);

	return 0;
};
