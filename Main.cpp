#include "PassThePigs.h"
// main function
int main() {
	// assign variables with data types
	int winningScore = 0;
	string Player1Name = "";
	string Player2Name = "";
	string pig1 = "";
	string pig2 = "";
	string rollResult = "";
	int Player1Points = 0;
	int Player2Points = 0;
	int tempPlayer1Points = 0;
	int tempPlayer2Points = 0;
	int turnPoints = 0;
	bool Player1Turn = true;
	bool Player2Turn = false;
	bool playerTurn = false;
	bool gameEnd = false;
	char PlayerChoice;
	char playAgain;
	// seed random roll generator
	srand(time(0));
	// call function
	displayGameRules();
	// get input from players
	cout << "Enter Player1 name: ";
	cin >> Player1Name;
	cout << "Enter Player2 name: ";
	cin >> Player2Name;
	cout << "Enter the total number of points representing a winning score that is an integer greater than 0 and less than or equal to 100: ";
	winningScore = getValidWinningScore();
	// loops for game
	while (Player1Points <= winningScore && Player2Points <= winningScore && gameEnd == false) {
		while (Player1Points <= winningScore && Player2Points <= winningScore && Player1Turn == true) {
			turnPoints = 0;
			if (playerTurn == false) {
				tempPlayer1Points = Player1Points;
				cout << Player1Name << "'s beginning turn points: " << tempPlayer1Points << endl;
				playerTurn = true;
			}
			// pig rolls called function
			pig1 = rollPig();
			pig2 = rollPig();
			// roll result called function
			rollResult = determineRollResult(pig1, pig2);
			// calculate points called function
			turnPoints = calculateTotalRollPoints(pig1, pig2, rollResult);
			// display chatter messages called function
			displayRollResultMessages(rollResult);
			// increment points
			Player1Points += turnPoints;
			// statement for a pig out and player loses points for turn
			if (rollResult == "PIGOUT") {
				Player1Points = tempPlayer1Points;
				cout << Player1Name << " needs to pass the pig!" << endl << endl;
				Player1Turn = false;
				Player2Turn = true;
				break;
			}
			// output the player's points
			cout << Player1Name << " has a total of: " << Player1Points << " points." << endl;
			// display chatter messages called function
			displayPointMessages(Player1Points, Player2Points, Player1Name, Player2Name);
			// game ends when player's score meets winning score
			if (Player1Points >= winningScore) {
				cout << Player1Name << " wins the game!" << endl;
				gameEnd = true;
				break;
			}
			// output player choices
			cout << "Would you like to keep rolling or pass? (r,p): ";
			cin >> PlayerChoice;
			cout << endl;
			// statements for choices
			if (PlayerChoice == 'r') {
				Player1Turn = true;
				Player2Turn = false;
			}
			else {
				Player1Turn = false;
				Player2Turn = true;
			}
			// display chatter messages called function
			displayPlayerChoiceMessages(PlayerChoice);
		}
		playerTurn = false;
		while (Player1Points <= winningScore && Player2Points <= winningScore && Player2Turn == true) {
			turnPoints = 0;
			if (playerTurn == false) {
				tempPlayer2Points = Player2Points;
				cout << Player2Name << "'s beginning turn points: " << tempPlayer2Points << endl;
				playerTurn = true;
			}
			// pig rolls called function
			pig1 = rollPig();
			pig2 = rollPig();
			// roll result called function
			rollResult = determineRollResult(pig1, pig2);
			// calculate points called function
			turnPoints = calculateTotalRollPoints(pig1, pig2, rollResult);
			// display chatter messages called function
			displayRollResultMessages(rollResult);
			// increment points
			Player2Points += turnPoints;
			// statement for a pig out and player loses points for turn
			if (rollResult == "PIGOUT") {
				Player2Points = tempPlayer2Points;
				cout << Player2Name << " needs to pass the pig!" << endl << endl;
				Player2Turn = false;
				Player1Turn = true;
				break;
			}
			// output the player's points
			cout << Player2Name << " has a total of: " << Player2Points << " points." << endl;
			// display chatter messages called function
			displayPointMessages(Player1Points, Player2Points, Player1Name, Player2Name);
			// game ends when player's score meets winning score
			if (Player2Points >= winningScore) {
				cout << Player2Name << " wins the game!" << endl;
				gameEnd = true;
				break;
			}
			// output player choices
			cout << "Would you like to keep rolling or pass? (r,p): ";
			cin >> PlayerChoice;
			cout << endl;
			// statements for choices
			if (PlayerChoice == 'r') {
				Player1Turn = false;
				Player2Turn = true;
			}
			else {
				Player1Turn = true;
				Player2Turn = false;
			}
			// display chatter messages called function
			displayPlayerChoiceMessages(PlayerChoice);
		}
		playerTurn = false;
		// prompt players if they want to play another game
		if (gameEnd == true) {
			cout << "Would you like to play another game? (y,n): ";
			cin >> playAgain;
			if (playAgain == 'y') {
				gameEnd = false;
				Player1Points = 0;
				Player2Points = 0;
				Player1Turn = true;
				Player2Turn = false;
				cout << endl;
				cout << "Enter the total number of points representing a winning score that is an integer greater than 0 and less than or equal to 100: ";
				winningScore = getValidWinningScore();
			}
			else {
				gameEnd = true;
			}
		}
	}
	return 0;
}
