#include"Connect4.h"

string toString(GameState gs)
{
	if(gs==finished) return "finished";
	if(gs==okay) return "okay";
	if(gs==repeat) return "repeat";
	if(gs==red_wins) return "red_wins";
	if(gs==yellow_wins) return "yellow_wins";
	if(gs==Tie) return "Tie";
	return " ";

}
string toString(player p)
{
	if(p==Red) return "Red";
	else return "Yellow";
}

void Connect4::Print()

{
    for(int i =0; i<6; i++){
        for(int j=0; j<7; j++){
        switch(game[i][j]){
          case 1:cout<<"R";break;
           case -1: cout<<"Yfj";break;
           case 0:cout<<"0";break;}
          }
cout<<endl;}


	/* add your code  here to print the board */
}
Connect4::Connect4(player Firstplayer):playertype(Firstplayer),redcount(0),yellowcount(0)
{
	for(int i =0; i<6; i++)
        for(int j=0; j<7; j++)
          game[i][j]=0;



}
player Connect4::GetCurrentPlayer()
{
    //if(s!=repeat|s!=red_wins|s!=yellow_wins|s!=finished)
	  return playertype;


}
GameState Connect4::PutDisc(int Column)
{ GameState state =Tie;


     for(int k=0; k<7; k++)
        if(game[0][k]==0)
         state =okay;

        if(state!=okay){
        return state;}





     if(yellowcount==3 || redcount==3){
        state= finished;
        return state;
        }


     if(game[0][Column]!=0){
           state=repeat;
           return state;
           }
    ////////////////////put it in the desk
    /////////////////////////
     if(game[5][Column]==0)
        if(playertype==Red)
          game[5][Column]=1;
        else
            game[5][Column]=-1;
     else
       for(int i=0; i<5; i++){
          if(game[i][Column]==0&&game[i+1][Column]!=0)
            if(playertype==Red){
               game[i][Column]=1;
               break;}

            else{
               game[i][Column]=-1;
               break;}
            }
      state=okay;



/////////////////////////////////the  first diagonal case
//////////////////


     int y =5;
     int k=0;
      for(int i =0; i<3; i++){
        k=i;
          for(int j=0; j<y; j++){
            if(game[k][j]==-1 &&  game[k+1][j+1]==game[k][j]==-1 ){
              yellowcount+=1;
              if (yellowcount==3)
                {
                    state=yellow_wins;
                    return state;        }     }

            else
                if(yellowcount!=3)
                yellowcount=0;

            if(game[k][j]==game[k+1][j+1]&&game[k][j]==1 ){
                    redcount+=1;
                    if (redcount==3)
                      {
                        state=red_wins;
                        return state;      }        }

            else
                if(redcount!=3)
                redcount=0;
                k++;     }

///////////////////////////


    k=i;
          for(int j=0; j<y; j++){
            if(game[j][k+1]==game[j+1][k+2] && game[j][k+1]==1){
                 redcount+=1;
                 if(redcount==3)
                  {
                      state=red_wins;
                      return state;
                                    }
            else
                if(redcount!=3)
                redcount=0;

            if(game[j][k+1]==game[j+1][k+2]&&game[j][k+1]==-1){
                yellowcount+=1;
                if (yellowcount==3){
                    state=yellow_wins;
                    return state;}         }

            else
              if(yellowcount!=3)
               yellowcount=0;

                    k++;
                    }

         y--;
          }   }
///////////////////////////////////////////
/////////////////the second diagonal case
 y =2;
 k=0;
yellowcount=0;
redcount=0;
      for(int i =0; i<3; i++){
        k=i;
          for(int j=6; j>=y; j--){
            if(game[k][j]==-1 && game[k+1][j-1]==game[k][j] ){
              yellowcount+=1;
               if (yellowcount>=3){
                    state=yellow_wins;
                    return state;}       }
            else
                if(!(yellowcount>=3))
                  yellowcount=0;

            if(game[k][j]==game[k+1][j-1]  && game[k][j]==1 ){
                    redcount+=1;
                    if(redcount>=3){
                       state=red_wins;
                       return state;   }  }



            else
                if(!(redcount>=3))
                   redcount=0;

                k++;}
            y++;
                }



///////////
y=2;
  for(int i =0; i<3; i++){
     k=i;
     for(int j=6;  j>=y; j--){
        if(game[k-i][j-1]==game[k+1][j-2]  && game[k-i][j-1]==1){
             redcount+=1;
              if(redcount==3)
                        {
                            state=red_wins;
                            return state;
                        }
                                                                }
        else
        if(redcount!=3)
           redcount=0;

        if(game[k-i][j-1]==game[k-i+1][j-2]&&game[k-i][j-1]==-1){
                                yellowcount+=1;
                                if (yellowcount==3)
                                       {
                                            state=yellow_wins;
                                             return state;  }     }

        else
          if(yellowcount!=3)
             yellowcount=0;

                    k++;
                    }

         y++;
          }



    /////// / ////////
////////////////////////the x axis case

yellowcount=0;
redcount=0;
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++){
          if(game[i][j]==game[i][j+1] && game[i][j]==1){
             redcount+=1;
             if(redcount==3){
                state=red_wins;
                return state;       }            }
          else
            if(redcount!=3)
              redcount=0;
          if(game[i][j]==game[i][j+1] && game[i][j]==-1){
                yellowcount+=1;
                if(yellowcount==3){
                     state=yellow_wins;
                      return state;       }  }
          else
            if(yellowcount!=3)
               yellowcount=0;
                      }


    //////////////////////
    ///////////////////////////the y axis case
redcount=0;
yellowcount=0;
for(int i=0; i<7; i++)
        for(int j=0; j<5; j++){
          if(game[j][i]==game[j+1][i]&&game[j][i]==1){
            redcount+=1;
            if(redcount==3){
                state=red_wins;
                return state;}  }
           else
             if(redcount!=3)
                redcount=0;

        if(game[j][i]==game[j+1][i] && game[j][i]==-1){
               yellowcount+=1;
               if(yellowcount==3){
                state=yellow_wins;
                return state; }
          }


        else
             if(yellowcount!=3)
             yellowcount=0;

        }


if(playertype==Red)
    playertype=Yellow;
else
    playertype=Red;
return state;
//////////////////
////////////////////
	//puts a disc into column if possible

	//return values:
	//finished:    game ended  before by a winner
	//repeat:      No empty space in this column so that the move should be repeated
	//red_wins:    PutDisc is done and red wins
	//yellow_wins: PutDisc is done and yellow wins
	//Tie:         no empty cells avaliable so PutDisc couldn't be beformed
	//okay:        PutDisc is done with no winner yet

	// note that the current player won't change if any wins*/
}
