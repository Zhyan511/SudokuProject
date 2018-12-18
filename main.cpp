// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"sudoku.h"
#include"time.h"
#include"check.h"
#define sudokuMaximum 1e6
using namespace std;


int main(int argc, char* argv[])
{
	int num = 0;
	check N(argc, argv);
	N.input_type_analyse();
	if (!N.found_error())
	{
		Sudoku M;
		char type = N.get_type();
		if (type == 'c')
		{
			int num = N.get_num();
			cout << "生成终局中..." << endl;
			clock_t s_time, e_time;
			s_time = clock();
			M.createSudoku(num);
			e_time = clock();
			cout << "Total time:" << (double)(e_time - s_time) / CLOCKS_PER_SEC << "S" << endl;
		}
		else if (type == 's')
		{
			char* filename = N.get_filename();
			cout << "求解数独中..." << endl;
			clock_t s_time, e_time;
			s_time = clock();
			M.solveSudoku(string(filename));
			e_time = clock();
			cout << "Total time:" << (double)(e_time - s_time) / CLOCKS_PER_SEC << "S" << endl;
		}
		cout << "Completed!" << endl << "You can look up the result in file 'sudoku.txt'!" << endl;
	}
	return 0;
}
