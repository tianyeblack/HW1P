#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "sudokuconstraint.h"
#include "sudokuvariable.h"
#include "sudokudomain.h"
#include "sudokucsp.h"
#include "sudokuassignment.h"
#include "domainrestoreinfo.h"
#include "backtrackingsearch.h"

using namespace std;

void convertToShort2D(string init[], short** result) {
	char* cstr = new char[init[0].length() + 1];
	for (int i = 1; i <= 9; i++) {
		std::strcpy(cstr, init[i].c_str());
		for(int j = 1; j <= 9; j++) {
			result[i][j] = cstr[2 * j - 2] == '-' ? 0 : cstr[2 * j - 2] - '0';
		}
	}
}

void convertToString2D(short** initial, string init[]) {
	char* cstr = new char[init[0].length() + 1];
	for (int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			cstr[2 * j - 2] = initial[i][j] + '0';
			cstr[2 * j - 1] = ' ';
		}
		cstr[17] = '\n';
		cstr[18] = '\0';
		init[i] = string(cstr);
	}
}

int main(int argc, char* argv[]) {
	ifstream ifile(argv[1]);
	string init[10];
	if (ifile.is_open()) {
		for (int i = 1; i <= 9; i++) {
			getline(ifile, init[i]);
		}
	}
	short** initial = new short*[10];
	for (int i = 0; i <= 9; i++) {
		initial[i] = new short[10];
	}
	convertToShort2D(init, initial);
	SudokuCSP* scsp = new SudokuCSP(initial);
	BackTrackingSearch* bts = new BackTrackingSearch();
	SudokuAssignment* sa = bts->solve(scsp, initial);
	sa->getAssignment(initial);
	convertToString2D(initial, init);
	ofstream ofile(argv[2]);
	if (ofile.is_open()) {
		for (int i = 1; i <= 9; i++) {
			ofile << init[i];
		}
	}
	return 0;
}
