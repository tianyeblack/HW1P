#pragma once

#include <vector>
#include "sudokuvariable.h"

using namespace std;

class SudokuAssignment;

class SudokuConstraint {
private:
	short ivar1, ivar2;
	vector<short> scope;
public:
	SudokuConstraint(SudokuVariable* var1, SudokuVariable* var2);
	short getI1() const;
	short getI2() const;
	vector<short>* getScope();
	bool isSatisfiedWith(SudokuAssignment* sa);
	bool isEqual(SudokuConstraint* con);
};
