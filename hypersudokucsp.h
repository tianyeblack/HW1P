#ifndef _HYPER_SUDOKU_CSP_H_
#define _HYPER_SUDOKU_CSP_H_

#include "sudokucsp.h"

class HyperSudokuCSP : public SudokuCSP {
public:
	HyperSudokuCSP(short** initial);
};
#endif
