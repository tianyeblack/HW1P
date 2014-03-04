#include "sudokudomain.h"

using namespace std;

SudokuDomain :: SudokuDomain() {
	domain = 0x01FF;
}

SudokuDomain :: SudokuDomain(short value) {
	domain = 0;
	domain &= (0x1 << (value - 1));
}

SudokuDomain :: SudokuDomain(short* d) {

}

SudokuDomain :: SudokuDomain(int d) {
	domain = d;
}

short SudokuDomain :: size() {
	short size = 0;
	for (int i = 0; i < 9; i++) {
		if (domain & (0x1 << i)) {
			size++;
		}
	}
	return size;
}

short SudokuDomain :: get(short index) {
	return 0;
}

short* SudokuDomain :: getDomainAsArray() {
	short* d = new short[10];
	int k = 0;
	for (int i = 0; i < 9; i++) {
		if (domain & (0x1 << i)) {
			d[k] = i + 1;
			k++;
		}
	}
	d[k] = 0;
	return d;
}

int SudokuDomain :: getDomain() {
	return domain;
}

void SudokuDomain :: setDomain(int d) {
	domain = d;
}

void SudokuDomain :: setDomain(short value) {
	domain = 0x0 | (0x1 << (value - 1));
}

void SudokuDomain :: setDomain(SudokuDomain* d) {
	domain = d->getDomain();
}

void SudokuDomain :: removeValue(short value) {
	domain &= ~(0x1 << (value - 1));
}

bool SudokuDomain :: isEmpty() {
	return domain == 0;
}

bool SudokuDomain :: contains(short value) {
	return domain & (0x1 << value);
}
