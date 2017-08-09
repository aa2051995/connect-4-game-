#include<string>
using namespace std;
#include<iostream>
#ifndef Connect4_header
#define Connect4_header

enum GameState{finished,okay,repeat,red_wins,yellow_wins,Tie};
enum player{Red,Yellow};

string toString(GameState gs);
string toString(player p);

class Connect4
{
	private:

		int game[6][7];

		player playertype;
		int redcount;
		int yellowcount;


	public:
			Connect4(player Firstplayer);
			void Print();
			player GetCurrentPlayer();
			GameState PutDisc(int Column);
};
#endif
