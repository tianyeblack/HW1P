#include "sudokuconstraint.h"

SudokuConstraint :: SudokuConstraint(SudokuVariable* var1, SudokuVariable* var2) {
	ivar1 = var1->getIndex();
	ivar2 = var2->getIndex();
	scope.insert(scope.end(), ivar1);
	scope.insert(scope.end(), ivar2);
}

short SudokuConstraint :: getI1() const {
	return ivar1;
}

short SudokuConstraint :: getI2() const {
	return ivar2;
}

vector<short>* SudokuConstraint :: getScope() {
	return &scope;
}

bool SudokuConstraint :: isEqual(SudokuConstraint* con) {
	if ((this->getI1() == con->getI1() && this->getI2() == con->getI2()) || (this->getI1() == con->getI2() && this->getI2() == con->getI1())) {
		return true;
	}
	return false;
}
