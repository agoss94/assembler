/*
 * parser.h
 *
 *  Created on: 23.08.2023
 *      Author: Andreas
 */

#ifndef PARSER_H_
#define PARSER_H_

enum InstructionType {
	A_INSTRUCTION, C_INSTRUCTION, L_INSTRUCTION
};

void setFile(FILE *file);
int hasMoreLines();
void advance();
int instructionType();
char* symbol();
char* dest();
char* comp();
char* jump();
int counter;

#endif /* PARSER_H_ */
