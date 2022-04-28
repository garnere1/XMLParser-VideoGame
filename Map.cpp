#include "Map.h"
#include <iostream>
#include <string>
#include "Trigger.h"

Map::Map() {
	std::cout << "Map:" << std::endl;
}

void Map::print() {
	std::cout <<"hi" <<std::endl;
}

void Map::addRoom(Room* room) {
	rooms.push_back(room);
}

void Map::addCreat(Creat* creat) {
	creats.push_back(creat);
}

void Map::addCont(Cont* cont) {
	conts.push_back(cont);
}

void Map::addItm(Itm* itm) {
	itms.push_back(itm);
}

Room * Map::getRoom(std::string name) {
	std::vector<Room*>::iterator iter;
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		if(name == (*iter)->getRoomType()) return (*iter);
		if(name == (*iter)->getName()) return (*iter);
	}

	return NULL;
}

//std::string Map::getRoomTriggers(std::string name, std::string object) {
Object* Map::getRoomTriggers(std::string name, std::string object) {
	std::vector<Room*>::iterator iter;
	//std::string obj1 = "";
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		if(name == (*iter)->getName()) {
			//Object* obj1 = (*iter)->parseTriggers(object);
			//return obj1;
			return (*iter)->parseTriggers(object);
		}
	}
	
	//return obj1;
	return NULL;
}

Cont * Map::getContainer(std::string name) {
	std::vector<Cont*>::iterator iter;
	for (iter = conts.begin(); iter != conts.end(); iter++) {
		//std::cout << (*iter)->getContName() << std::endl;
		if(name == (*iter)->getContName()) 
			return (*iter);
	}
	return NULL;
}

Room * Map::getRoomItem(std::string name) {
	std::vector<Room*>::iterator iter;
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		for(int i = 0; i < (*iter)->getItems().size(); i++) {
			if((*iter)->getItems()[i] == name) {
					return (*iter);
			}
		}
	}
	return NULL;
}

Creat * Map::getCreat(std::string name) {
	std::vector<Creat*>::iterator iter;
	for (iter = creats.begin(); iter != creats.end(); iter++) {
		//std::cout << (*iter)->getCreatName() << std::endl;
		if(name == (*iter)->getCreatName()) {
			//std::cout << (*iter)->attacks[0]->getAttackPrint() << std::endl;
			return (*iter);
		}
	}
	return NULL;
}

Itm * Map::getItem(std::string name) {
	std::vector<Itm*>::iterator iter;
	for (iter = itms.begin(); iter != itms.end(); iter++) {
		if(name == (*iter)->getItmName()) 
			return (*iter);
	}
	return NULL;
}

//std::string Map::getContainerObjects(std::string name, std::string object) {
Object* Map::getContainerObjects(std::string name, std::string object) {
	std::vector<Cont*>::iterator iter;
	//std::string obj1 = "";
	for (iter = conts.begin(); iter != conts.end(); iter++)
	{	
		//if ((*iter)->getOwner() == name)
		if ((*iter)->getHasTrigger() == "yes")
		{
			//obj1 = (*iter)->parseContTriggers(object);
			Object* obj1 = (*iter)->parseContTriggers(object);
			return obj1;
		}
	}
	//return obj1;
	return NULL;
}

std::string Map::getContainerOwner(std::string name) {
	std::vector<Cont*>::iterator iter;
	for (iter = conts.begin(); iter != conts.end(); iter++)
	{	
		if ((*iter)->getHasTrigger() == "yes")
		{
			if ((*iter)->getOwner() == name)
			{
				return (*iter)->getContName();
			}
		}
	}
	return "";
}

std::string Map::checkRoom(std::string name) {
	std::vector<Room*>::iterator iter;
	std::string check = "false";
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		if(name == (*iter)->getName())
		{
			check = "true";
		}
	}
	return check;
}

void Map::deleteRoom(std::string name)
{
	int idx;
	for(int i = 0; i < rooms.size(); i++) {
		if(rooms[i]->getName() == name) {
			idx = i;
		}
	}
	rooms.erase(rooms.begin() + idx);
}

void Map::updateCondition(std::string name, std::string object, std::string status) {
	std::vector<Room*>::iterator iter;
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		if(name == (*iter)->getName()) {
			(*iter)->parseTriggersUpdate(object, status);
		}
	}
	std::vector<Cont*>::iterator iter2;
	for (iter2 = conts.begin(); iter2 != conts.end(); iter2++)
	{	
		if ((*iter2)->getHasTrigger() == "yes")
		{
			(*iter2)->parseContTriggersUpdate(object, status);
		}
	}
}

void Map::deleteObject(std::string name, std::string object) {
	std::vector<Room*>::iterator iter;
	for (iter = rooms.begin(); iter != rooms.end(); iter++) {
		if(name == (*iter)->getName()) {
			(*iter)->parseTriggersDelete(object);
		}
	}
	std::vector<Cont*>::iterator iter2;
	for (iter2 = conts.begin(); iter2 != conts.end(); iter2++)
	{	
		if ((*iter2)->getHasTrigger() == "yes")
		{
			(*iter2)->parseContTriggersDelete(object);
		}
	}
}
