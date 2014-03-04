#pragma once

#include <vector>
#include "sudokucsp.h"

using namespace std;

class SudokuAssignment {
private:
	short asmt[81];
public:
	SudokuAssignment();
	SudokuAssignment(short** initial);
	short** getAssignment(short** result);
	short getSudokuAssignmentOf(short index);
	short getSudokuAssignmentOf(const SudokuVariable* var);
	void setSudokuAssignmentOf(const SudokuVariable* var, short value);
	bool hasAssignmentFor(const SudokuVariable* var);
	void removeSudokuAssignmentOf(const SudokuVariable* var);
	bool isComplete(SudokuVariable* vars);
	bool isConsistent(vector<SudokuConstraint*>* cstrs);
	bool isSolution(SudokuCSP* sdk);
};
