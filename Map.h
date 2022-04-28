#pragma once
#include <string>
#include <vector>
#include "Room.h"
#include "Creat.h"
#include "Cont.h"
#include "Itm.h"
#include "Object.h"

class Map {
private:
	std::vector<Room*> rooms;
	//std::vector<Creat*> creats;
	//std::vector<Cont*> conts;
	//std::vector<Itm*> itms;

public:
	Map();
	std::vector<Itm*> itms;
	std::vector<Creat*> creats;
	void addRoom(Room* room);
	std::vector<Cont*> conts;
	void addCreat(Creat* creat);
	void addCont(Cont* cont);
	void addItm(Itm* itm);
	Room * getRoom(std::string name);
	Room * getRoomItem(std::string name);
	Itm * getItem(std::string name);
	Creat * getCreat(std::string name);
	void print();
	//std::string getRoomTriggers(std::string name, std::string object);
	Object* getRoomTriggers(std::string name, std::string object);
	//std::string getContainerObjects(std::string name, std::string object);
	Object* getContainerObjects(std::string name, std::string object);
	Object* getObject(std::string name, std::string object);
	std::string getContainerOwner(std::string name);
	void deleteRoom(std::string name);
	std::string checkRoom(std::string name);
	void updateCondition(std::string name, std::string object, std::string status);
	void deleteObject(std::string name, std::string object);
	Cont* getContainer(std::string name);
};
