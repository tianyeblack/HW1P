#include "backtrackingsearch.h"

using namespace std;

BackTrackingSearch :: BackTrackingSearch() {
	explored = 0;
}

unsigned long BackTrackingSearch :: getExplored() const {
	return explored;
}

SudokuAssignment* BackTrackingSearch :: solve(SudokuCSP* scsp, short** initial) {
		return recursiveBackTrackingSearch(scsp, new SudokuAssignment(initial, scsp));
}

SudokuAssignment* BackTrackingSearch :: recursiveBackTrackingSearch(SudokuCSP* scsp, SudokuAssignment* sa) {
	SudokuAssignment* result = 0;
	if (sa->isComplete(scsp->getVariables())) {
		result = sa;
	} else {
		SudokuVariable* var = selectUnassignedVariable(sa, scsp);
		short* d = orderDomainValues(var, sa, scsp)->getDomainAsArray();
		for (short i = 0; d[i] != 0; i++) {
			sa->setSudokuAssignmentOf(var, d[i]);
			explored++;
			// fireStateChanged(scsp);
			if (sa->isConsistent(scsp->getConstraints(var))) {
				DomainRestoreInfo* info = inference(var, sa, scsp);
				if (!info->isEmpty()) {
					// fireStateChanged(scsp);
				}
				if (!info->isEmptyDomainFound()) {
					result = recursiveBackTrackingSearch(scsp, sa);
					if (result) {
						break;
					}
				}
				info->restoreDomains(scsp);
			}
			sa->removeSudokuAssignmentOf(var);
		}
	}
	return result;
}

DomainRestoreInfo* BackTrackingSearch :: inference(SudokuVariable* var, SudokuAssignment* sa, SudokuCSP* scsp) {
	DomainRestoreInfo* dri = new DomainRestoreInfo();
	return dri->compactify();
}

SudokuDomain* BackTrackingSearch :: orderDomainValues(SudokuVariable* var, SudokuAssignment* sa, SudokuCSP* scsp) {
	return scsp->getDomain(var);
}

SudokuVariable* BackTrackingSearch :: selectUnassignedVariable(SudokuAssignment* sa, SudokuCSP* scsp) {
	SudokuVariable* s = scsp->getVariables();
	for (int i = 0; i < 81; i++) {
		if (!(sa->hasAssignmentFor(&s[i]))) {
			return &s[i];
		}
	}
	return 0;
}
