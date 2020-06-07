#pragma once
#include "includes.h"

class Log
{
	vector<string> logs;
public:
	Log();
	~Log();
	void adicionaMensagem(string str);
	string getLogAsString();
};

