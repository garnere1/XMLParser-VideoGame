#include <string>
#include <vector>
#include <iostream>
#include "XMLParser.h"
#include "tinyxml.h"

//Left most is map
Map* XMLParser::parseMap(TiXmlElement* element) {
	Map* map = new Map();
	std::string n = "MainCavern";
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			//Room
			if (name == "room") {
				Room* room = parseRoom(childElement);
				//own = room->name;
				if (room != NULL) {
					map->addRoom(room);
				}
			}
			//Item
			else if (childElement->ValueStr() == "item") {
				Itm* itm = parseItm(childElement);
				if (itm != NULL)
				{
					map->addItm(itm);
				}
			}
			//Container
			else if (childElement->ValueStr() == "container") {
				Cont* cont = parseCont(childElement, n);
				//std::cout << cont->getContName() << std::endl;
				if (cont != NULL)
				{
					std::cout << cont->getContName() << std::endl;
					map->addCont(cont);
				}
			}
			//Creature
			else if (childElement->ValueStr() == "creature") {
				Creat* creat = parseCreat(childElement);
				//std::cout << creat->attacks[0]->getAttackPrint() <<std::endl;
				if (creat != NULL) {
					map->addCreat(creat);
				}
			}
		}
	}
	return map;
}

//Given function from example XML Parser
std::string getTextFromNamedChild(TiXmlElement* element, std::string name) {
	TiXmlElement* child = element->FirstChildElement(name);
	if (child != NULL) {
		// we could use GetText instead of getting the child and calling ToText, but I wanted to show another method of parsing the child node
		TiXmlNode* grandchild = child->FirstChild();
		if (grandchild != NULL) {
			// similar to ToElement, this returns null if the node is not a text node
			TiXmlText* text = grandchild->ToText();
			if (text != NULL) {
				return text->ValueStr();
			}
		}
	}
	return "";
}

//Function to parse Items
Itm* XMLParser::parseItm(TiXmlElement* element)
{
	Itm* itm = new Itm();
	
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "name")
			{
				std::string value = childElement->GetText();
				itm->setItmName(value);
			}
			else if (name == "status")
			{
				std::string value = childElement->GetText();
				itm->setItmStatus(value);
			}
			else if (name == "writing")
			{
				std::string value = childElement->GetText();
				itm->setItmWriting(value);
			}
		}
	}
	
	itm->printItmWriting();
	
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "turnon")
			{
				Turnon* turnon = parseTurnon(childElement);
				if (turnon != NULL)
				{
					itm->addTurnon(turnon);
				}
			}
		}
	}
	
	return itm;
}

//Function to parse Turnons
Turnon* XMLParser::parseTurnon(TiXmlElement* element)
{
	Turnon* turnon = new Turnon();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "print")
			{
				std::string value = childElement->GetText();
				turnon->setPrint(value);
			}
			else if (name == "action")
			{
				std::string value = childElement->GetText();
				turnon->setAction(value);
			}
		}
	}
	return turnon;
}

//Function to parse Containers
Cont* XMLParser::parseCont(TiXmlElement* element, std::string own)
{
	Cont *cont = new Cont();
	std::string i = "";
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "name")
			{
				std::string value = childElement->GetText();
				cont->setContName(value, own);
			}
			else if (name == "item")
			{
				std::string value = childElement->GetText();
				cont->setContItem(value);
			}
			else if (name == "status")
			{
				std::string value = childElement->GetText();
				cont->setContStatus(value);
			}
			else if (name == "accept")
			{
				std::string value = childElement->GetText();
				cont->setAccept(value);
			}
			else if (name == "trigger")
			{
				cont->setHasTrigger("yes");
				i = "item";
				Trigger *cont_trigger = parseTrigger(childElement, i);
				if (cont_trigger != NULL)
				{
					cont->addContTrigger(cont_trigger);
				}
			}
		}
	}
	cont->setOwner(own);
	cont->printAccepts();
	return cont;
}

//Function to parse Creatures
Creat* XMLParser::parseCreat(TiXmlElement* element) {
	Creat* creat = new Creat();
	std::string i = "";
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "name")
			{
				std::string value = childElement->GetText();
				creat->setCreatName(value);
			}
			else if (name == "trigger")
			{
				i = "Item";
				Trigger *creat_trigger = parseTrigger(childElement, i);
				if (creat_trigger != NULL)
				{
					creat->addCreatTrigger(creat_trigger);
				}
			}
		}
	}
	int check = 0;
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "vulnerability")
			{
				std::string value = childElement->GetText();
				creat->printCreatO();
				creat->setVun(value);
				creat->addVun(value);
			}
			else if (name == "attack")
			{
				Attack* attack = parseAttack(childElement);
				if (attack != NULL)
				{
					check = 1;
					creat->setAttack(attack);
					//creat->addAttack(attack);
				}
			}
		}
	}
	if (check == 0) {
		creat->atk = NULL;
	}
	return creat;
}

//Function to parse Attacks
Attack* XMLParser::parseAttack(TiXmlElement* element)
{
	Attack* attack = new Attack();
	std::string i = "";
	
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "print")
			{
				std::string value = childElement->GetText();
				attack->setAttackPrint(value);
			}
			else if (name == "action")
			{
				std::string value = childElement->GetText();
				attack->setAction(value);
			}
			//New Code
			else if (name == "condition") {
				i = "Item";
				TiXmlElement* attack_cond = element->FirstChildElement("condition");
				Condition* attack_condition = parseCondition(attack_cond, i);
				attack->addAttackCondition(attack_condition);
			}
			//
		}
	}
	
	//Old code
	/*
	i = "Item";
	TiXmlElement* attack_cond = element->FirstChildElement("condition");
	Condition* attack_condition = parseCondition(attack_cond, i);
	attack->addAttackCondition(attack_condition);
	*/
			
	return attack;
}

//Function to parse Rooms
Room* XMLParser::parseRoom(TiXmlElement* element) {
	Room* room = new Room();
	
	int b_count = 0;
	std::string i = "";
	int check = 0;
	
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "name") {
				std::string value = childElement->GetText();
				room->setName(value);
			}
			else if (name == "description") {
				std::string value = childElement->GetText();
				room->setDescription(value);
			}
			else if (name == "type") {
				std::string value = childElement->GetText();
				room->setRoomType(value);
			}
			else if (name == "item") {
				std::string value = childElement->GetText();
				room->setItem(value);
				i = "Item";
			}
			else if (name == "container") {
				i = "Container";
			}
			else if (name == "trigger") {
				check = 1;
				Trigger *trigger = parseTrigger(childElement, i);
				if (trigger != NULL)
				{
					room->addTrigger(trigger);
				}
			}
			else if (name == "border") {
				Border *border = parseBorder(childElement);
				if (border != NULL)
				{
					room->addBorder(border);
					b_count++;
				}
			}
		}
	}
	
	room->printRoomType();
	
	for (int j = 0; j < b_count; j++)
	{
		Border* b = room->borders[j];
		b->printBorder();
	}
	
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			
			std::string name = childElement->ValueStr();
			
			if (name == "container") {
				std::string value = childElement->GetText();
				room->setContainer(value);
			}
			else if (name == "creature") {
				std::string value = childElement->GetText();
				room->setCreature(value);
			}
		}
	}
	
	if (check == 0) {
		room->room_trig = NULL;
	}
	
	room->printItem();
	return room;
}

//Function to parse Triggers
Trigger* XMLParser::parseTrigger(TiXmlElement* element, std::string i) {
	//New Code
	Trigger* trigger = new Trigger();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			std::string name = childElement->ValueStr();
			
			if (name == "type") {
				std::string value = childElement->GetText();
				trigger->setType(value);
			}
			
			if (name == "command") {
				std::string value = childElement->GetText();
				trigger->setCommand(value);
			}
			if(name == "print") {
				std::string value = childElement->GetText();
				trigger->setPrint(value);
			}
			if (name == "action") {
				std::string value = childElement->GetText();
				trigger->setTriggerAction(value);
				trigger->addAction(value);
			}
			if (name == "condition") {
				TiXmlElement* cond = element->FirstChildElement("condition");
				Condition* condition = parseCondition(cond, i);
				trigger->addCondition(condition);
			}
		}
	}
	//Old Code
	/*
	Trigger* trigger = new Trigger();
	trigger->setType(getTextFromNamedChild(element, "type"));
	trigger->setCommand(getTextFromNamedChild(element, "command"));
	trigger->setPrint(getTextFromNamedChild(element, "print"));
	trigger->setTriggerAction(getTextFromNamedChild(element, "action"));
	TiXmlElement* cond = element->FirstChildElement("condition");
	Condition* condition = parseCondition(cond, i);
	trigger->addCondition(condition);
	*/
	return trigger;
}

//Function to parse Conditions
Condition* XMLParser::parseCondition(TiXmlElement* element, std::string i) {
	Condition* condition = new Condition();
	condition->printCondition();
	condition->setHas(getTextFromNamedChild(element, "has"));
	condition->setObjName(getTextFromNamedChild(element, "object"), i);
	Object* obj = new Object();
	obj->setName(condition->getObjName());
	condition->addObject(obj);
	condition->setOwnerName(getTextFromNamedChild(element, "owner"));
	condition->setObjStatus(getTextFromNamedChild(element, "status"));
	condition->printStatus();
	//std::cout << "here" << std::endl;
	return condition;
}

//Function to parse Borders
Border* XMLParser::parseBorder(TiXmlElement* element) {
	Border* border = new Border();
	border->setDirection(getTextFromNamedChild(element, "direction"), getTextFromNamedChild(element, "name"));
	border->setName(getTextFromNamedChild(element, "name"));
	return border;
}

//Function to parse Map
std::vector<Map*> XMLParser::parseMaps(TiXmlElement* element) {
	std::vector<Map*> maps;
	
	//Only one map so no need for while loop
	if (element->ValueStr() == "map") {
		maps.push_back(parseMap(element));
	}

	return maps;
}

//XMP parser function
std::vector<Map*> XMLParser::parseXML(std::string filename) {
	TiXmlDocument doc(filename);
	doc.LoadFile();

	TiXmlElement* rootElement = doc.RootElement();

	if (rootElement == NULL) {
		std::cerr << "Invalid XML file, contains no data" << std::endl;
		return std::vector<Map*>();
	}

	if (rootElement->ValueStr() != "map") {
		std::cerr << "Invalid XML file, should start with a map" << std::endl;
		return std::vector<Map*>();
	}

	return parseMaps(rootElement);
}
