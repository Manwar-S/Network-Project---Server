

#ifndef LURK_PRO_SERVER_H
#define LURK_PRO_SERVER_H


#include <string>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string.h>
#include<array>
//#include"lurk_classes.h"
//using std:: vector;

//extern vector<Connection*> CoRooms;
//extern vector<Character> Monsters;
using namespace std;


//1
struct Message{
        unsigned short Message_Len;
        string Rec_Name;
        string Sen_Name;
        string The_Message;
};
//2
struct ChangeRoom{
        unsigned short change_room;
};
//3
struct Fight{
};
//4
struct PvPFight{
        string Fighter_Name;
};


//5
struct Loot{
        string Loot_Name;
};

//6
struct Start{
        
};
//7
struct Error{ 
        unsigned short Err_code;
        unsigned short Err_Message_len;
        string Err_Message;

};
//8
struct Accept{
        unsigned int Accepted;
};
//9
struct Room{
//	Player* enemy; 
        unsigned short Room_num;
        string Room_name;
        unsigned short Room_des_len;
        string Room_des;
	vector<int> conn;
	//extern vector<Player*> Players;
	string getRname(){
		return Room_name;
	}
	string getRdes(){
                return Room_des;
        }
	int getRnum(){
		return Room_num;
	}
	
	void setRname(string n){
		Room_name = n;
	}
	void setRdes(string de){
		Room_des = de;
        }
	void setRnum(int num){
		Room_num = num;
        }
	/*void addMonsters(string n, int a, int d, int r, int h, int g, string de){
		Character m;
		strcpy(m.CharName,n.c_str());
		m.Flags = 248;
		m.Attack = a;
		m.Defense = d;
		m.Regen = r;
		m.Health = h;
		m.Gold = g;
		m.Char_Des = de;
		m.Char_Des_len = m.Char_des.length();
		Monsters.push_back(m);
	}*/

};

//10
struct Character{ 
        //char Char_Name[32];
	string Char_Name;
	//std::array<char, 32> Char_Name;
        unsigned char  Flags;
        unsigned short Attack;
        unsigned short Defense;
        unsigned short Regen;
        short Health;
        unsigned short Gold;
        unsigned short Curr_Room_Num;
        unsigned short Char_Des_len;
        string Char_des;

	string getMName(){
        	return Char_Name;

	}

	char getFlags(){
        	return Flags;
	}
	int getAtt(){
        	return Attack;
	}
	int getDef(){
        	return Defense;
	}
	int getReg(){
        	return Regen;
	}
	int getHP(){
        	return Health;
	}
	int getGold(){
        	return Gold;
	}
	int getRoom(){
        	return Curr_Room_Num;
	}

	string getDes(){
        	return Char_des;
	}

	void setName( string n){
        	Char_Name = n;
	}
	void setFlags(char f){

        	Flags = f;
	}
	void setAtt(int a){

        	Attack = a;
	}
	void setDef(int d){

        	Defense = d;
	}
	void setReg(int r){

        	Regen = r;
	}
	void setHP(int h){

        	Health = h;
	}
	void setGold(int g){

        	Gold = g;
	}
	void setRoom(int r){

        	Curr_Room_Num = r;
	}
	void setDes(string de){

      		Char_des = de;
	}

	
	

};

//11
struct Game{ 
        unsigned short Int_points = 100;
        unsigned short Stat_limit = 7000;
        unsigned short Game_Des_len;
        string Game_des = "You wake up in the middle of a place called LCSC! It used to be place for students to go to in order to learn but not anymore. Now Its being controlled by a powerful wizard gone mad after doing some experiments that resulted in mass killing and turning people into MONSTERS!! Your mission is to locate and eliminate him and the monsters on the way.";
};
//12
struct Leave{
        
};

//13
struct Connection{ 
        unsigned short Conn_Room_num;
        string Conn_Room_name;
        unsigned short Conn_Room_des_len;
        string Conn_Room_des;
	string getRname(){
                return Conn_Room_name;
        }
        string getRdes(){
                return Conn_Room_des;
        }
        int getRnum(){
                return Conn_Room_num;
        }

        void setRname(string n){
                Conn_Room_name = n;
        }
        void setRdes(string de){
                Conn_Room_des = de;
        }
        void setRnum(int num){
                Conn_Room_num = num;
        }

};

//extern vector<Connection*> CoRooms;



// read type 13
void readConnection(Connection &P);

// read type 12
void readLeave(Leave &P);

// read type 11
void readGame(Game &P);

// read type 10
void readCharacter(Character &P);

// read type 9
void readRoom(Room &P);

// read type 8
void readAccept(Accept &P);

// read type 5
void readLoot(Loot &P);

// read type 2
void readChangeRoom(ChangeRoom &P);

// read type 1
void readMessage( Message &P);

//___________________________________________________________________________

// write type 13
void writeConnection(Connection P, int skt);

// write type 11
void writeGame(Game P, int skt);

//write type 10
void writeCharacter(Character P, int skt);

// write type 9
void writeRoom(Room P, int skt);

//write type 8
void writeAccept(Accept P, int skt);

//write type 7
void writeError(Error P, int skt);

//write type 1
void writeMessage(Message P, int skt);





#endif
 




