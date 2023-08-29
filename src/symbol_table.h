/*
 * symbol_table.h
 *
 *  Created on: 20.08.2023
 *      Author: Andreas
 */

#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

int contains(char *symbol);
void addEntry(char *symbol, int address);
int getAddress(char *symbol);
void initTable();
void freeTable();

#endif /* SYMBOL_TABLE_H_ */
