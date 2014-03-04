#include <iostream>
#include "sudokudomain.h"

using namespace std;

int main() {
	SudokuDomain* sd = new SudokuDomain();
	cout << sd->getDomain() << endl;
	sd->setDomain(5);
	cout << sd->getDomain() << endl;
}
