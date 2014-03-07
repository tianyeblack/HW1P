#include "heuristicbacktrackingsearch.h"

using namespace std;

SudokuAssignment* HeuristicBackTrackingSearch :: solve(SudokuCSP* scsp, short** initial) {
		return this->recursiveBackTrackingSearch(scsp, new SudokuAssignment(initial, scsp));
}

SudokuAssignment* HeuristicBackTrackingSearch :: recursiveBackTrackingSearch(SudokuCSP* scsp, SudokuAssignment* sa) {
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
					result = this->recursiveBackTrackingSearch(scsp, sa);
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

vector<SudokuVariable*>* HeuristicBackTrackingSearch :: MRVHeuristic(SudokuAssignment* sa, SudokuCSP* scsp ) {
	vector<SudokuVariable*>* result = new vector<SudokuVariable*>();
	short mrv = 10;
	for (int i = 0; i < 81; i++) {
		SudokuVariable* var = &(scsp->getVariables()[i]);
		if (!sa->hasAssignmentFor(var)) {
			short num = scsp->getDomain(var)->size();
			if (num <= mrv) {
				if (num < mrv) {
					result->clear();
					mrv = num;
				}
				result->insert(result->end(), var);
			}
		}
	}
	return result;
}

vector<SudokuVariable*>* HeuristicBackTrackingSearch :: DegreeHeuristic(vector<SudokuVariable*>* vars, SudokuAssignment* sa, SudokuCSP* scsp) {
	vector<SudokuVariable*>* result = new vector<SudokuVariable*>();
	short maxDegree = 0;
	for (std::vector<SudokuVariable*>::iterator it1 = result->begin(); it1 != result->end(); it1++) {
		short degree = 0;
		vector<SudokuConstraint*>* cons = scsp->getConstraints(*it1);
		for (std::vector<SudokuConstraint*>::iterator it2 = cons->begin(); it2 != cons->end(); it2++) {
			SudokuVariable* neighbor = scsp->getNeighbor(*it1, *it2);
			if (!sa->hasAssignmentFor(neighbor) && scsp->getDomain(neighbor)->size() > 1) {
				++degree;
			}
		}
		if (degree >= maxDegree) {
			if (degree > maxDegree) {
				result->clear();
				maxDegree = degree;
			}
			result->insert(result->end(), *it1);
		}
	}
	return result;
}

SudokuVariable* HeuristicBackTrackingSearch :: selectUnassignedVariable(SudokuAssignment* sa, SudokuCSP* scsp) {
	vector<SudokuVariable*>* result = MRVHeuristic(sa, scsp);
	vector<SudokuVariable*>* vars = DegreeHeuristic(result, sa, scsp);
	return (*result)[0];
}
