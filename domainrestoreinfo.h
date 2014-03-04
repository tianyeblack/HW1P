#ifndef _DOMAIN_RESTORE_INFO_H_
#define _DOMAIN_RESTORE_INFO_H_

#include <map>
#include <set>
#include "sudokuvariable.h"
#include "sudokudomain.h"
#include "sudokucsp.h"

using namespace std;

struct ltsv {
	bool operator() (const SudokuVariable* var1, const SudokuVariable* var2) const {
		return var1->getIndex() < var2->getIndex();
	}
};

class DomainRestoreInfo {
private:
	map<SudokuVariable*, SudokuDomain*, ltsv> savedDomains;
	set<SudokuVariable*, ltsv> affectedVariables;
	bool emptyDomainObserved;
	bool empty;
public:
	DomainRestoreInfo();
	void storeDomainFor(SudokuVariable* var, SudokuDomain* domain);
	void setEmptyDomainFound(bool b);
	DomainRestoreInfo* compactify();
	bool isEmpty();
	bool isEmptyDomainFound();
	void restoreDomains(SudokuCSP* scsp);
};

#endif
