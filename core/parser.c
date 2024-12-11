#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: add label parsing
void parse_file(char *file) {
	Section *program_sections = NULL;
	Instruction *program_instructions = NULL;

	int section_count = 0;
	int instruction_count = 0;

	int line_number = 0;

	char *line;
	char *word;

	while ((line = strsep(&file, "\n"))) {
		line_number++;
		if (strstr(line, ".section") != NULL) {
			program_sections =
			    realloc(program_sections,
			            (section_count + 1) * sizeof(Section));

			char *section_name = strsep(&line, " ");

			Section tmp = {
			    .line_start = line_number,
			    .string_name = &section_name[9],

			};

			program_sections[section_count++] = tmp;
		};

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
						exit(EXIT_FAILURE);
					}

					program_instructions
					    [instruction_count++] =
					        INSTRUCTION_SET[i];

					break;
				};
			}
		}
	}

	for (int i = 0; i < section_count; i++) {
		printf("%d: %s\n", program_sections[i].line_start,
		       program_sections[i].string_name);
	}

	for (int i = 0; i < instruction_count; i++) {
		printf("%s\n", program_instructions[i].string_name);
	}

	free(program_instructions);
}
