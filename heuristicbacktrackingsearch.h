#ifndef _HEURISTIC_BACKTRACKING_SEARCH_H_
#define _HEURISTIC_BACKTRACKING_SEARCH_H_

#include <vector>
#include "backtrackingsearch.h"

using namespace std;

class HeuristicBackTrackingSearch : public BackTrackingSearch {
private:
	SudokuAssignment* recursiveBackTrackingSearch(SudokuCSP* scsp, SudokuAssignment* sa);
	vector<SudokuVariable*>* MRVHeuristic(SudokuAssignment* sa, SudokuCSP* scsp );
	vector<SudokuVariable*>* DegreeHeuristic(vector<SudokuVariable*>* vars, SudokuAssignment* sa, SudokuCSP* scsp);
protected:
	SudokuVariable* selectUnassignedVariable(SudokuAssignment* sa, SudokuCSP* scsp);
public:
	HeuristicBackTrackingSearch() : BackTrackingSearch() {};
	SudokuAssignment* solve(SudokuCSP* scsp, short** initial);
};

#endif
