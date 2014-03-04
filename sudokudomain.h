#ifndef _SODUKU_DOMAIN_H_
#define _SODUKU_DOMAIN_H_

class SudokuDomain {
private:
	int domain;
public:
	SudokuDomain();
	SudokuDomain(short value);
	SudokuDomain(short* d);
	SudokuDomain(int d);
	short size();
	short get(short index);
	short* getDomainAsArray();
	int getDomain();
	void setDomain(int d);
	void setDomain(short value);
	void setDomain(SudokuDomain* d);
	void removeValue(short value);
	bool isEmpty();
	bool contains(short value);
};

#endif
