#pragma once
#include <string>

class Turnon {
private:
	std::string print;
	//std::string action;
public:
	Turnon();
	std::string action;
	int used;
	void setUsed(int _used);
	void setPrint(std::string print);
	void setAction(std::string action);
	void printTurnon();
	
	std::string getPrint();
	std::string getAction();
	int getUsed();
};
