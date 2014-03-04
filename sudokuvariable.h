#ifndef _SUDOKU_VARIABLE_H_
#define _SUDOKU_VARIABLE_H_


class SudokuVariable {
private:
	short _x, _y;
	short _index;

public:
	SudokuVariable();
	SudokuVariable(short x, short y);
	SudokuVariable(const SudokuVariable &var);
	bool operator==(SudokuVariable* rhs);
	short getX() const;
	short getY() const;
	short getIndex() const;
	void setXandY(short x, short y);
};

#endif
