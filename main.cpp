#include<iostream>
#include"connect4.h"
using namespace std;

GameState g1[]={okay,okay,okay,okay,okay,okay,repeat,repeat,repeat,okay,okay,okay,okay,red_wins,finished,finished,finished};
player p1[]={Yellow,Red,Yellow,Red,Yellow,Red,Red,Red,Red,Yellow,Red,Yellow,Red,Red,Red,Red,Red};
GameState g2[]={okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,yellow_wins,finished};
player p2[]={Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Yellow,Yellow};
GameState g3[]={okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,okay,Tie,Tie};
player p3[]={Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Red,Yellow,Yellow,Yellow};


player* ps[]={p1,p2,p3};
GameState* gs[]={g1,g2,g3};

void check(int i,GameState ggs,player p, bool reset=false)
{
	static int count=0;
	if(reset) count=0;
	if(gs[i][count]!=ggs)
	{
		cout<<"Invalid return of PutDisc No."<<count+1<<" in C"<<i+1<<endl;
		cout<<"Expected"<<toString(gs[i][count])<<endl;
		cout<<"returned"<<toString(ggs)<<endl;
		exit(-1);
	}
	if(ps[i][count]!=p)
	{
		cout<<"Invalid current player after PutDisc No."<<count+1<<" in C"<<i+1<<endl;
		cout<<"Expected"<<toString(ps[i][count])<<endl;
		cout<<"returned"<<toString(p)<<endl;
		exit(-2);
	}
	count++;
}
int main()
{
	Connect4 c1(Red);
	GameState gs;
	player p;
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p,true);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(1);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(2);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(2);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(3);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(3);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(4);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(4);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(4);p= c1.GetCurrentPlayer();check(0,gs,p);
	gs=c1.PutDisc(4);p= c1.GetCurrentPlayer();check(0,gs,p);
	c1.Print();
	cout<<"c1 finished correctly"<<endl;

	Connect4 c2(Yellow);
	gs=c2.PutDisc(1);p= c2.GetCurrentPlayer();check(1,gs,p,true);
	gs=c2.PutDisc(1);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(1);p= c2.GetCurrentPlayer();check(1,gs,p);

	gs=c2.PutDisc(2);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(2);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(2);p= c2.GetCurrentPlayer();check(1,gs,p);

	gs=c2.PutDisc(4);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(4);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(5);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(4);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(4);p= c2.GetCurrentPlayer();check(1,gs,p);

	gs=c2.PutDisc(5);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(6);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(5);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(6);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(5);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(5);p= c2.GetCurrentPlayer();check(1,gs,p);

	gs=c2.PutDisc(3);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(3);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(6);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(3);p= c2.GetCurrentPlayer();check(1,gs,p);
	gs=c2.PutDisc(3);p= c2.GetCurrentPlayer();check(1,gs,p);
	c2.Print();
	cout<<"c2 finished correctly"<<endl;

	Connect4 c3(Yellow);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p,true);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(0);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(1);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(2);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(3);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(4);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(5);p= c3.GetCurrentPlayer();check(2,gs,p);

	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);
	gs=c3.PutDisc(6);p= c3.GetCurrentPlayer();check(2,gs,p);

	c3.Print();
	cout<<"c3 finished correctly"<<endl;



    return 0;
}


