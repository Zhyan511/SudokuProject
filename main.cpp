// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"sudoku.h"
#define sudokuMaximum 1e6
using namespace std;


int main(int argc, char* argv[])
{
	ofstream exa("example.txt");
	int num = 0;
	if (argc!= 3)
	{
		//Raise_error();
		cout << "Number of parameters wrong!" << endl;
	    return 0;
	}
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
       Sudoku M;
       int len = strlen(argv[2]);
	   for(int i=0;i<len;i++)
		   if (argv[2][i] <= '0' || argv[2][i] >= '9')
		   {
			   cout << "Number wrong!" << endl;
			   return 0;
		   }
	   for(int i=0;i<len;i++)
	     num = num*10+argv[2][i]-'0';
		if (num > 0 && num <= sudokuMaximum)
			M.createSudoku(num);
		else
		{
          //Raise_error();
		  cout << "Number of sudoku wrong !" << endl;
		  return 0;
		}
			
	}
	else if (argv[1][0] == '-' && argv[1][1] == 's')
	{
		Sudoku M;
		M.solveSudoku(string(argv[2]));
	}
	else
	{
		//Raise_error();
		cout << "Type of command wrong!" << endl;
		return 0;
	}
	cout << "Completed!"<<endl<<"You can look up the result in file 'sudoku.txt'!" << endl;
	return 0;
}
