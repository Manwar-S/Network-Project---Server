#ifndef LURK_CLASSES_H
#define LURK_CLASSES_H



#include "lurk_pro_server.h"
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;




class Player{

	public:
	int client_fd;
	Character Ch;
	
	void setName(string);
	void setFlags(char);
	void setAtt(int);
	void setDef(int);
	void setReg(int);
	void setHP(int);
	void setGold(int);
	void setRoom(int);
	void setDes(string);

	string getName();
	char getFlags();
	int getSkt();
	int getAtt();
	int getDef();
	int getReg();
	int getHP();
	int getGold();
	int getRoom();
	string getDes();

	void AddChar(Player*);
	void RmChar(Player*);
	//void addMonsters(char [32], int, int, int,int,int, string);
	void HereIam(Player);
	Character getPlayer();
};


/*class Rooms{

        public:
        int skt;
        Room R;

	void setNum(int);
	void setName(string);
	void setDes(string);

	int getNum();
	string getName();
	string getDes();
	int getSkt();


};*/
#endif
