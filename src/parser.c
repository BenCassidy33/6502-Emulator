#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
} Parser;

// TODO: FIX THIS
void parse_file(char *file) {
	Instruction *program_instructions = NULL;
	int instruction_count = 0;

	char *line;
	char *word;

	while ((line = strsep(&file, "\n"))) {
		while ((word = strsep(&line, " "))) {
			if (strcmp(word, "") == 0) {
				continue;
			}

			for (int i = 0; INSTRUCTION_SET[i].ident != ENDSET;
			     i++) {
				if (strcmp(word,
				           INSTRUCTION_SET[i].string_name) ==
				    0) {

					program_instructions =
					    realloc(program_instructions,
					            (instruction_count + 1) *
					                sizeof(Instruction));

					if (!program_instructions) {
						printf("Failed to allocate "
						       "additional "
						       "memory");
						exit(EXIT_FAILURE);
					}

					program_instructions
					    [instruction_count++] =
					        INSTRUCTION_SET[i];
				};

				printf("Finding: %s\n", word);
			}
		}

		printf("\n");
	}

	for (int i = 0; i < instruction_count; i++) {
		printf("Instruction: %s\n",
		       program_instructions[i].string_name);
	}

	free(program_instructions);
}
