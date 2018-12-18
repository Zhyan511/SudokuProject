#include"stdafx.h"
#include"sudoku.h"
#include"check.h"
#include<algorithm>
#include<stdio.h>
	
    check::check(int argc ,char *argv[])
	{
		this->argc = argc;
		this->argv = argv;
		filename = NULL;
		type = 0;
		num = 0;
		input_error = false;
	}
	void check::input_type_analyse()
	{
		if (argc == 3)
		{
			if (strcmp(argv[1], "-c") == 0)
			{
				type = 'c';
				int len = strlen(argv[2]);
				num = 0;
				int flag = 0;
				for (int i = 0; i < len; i++)
				{
					if (argv[2][i] >= '0'&&argv[2][i] <= '9')
						num = num * 10 + (argv[2][i] - '0');
					else
					{
						input_error = true;
						printf("Error found in parameter, you should input only integar like '0~9'\n");
						num = -1;
						flag = 1;
						break;
					}
				}
				if (flag==0&&(num <= 0 || num > 1000000))
				{
					num = -1;
					input_error = true;
					printf("Number of sudoku wrong !\n");
				}
			}
			else if (strcmp(argv[1], "-s") == 0)
				{
					type = 's';
					filename = argv[2];

					//prevent us from opening a file that doesn't exist
					errno_t err;
					FILE *tryopen;
					err = fopen_s(&tryopen, filename, "r");
					if (err != 0)
					{
						input_error = true;
						printf("The file you want to open doesn't exist\n");
					}
				}
		    else
			{
					input_error = true;
					printf("the input is anomalous! Type of command wrong!\n");
			}
	
		}
		else
		{
			input_error = true;
			printf("Numbers of command parameters are not correct!%d\n", argc);
		}
	}

	char check::get_type()
	{
		return type;
	}
	int check::get_num()
	{
		return num;
	}
	char* check::get_filename()
	{
		return filename;
	}
	bool check::found_error()
	{
		return input_error;
	}