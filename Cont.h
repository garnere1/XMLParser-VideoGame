#pragma once
#include <string>
#include <vector>
#include "Trigger.h"
#include "Room.h"
#include "Object.h"


class Cont {
private:
	//std::string cont_name;
	//std::string cont_item;
	std::string cont_status;
	std::string accept;

	bool open;
	//std::string owner;
	//std::vector<Trigger*> cont_triggers;
	std::vector<std::string> cont_items;
	//std::vector<Object*> cont_objects;
	
public:
    Cont();
    Trigger* cont_trig;
    std::string cont_name;
    std::string owner;
    std::string has_trigger;
	void setContName(std::string cont_name, std::string own);
	void setContItem(std::string cont_item);
	void setContItem2(std::string cont_item);
	void setContStatus(std::string cont_status);
	void setAccept(std::string accept);
	void setOwner(std::string n);
	void addContTrigger(Trigger* cont_trigger);
	void printAccepts();
	void setHasTrigger(std::string has_t);
	//std::string parseContTriggers(std::string object);
	Object* parseContTriggers(std::string object);
	void parseContTriggersUpdate(std::string object, std::string status);
	void parseContTriggersDelete(std::string object);

	std::string getContName();
	std::vector<std::string> getContItem();
	std::string getContStatus();
	std::string getAccept();
	std::string getOwner();
	std::string getHasTrigger();
	bool getOpen();
	void removeCit(std::string item);

	void setContOpen();
	bool getContOpen();
};


