#include "lurk_classes.h"
#include "lurk_pro_server.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

vector<Player*> Players;
vector<Player*> Mine;
//vector<Rooms*> Roomss;
//vector <Player*> Monsters;
extern vector<Room> myRooms;
string Player:: getName(){
	return Ch.Char_Name;

}

char Player:: getFlags(){
	return Ch.Flags;
}

int Player :: getSkt(){
	return client_fd;
}
int Player :: getAtt(){
	return Ch.Attack;
}
int Player :: getDef(){
        return Ch.Defense;
}
int Player :: getReg(){
        return Ch.Regen;
}
int Player :: getHP(){
        return Ch.Health;
}
int Player :: getGold(){
        return Ch.Gold;
}
int Player :: getRoom(){
        return Ch.Curr_Room_Num;
}

string Player :: getDes(){
	return Ch.Char_des;
}



void Player:: setName(string n){
	Ch.Char_Name = n;
}
void Player::setFlags(char f){

	Ch.Flags = f;
}
void Player::setAtt(int a){

        Ch.Attack = a;
}
void Player::setDef(int d){

        Ch.Defense = d;
}
void Player::setReg(int r){

        Ch.Regen = r;
}
void Player::setHP(int h){

        Ch.Health = h;
}
void Player::setGold(int g){

        Ch.Gold = g;
}
void Player::setRoom(int r){

        Ch.Curr_Room_Num = r;
}
void Player:: setDes(string de){

      Ch.Char_des = de;
}



void Player::AddChar(Player* i){
	Players.push_back(i);
	cout <<"Curr_Vector_Size: " << Players.size() << endl;
	for(int i =0; i < Players.size(); i++){
		cout <<"Player: " << Players[i]->getName() << endl;
		cout <<"Des: " << Players[i]->getDes() << endl;
	}
}
void Player::RmChar(Player* i){
	for( int j = 0; j < Players.size(); j++){
		if(i->getName() == Players[j]->getName()){
			Players.erase(Players.begin()+j);
			cout << "new size: " << Players.size() << endl;
			break;
		}
	}
}

void Player::HereIam(Player p){

		for( int j = 0; j < Players.size(); j++){
			writeCharacter(p.getPlayer(), Players[j]->client_fd);
		}

}
/*void Player::addMonsters(char n[32], int a, int d, int r, int h, int g, string de){
                Player* m;
                m->setName(n);
                m->setFlags(248);
                m->setAtt(a);
                m->setDef(d);
                m->setReg(r);
                m->setHP(h);
                m->setGold(g);
                m->setDes(de);
                //m->Char_Des_len = m->Char_des.length();
                Monsters.push_back(m);
}*/


Character Player:: getPlayer(){
	return Ch;

}

