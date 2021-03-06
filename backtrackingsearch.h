#ifndef _BACKTRACKING_SEARCH_H_
#define _BACKTRACKING_SEARCH_H_

#include "sudokucsp.h"
#include "sudokuassignment.h"
#include "domainrestoreinfo.h"

class BackTrackingSearch {
private:
	SudokuAssignment* recursiveBackTrackingSearch(SudokuCSP* scsp, SudokuAssignment* sa);
protected:
	unsigned long explored;
	SudokuVariable* selectUnassignedVariable(SudokuAssignment* sa, SudokuCSP* scsp);
	SudokuDomain* orderDomainValues(SudokuVariable* var, SudokuAssignment* sa, SudokuCSP* scsp);
	DomainRestoreInfo* inference(SudokuVariable* var, SudokuAssignment* sa, SudokuCSP* scsp);
public:
	BackTrackingSearch();
	unsigned long getExplored() const;
	void setExplored(unsigned long value);
	SudokuAssignment* solve(SudokuCSP* scsp, short** initial);
};

#endif
