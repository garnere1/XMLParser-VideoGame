#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Move.h"
#include "Map.h"
#include "Object.h"

void play(std::vector<Map*> map, Player * player) {
	std::string input;
	Room* room = map[0]->getRoom("Entrance");
	player->setLocation(room);
	//std::cout << map[0]->conts[0]->getContName() << std::endl;

	bool run = true;
	std::cout << "Current Room: " << room->getName() << std::endl;
	std::cout << room->getDescription() << std::endl;
	while(run) {
		int invalid = 0;
		std::getline(std::cin, input);
		if(input == "i") {
			if(player->items.empty()) {
				std::cout << "Inventory: empty" << std::endl;
			}
			else {
				std::cout << "Inventory:";
				for(int i = 0; i < player->items.size() - 1; i ++) {
					std::cout << player->items[i]->getItmName() << ",";
				}
				std::cout << player->items[player->items.size() - 1]->getItmName() << std::endl;
			}
			invalid = 1;
		}
		else if(input == "open exit") {
			if(player->getLocation()->getRoomType() == "exit") {
				std::cout << "Victory!" << std::endl;
				std::cout << "Game over" << std::endl;
				run = false;
			}
			else {
				std::cout << "Room does not contain exit" << std::endl;
			}
			invalid = 1;
		}
		else if(input == "n" || input == "s" || input == "e" || input == "w") {
			Room* croom = player->getLocation();
			std::string border = croom->getBorder(input);
			if(border == "no") {
				std::cout << "Can't go that way" << std::endl;
			}
			//New Code
			else if ((croom->room_trig != NULL) && (croom->room_trig->trig_cond->getHas() == 0) && (croom->room_trig->getCommand() == input)) {
				std::cout << croom->room_trig->getType() << std::endl;
			}
			//
			
			//Old Code
			/*
			else if ((croom->room_trig->trig_cond->getHas() == 0) && (croom->room_trig->getCommand() == input)) {
				std::cout << "here" <<std::endl;
				std::cout << croom->room_trig->getType() << std::endl;
			}*/
			else {
				croom = map[0]->getRoom(border);
				player->setLocation(croom);
				std::cout << "Current room: " << player->getLocation()->getName() << std::endl;
				std::cout << player->getLocation()->getDescription() << std::endl;
			}
			invalid = 1;
		}
		const char c = ' ';
		std::stringstream ss(input);
		std::string input1;
		std::string input2;
		std::string input3;
		std::string input4;
		std::getline(ss, input1, c);
		std::getline(ss, input2, c);
		std::getline(ss, input3, c);
		std::getline(ss, input4, c);
		if(input1 == "take") {
			Room* cRoom = player->getLocation();
			int check = 0;
			std::vector<std::string> ritems = cRoom->getItems();
			for(int i = 0; i < ritems.size(); i ++) {
				if(ritems[i] == input2)
					check = 1;
			}
			std::vector<std::string> rconts = cRoom->getContainers();
			int s;
			for(int i = 0; i < rconts.size(); i ++) {
				Cont* c = map[0]->getContainer(rconts[i]);
				std::vector<std::string> contIts = c->getContItem();
				if(contIts.size() != 0) {
					if(contIts[0] == input2 && c->getOpen()) {
						check = 2;
						s = i;
						break;
					}
				}	
			}
			if(check == 0) {
				int yes = 0;
				std::vector<Itm*>::iterator iter;
				for (iter = player->items.begin(); iter != player->items.end(); iter++) {
					if(input2 == (*iter)->getItmName()) {
						yes = 1;
						std::cout << input2 << " already added to inventory" << std::endl;
					}
				}
				if (yes == 0) {
					std::cout << input2 << " not in current room or its container is not open" << std::endl;
				}
			}
			else {
				Itm* it = map[0]->getItem(input2);
				player->addItem(it);
				if(check == 1)
					cRoom->removeIt(it->getItmName());
				if(check == 2) {
					Cont* c = map[0]->getContainer(rconts[s]);
					c->removeCit(it->getItmName());
				}

				std::cout << "Item " << it->getItmName() << " added to the inventory" << std::endl;
				
				
				//New Code
				if ((cRoom->room_trig != NULL) && (cRoom->room_trig->trig_cond->getOwnerName() == "inventory")) {
					std::string object = cRoom->room_trig->trig_cond->getObjName();
					if (it->getItmName() == object) {
						cRoom->room_trig->trig_cond->setHas("yes");
					}
				}
				for (int i = 0; i < map[0]->creats.size(); i++)
				{
					if (map[0]->creats[i]->creat_trig != NULL) {
						if (map[0]->creats[i]->creat_trig->trig_cond != NULL)
						{
							if ((map[0]->creats[i]->creat_trig->trig_cond->getObjName() == input2) && (map[0]->creats[i]->creat_trig->trig_cond->getOwnerName() == "inventory")) {
								std::cout << map[0]->creats[i]->creat_trig->getType() << std::endl;
								std::string temp = map[0]->creats[i]->creat_trig->getTriggerAction();
								std::istringstream iss(temp);
								std::string subs;
								for (int j = 0; j < 4; j++) {
									iss >> subs;
								}
								it->setItmStatus(subs);
							}
							//std::cout << map[0]->creats[i]->creat_trig->trig_cond->getObjName() << std::endl;
						}
					}
				}
				//
				
				//Old code
				/*if ((cRoom->room_trig->trig_cond->getOwnerName()) && (cRoom->room_trig->trig_cond->getOwnerName() == "inventory")) {
					std::string object = cRoom->room_trig->trig_cond->getObjName();
					if (it->getItmName() == object) {
						cRoom->room_trig->trig_cond->setHas("yes");
					}
				}
				it->setItmStatus(cRoom->getName());
				std::cout << it->getItmWriting() << std::endl;
				* */
			}
		}
		else if(input1 == "read") {
			Itm * it = map[0]->getItem(input2);
			int check = 1;

			std::vector<Itm*>::iterator iter;
			for (iter = player->items.begin(); iter != player->items.end(); iter++) {
				if(input2 == (*iter)->getItmName()) {
					check = 0;
				}
			}	
			if(check == 0) {
				if(it->getItmWriting().empty()) {
					std::cout << "Nothing written" << std::endl;
				}
				else {
					std::cout << it->getItmWriting() << std::endl;
				}
			}
			else {
				std::cout << input2 << " not in inventory" << std::endl;
			}
		}
		else if(input1 == "open" && input2 != "exit") {
			Cont * c = map[0]->getContainer(input2);
			if (c != NULL) {
				c->setContOpen();
				std::vector<std::string> its = c->getContItem();
				if(its.size() != 0) {
					std::cout << input2 << " contains ";
					std::cout << its[0] << std::endl;
				}
				
				//Old code
				//else if (c->cont_trig->getType() != "") {
				
				//New Code
				else if ((its.size() == 0) && (c->getHasTrigger() == "yes")) {
				//
					for(int i = 0; i < player->items.size(); i ++) {
						if (player->items[i]->getItmName() == c->getAccept()) {
							std::cout << c->cont_trig->getType() << std::endl;
							Room* cRoom = player->getLocation();
							if (cRoom->room_trig->trig_cond->getObjName() == c->getContName()) {
								cRoom->room_trig->trig_cond->setHas("yes");
							}
						}
					}
				}
				else {
					std::cout << input2 << " contains nothing" << std::endl;
				}
			}
			else {
				std::cout << "No such container exists in this room" << std::endl;
			}
		}
		else if(input1 == "put") {
			Cont * c = map[0]->getContainer(input4);
			
			//New Code
			int check = 1;

			std::vector<Itm*>::iterator iter;
			for (iter = player->items.begin(); iter != player->items.end(); iter++) {
				if(input2 == (*iter)->getItmName()) {
					check = 0;
				}	
			}
			if(check == 1) {
				std::cout << input2 << " not in inventory" << std::endl;
			}
			else {
				Itm* it = map[0]->getItem(input2);
				if (it != NULL) {
					player->removeItem(it);
					c->setContItem2(input2);
					std::cout << "Item " << input2 << " added to " << input4 << std::endl;
					if (c->cont_trig != NULL) {
						std::cout << c->cont_trig->getType() << std::endl;
						Room* cRoom = player->getLocation();
						if (cRoom->room_trig->trig_cond->getObjName() == c->getContName()) {
							cRoom->room_trig->trig_cond->setHas("yes");
						}
					}
				}
				else {
					std::cout << "Item " << input2 << "cannot be added to " << input4 << std::endl;
				}
			}
		//
			
			//Old code
			/*
			if(c->getContOpen() == false) {
				std::cout << "Cannot add " << input2 << " to closed " << input4 << std::endl;
			}
			else {
				int check = 1;

				std::vector<Itm*>::iterator iter;
				for (iter = player->items.begin(); iter != player->items.end(); iter++) {
					if(input2 == (*iter)->getItmName()) {
						check = 0;
					}	
				}
				if(check == 1) {
					std::cout << input2 << " not in inventory" << std::endl;
				}
				else {
					Itm* it = map[0]->getItem(input2);
					if (it != NULL) {
						player->removeItem(it);
						c->setContItem2(input2);
						std::cout << "Item " << input2 << " added to " << input4 << std::endl;
					}
					else {
						std::cout << "Item " << input2 << "cannot be added to " << input4 << std::endl;
					}
				}
			}
			*/
		}
		else if(input1 == "drop") {
			std::vector<Itm*>::iterator iter;
			bool in = false;
			for (iter = player->items.begin(); iter != player->items.end(); iter++) {
				if(input2 == (*iter)->getItmName()) in = true;
			}
			if(in == false) {
				std::cout << input2 << " not in inventory." << std::endl;
			}
			else {
				Room * room = player->getLocation();
				room->setItem(input2);
				Itm * it = map[0]->getItem(input2);
				player->removeItem(it);
				std::cout << input2 << " dropped" << std::endl;
			}
		}
	    else if (input1 == "Add")
		{
			std::string roomName = player->getLocation()->getName();
			Object* objRoom = map[0]->getRoomTriggers(roomName, input2);
			Room * room = player->getLocation();
			if (objRoom == NULL)
			{
				std::string owner = map[0]->getContainerOwner(roomName);
				Object* objCont = map[0]->getContainerObjects(roomName, input2);
				if (objCont == NULL)
				{
					std::cout << "Object not found" << std::endl;
				}
				else
				{
					std::cout << objCont->name << " added to container " << owner << std::endl;
				}
			}
			else if (objRoom->name == input2)
			{
				std::cout << objRoom->name << " added to room " << room->getName() << std::endl;
			}
		}
		else if (input1 == "Delete")
		{
			std::string check = map[0]->checkRoom(input2);
			if (check == "true")
			{
				map[0]->deleteRoom(input2);
				std::cout << input2 << " deleted. It cannot be added back" << std::endl;
			}
			else
			{
				std::string name = player->getLocation()->getName();
				map[0]->deleteObject(name, input2);
				std::cout << input2 << " object deleted." << std::endl;
			}
		}
		else if (input1 == "Update")
		{
			std::string name = player->getLocation()->getName();
			map[0]->updateCondition(name, input2, input4);
			std::cout << input2 << " updated to " << input4 << std::endl;
		}
		else if ((input1 == "Game") && (input2 == "Over"))
		{
			//std::cout << "Victory!" << std::endl;
			run = false;
		}
		else if ((input1 == "turn") && (input2 == "on")) {
			Itm* itemToDrop = NULL;
			std::vector<Itm*>::iterator iter;
			bool in = false;
			for (iter = player->items.begin(); iter != player->items.end(); iter++) {
				if(input3 == (*iter)->getItmName()) { 
					in = true;
					std::cout << (*iter)->itm_turnon->getPrint() << std::endl;
					(*iter)->itm_turnon->printTurnon();
					std::string temp = (*iter)->itm_turnon->action;
					std::istringstream iss(temp);
					std::string subs;
					for (int i = 0; i < 4; i++) {
						iss >> subs;
					}
					/*if ((*iter)->itm_turnon->getPrint() != "") {
						(*iter)->itm_turnon->getPrint();
					}*/
					const char c = ' ';
					std::stringstream ss(temp);
					std::string act;
					std::getline(ss, act, c);

					(*iter)->setItmStatus(subs);
					//(*iter)->turnons[0]->setUsed(1);
					(*iter)->itm_turnon->setUsed(1);
					Room* croom = player->getLocation();
					//Old code
					/*std::string creature = croom->getCreature();
					if (creature != "") {
						Creat* ccreat = map[0]->getCreat(creature);*/
					
					//New Code
					//if (croom->room_creats[0] != "") {
					if (!croom->room_creats.empty()) {
						Creat* ccreat = map[0]->getCreat(croom->room_creats[0]);
						std::vector<Itm*>::iterator iter;
						for (iter = player->items.begin(); iter != player->items.end(); iter++) {
							if ((*iter)->getItmStatus() == ccreat->creat_trig->trig_cond->objStatus) {
								std::cout<< ccreat->creat_trig->getType() <<std::endl;
							}
						}
					}
					if(act == "drop") {
						itemToDrop = (*iter);
					}
				}
			}
			if(itemToDrop != NULL) {
				player->removeItem(itemToDrop);
				Room * room = player->getLocation();
				room->setItem(input3);
			}
			if(in == false) {
				std::cout << input3 << " not in inventory." << std::endl;
			}
		}
		else if ((input1 == "attack") && (input3 == "with")) {
			
			Room * room = player->getLocation();
			int check = room->parseCreatures(input2);
			if (check == 0) {
				int check2 = 0;
				for (int k = 0; k < map[0]->creats.size(); k++) {
					if (map[0]->creats[k]->getCreatName() == input2) {
						check2 = 1;
					}
				}
				if (check2 == 0) {
					std::cout << input2 << " not in game or not able to be attacked" << std::endl;
				}
				else {
					std::cout << input2 << " not in current room" << std::endl;
				}
			}
			/*std::string rcreat = room->getCreature();
			if (input2 != rcreat) {
				std::cout << input2 << " not in current room" << std::endl;
			}*/
			else {
				Creat* ccreat = map[0]->getCreat(input2);
				if (ccreat == NULL)
				{
					std::cout << "No such creature exists" << std::endl;
				}
				else {
					std::vector<Itm*>::iterator iter;
					bool in = false;
					for (iter = player->items.begin(); iter != player->items.end(); iter++) {
						if(input4 == (*iter)->getItmName()) {
							in = true;
							int check = 0;
							
							//New Code
							for (int j = 0; j < ccreat->vuns.size(); j++) {
								if ((*iter)->getItmName() == ccreat->vuns[j]) {
									check = 1;
								}
							}
							if (check == 0) {
								std::cout << "cannot attack " << input2 << " with " << input4 << std::endl;
								break;
							}
							//
							
							//Old Code
							/*if ((*iter)->getItmName() != ccreat->getVun()) {
								std::cout << "cannot attack " << input2 << " with " << input4 << std::endl;
								break;
							}*/
							
							//New Code 
							if ((ccreat->creat_trig != NULL) && (ccreat->atk == NULL)) {
								for (int b = 0; b < player->items.size(); b++) {
									if (ccreat->creat_trig->trig_cond->getObjStatus() == player->items[b]->getItmStatus()) {
										//std::cout << player->items[b]->getItmStatus() << std::endl;
										std::cout << ccreat->creat_trig->getType() << std::endl;
									}
								}
								std::cout << "You've attacked the " << input2 << " with the " << input4 << std::endl;
								//std::cout << ccreat->creat_trig->trigger_actions[0] << std::endl;
								for (int f = 0; f < player->items.size(); f++) {
									if (player->items[f]->getItmStatus() == ccreat->creat_trig->trig_cond->getObjStatus()) {
										std::vector<std::string>::iterator iter5;
										for (int d = 0; d < ccreat->creat_trig->trigger_actions.size(); d++) {
											std::istringstream iss(ccreat->creat_trig->trigger_actions[d]);
											std::string subs;
											iss >> subs;
											if (subs == "Add") {
												iss >> subs;
												//New Code
												std::vector<Itm*>::iterator iter4;
												for (int a = 0; a < map[0]->itms.size(); a++)
												{
													if (map[0]->itms[a]->getItmName() == subs) {
														room->setItem(subs);
													}
												}
												for (int a = 0; a < map[0]->creats.size(); a++)
												{
													if (map[0]->creats[a]->getCreatName() == subs) {
														room->setCreature(map[0]->creats[a]->getCreatName());
													}
												}
												//Old Code
												//room->setItem(subs);
											}
											else if (subs == "Delete") {
												for (int i = 0; i < room->room_creats.size(); i++) {
													if (room->room_creats[i] == input2) {
														room->room_creats.erase(room->room_creats.begin() + i);
													}
												}
												for (int k = 0; k < map[0]->creats.size(); k++) {
													if (map[0]->creats[k]->getCreatName() == input2) {
														map[0]->creats.erase(map[0]->creats.begin() + k);
													}
												}
											}
											else if (subs == "Game") {
												std::cout << "Victory!" << std::endl;
												run = false;
											}
										}
									}
								}
							}
							else if (ccreat->atk->atk_cond != NULL) {
							//if (ccreat->atk != NULL) {
								//std::cout << "here" <<std::endl;
								if ((*iter)->getItmStatus() == ccreat->atk->atk_cond->getObjStatus()) {
									std::cout << "here" << std::endl;
									std::vector<Itm*>::iterator iter3;
									for (iter3 = player->items.begin(); iter3 != player->items.end(); iter3++) {
										if(ccreat->creat_trig->trig_cond->getObjName() == (*iter3)->getItmName()) { 
											if (ccreat->creat_trig->trig_cond->getObjStatus() != (*iter3)->getItmStatus()) {
												std::cout << "Cannot attack " << input2 << " yet...maybe try turning on an item in your inventory" << std::endl;
											}
											else {
												std::cout << "You've attacked the " << input2 << " with the " << input4 << std::endl;
												if (ccreat->atk->getAttackPrint() != "") {
													std::cout << ccreat->atk->getAttackPrint() << std::endl;
												}
												std::vector<std::string>::iterator iter2;
												for (iter2 = ccreat->atk->actions.begin(); iter2 != ccreat->atk->actions.end(); iter2++) {
													std::istringstream iss(*iter2);
													std::string subs;
													iss >> subs;
													if (subs == "Add") {
														iss >> subs;
														room->setItem(subs);
													}
													else if (subs == "Delete") {
														for (int i = 0; i < room->room_creats.size(); i++) {
															if (room->room_creats[i] == input2) {
																room->room_creats.erase(room->room_creats.begin() + i);
															}
														}
														for (int k = 0; k < map[0]->creats.size(); k++) {
															if (map[0]->creats[k]->getCreatName() == input2) {
																map[0]->creats.erase(map[0]->creats.begin() + k);
															}
														}
													}
												}
											}
										}
									}
								}
								else {
									std::cout << "Cannot attack " << input2 << " yet...maybe try turning on an item in your inventory" << std::endl;
								}
							}
							else {
								std::cout << "You've attacked the " << input2 << " with the " << input4 << std::endl;
								if (ccreat->atk->getAttackPrint() != "") {
									std::cout << ccreat->atk->getAttackPrint() << std::endl;
								}
								std::vector<std::string>::iterator iter2;
								for (iter2 = ccreat->atk->actions.begin(); iter2 != ccreat->atk->actions.end(); iter2++) {
									std::istringstream iss(*iter2);
									std::string subs;
									iss >> subs;
									if (subs == "Add") {
										iss >> subs;
										//New Code
										std::vector<Itm*>::iterator iter4;
										for (int a = 0; a < map[0]->itms.size(); a++)
										{
											if (map[0]->itms[a]->getItmName() == subs) {
												room->setItem(subs);
											}
										}
										for (int a = 0; a < map[0]->creats.size(); a++)
										{
											if (map[0]->creats[a]->getCreatName() == subs) {
												room->setCreature(map[0]->creats[a]->getCreatName());
											}
										}
										//Old Code
										//room->setItem(subs);
									}
									else if (subs == "Delete") {
										for (int i = 0; i < room->room_creats.size(); i++) {
											if (room->room_creats[i] == input2) {
												room->room_creats.erase(room->room_creats.begin() + i);
											}
										}
										for (int k = 0; k < map[0]->creats.size(); k++) {
											if (map[0]->creats[k]->getCreatName() == input2) {
												map[0]->creats.erase(map[0]->creats.begin() + k);
											}
										}
									}
									else if (subs == "Game") {
										std::cout << "Victory!" << std::endl;
										run = false;
									}
								}
							}
						}
					}
					if(in == false) {
						std::cout << input4 << " not in inventory." << std::endl;
					}
				}
			}
		}
		else {
			if(invalid == 0) {
				std::cout << "Invalid Input" << std::endl;
			}
		}
	}
}
