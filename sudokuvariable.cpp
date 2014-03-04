#include "sudokuvariable.h"

SudokuVariable :: SudokuVariable(){
	_x = 0;
	_y = 0;
	_index = 0;
}

SudokuVariable :: SudokuVariable(short x, short y) {
	if (x <= 0 || y <= 0) {
	
	}
	_x = x;
	_y = y;
	_index = (x - 1) * 9 + y - 1;
}

short SudokuVariable :: getIndex() const {
	return _index;
}

short SudokuVariable :: getX() const {
	return _x;
}

short SudokuVariable :: getY() const {
	return _y;
}

void SudokuVariable :: setXandY(short x, short y){
	_x = x;
	_y = y;
	_index = (x - 1) * 9 + y - 1;
}

bool SudokuVariable :: operator==(SudokuVariable* rhs) {
	if (_x == rhs->getX() && _y == rhs->getY()) {
		return true;
	} else {
		return false;
	}
}

