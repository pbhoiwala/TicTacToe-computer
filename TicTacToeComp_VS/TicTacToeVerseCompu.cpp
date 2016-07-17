/*
* File:   main.cpp
* Author: PARTH BHOIWALA
*
* Created on April 2, 2015, 7:27 PM
*/

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;




void displayBoard(char Numbers[], string player1, char choice1, char choice2);
//har computersTurn(char Numbers[]);
bool checkForWinner1(char Numbers[], char choice1);
bool checkForWinner2(char Numbers[], char choice2);
bool checkIfGameOver(char Numbers[]);

int main(int argc, char** argv) {


	cout << endl << " WELCOME TO TIC-TAC-TOE " << endl;
	string player1;
	char choice1, choice2;
	bool invalidEntry = true;
	
	cout << endl << " Enter Player's Name:  ";
	cin >> player1;
	cout << endl;
	
	while (invalidEntry)
	{
		cout << " " << player1 << ", which one do you want to pick 'X' or 'O' ?  ";
		cin >> choice1;
		if (choice1 != 'O' && choice1 != 'o' && choice1 != 'X' && choice1 != 'x')
		{
			cout << " Invalid Entry! Try Again!" << endl;
			invalidEntry = true;
		}
		else { invalidEntry = false; }

	}
	if (choice1 == 'O' || choice1 == 'o')
	{
		choice2 = 'X';
		cout << " Okay! So the Computer is " << choice2 << endl;
	}
	else
	{
		choice2 = 'O';
		cout << " Okay! So the Computer is " << choice2 << endl;
	}

	char goFirst;
	invalidEntry = true;
	while (invalidEntry)
	{
		cout << " Do you want to go first? (Y/N):  ";
		cin >> goFirst;
		if (goFirst != 'Y' && goFirst != 'y' && goFirst != 'N' && goFirst != 'n')
		{
			cout << " Invalid Entry! Try Again!" << endl;
			invalidEntry = true;
		}
		else { invalidEntry = false; }
	}
	
	//cout << " Player 1 is 'O' and Computer is 'X' " << endl;
	//cout << " Enter the Location Number where you would " << endl;
	//cout << " Like to place your 'O' or 'X' " << endl;


	char Layout[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	displayBoard(Layout, player1, choice1, choice2);

	char Numbers[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


	int i;
	if (goFirst == 'Y' || goFirst == 'y')
	{
		i = 0;
	}
	else { i = 1; }
	int choice;
	while (true)
	{

		if (i % 2 == 0)  // if 'i' is even - PLAYER 1
		{
			cout << endl << endl;
			cout << " " << player1 << " :  ";
			cin >> choice;
			// make sure user enters only 1-9
			if (choice > 9 || Numbers[choice - 1] == 'X' || Numbers[choice - 1] == 'O') { cout << " Invalid Entry! Try Again " << endl; }
			else{
				Numbers[choice - 1] = choice1;
				displayBoard(Numbers, player1, choice1, choice2);
				i++;
			}
			bool checkWin = checkForWinner1(Numbers, choice1);
			if (checkWin == true)
			{
				cout << " YAY! " << player1 << " WINS " << endl;
				break;
			}

		}
		else /*if (i % 2 != 0)*/ // if 'i' is odd - PLAYER 2
		{
			/*char comp;
			comp = computersTurn(Numbers);
			displayBoard(Numbers);*/
			// check to win first
			cout << " Computer is thinking..." << endl;
			if (Numbers[0] == choice2 && Numbers[1] == choice2 && Numbers[2] == ' ')        { Numbers[2] = choice2; }
			else if (Numbers[3] == choice2 && Numbers[4] == choice2 && Numbers[5] == ' ')	{ Numbers[5] = choice2; }
			else if (Numbers[6] == choice2 && Numbers[7] == choice2 && Numbers[8] == ' ')	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice2 && Numbers[2] == choice2 && Numbers[1] == ' ')	{ Numbers[1] = choice2; }
			else if (Numbers[3] == choice2 && Numbers[5] == choice2 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[6] == choice2 && Numbers[8] == choice2 && Numbers[7] == ' ') 	{ Numbers[7] = choice2; }
			else if (Numbers[1] == choice2 && Numbers[2] == choice2 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice2 && Numbers[5] == choice2 && Numbers[3] == ' ') 	{ Numbers[3] = choice2; }
			else if (Numbers[7] == choice2 && Numbers[8] == choice2 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[0] == choice2 && Numbers[3] == choice2 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[1] == choice2 && Numbers[4] == choice2 && Numbers[7] == ' ') 	{ Numbers[7] = choice2; }
			else if (Numbers[2] == choice2 && Numbers[5] == choice2 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice2 && Numbers[6] == choice2 && Numbers[3] == ' ') 	{ Numbers[3] = choice2; }
			else if (Numbers[1] == choice2 && Numbers[7] == choice2 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[2] == choice2 && Numbers[8] == choice2 && Numbers[5] == ' ') 	{ Numbers[5] = choice2; }
			else if (Numbers[3] == choice2 && Numbers[6] == choice2 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice2 && Numbers[7] == choice2 && Numbers[1] == ' ') 	{ Numbers[1] = choice2; }
			else if (Numbers[2] == choice2 && Numbers[5] == choice2 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice2 && Numbers[4] == choice2 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice2 && Numbers[8] == choice2 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[4] == choice2 && Numbers[8] == choice2 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice2 && Numbers[2] == choice2 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[4] == choice2 && Numbers[6] == choice2 && Numbers[2] == ' ') 	{ Numbers[2] = choice2; }
			else if (Numbers[2] == choice2 && Numbers[6] == choice2 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }

			// check if opponent is winning					 						    
			else if (Numbers[0] == choice1 && Numbers[1] == choice1 && Numbers[2] == ' ') 	{ Numbers[2] = choice2; }
			else if (Numbers[3] == choice1 && Numbers[4] == choice1 && Numbers[5] == ' ')	{ Numbers[5] = choice2; }
			else if (Numbers[6] == choice1 && Numbers[7] == choice1 && Numbers[8] == ' ')	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice1 && Numbers[2] == choice1 && Numbers[1] == ' ')	{ Numbers[1] = choice2; }
			else if (Numbers[3] == choice1 && Numbers[5] == choice1 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[6] == choice1 && Numbers[8] == choice1 && Numbers[7] == ' ') 	{ Numbers[7] = choice2; }
			else if (Numbers[1] == choice1 && Numbers[2] == choice1 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice1 && Numbers[5] == choice1 && Numbers[3] == ' ') 	{ Numbers[3] = choice2; }
			else if (Numbers[7] == choice1 && Numbers[8] == choice1 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[0] == choice1 && Numbers[3] == choice1 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[1] == choice1 && Numbers[4] == choice1 && Numbers[7] == ' ') 	{ Numbers[7] = choice2; }
			else if (Numbers[2] == choice1 && Numbers[5] == choice1 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice1 && Numbers[6] == choice1 && Numbers[3] == ' ') 	{ Numbers[3] = choice2; }
			else if (Numbers[1] == choice1 && Numbers[7] == choice1 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[2] == choice1 && Numbers[8] == choice1 && Numbers[5] == ' ') 	{ Numbers[5] = choice2; }
			else if (Numbers[3] == choice1 && Numbers[6] == choice1 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice1 && Numbers[7] == choice1 && Numbers[1] == ' ') 	{ Numbers[1] = choice2; }
			else if (Numbers[2] == choice1 && Numbers[5] == choice1 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice1 && Numbers[4] == choice1 && Numbers[8] == ' ') 	{ Numbers[8] = choice2; }
			else if (Numbers[0] == choice1 && Numbers[8] == choice1 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }
			else if (Numbers[4] == choice1 && Numbers[8] == choice1 && Numbers[0] == ' ') 	{ Numbers[0] = choice2; }
			else if (Numbers[4] == choice1 && Numbers[2] == choice1 && Numbers[6] == ' ') 	{ Numbers[6] = choice2; }
			else if (Numbers[4] == choice1 && Numbers[6] == choice1 && Numbers[2] == ' ') 	{ Numbers[2] = choice2; }
			else if (Numbers[2] == choice1 && Numbers[6] == choice1 && Numbers[4] == ' ') 	{ Numbers[4] = choice2; }

			// if not then generate a random number and put it
			else
			{		
				srand(time(NULL));
				int randomNum;
				while (true)
				{
					cout << " Generating random num " << endl;
					randomNum = rand() % 9;
					if (Numbers[randomNum] == ' ')
					{
						cout << "Empty spot found! Place: " << randomNum << endl;
						Numbers[randomNum] = choice2;
						break;
					}
				}
				 //Numbers[randomNum] = 'X';				
			}

			displayBoard(Numbers, player1, choice1, choice2);

			// check for win
			bool checkWin = checkForWinner2(Numbers, choice2);
			if (checkWin == true)
			{
				cout << " SORRY! YOUR LOSE -- COMPUTER WINS " << endl;
				break;
			}



			
			i++;
		}

		bool checkGameOver = checkIfGameOver(Numbers);
		if (checkGameOver == true)
		{
			cout << " GAME OVER! NOBODY WON " << endl;
			break;
		}



	}








	system("pause");

	return 0;
}

void displayBoard(char Numbers[], string player1, char choice1, char choice2)
{
	system("cls");

	cout << endl;
	cout << " ===================================" << endl;
	cout << "         TIC - TAC - TOE " << endl;
	cout << " ===================================" << endl;
	cout << "   " << player1 << " is " << choice1 << " and Computer is " << choice2 << endl;
	//clrscr();

	// level 1
	cout << setw(5) << endl << endl << endl;
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[0] << " |" << "  " << Numbers[1] << " |" << "  " << Numbers[2] << " " << endl;
	cout << setw(8) << "   ____|____|____" << endl;
	// level 2
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[3] << " |" << "  " << Numbers[4] << " |" << "  " << Numbers[5] << " " << endl;
	// cout << setw(8)  << "   |" << "    |" << "    " << endl;
	cout << setw(5) << "   ____|____|____" << endl;
	// level 3
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[6] << " |" << "  " << Numbers[7] << " |" << "  " << Numbers[8] << " " << endl;
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	//  cout << setw(5)  << "   ____|____|____" << endl;
	// level 4


}




bool checkForWinner1(char Numbers[], char choice1)
{
	if ((Numbers[0] == choice1 && Numbers[1] == choice1 && Numbers[2] == choice1) ||
		(Numbers[3] == choice1 && Numbers[4] == choice1 && Numbers[5] == choice1) ||
		(Numbers[6] == choice1 && Numbers[7] == choice1 && Numbers[8] == choice1) ||
		(Numbers[0] == choice1 && Numbers[3] == choice1 && Numbers[6] == choice1) ||
		(Numbers[1] == choice1 && Numbers[4] == choice1 && Numbers[7] == choice1) ||
		(Numbers[2] == choice1 && Numbers[5] == choice1 && Numbers[8] == choice1) ||
		(Numbers[0] == choice1 && Numbers[4] == choice1 && Numbers[8] == choice1) ||
		(Numbers[2] == choice1 && Numbers[4] == choice1 && Numbers[6] == choice1))
	{ // being long if

		return true;
	} // exit long if

	else
		return false;

}



bool checkForWinner2(char Numbers[], char choice2)
{
	if ((Numbers[0] == choice2 && Numbers[1] == choice2 && Numbers[2] == choice2) ||
		(Numbers[3] == choice2 && Numbers[4] == choice2 && Numbers[5] == choice2) ||
		(Numbers[6] == choice2 && Numbers[7] == choice2 && Numbers[8] == choice2) ||
		(Numbers[0] == choice2 && Numbers[3] == choice2 && Numbers[6] == choice2) ||
		(Numbers[1] == choice2 && Numbers[4] == choice2 && Numbers[7] == choice2) ||
		(Numbers[2] == choice2 && Numbers[5] == choice2 && Numbers[8] == choice2) ||
		(Numbers[0] == choice2 && Numbers[4] == choice2 && Numbers[8] == choice2) ||
		(Numbers[2] == choice2 && Numbers[4] == choice2 && Numbers[6] == choice2))
	{ // being long if

		return true;
	} // exit long if

	else
		return false;

}


bool checkIfGameOver(char Numbers[])
{
	if ((Numbers[0] != ' ') &&
		(Numbers[1] != ' ') &&
		(Numbers[2] != ' ') &&
		(Numbers[3] != ' ') &&
		(Numbers[4] != ' ') &&
		(Numbers[5] != ' ') &&
		(Numbers[6] != ' ') &&
		(Numbers[7] != ' ') &&
		(Numbers[8] != ' '))
	{
		return true;
	}
	else
	{
		return false;
	}



}

/*char computersTurn(char Numbers[])
{
	// check to win first
	if		(Numbers[0] == 'X' && Numbers[1] == 'X') { return  Numbers[2] = 'X'; }
	else if (Numbers[3] == 'X' && Numbers[4] == 'X') { return Numbers[5] = 'X'; }
	else if (Numbers[6] == 'X' && Numbers[7] == 'X') { return Numbers[8] = 'X'; }
	else if (Numbers[0] == 'X' && Numbers[2] == 'X') { return Numbers[1] = 'X'; }
	else if (Numbers[3] == 'X' && Numbers[5] == 'X') { return Numbers[4] = 'X'; }
	else if (Numbers[6] == 'X' && Numbers[8] == 'X') { return Numbers[7] = 'X'; }
	else if (Numbers[1] == 'X' && Numbers[2] == 'X') { return Numbers[0] = 'X'; }
	else if (Numbers[4] == 'X' && Numbers[5] == 'X') { return Numbers[3] = 'X'; }
	else if (Numbers[7] == 'X' && Numbers[8] == 'X') { return Numbers[6] = 'X'; }
	else if (Numbers[0] == 'X' && Numbers[3] == 'X') { return Numbers[6] = 'X'; }
	else if (Numbers[1] == 'X' && Numbers[4] == 'X') { return Numbers[7] = 'X'; }
	else if (Numbers[2] == 'X' && Numbers[5] == 'X') { return Numbers[8] = 'X'; }
	else if (Numbers[0] == 'X' && Numbers[6] == 'X') { return Numbers[3] = 'X'; }
	else if (Numbers[1] == 'X' && Numbers[7] == 'X') { return Numbers[4] = 'X'; }
	else if (Numbers[2] == 'X' && Numbers[8] == 'X') { return Numbers[5] = 'X'; }
	else if (Numbers[3] == 'X' && Numbers[6] == 'X') { return Numbers[0] = 'X'; }
	else if (Numbers[4] == 'X' && Numbers[7] == 'X') { return Numbers[1] = 'X'; }
	else if (Numbers[2] == 'X' && Numbers[5] == 'X') { return Numbers[8] = 'X'; }
	else if (Numbers[0] == 'X' && Numbers[4] == 'X') { return Numbers[8] = 'X'; }
	else if (Numbers[0] == 'X' && Numbers[8] == 'X') { return Numbers[4] = 'X'; }
	else if (Numbers[4] == 'X' && Numbers[8] == 'X') { return Numbers[0] = 'X'; }
	else if (Numbers[4] == 'X' && Numbers[2] == 'X') { return Numbers[6] = 'X'; }
	else if (Numbers[4] == 'X' && Numbers[6] == 'X') { return Numbers[2] = 'X'; }
	else if (Numbers[2] == 'X' && Numbers[6] == 'X') { return Numbers[4] = 'X'; }
													     
	// check if opponent is winning					     
	else if (Numbers[0] == 'O' && Numbers[1] == 'O') { return  Numbers[2] = 'X'; }
	else if (Numbers[3] == 'O' && Numbers[4] == 'O') { return  Numbers[5] = 'X'; }
	else if (Numbers[6] == 'O' && Numbers[7] == 'O') { return  Numbers[8] = 'X'; }
	else if (Numbers[0] == 'O' && Numbers[2] == 'O') { return  Numbers[1] = 'X'; }
	else if (Numbers[3] == 'O' && Numbers[5] == 'O') { return  Numbers[4] = 'X'; }
	else if (Numbers[6] == 'O' && Numbers[8] == 'O') { return  Numbers[7] = 'X'; }
	else if (Numbers[1] == 'O' && Numbers[2] == 'O') { return  Numbers[0] = 'X'; }
	else if (Numbers[4] == 'O' && Numbers[5] == 'O') { return  Numbers[3] = 'X'; }
	else if (Numbers[7] == 'O' && Numbers[8] == 'O') { return  Numbers[6] = 'X'; }
	else if (Numbers[0] == 'O' && Numbers[3] == 'O') { return  Numbers[6] = 'X'; }
	else if (Numbers[1] == 'O' && Numbers[4] == 'O') { return  Numbers[7] = 'X'; }
	else if (Numbers[2] == 'O' && Numbers[5] == 'O') { return  Numbers[8] = 'X'; }
	else if (Numbers[0] == 'O' && Numbers[6] == 'O') { return  Numbers[3] = 'X'; }
	else if (Numbers[1] == 'O' && Numbers[7] == 'O') { return  Numbers[4] = 'X'; }
	else if (Numbers[2] == 'O' && Numbers[8] == 'O') { return  Numbers[5] = 'X'; }
	else if (Numbers[3] == 'O' && Numbers[6] == 'O') { return  Numbers[0] = 'X'; }
	else if (Numbers[4] == 'O' && Numbers[7] == 'O') { return  Numbers[1] = 'X'; }
	else if (Numbers[2] == 'O' && Numbers[5] == 'O') { return  Numbers[8] = 'X'; }
	else if (Numbers[0] == 'O' && Numbers[4] == 'O') { return  Numbers[8] = 'X'; }
	else if (Numbers[0] == 'O' && Numbers[8] == 'O') { return  Numbers[4] = 'X'; }
	else if (Numbers[4] == 'O' && Numbers[8] == 'O') { return  Numbers[0] = 'X'; }
	else if (Numbers[4] == 'O' && Numbers[2] == 'O') { return  Numbers[6] = 'X'; }
	else if (Numbers[4] == 'O' && Numbers[6] == 'O') { return  Numbers[2] = 'X'; }
	else if (Numbers[2] == 'O' && Numbers[6] == 'O') { return  Numbers[4] = 'X'; }

	// if not then generate a random number and put it
	else
	{
		srand(time(NULL));
		int randomNum = rand() % 9;
		while (Numbers[randomNum] == 'X' || Numbers[randomNum] == 'O')
		{			
			int randomNum = rand() % 9;
		}
		return Numbers[randomNum] = 'X';
		//displayBoard(Numbers);
	}




}*/






















/*
cout << endl << endl;
cout << " COMPUTER:  ";
cin >> choice;
// make sure user enters only 1-9
if (choice > 9 || Numbers[choice - 1] == 'X' || Numbers[choice - 1] == 'O') { cout << " Invalid Entry! Try Again " << endl; }
else {
Numbers[choice - 1] = 'X';
displayBoard(Numbers);
i++;
}
bool checkWin = checkForWinner2(Numbers);
if (checkWin == true)
{
cout << " YAY! PLAYER 2 WINS " << endl;
break;
}

*/