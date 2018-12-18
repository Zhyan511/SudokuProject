#include"stdafx.h"
#include"sudoku.h"
#include<algorithm>
#include<stdio.h>
using namespace std;

Sudoku::Sudoku()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = 0;
	for (int i = 0; i < 162; i++)
		matrix[i] = ' ';
	//resultfile.open("sudoku.txt");
}

void Sudoku::createSudoku(int sudokuCount)
{
	//fopen_s用法:，须定义另外一个变量errno_t err，然后err = fopen_s(&fp, filename, "w")。
	errno_t err;
	err = fopen_s(&resultfile1, "sudoku.txt", "w");
	cout << "打开写文件sudoku.txt" << endl;
	int count = 0;
	//char data_store[200]= {' '};
	int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
	for (int i = 0; i < 6; i++)
	{
		if (count >= sudokuCount)
			break;
		if (i)
		{
			next_permutation(shift + 3, shift + 6);     //交换4~6行的任意两行
			shift[6] = 2, shift[7] = 5, shift[8] = 8;
		}
		for (int j = 0; j < 6; j++)
		{
			if (count >= sudokuCount)
				break;
			if (j) next_permutation(shift + 6, shift + 9);   //交换7~9行的任意两行
			char row[10] = "712345689";
			for (int k = 0; k < 40320; k++)
			{
				if (count >= sudokuCount)
					break;
				if (k) next_permutation(row + 1, row + 9);//第一个数字不能换 学号：1120161760
				
				//fputs(data_store, resultfile1);
				int m = 0;
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						matrix[m] = row[(j + shift[i]) % 9];
						m += 2;
					}
					matrix[m - 1] = '\n';
				}
				
			  
				   fputs(matrix, resultfile1);
				  
				fputs("\n", resultfile1);
				count++;
			}
		}
	}
}
