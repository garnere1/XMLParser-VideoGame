#pragma once
#include <string>
#include <vector>
#include "Turnon.h"


class Itm {
private:
	std::string itm_status;
	std::string itm_writing;
	
public:
    Itm();
    std::string itm_name;
    //std::vector<Turnon*> turnons;
    Turnon* itm_turnon;
	void setItmName(std::string itm_name);
	void setItmStatus(std::string itm_status);
	void setItmWriting(std::string itm_writing);
	void addTurnon(Turnon* turnon);
	void printItmWriting();
	std::string getItmName();
	std::string getItmStatus();
	std::string getItmWriting();
};



