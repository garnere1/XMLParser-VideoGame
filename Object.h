#pragma once
#include <string>

class Object{
private:
	//std::string name;
	//Room* roomOwner;

public:
	Object();
	std::string name;
	//std::string objOwner;
	void setName(std::string _name);
	//void setObjOwner(std::string _owner);
	//std::string getObjOwner();
	
	std::string getName();
};

