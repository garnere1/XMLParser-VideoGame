#pragma once
#include <string>
#include <vector>
#include "Trigger.h"
#include "Border.h"
#include "Object.h"

class Room {
private:
	//std::string name;
	std::string description;
	//std::string container;
	std::vector<std::string> room_containers;
	//std::string creature;
	//std::vector<Trigger*> triggers;
	std::string room_type;

public:
    Room();
    std::vector<std::string> room_creats;
    //std::vector<Trigger*> triggers;
    Trigger* room_trig;
    std::vector<std::string> room_items;
    //std::vector<std::string> objects;
    std::string name;
    std::vector<Border*> borders;
	void setName(std::string name);
	void setDescription(std::string description);
	void setItem(std::string item);
	void setItem2(std::string item);
	void setContainer(std::string container);
	void setCreature(std::string rcreat);
	void setRoomType(std::string room_type);
	void addTrigger(Trigger* trigger);
	void addBorder(Border* border);
	void printItem();
	void printRoomType();
	//void setRoomCont();
	void removeIt(std::string item);
	//std::string parseTriggers(std::string object);
	Object* parseTriggers(std::string object);
	void parseTriggersUpdate(std::string object, std::string status);
	void parseTriggersDelete(std::string object);

	std::string getName();
	std::string getDescription();
	std::vector<std::string> getItems();
	std::vector<std::string> getContainers();
	//std::string getCreature();
	int parseCreatures(std::string rcreat);
	std::string getRoomType();
	std::vector<std::string> getRoomCont();

	std::string getBorder(std::string name);
};
