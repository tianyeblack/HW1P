HyperSudokuSolver:	hypersudokusolver.o backtrackingsearch.o domainrestoreinfo.o sudokuassignment.o hypersudokucsp.o sudokucsp.o sudokuconstraint.o sudokudomain.o sudokuvariable.o
	g++ -o HyperSudokuSolver -g -lstdc++ hypersudokusolver.o backtrackingsearch.o domainrestoreinfo.o sudokuassignment.o hypersudokucsp.o sudokucsp.o sudokuconstraint.o sudokudomain.o sudokuvariable.o

SudokuSolver:		sudokusolver.o backtrackingsearch.o domainrestoreinfo.o sudokuassignment.o sudokucsp.o sudokuconstraint.o sudokudomain.o sudokuvariable.o
	g++ -o SudokuSolver -g -lstdc++ sudokusolver.o backtrackingsearch.o domainrestoreinfo.o sudokuassignment.o sudokucsp.o sudokuconstraint.o sudokudomain.o sudokuvariable.o

DomainTest:		sudokudomaintest.o sudokudomain.o
	g++ -o DomainTest sudokudomaintest.o sudokudomain.o
	
sudokudomaintest.o:	sudokudomaintest.cpp
	g++ -Wall -g -c sudokudomaintest.cpp
	
hypersudokusolver.o:
	g++ -Wall -g -c hypersudokusolver.cpp
	
sudokusolver.o:		sudokusolver.cpp
	g++ -Wall -g -c sudokusolver.cpp

backtrackingsearch.o:	backtrackingsearch.cpp
	g++ -Wall -g -c backtrackingsearch.cpp
	
domainrestoreinfo.o:	domainrestoreinfo.cpp
	g++ -Wall -g -c domainrestoreinfo.cpp
	
sudokuassignment.o:	sudokuassignment.cpp
	g++ -Wall -g -c sudokuassignment.cpp
	
hypersudokucsp.o:	hypersudokucsp.cpp
	g++ -Wall -g -c hypersudokucsp.cpp
	
sudokucsp.o:		sudokucsp.cpp
	g++ -Wall -g -c sudokucsp.cpp
	
sudokuconstraint.o:	sudokuconstraint.cpp
	g++ -Wall -g -c sudokuconstraint.cpp

sudokudomain.o:		sudokudomain.cpp
	g++ -Wall -g -c sudokudomain.cpp
	
sudokuvariable.o:	sudokuvariable.cpp
	g++ -Wall -g -c sudokuvariable.cpp

clean:
	rm -f *.o SudokuSolver HyperSudokuSolver
