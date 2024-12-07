#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
} Parser;

// TODO: FIX THIS
void parse_file(char *file) {
	char *line;
	char *word;
	char *lines[999999];
	int count = 0;

	line = strtok(file, "\n");

	while (line != NULL) {
		lines[count] = strdup(line);
		count++;
		line = strtok(NULL, "\n");
	}

	for (int i = 0; i < count; i++) {
		word = strtok(lines[i], " ");

		while (word != NULL) {
			word = strtok(NULL, " ");
		}

		/*printf("%s\n", lines[i]);*/
		free(lines[i]);
	}
};
