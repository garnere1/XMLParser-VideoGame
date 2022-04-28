#pragma once
#include <vector>
#include <string>
#include "Map.h"
#include "Element.h"
#include "Room.h"
#include "Trigger.h"
#include "Condition.h"
#include "tinyxml.h"
#include "Border.h"
#include "Creat.h"
#include "Attack.h"
#include "Cont.h"
#include "Itm.h"
#include "Turnon.h"

class XMLParser {
private:
	std::vector<Map*> parseMaps(TiXmlElement* element);
	Map* parseMap(TiXmlElement* element);
	Room* parseRoom(TiXmlElement* element);
	Trigger* parseTrigger(TiXmlElement* element, std::string i);
	Attack* parseAttack(TiXmlElement* element);
	Itm* parseItm(TiXmlElement* element);
	Condition* parseCondition(TiXmlElement* element, std::string i);
	Border* parseBorder(TiXmlElement* element);
	Creat* parseCreat(TiXmlElement* element);
	Cont* parseCont(TiXmlElement* element, std::string own);
	Turnon* parseTurnon(TiXmlElement* element);
	
public:
	std::vector<Map*> parseXML(std::string filename);
};
