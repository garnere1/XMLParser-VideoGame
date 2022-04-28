#pragma once
#include <string>
#include <vector>
#include "Attack.h"
#include "Trigger.h"

class Creat {
private:
	//std::string creat_name;
	//std::string vun;
	//std::vector<Attack*> attacks;
	//std::vector<Trigger*> creat_triggers;
public:
    Creat();
    std::vector<std::string> vuns;
    //std::vector<Attack*> attacks;
    Attack* atk;
    Trigger* creat_trig;
    void setAttack(Attack* _attack);
    std::string creat_name;
    std::string vun;
	void setCreatName(std::string creat_name);
	void setVun(std::string vun);
	//void addAttack(Attack* attack);
	void addVun(std::string vun);
	void addCreatTrigger(Trigger* creat_trigger);
	void creatDone();
	void printCreatO();

	std::string getCreatName();
	std::string getVun();
};

