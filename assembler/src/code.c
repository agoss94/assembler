/*
 * code.c
 *
 *  Created on: 27.08.2023
 *      Author: Andreas
 */
#include <stdlib.h>
#include <string.h>

char* destCode(char* s) {
	if(s == NULL) {
		return "000";
	} else if (strcmp(s, "M") == 0) {
		return "001";
	} else if (strcmp(s, "D") == 0) {
		return "010";
	} else if (strcmp(s, "DM") == 0) {
		return "011";
	} else if (strcmp(s, "A") == 0) {
		return "100";
	} else if (strcmp(s, "AM") == 0) {
		return "101";
	} else if (strcmp(s, "AD") == 0) {
		return "110";
	} else if (strcmp(s, "ADM") == 0) {
		return "111";
	} else {
		return NULL;
	}
}

char* jumpCode(char* s) {
	if(s == NULL) {
		return "000";
	}else if (strcmp(s, "JGT") == 0) {
		return "001";
	} else if (strcmp(s, "JEQ") == 0) {
		return "010";
	} else if (strcmp(s, "JGE") == 0) {
		return "011";
	} else if (strcmp(s, "JLT") == 0) {
		return "100";
	} else if (strcmp(s, "JNE") == 0) {
		return "101";
	} else if (strcmp(s, "JLE") == 0) {
		return "110";
	} else if (strcmp(s, "JMP") == 0) {
		return "111";
	} else {
		return NULL;
	}
}

char* compCode(char* s) {
	if(s == NULL) {
		return "0000000";
	}else if (strcmp(s, "0") == 0) {
		return "0101010";
	} else if (strcmp(s, "1") == 0) {
		return "0111111";
	} else if (strcmp(s, "-1") == 0) {
		return "0111010";
	} else if (strcmp(s, "D") == 0) {
		return "0001100";
	} else if (strcmp(s, "A") == 0) {
		return "0110000";
	} else if (strcmp(s, "M") == 0) {
		return "1110000";
	} else if (strcmp(s, "!D") == 0) {
		return "0001101";
	} else if (strcmp(s, "!A") == 0) {
		return "0110001";
	} else if (strcmp(s, "!M") == 0) {
		return "1110001";
	} else if (strcmp(s, "-D") == 0) {
		return "0001111";
	} else if (strcmp(s, "-A") == 0) {
		return "0110011";
	} else if (strcmp(s, "-M") == 0) {
		return "1110011";
	} else if (strcmp(s, "D+1") == 0) {
		return "0011111";
	} else if (strcmp(s, "A+1") == 0) {
		return "0110111";
	} else if (strcmp(s, "M+1") == 0) {
		return "1110111";
	} else if (strcmp(s, "D-1") == 0) {
		return "0001110";
	} else if (strcmp(s, "A-1") == 0) {
		return "0110010";
	} else if (strcmp(s, "M-1") == 0) {
		return "1110010";
	} else if (strcmp(s, "D+A") == 0) {
		return "0000010";
	} else if (strcmp(s, "D+M") == 0) {
		return "1000010";
	} else if (strcmp(s, "D-A") == 0) {
		return "0010011";
	} else if (strcmp(s, "D-M") == 0) {
		return "1010011";
	} else if (strcmp(s, "A-D") == 0) {
		return "0000111";
	} else if (strcmp(s, "M-D") == 0) {
		return "1000111";
	} else if (strcmp(s, "D&A") == 0) {
		return "0000000";
	} else if (strcmp(s, "D&M") == 0) {
		return "1000000";
	} else if (strcmp(s, "D|A") == 0) {
		return "0010101";
	} else if (strcmp(s, "D|M") == 0) {
		return "1010101";
	}  else {
		return NULL;
	}
}
