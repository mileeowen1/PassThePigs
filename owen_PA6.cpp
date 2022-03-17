/*
Name: Milee Owen
Class: CPSC 121, Spring 2019
Date: March 12, 2019
Programming Assignment: PA6
Description: Create a program that plays the game Pass the Pigs. Pass the Pigs is a popular games of chance for two or more players based on a dice game called Pig.
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
// function to display the rules of the game
void displayGameRules() {
	cout << "The rules of the game are straightforward. A player tosses two toy pigs, each of which has a dot on one side. Each pig can land in one of six positions: \n\t1. On its side \n\t1a. Side with dot down \n\t1b. Side with dot up \n\t2. Razorback (on its back) \n\t3. Trotter (on all four feet) \n\t4. Snouter (balanced on front two feet and its snout) \n\t5. Leaning jowler (balanced on one foot, snout, and ear) \nAfter the pigs have come to rest, the player gains or loses points based on the way the pigs land: \n\tDouble (both pigs in the same position) \n\t\t1. Sider (either both with the spot facing upward or both with the spot facing downward): 1 point \n\t\t2. Double Razorback: 20 points \n\t\t3. Double Trotter: 20 points \n\t\t4. Double Snouter: 40 points \n\t\t5. Double Leaning Jowler: 60 points \n\t\t6. Pig Out: 0 Points!! If both pigs are lying on their sides, one with the spot facing upwards and one with the spot facing downwards the score for that turn is reset to 0 and the turn changes to the next player \n\tMixed Combo: A combination not mentioned above is the sum of the single pigs' scores. Single pigs' scores: \n\t\t1. The pig is lying on its side: 0 points \n\t\t2. Razorback: 5 points \n\t\t3. Trotter: 5 points \n\t\t4. Snouter: 10 points \n\t\t5. Leaning Jowler: 15 points \nEach player's turn continues until the player decides to stop their turn (accumulating points), or rolls a Pig Out. The player's score is updated and the turn is passed to the next player. The game ends when a player reaches a predetermined number of points (usually 100)." << endl << endl;
}
// function to determine if winning score input is valid
bool isValidWinningScore(int winningScore) {
	// statement to make sure input is within range
	if (winningScore > 0 && winningScore <= 100) {
		cout << "Game point is " << winningScore << "." << endl;
		return true;
	}
	else {
		cout << "Invalid number. Please enter another integer: ";
		return false;
	}
}
// function to get the winning score input
int getValidWinningScore() {
	// assign variables with data types
	int winningScore = 0;
	bool isValid = false;
	// get user input
	cin >> winningScore;
	// call function
	isValid = isValidWinningScore(winningScore);
	// statement to test called function
	if (isValid == true) {
		cout << "Let the game begin!" << endl << endl;
		return winningScore;
	}
	else {
		getValidWinningScore();
	}
}
// function to determine pig position
string rollPig() {
	// assign variables with data types
	int pigRoll = 0;
	string positionPig = "";
	// random roll generator
	pigRoll = rand() % 100 + 1;
	// number categories for position
	if (pigRoll >= 35 && pigRoll <= 100) {
		positionPig = "SIDE";
	}
	else if (pigRoll >= 30) {
		positionPig = "SIDE-D";
	}
	else if (pigRoll >= 22) {
		positionPig = "RZR";
	}
	else if (pigRoll >= 9) {
		positionPig = "TROT";
	}
	else if (pigRoll >= 3) {
		positionPig = "SNOUT";
	}
	else {
		positionPig = "LEAN";
	}
	return positionPig;
}
// function to determine the roll result
string determineRollResult(string pig1, string pig2) {
	// assign variables with data types
	string rollResult = "";
	// statements to place rolls with positions
	if (pig1 == "SIDE" && pig2 == "SIDE") {
		rollResult = "SIDER";
	}
	else if (pig1 == "SIDE-D" && pig2 == "SIDE-D") {
		rollResult = "SIDER";
	}
	else if (pig1 == "RZR" && pig2 == "RZR") {
		rollResult = "DBL-RAZR";
	}
	else if (pig1 == "TROT" && pig2 == "TROT") {
		rollResult = "DBL-TROT";
	}
	else if (pig1 == "SNOUT" && pig2 == "SNOUT") {
		rollResult = "DBL-SNOUT";
	}
	else if (pig1 == "LEAN" && pig2 == "LEAN") {
		rollResult = "DBL-LEAN";
	}
	else if (pig1 == "SIDE" && pig2 == "SIDE-D") {
		rollResult = "PIGOUT";
	}
	else if (pig1 == "SIDE-D" && pig2 == "SIDE") {
		rollResult = "PIGOUT";
	}
	else {
		rollResult = "MIXED";
	}
	return rollResult;
}
// function to calculate the points for positions
int calculateTotalRollPoints(string pig1, string pig2, string rollResult) {
	// assign variables with data types
	int totalRollPoints = 0;
	// statements for points to be assigned to positions
	if (rollResult == "SIDER") {
		cout << "You rolled a sider." << endl;
		totalRollPoints += 1;
	}
	else if (rollResult == "DBL-RAZR") {
		cout << "You rolled a double razorback." << endl;
		totalRollPoints += 20;
	}
	else if (rollResult == "DBL-TROT") {
		cout << "You rolled a double trotter." << endl;
		totalRollPoints += 20;
	}
	else if (rollResult == "DBL-SNOUT") {
		cout << "You rolled a double snouter." << endl;
		totalRollPoints += 40;
	}
	else if (rollResult == "DBL-LEAN") {
		cout << "You rolled a double leaning jowler." << endl;
		totalRollPoints += 60;
	}
	else if (rollResult == "PIGOUT") {
		cout << "You rolled a pigout." << endl;
		totalRollPoints += 0;
	}
	else {
		if (pig1 == "SIDE") {
			totalRollPoints += 0;
			
			if (pig2 == "SIDE-D") {
				cout << "You rolled a side and a side-d." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "RZR") {
				cout << "You rolled a side and a razorback." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "TROT") {
				cout << "You rolled a side and a trotter." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "SNOUT") {
				cout << "You rolled a side and a snouter." << endl;
				totalRollPoints += 10;
			}
			else {
				cout << "You rolled a side and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else if (pig1 == "SIDE-D") {
			totalRollPoints += 0;
			
			if (pig2 == "SIDE") {
				cout << "You rolled a side-d and a side." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "RZR") {
				cout << "You rolled a side-d and a razorback." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "TROT") {
				cout << "You rolled a side-d and a trotter." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "SNOUT") {
				cout << "You rolled a side-d and a snouter." << endl;
				totalRollPoints += 10;
			}
			else {
				cout << "You rolled a side-d and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else if (pig1 == "RZR") {
			totalRollPoints += 5;
			
			if (pig2 == "SIDE") {
				cout << "You rolled a razorback and a side." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "SIDE-D") {
				cout << "You rolled a razorback and a side-d." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "TROT") {
				cout << "You rolled a razorback and a trotter." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "SNOUT") {
				cout << "You rolled a razorback and a snouter." << endl;
				totalRollPoints += 10;
			}
			else {
				cout << "You rolled a razorback and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else if (pig1 == "TROT") {
			totalRollPoints += 5;
			
			if (pig2 == "SIDE") {
				cout << "You rolled a trotter and a side." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "SIDE-D") {
				cout << "You rolled a trotter and a side-d." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "RZR") {
				cout << "You rolled a trotter and a razorback." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "SNOUT") {
				cout << "You rolled a trotter and a snouter." << endl;
				totalRollPoints += 10;
			}
			else {
				cout << "You rolled a trotter and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else if (pig1 == "SNOUT") {
			totalRollPoints += 10;
			
			if (pig2 == "SIDE") {
				cout << "You rolled a snouter and a side." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "SIDE-D") {
				cout << "You rolled a snouter and a side-d." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "RZR") {
				cout << "You rolled a snouter and a razorback." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "TROT") {
				cout << "You rolled a snouter and a trotter." << endl;
				totalRollPoints += 5;
			}
			else {
				cout << "You rolled a snouter and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else {
			totalRollPoints += 15;
			
			if (pig2 == "SIDE") {
				cout << "You rolled a leaning jowler and a side." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "SIDE-D") {
				cout << "You rolled a leaning jowler and a side-d." << endl;
				totalRollPoints += 0;
			}
			else if (pig2 == "RZR") {
				cout << "You rolled a leaning jowler and a razorback." << endl;
				totalRollPoints += 5;
			}
			else if (pig2 == "TROT") {
				cout << "You rolled a leaning jowler and a trotter." << endl;
				totalRollPoints += 5;
			}
			else {
				cout << "You rolled a leaning jowler and a snouter." << endl;
				totalRollPoints += 10;
			}
		}
	}
	return totalRollPoints;
}
// function to display fun chatter messages
void displayPointMessages(int Player1Points, int Player2Points, string Player1Name, string Player2Name) {
	
	if (Player1Points > Player2Points) {
		cout << Player1Name << " is beating you " << Player2Name << "!" << endl;
	}
	else if (Player1Points == Player2Points) {
		cout << "You guys are tied!" << endl;
	}
	else {
		cout << Player2Name << " is beating you " << Player1Name << "!" << endl;
	}
}
// function to display fun chatter messages
void displayRollResultMessages(string rollResult) {

	if (rollResult == "PIGOUT") {
		cout << "Oooofffff. Bad luck." << endl;
	}
	else if (rollResult == "DBL-RAZR") {
		cout << "Yessuh! Blessuh!" << endl;
	}
	else if (rollResult == "DBL-TROT") {
		cout << "BAM WHAT!" << endl;
	}
	else if (rollResult == "DBL-SNOUT") {
		cout << "AUHMAAAZIIINNNG!" << endl;
	}
	else if (rollResult == "DBL-LEAN") {
		cout << "WOW. A one in a million chance!" << endl;
	}
	else {
		cout << "Nice roll." << endl;
	}
}
// function to display fun chatter messages
void displayPlayerChoiceMessages(char PlayerChoice) {

	if (PlayerChoice == 'r') {
		cout << "Keep it rollin'." << endl;
	}
	else {
		cout << "You're a pussy cat." << endl;
	}
}
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
