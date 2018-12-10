#include"stdafx.h"
#include"sudoku.h"
#include<algorithm>
using namespace std;

Sudoku::Sudoku()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = 0;
	resultfile.open("sudoku.txt");
}

void Sudoku::createSudoku(int sudokuCount)
{
	int count = 0;
	int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
	for (int i = 0; i < 6; i++)
	{
		if (count >= sudokuCount)
			break;
		if (i)
		{
			next_permutation(shift + 3, shift + 6);     //����4~6�е���������
			shift[6] = 2, shift[7] = 5, shift[8] = 8;
		}
		for (int j = 0; j < 6; j++)
		{
			if (count >= sudokuCount)
				break;
			if (j) next_permutation(shift + 6, shift + 9);   //����7~9�е���������
			char row[10] = "712345689";
			for (int k = 0; k < 40320; k++)
			{
				if (count >= sudokuCount)
					break;
				if (k) next_permutation(row + 1, row + 9);//��һ�����ֲ��ܻ� ѧ�ţ�1120161760
				//ofstream resultfile; 
				//resultfile.open("sudoku.txt");
				for (int r = 0; r < 9; r++)
				{
					for (int c = 0; c < 9; c++)
						resultfile << row[(c + shift[r]) % 9] << ' ';
					resultfile << endl;
				}
				resultfile << endl;
				count++;
			}
		}
	}
}