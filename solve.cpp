#include"stdafx.h"
#include"sudoku.h"
#include<fstream>



bool Sudoku::isPlace(int count)
{
	int row = count / 9;
	int col = count % 9;
	int j;
	for (j = 0; j < 9; j++)     //ͬһ��
	{
		if (grid[row][j] == grid[row][col] && j != col)
			return false;
	}
	
	for (j = 0; j < 9; j++)     //ͬһ��
	{
		if (grid[j][col] == grid[row][col] && j != row)
			return false;
	}
	
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for (j = tempRow; j < tempRow + 3; j++)   //ͬһ��
	{
		for (int k = tempCol; k < tempCol + 3; k++)
		{
			if (grid[j][k] == grid[row][col] && j != row && k != col)
				return false;
		}
	}
	return true;
}

void Sudoku::backtrace(int count)
{
	//resultfile.open("sudoku.txt");
	if (count == 81)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				resultfile << grid[i][j] << " ";
			resultfile << endl;
		}
		resultfile << endl;
		return;
	}
	int row = count / 9;   //position��Ӧ��x����
	int col = count % 9;  //position��Ӧ��y����
	if (grid[row][col] == '0')
	{
		for (int i = 1; i <= 9; i++)//���Զ���һ�����1~9�ĸ�ֵ
		{
			grid[row][col] = i + '0';
			if (isPlace(count))//���Է�
			{
               backtrace(count + 1);//������һ��
			}
				
		}
		grid[row][col] = '0';//����
	}
	else
	backtrace(count + 1);
}

void Sudoku::solveSudoku(string path)
{
	ifstream problemfile(path);
	if (problemfile)
	{
		int total = 0;
		string temp[9];
		string str;
		int line = 0;
		bool exc = false;     // ʶ����problemfile��û�д�������
		while (total < 1000000 && getline(problemfile, str))
		{
			temp[line] = str;  //��problemfile�ж�ȡһ�е�temp��
			line++;
			if (line == 9)   //ÿ����9�н���һ�δ���
			{
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 9; j++)
					{
						grid[i][j] = temp[i][2 * j];  //�����ո�һ����������װ��grid��
						if (grid[i][j] < '0' || grid[i][j] > '9')
						{
							exc = true;
							break;
						}
					}
				getline(problemfile, str);//����һ����Ŀ��Ŀ���
				line = 0;
				if (exc)
				{
					exc = false;
					cout << "Error!" << endl;
					continue;
				}
				total++;
				// solve sudoku
				long count = 0;
				backtrace(0);
			}
		}
		//resultfile.close();
	}
	else
		cout << "Can't find such file:" << string(path) << endl;
}