#pragma once

#include <vector>
#include <map>
#include "sudokuvariable.h"
#include "sudokudomain.h"
#include "sudokuconstraint.h"

using namespace std;

struct ltsvar {
	bool operator() (SudokuVariable* var1, SudokuVariable* var2) {
		return var1->getIndex() < var2->getIndex();
	}
};

class SudokuCSP {
protected:
	SudokuVariable svariables[81];
	SudokuDomain sdomains[81];
	vector<SudokuConstraint*> sconstraints;
	map<SudokuVariable*, vector<SudokuConstraint*>, ltsvar> cnet;
	// enum values = {One = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine};
public:
	short xyTo1D(short x, short y);
	SudokuCSP(short** initial);
	SudokuVariable* getVariables();
	SudokuDomain* getDomain(const SudokuVariable* var);
	vector<SudokuConstraint*>* getConstraints();
	vector<SudokuConstraint*>* getConstraints(SudokuVariable* var);
	void setDomain(const SudokuVariable* var, SudokuDomain* domain);
	void removeValueFromDomain(const SudokuVariable* var, short value);
	void removeValueFromColumn(const SudokuVariable* var, short value);
	void removeValueFromRow(const SudokuVariable* var, short value);
	void removeValueFromSquare(const SudokuVariable* var, short value);
	bool containConstraint(SudokuConstraint* con);
	void addConstraint(SudokuConstraint* con);
};
