#include "domainrestoreinfo.h"

DomainRestoreInfo :: DomainRestoreInfo() {
	empty = true;
}

void DomainRestoreInfo :: storeDomainFor(SudokuVariable* var, SudokuDomain* domain) {
	if (affectedVariables.count(var) != 0) {
		savedDomains[var] = domain;
		affectedVariables.insert(var);
		empty = false;
	}
}

void DomainRestoreInfo :: setEmptyDomainFound(bool b) {
	emptyDomainObserved = b;
}

DomainRestoreInfo* DomainRestoreInfo :: compactify() {
	return this;
}

bool DomainRestoreInfo :: isEmpty() {
	return empty;
}

bool DomainRestoreInfo :: isEmptyDomainFound() {
	return emptyDomainObserved;
}

void DomainRestoreInfo :: restoreDomains(SudokuCSP* scsp) {
	for (std::set<SudokuVariable*>::iterator it = affectedVariables.begin(); it != affectedVariables.end(); it++) {
		scsp->setDomain(*it, savedDomains[*it]);
	}
}
