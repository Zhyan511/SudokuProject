// sudoku.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"sudoku.h"
#include"time.h"
#define sudokuMaximum 1e6
using namespace std;


int main(int argc, char* argv[])
{
	int num = 0;
	if (argc!= 3)
	{
		//Raise_error();
		cout << "Number of parameters wrong!" << endl;//参数数量错误
	    return 0;
	}
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
       Sudoku M;
       int len = strlen(argv[2]);
	   for(int i=0;i<len;i++)
		   if (argv[2][i] < '0' || argv[2][i] > '9')
		   {
			   cout << "Number wrong!" <<argv[2][i]<< endl;//字符错误（不是数字）
			   return 0;
		   }
	   for(int i=0;i<len;i++)
	     num = num*10+argv[2][i]-'0';
	   if (num > 0 && num <= sudokuMaximum)
	   {
		   cout << "生成终局中..." << endl;
		   clock_t s_time, e_time;
		   s_time = clock();
          M.createSudoku(num);
		  e_time = clock();
		  cout << "Total time:" << (double)(e_time - s_time) / CLOCKS_PER_SEC << "S" << endl;

		}
			
		else
		{
          //Raise_error();
		  cout << "Number of sudoku wrong !" << endl; //生成终局数量错误
		  return 0;
		}
			
	}
	else if (argv[1][0] == '-' && argv[1][1] == 's')
	{
		Sudoku M;
		cout << "求解数独中..." << endl;
		clock_t s_time, e_time;
		s_time = clock();
		M.solveSudoku(string(argv[2]));
		e_time = clock();
		cout << "Total time:" << (double)(e_time - s_time) / CLOCKS_PER_SEC << "S" << endl;
	}
	else
	{
		//Raise_error();
		cout << "Type of command wrong!" << endl;//参数指令类型错误
		return 0;
	}
	cout << "Completed!"<<endl<<"You can look up the result in file 'sudoku.txt'!" << endl;
	return 0;
}
