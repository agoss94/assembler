/*
 * symbol_table.c
 *
 *  Created on: 20.08.2023
 *      Author: Andreas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resizeTable();

typedef struct {
	char symbol[20];
	int address;
} Entry;

static int size = 100;
static Entry* symbol_table;
static int counter = 0;

int getAddress(char* symbol) {
	for (int i = 0; i < counter; i++) {
			Entry e = symbol_table[i];
			if(strcmp(e.symbol, symbol) == 0) {
				return e.address;
			}
		}
		return -1;
}

int contains(char* symbol) {
	for (int i = 0; i < counter; i++) {
		if(strcmp(symbol_table[i].symbol, symbol) == 0) {
			return 1;
		}
	}
	return 0;
}

void initTable() {
	symbol_table = malloc(size * sizeof(Entry));
}

void freeTable() {
	free(symbol_table);
}

void addEntry(char* symbol, int address) {
	if (counter < size) {
		Entry e;
		e.address = address;
		strcpy(e.symbol, symbol);
		symbol_table[counter] = e;
		counter++;
	} else {
		resizeTable();
		if (counter == size) {
			//Reallocation failed we exit the function.
			return;
		} else {
			addEntry(symbol, address);
		}
	}
}

void resizeTable() {
	Entry* temp = symbol_table;
	size *= 2;

	symbol_table = realloc(symbol_table, size * sizeof(Entry));
	if (!symbol_table) {
		printf("Memory Re-allocation failed.");
		symbol_table = temp;
		size /= 2;
	}
}

