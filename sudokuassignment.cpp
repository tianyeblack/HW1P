#include "sudokuassignment.h"


bool SudokuConstraint :: isSatisfiedWith(SudokuAssignment* sa) {
	short value1 = sa->getSudokuAssignmentOf(ivar1);
	short value2 = sa->getSudokuAssignmentOf(ivar2);
	return (value1 + value2) == 0 || (value1 != 0 && value1 != value2);
}

SudokuAssignment :: SudokuAssignment() {
	for (int i = 0; i < 81; i++) {
		asmt[i] = 0;
	}
}

SudokuAssignment :: SudokuAssignment(short** initial) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			asmt[(i - 1) * 9 + (j - 1)] = initial[i][j];
		}
	}
}

short** SudokuAssignment :: getAssignment(short** result) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			result[i][j] = this->asmt[(i - 1) * 9 + (j - 1)];
		}
	}
	return result;
}

short SudokuAssignment :: getSudokuAssignmentOf(short index) {
	return asmt[index];
}

short SudokuAssignment :: getSudokuAssignmentOf(const SudokuVariable* var) {
	return getSudokuAssignmentOf(var->getIndex());
}

void SudokuAssignment :: setSudokuAssignmentOf(const SudokuVariable* var, short value) {
	asmt[var->getIndex()] = value;
}

bool SudokuAssignment :: hasAssignmentFor(const SudokuVariable* var) {
	return asmt[var->getIndex()] != 0;
}

void SudokuAssignment :: removeSudokuAssignmentOf(const SudokuVariable* var) {
	asmt[var->getIndex()] = 0;
}

bool SudokuAssignment :: isComplete(SudokuVariable* vars) {
	for (int i = 0; i < 81; i++) {
		if (asmt[i] == 0) {
			return false;
		}
	}
	return true;
}

bool SudokuAssignment :: isConsistent(vector<SudokuConstraint*>* cstrs) {
	for (unsigned int i = 0; i < cstrs->size(); i++) {
		if (!(*cstrs)[i]->isSatisfiedWith(this)) {
			return false;
		}
	}
	return true;
}

bool SudokuAssignment :: isSolution(SudokuCSP* sdk) {
	return isConsistent(sdk->getConstraints()) && isComplete(sdk->getVariables());
}
