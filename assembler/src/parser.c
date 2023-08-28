/*
 * Parser.c
 *
 *  Created on: 20.08.2023
 *      Author: Andreas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

int counter;
char* trim(char *s);

// File pointer for access.
FILE *file;
char currentInstruction[100];
int currentInstructionType = -1;

void setFile(FILE *ptr) {
	file = ptr;
	counter = 0;
}

int hasMoreLines() {
	return fgets(currentInstruction, 100, file) != NULL;
}

int instructionType() {
	return currentInstructionType;
}

void advance() {
	strtok(currentInstruction, "//"); //Strip comments
	char line[100];
	strcpy(line, trim(currentInstruction));
	if (line[0] == '\0') {
		currentInstructionType = -1;
		return;
	}
	if (line[0] == '/' && line[1] == '/') {
		currentInstructionType = -1;
		return;
	}
	if (line[0] == '@') {
		currentInstructionType = A_INSTRUCTION;
		counter++;
	} else if (line[0] == '(') {
		currentInstructionType = L_INSTRUCTION;
	} else {
		currentInstructionType = C_INSTRUCTION;
		counter++;
	}
	strcpy(currentInstruction, line);
}

char* symbol() {
	char *returnValue = malloc(25 * sizeof(char));
	if (currentInstruction[0] == '@') {
		sscanf(currentInstruction, "@%s", returnValue);
	} else {
		sscanf(currentInstruction, "(%[^)]s)", returnValue);
	}
	return returnValue;
}

char* dest() {
	if (strchr(currentInstruction, '=') == NULL) {
		return NULL;
	} else {
		char *returnValue = malloc(4 * sizeof(char));
		strcpy(returnValue, currentInstruction);
		sscanf(currentInstruction, "%3[ADM]", returnValue);
		return returnValue;
	}
}

char* comp() {
	char *returnValue = malloc(4 * sizeof(char));
	if (strchr(currentInstruction, '=') != NULL) {
		sscanf(currentInstruction, "%*[ADM]=%3s", returnValue);
		return returnValue;
	} else {
		sscanf(currentInstruction, "%[ADM0]", returnValue);
		return returnValue;
	}
}

char* jump() {
	char *returnValue = malloc(4 * sizeof(char));
	if (strchr(currentInstruction, ';') == NULL) {
		return NULL;
	} else {
		sscanf(currentInstruction, "%*[ADM0];%s3", returnValue);
		return returnValue;
	}
}

char* trim(char *s) {
	int i;

	while (isspace(*s))
		s++;   // skip left side white spaces
	for (i = strlen(s) - 1; (isspace(s[i])); i--)
		;   // skip right side white spaces
	s[i + 1] = '\0';
	return s;
}

