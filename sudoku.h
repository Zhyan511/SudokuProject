#pragma once
#include"stdafx.h"
#include<algorithm>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Sudoku
{

public:
	Sudoku();
	void solveSudoku(string path);
	void createSudoku(int sudokuCount);
	void backtrace(int count);
	bool isPlace(int count);

private:
	char grid[9][9];
	ofstream resultfile;
	//void PrintTOFile();

};
