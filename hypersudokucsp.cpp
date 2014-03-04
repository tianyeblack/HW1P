#include "hypersudokucsp.h"

HyperSudokuCSP :: HyperSudokuCSP(short** initial) : SudokuCSP(initial) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int m = 2; m <= 4; m++) {
				for (int n = 2; n <= 4; n++) {
					int x = i * 4 + m;
					int y = j * 4 + n;
					for (int p = i * 4 + 2; p <= i * 4 + 4; p++) {
						for (int q = j * 4 + 2; q <= j * 4 + 4; q++) {
							if (p == x && q == y) continue;
							SudokuConstraint* con = new SudokuConstraint(&svariables[xyTo1D(x, y)], &svariables[xyTo1D(p, q)]);
							if (!containConstraint(con)) {
								addConstraint(con);
							} else {
								delete con;
							}
							if (initial[x][y] != 0) {
								removeValueFromDomain(&svariables[xyTo1D(p, q)], initial[x][y]);
							}
						}
					}
					
				}
			}
		}
	}
}
