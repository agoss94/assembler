/*
 ============================================================================
 Name        : assembler.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "symbol_table.h"
#include "parser.h"
#include "code.h"

void initDefaultMappings();

int nextRegister = 16;

int main(int argc, char **argv) {
	initTable();
	initDefaultMappings();

	//Build symbol table.
	FILE *file = fopen(argv[1], "r");
	setFile(file);
	while (hasMoreLines()) {
		advance();
		if (instructionType() == L_INSTRUCTION) {
			addEntry(symbol(), counter + 1);
		}
	}

	//Reset file pointer
	rewind(file);

	//Name of output file.
	char outputName[100];
	sscanf(argv[1], "%[^.]s.asm", outputName);
	strcat(outputName, ".hack");

	FILE *output = fopen(outputName, "w");
	//Finally read and parse file.

	char oLine[20];
	while (hasMoreLines()) {
		advance();
		if (instructionType() == A_INSTRUCTION) {
			char address[16] = "000000000000000";
			char binNumber[16] = "0";
			if (contains(symbol())) {
				itoa(getAddress(symbol()), binNumber, 2);
			} else if (isdigit(symbol()[0])) {
				int i = 0;
				sscanf(symbol(), "%d", &i);
				itoa(i, binNumber, 2);
			} else {
				addEntry(symbol(), nextRegister);
				itoa(nextRegister, binNumber, 2);
				nextRegister++;
			}

			int binLength = strlen(binNumber);
			for (int j = binLength; j > 0; j--) {
				address[14 - binLength + j] = binNumber[j-1];
			}

			fputs("0", output);
			fputs(address, output);
			fputs("\n", output);
		} else if (instructionType() == C_INSTRUCTION) {
			oLine[0] = '1';
			oLine[1] = '1';
			oLine[2] = '1';
			oLine[3] = '\0';
			strcat(oLine, destCode(dest()));
			strcat(oLine, compCode(comp()));
			strcat(oLine, jumpCode(jump()));
			fputs(oLine, output);
			fputs("\n", output);
		}
	}

	freeTable();
	fclose(file);
	fclose(output);
	return 0;
}

void initDefaultMappings() {
	//Fill in symbol table with defaults
	//Register 0..15
	addEntry("R0", 0);
	addEntry("R1", 1);
	addEntry("R2", 2);
	addEntry("R3", 3);
	addEntry("R4", 4);
	addEntry("R5", 5);
	addEntry("R6", 6);
	addEntry("R7", 7);
	addEntry("R8", 8);
	addEntry("R9", 9);
	addEntry("R10", 10);
	addEntry("R11", 11);
	addEntry("R12", 12);
	addEntry("R13", 13);
	addEntry("R14", 14);
	addEntry("R15", 15);
	//Default Pointer
	addEntry("SP", 0);
	addEntry("LCL", 1);
	addEntry("ARG", 2);
	addEntry("THIS", 3);
	addEntry("THAT", 4);
	//IO
	addEntry("SCREEN", 16384);
	addEntry("KBD", 24576);
}

