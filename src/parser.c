/*
 * parser.c
 *
 *  Created on: 29.08.2023
 *      Author: Andreas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

char* trim(char *s);

//------------------------Variables------------------------

//File pointer
FILE *file;

char instruction[100];
int type;

//Symbol can be longer
char symbolValue[100];

//Return values for dest, comp and jump
char destValue[4];
char compValue[4];
char jumpValue[4];

//---------------------------------------------------------

void setFile(FILE *ptr) {
	file = ptr;
	rewind(file);
	counter = -1;
	type = -1;
}

int hasMoreLines() {
	return fgets(instruction, 100, file) != NULL;
}

void advance() {
	strtok(instruction, "//"); //Strip comments
	char temp[100];
	strcpy(temp, trim(instruction));
	strcpy(instruction, temp);
	if (instruction[0] == '\0') {
		type = -1;
		return;
	}
	if (instruction[0] == '/' && instruction[1] == '/') {
		type = -1;
		return;
	}
	if (instruction[0] == '(') {
		type = L_INSTRUCTION;
	} else if (instruction[0] == '@') {
		type = A_INSTRUCTION;
		counter++;
	} else {
		type = C_INSTRUCTION;
		counter++;
	}

}

int instructionType() {
	return type;
}

char* symbol() {
	if (instruction[0] == '@') {
		sscanf(instruction, "@%s", symbolValue);
	} else {
		sscanf(instruction, "(%[^)]s)", symbolValue);
	}
	return symbolValue;
}

char* dest() {
	if (strchr(instruction, '=') == NULL) {
		return NULL;
	} else {
		sscanf(instruction, "%3[ADM]", destValue);
		return destValue;
	}
}

char* comp() {
	if (strchr(instruction, '=') != NULL) {
		sscanf(instruction, "%*[ADM]=%3s", compValue);
		return compValue;
	} else {
		sscanf(instruction, "%[ADM0]", compValue);
		return compValue;
	}
}

char* jump() {
	if (strchr(instruction, ';') == NULL) {
		return NULL;
	} else {
		sscanf(instruction, "%*[ADM0];%s3", jumpValue);
		return jumpValue;
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
