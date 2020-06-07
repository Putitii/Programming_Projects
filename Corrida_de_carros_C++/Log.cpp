#include "Log.h"


Log::Log()
{

}

Log::~Log()
{
}

void Log::adicionaMensagem(string str) {
	logs.push_back(str);
}

string Log::getLogAsString() {
	ostringstream os;
	for (unsigned int i = 0; i < logs.size(); i++) {
		os << logs[i];
	}
	return os.str();
}