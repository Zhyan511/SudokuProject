#pragma once
#include<cstdlib>
#include<string>
using namespace std;
 
class check
{
public:
	check(int argc, char *argv[]);
	void input_type_analyse();
	char get_type();
	int get_num();
	char* get_filename();
	bool found_error();

private:
	int argc;
	char **argv;
	int num;
	char type;
	char* filename;
	bool input_error;
};