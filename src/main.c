#include "cpu.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

char *get_program_file(int argc, char **argv) {
	char *file_name;

	for (int i = 0; i < argc; i++) {
		if (strstr(argv[i], ".p") != NULL) {
			file_name = argv[i];
		}
	}

	return file_name;
}

int main(int argc, char **argv) {
	printf("ARGC: %d\n", argc);

	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	if (argc > 1 && strcmp(argv[1], "--test") == 0) {
		printf("\n\n==========Running Tests==========\n\n\n");
		return run_unit_tests();
	}

	char *file_name = get_program_file(argc, argv);
	printf("%s\n", file_name);

	return 0;
};
