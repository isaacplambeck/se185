//SE 185: Final Project Template//
/////////////////////////
/* 
Team member 1 "Isaac Plambeck" | "100%"
*/

////////////////////
#include<stdio.h>//
//add more here////
#include <unistd.h> //for sleep()
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 9

//////////////////////
//Struct Definition//
////////////////////
typedef struct {
  char name[10];
  int score;
  int rank;
}player;



/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//them below the main function////
/////////////////////////////////
void Triangle();
void SquarePlusCircle();
void X();
void Spaces(int numSpaces);
void CircledX();
void CircledTriangle();
void CircledSquare();
void CircledCircle();
void randomGame(int time, int turn, int* num, int* answer);
void addToScoreboard(int score);
void newLine(int numOfLines);
void showHighscores(player p[]);
void writeToFile(player p[], int score);

//////////////////////
/////File name////////
//////////////////////
char fileName[30] = "highscores.txt"; //File name global var


int main(){
	
	player p[SIZE];
	
	srand(time(NULL)); /* This will ensure a random game each time. */
	
	//variables:
	char play; //player response when asked to play
	int num; //random number 0-3
	int turn; //number of turns that have happened
	int time; //number of times a circled shape was shown
	int score; //current score
	//char answer = 'x'; //correct choice w,a,s,d
	char userChoice = 'x'; //user choice w,a,s,d
	int answer[30]; //ASCII value of the letters w,a,s,d
	
	//opening message
	printf("Welcome to the Memory game.\n"
	"To start the game press \"g\".\n"
	"In the game various shapes will appear with a circle around it\n"
	"You must remember the shapes that are circled and repeat the order\n"
	"Use w for up, s for down, d for right, a for left\n");
	
	//new line above highscore table
	printf("\n");
	
	//print highscore table
	showHighscores(p);
	
	//remove later
	printf("\n");
	
	//starting question
	printf("What would you like to do?\n"
	"\"g\" for a game\n");
	
	//scan for input
	scanf("%c", &play);
	
	//starting game
	if(play == 'g'){
		printf("3...\n");
		sleep(1);
		printf("2...\n");
		sleep(1);
		printf("1...\n");
		sleep(1); 
	}
	
	
	turn = 1;
	time = 1;
	num = 0;
	score = 0;
	
	
	
	
	
	while(1){
		
		
	int temp = 0;
	
	time = 1;
	
	newLine(3);
	
	while(turn - temp > 0){
		
		printf("Shape %d: \n", time);
		
		randomGame(time, turn, &num, answer);
		temp += 1;
		time += 1;
		
		printf("\n");
		
		printf("loading...\n");
		sleep(3);
		
		newLine(100);
		
		
	}
	
	time = 1;
	
		
	
	
	printf("\n\n");
	
	printf("Turn: %d\n", turn);
	printf("Score: %d\n", score);
	printf("Okay, what was the order?(Use w,a,s,d)\n");
	
	while(time <= turn){
		
		printf("%d time: ", time);
		scanf(" %c", &userChoice);
		
		
		if(userChoice == answer[time]){
			
			score += 1;
			
			
			
			printf("Score: %d\n", score);
			printf("\n");
			
			if(turn - time == 0){
				turn += 1;
				printf("Good job, get ready for the next round.\n");
				
				
				printf("3...\n");
				sleep(1);
				printf("2...\n");
				sleep(1);
				printf("1...\n");
				sleep(1); 
				
				break;
				
				
			}
			
		
			time += 1;
			
			
		}
		else{
			
			char a = answer[time];
			
			printf("Nope the correct answer was %c.\n", a);
			printf("Sorry, you lose, at least you got to turn %d.\n", turn);
			printf("Your final score was %d. Try again and get even higher!\n", score);
			
			writeToFile(p, score);
			
			showHighscores(p);
			
			
			exit(0);
			
		}
		
	}
		
	}
	
	
	
	
	
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
void Triangle(){
	
	int totalRowNum, row, space, symbol;
	
	totalRowNum = 6;
	
	for(row = 1; row <= totalRowNum;  row++){
		//print spaces
		for(space = 1; space <= (totalRowNum - row)+13; space++){
			printf(" ");
		}
		
		//print symbol
		for(symbol = 1; symbol <= ((2*row)-1); symbol++){
			printf("^");
		}
		
		printf("\n");
	}
	
	
}

void SquarePlusCircle(){
	
	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	
	//circle part
	Spaces(20);
	printf("OO");
	
	printf("\n");	
	
	printf("   H     H");
	Spaces(19);
	printf("O  O");
	printf("\n");
	
	
	printf("   H     H");
	Spaces(18);
	printf("O    O");
	printf("\n");
	
	printf("   H     H");
	Spaces(18);
	printf("O    O");
	printf("\n");
	
	printf("   H     H");
	Spaces(19);
	printf("O  O");
	printf("\n");
	
	printf("   H     H");
	Spaces(20);
	printf("OO");
	printf("\n");
	
	
		
	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	
	
}

void X(){
	
	int num;
	
	Spaces(15);
	printf("X     X\n");
	
	Spaces(16);
	printf("X   X\n");
	
	Spaces(17);
	printf("X X\n");
	
	Spaces(18);
	printf("X\n");
	
	Spaces(17);
	printf("X X\n");
	
	Spaces(16);
	printf("X   X\n");
	
	Spaces(15);
	printf("X     X\n");
	
}


void Spaces(int numSpaces){
	int num = numSpaces; 
	
	while(num != 0){
		printf(" ");
		--num;
	}
	
}

void CircledX(){
	
	int num;
	
	Spaces(12);
	printf(".............\n");
	Spaces(12);
	printf(".");
	Spaces(11);
	printf(".\n");
	Spaces(12);
	printf(".  X     X  .\n");
	
	Spaces(12);
	printf(".   X   X   .\n");
	
	Spaces(12);
	printf(".    X X    .\n");
	
	Spaces(12);
	printf(".     X     .\n");
	
	Spaces(12);
	printf(".    X X    .\n");
	
	Spaces(12);
	printf(".   X   X   .\n");
	
	Spaces(12);
	printf(".  X     X  .\n");
	
	Spaces(12);
	printf(".");
	Spaces(11);
	printf(".\n");
	
	Spaces(12);
	printf(".............\n");
	
}

void CircledTriangle(){
	
	int totalRowNum, row, space, symbol;
	
	totalRowNum = 6;
	
	Spaces(11);
	printf(".................\n");
	
	Spaces(11);
	printf(".");
	
	Spaces(15);
	printf(".\n");
	
	for(row = 1; row <= totalRowNum;  row++){
		//print spaces
		for(space = 1; space <= (totalRowNum - row)+13; space++){
			if(space == 12){
				printf(".");
			}
			printf(" ");
		}
		
		//print symbol
		for(symbol = 1; symbol <= ((2*row)-1); symbol++){
			printf("^");
		}
		
		//printf("%d", row);
		
		if(row == 1){
			Spaces(7);
			printf(".");
		}
		else if(row == 2){
			Spaces(6);
			printf(".");
		}
		else if(row == 3){
			Spaces(5);
			printf(".");
		}
		else if(row == 4){
			Spaces(4);
			printf(".");
		}
		else if(row == 5){
			Spaces(3);
			printf(".");
		}
		else if(row == 6){
			Spaces(2);
			printf(".");
		}
		
		
		printf("\n");
	}
	
	Spaces(11);
	printf(".");
	
	Spaces(15);
	printf(".\n");
	
	Spaces(11);
	printf(".................\n");
	
}

void CircledSquare(){
	
	printf("\n");
	printf(" ...........\n");
	
	printf(" .");
	Spaces(9);
	printf(".\n");
	
	
	printf(" . ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	printf(" .");
	
	//circle part
	Spaces(18);
	printf("OO");
	
	printf("\n");	
	
	printf(" . H     H");
	printf(" .");
	Spaces(17);
	printf("O  O");
	printf("\n");
	
	
	printf(" . H     H");
	printf(" .");
	Spaces(16);
	printf("O    O");
	printf("\n");
	
	printf(" . H     H");
	printf(" .");
	Spaces(16);
	printf("O    O");
	printf("\n");
	
	printf(" . H     H");
	printf(" .");
	Spaces(17);
	printf("O  O");
	printf("\n");
	
	printf(" . H     H");
	printf(" .");
	Spaces(18);
	printf("OO");
	printf("\n");
	
	
		
	printf(" . ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	printf(" .");
	
	printf("\n");
	
	printf(" .");
	Spaces(9);
	printf(".\n");
	
	printf(" ...........\n");
	
	
}

void CircledCircle(){
	
	Spaces(25);
	printf("............\n");
	
	Spaces(25);
	printf(".");
	
	Spaces(10);
	printf(".\n");
	
	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	
	//circle part
	Spaces(15);
	printf(".    OO    .");
	
	printf("\n");	
	
	printf("   H     H");
	Spaces(15);
	printf(".   O  O   .");
	printf("\n");
	
	
	printf("   H     H");
	Spaces(15);
	printf(".  O    O  .");
	printf("\n");
	
	printf("   H     H");
	Spaces(15);
	printf(".  O    O  .");
	printf("\n");
	
	printf("   H     H");
	Spaces(15);
	printf(".   O  O   .");
	printf("\n");
	
	printf("   H     H");
	Spaces(15);
	printf(".    OO    .");
	printf("\n");
	
		
	printf("   ");
	for(int i = 0; i < 7; i++){
		printf("H");
	}
	Spaces(15);
	printf(".");
	
	Spaces(10);
	printf(".\n");
	
	Spaces(25);
	printf("............\n");
	
	
	
	
}

void randomGame(int time, int turn, int* num, int* answer){
	
	
	//struct gameResponse gr;
	
	*num = rand() % 4; //generate random number 0-3
		
	//printf("%d", num);
		
		
		if(*num == 0){
			
			answer[time] = 119; //ASCII value of w
			
			//gr[time].correctAnswer = 'w';
			
			//*answer = 'w';
			
			printf("\n");

			
			CircledTriangle();
			//Triangle();
			
			printf("\n\n");
			
			SquarePlusCircle();
			//CircledSquare();
			//CircledCircle();
			
			printf("\n\n");
			
			
			X();
			//CircledX();
			
			
			
		}
		else if(*num == 1){
			
			answer[time] = 100; //ASCII value of d
			
			//gr[time].correctAnswer = 'd';
			
			//*answer = 'd';
			
			printf("\n");

			
			//CircledTriangle();
			Triangle();
			
			printf("\n\n");
			
			//SquarePlusCircle();
			//CircledSquare();
			CircledCircle();
			
			printf("\n\n");
			
			
			X();
			//CircledX();
			
		}
		else if(*num == 2){
			
			answer[time] = 115; //ASCII value of s
			
			//gr[time].correctAnswer = 's';
			
			//*answer = 's';
			
			printf("\n");

			
			//CircledTriangle();
			Triangle();
			
			printf("\n\n");
			
			SquarePlusCircle();
			//CircledSquare();
			//CircledCircle();
			
			printf("\n\n");
			
			
			//X();
			CircledX();
		}
		else if(*num == 3){
			
			answer[time] = 97; //ASCII value of a
			
			//gr[time].correctAnswer = 'a';
			
			//*answer = 'a';
			
			printf("\n");

			
			//CircledTriangle();
			Triangle();
			
			printf("\n\n");
			
			//SquarePlusCircle();
			CircledSquare();
			//CircledCircle();
			
			printf("\n\n");
			
			
			X();
			//CircledX();
		}
	
	
}


void newLine(int numOfLines){
	
	int done = 0;
	
	while(numOfLines - done >= 0){
		printf("\n");
		done += 1;
		
	}
	
	
}

void showHighscores(player p[]){
	
	//player p[SIZE];
	
	printf("Highscore Table: \n");
	
	printf("Rank  Score  Name\n");
	
	FILE *file;
	
	if ((file = fopen(fileName,"r")) == NULL){
		
		for(int i = 0; i < SIZE; ++i){
	   
			p[i].score = 0;
			strcpy(p[i].name, "N/A");
	   
		}
	
	
		
		for(int i = 0, j = 1; i < SIZE; ++i, ++j){
			printf(" %d      %d     %s\n", j, p[i].score, p[i].name);
		}
	
	
       
   }else{
	   
	   for(int i = 0; i < SIZE; ++i){
	   fscanf(file, "%2d %3s-", &p[i].score, &p[i].name);
	   
   }
   
	
	for(int i = 0, j = 1; i < SIZE; ++i, ++j){
		printf(" %d      %d     %s\n", j, p[i].score, p[i].name);
	}
	   
   }
	
}

void writeToFile(player p[], int score){
	
	//int score = 27;
	//int rank = 0;

	//char name[5];
	FILE *file;
	
	file = fopen(fileName, "a+");
	
	if(file == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   int count = 0; //count where the score is higher
	for(int i = 0; i < SIZE; ++i){
		if(score >= p[i].score){
			count++;
		}
		
	}
	
	if(count > 0){
		

		printf("Congratulations, you made it on the highscore table\n");
		printf("Please enter your name (Only 3 captial letters): \n");
		scanf("%s", p[9-count].name);
		p[9-count].score = score;
	}
	else{
		exit(0);
	}
	
		
	FILE *file2;
	
	file2 = fopen(fileName, "w");
	
	if(file2 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   for(int i = 0; i < SIZE; ++i){
	   
	   fprintf(file2, "%d %s-", p[i].score, p[i].name);
	   
   }
	
	fclose(file2);
	
	
	
}

