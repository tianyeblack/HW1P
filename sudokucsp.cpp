#include "sudokucsp.h"

short SudokuCSP :: xyTo1D(short x, short y) {
	return (x - 1) * 9 + (y - 1);
}

SudokuCSP :: SudokuCSP(short** initial) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			svariables[xyTo1D(i, j)].setXandY(i, j);
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int m = i + 1; m <= 9; m++) {
				addConstraint(new SudokuConstraint(&svariables[xyTo1D(i, j)], &svariables[xyTo1D(m, j)]));
			}
			for (int n = j + 1; n <= 9; n++) {
				addConstraint(new SudokuConstraint(&svariables[xyTo1D(i, j)], &svariables[xyTo1D(i, n)]));
			}
			for (int m = i + 1; m <= (i - 1) / 3 * 3 + 3; m++) {
				for (int n = j + 1; n <= (j - 1) / 3 * 3 + 3; n++) {
					addConstraint(new SudokuConstraint(&svariables[xyTo1D(i, j)], &svariables[xyTo1D(m, n)]));
				}
			}
			if (initial[i][j] != 0) {
				removeValueFromColumn(&svariables[xyTo1D(i, j)], initial[i][j]);
				removeValueFromRow(&svariables[xyTo1D(i, j)], initial[i][j]);
				removeValueFromSquare(&svariables[xyTo1D(i, j)], initial[i][j]);
				sdomains[xyTo1D(i, j)].setDomain((short)initial[i][j]);
			}
		}
	}
}

SudokuVariable* SudokuCSP :: getVariables() {
	return svariables;
}

SudokuDomain* SudokuCSP :: getDomain(const SudokuVariable* var) {
	return &(sdomains[var->getIndex()]);
}

vector<SudokuConstraint*>* SudokuCSP :: getConstraints() {
	return &sconstraints;
}

vector<SudokuConstraint*>* SudokuCSP :: getConstraints(SudokuVariable* var) {
	return &cnet[var];
}

SudokuVariable* SudokuCSP :: getNeighbor(SudokuVariable* var, SudokuConstraint* con) {
	vector<short>* scope = con->getScope();
	if (scope->size() == 2) {
		if (var->getIndex() == (*scope)[0]) {
			return &svariables[(*scope)[1]];
		} else if (var->getIndex() == (*scope)[1]) {
			return &svariables[(*scope)[0]];
		}
	}
	return 0;
}

void SudokuCSP :: setDomain(const SudokuVariable* var, SudokuDomain* domain) {
	sdomains[var->getIndex()].setDomain(domain);
}

void SudokuCSP :: removeValueFromDomain(const SudokuVariable* var, short value) {
	sdomains[var->getIndex()].removeValue(value);
}

void SudokuCSP :: removeValueFromColumn(const SudokuVariable* var, short value) {
	for (int i = 0; i < 9; i++) {
		removeValueFromDomain(&svariables[i * 9 + var->getY() - 1], value);
	}
}

void SudokuCSP :: removeValueFromRow(const SudokuVariable* var, short value) {
	for (int i = 0; i < 9; i++) {
		removeValueFromDomain(&svariables[(var->getX() - 1) * 9 + i], value);
	}
}

void SudokuCSP :: removeValueFromSquare(const SudokuVariable* var, short value) {
	short x = var->getX();
	short y = var->getY();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			removeValueFromDomain(&svariables[(((x - 1) / 3) * 3 + i) * 9 + ((y - 1) / 3) * 3 + j], value);
		}
	}
}

bool SudokuCSP :: containConstraint(SudokuConstraint* con) {
	SudokuVariable* var1 = &svariables[(*(con->getScope()))[0]];
	SudokuVariable* var2 = &svariables[(*(con->getScope()))[1]];
	for (std::vector<SudokuConstraint*>::iterator it = cnet[var1].begin(); it != cnet[var1].end(); it++) {
		if (con->isEqual(*it)) {
			return true;
		}
	}
	for (std::vector<SudokuConstraint*>::iterator it = cnet[var2].begin(); it != cnet[var2].end(); it++) {
		if (con->isEqual(*it)) {
			return true;
		}
	}
	return false;
}

void SudokuCSP :: addConstraint(SudokuConstraint* con) {
	SudokuVariable* var;
	sconstraints.insert(sconstraints.end(), &(*con));
	var = &svariables[(*(con->getScope()))[0]];
	cnet[var].insert(cnet[var].end(), &(*con));
	var = &svariables[(*(con->getScope()))[1]];
	cnet[var].insert(cnet[var].end(), &(*con));
}
