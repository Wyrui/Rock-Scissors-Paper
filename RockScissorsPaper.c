//Rock, Scissors, Paper

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int req,contU,contP,winU,winP,goal,bo; //ContU is for user's won rounds and contP is for PC's
	winP = 0; winU = 0;
	
	printf("Instructions: \n1.- Enter the number of rounds you need to win. \n2.- Enter a number to select Rock, Scissors or Paper. \n3.- 1 is Rock / 2 is Scissors / 3 is Paper. \nGood Luck! \n\n\n");
	
	printf("Introduce the number of rounds you need to win to get the victory: ");
	scanf("%i",&contU); contP=contU; goal=contU; bo=(contU*2-1); //Best Of calculated as wins (needed * 2) - 1. Example: BO 3 --> 2 wins needed
	printf("\n\n\n");
	printf("*** Best Of %i game selected *** \n\n\n\n",bo);
	
	while(contU>0 && contP>0){
		printf("Introduce a number between 1 and 3 to play: ");
	    scanf("%i",&req); //User's pick
	    printf("\n\n\n");
	    int p = ((rand() % 3)+1); //Random number between 1 and 3 (Generates number between 0 and 2 and adds 1 unit). PC's pick
	    if(p==1){ //Comparison with PC: Rock
	    		switch(req){
	    			case 1: printf("*** PC picked Rock and you picked Rock! That's a tie! *** \n\n");break;
	    			case 2: printf("*** PC picked Rock and you picked Scissors! You lose this round! *** \n\n"); contP--;winP++;break; //-1 unit to contP (while finishes with contP or contU = 0)
	    			case 3: printf("*** PC picked Rock and you picked Paper! You win this round! *** \n\n"); contU--;winU++;break; //winU & winP only required to show scores on line 47
	    			default: printf("*** Please read instructions and try again! *** \n\n");break;
				}
		}
		else if(p==2){ //Comparison with PC: Scissors
				switch(req){
	    			case 1: printf("*** PC picked Scissors and you picked Rock! You win this round! *** \n\n");contU--;winU++;break;
	    			case 2: printf("*** PC picked Scissors and you picked Scissors! That's a tie! *** \n\n");break;
	    			case 3: printf("*** PC picked Scissors and you picked Paper! You lose this round! *** \n\n"); contP--;winP++;break;
	    			default: printf("*** Please read instructions and try again! *** \n\n");break;	
		        }
		}
		else if(p==3){ //Comparison with PC: Paper
		    	switch(req){
	    			case 1: printf("*** PC picked Paper and you picked Rock! You lose this round! *** \n\n");contP--;winP++;break;
	    			case 2: printf("*** PC picked Paper and you picked Scissors! You win this round! *** \n\n");contU--;winU++;break;
	    			case 3: printf("*** PC picked Paper and you picked Paper! That's a tie! *** \n\n");break;
	    			default: printf("*** Please read instructions and try again! *** \n\n");break;	
	            }
	    }
	    printf("*** Scores right now are: PC %i/%i VS %i/%i You *** \n\n\n\n",winP,goal,winU,goal); //Shows how the match is going
	}
	if(contP==0){
		printf("**********PC WINS********** \n\n\n");
	}
	else{
		printf("**********YOU WIN********** \n\n\n");
	}
		
    
    system("pause");
	return 0; 
}


