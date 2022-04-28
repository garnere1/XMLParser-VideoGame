#ifndef PLAYER_H_
#define PLAYER_H_

#include "Room.h"
#include "Itm.h"
#include "Cont.h"
#include "Object.h"

class Player {
public:
	virtual ~Player();
	void setLocation(Room * room);
	Room * getLocation();
	void addItem(Itm* item);
	void addObj(Object* obj);
	void removeItem(Itm* item);

	std::vector<Itm*> items;
	std::vector<Object*> objs;
	
private:
	Room * location;
	
};

#endif /* PLAYER_H_ */
