#include "cpu.h"
#include <stdio.h>
#include <string.h>

typedef struct {
} Parser;

// TODO: FIX THIS
void parse_file(char *file) {
	Instruction builder[] = {};

	char *line;
	char *word;

	while ((line = strsep(&file, "\n"))) {
		Instruction local_builder;

		while ((word = strsep(&line, " "))) {
			if (strcmp(word, "") == 0) {
				continue;
			}

			for (int i = 0; INSTRUCTION_SET[i].ident != NULL; i++) {
				printf("%s, %s", word,
				       INSTRUCTION_SET[i].ident);
			}
		}

		printf("\n");
	}
};
