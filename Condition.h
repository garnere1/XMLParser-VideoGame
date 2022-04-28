#pragma once
#include <string>
#include "Object.h"
#include <vector>

class Condition{
private:
	//std::string objName;
	//std::string objStatus;
	//std::string ownerName;
	std::vector<Object*> objects;

public:
	//std::vector<Object*> objects;
	std::string objName;
	int has;
	std::string objStatus;
	std::string ownerName;
	Condition();
	void setHas(std::string has);
	void setObjName(std::string objName, std::string i);
	void setObjStatus(std::string objStatus);
	void setOwnerName(std::string ownerName);
	void printCondition();
	void addObject(Object* obj);
	//std::string parseObjects(std::string object);
	Object* parseObjects(std::string object, std::string type);
	void printStatus();
	void parseObjectsDelete(std::string object);

	int getHas();
	std::string getObjName();
	std::string getObjStatus();
	std::string getOwnerName();
};
