/*
Name: Milee Owen
Class: CPSC 121, Spring 2019
Date: March 12, 2019
Programming Assignment: PA6
Description: Create a program that plays the game Pass the Pigs. Pass the Pigs is a popular games of chance for two or more players based on a dice game called Pig.
*/
#include <iostream>
#include <ctime>
using namespace std;

void displayGameRules() {
	cout << "The rules of the game are straightforward. A player tosses two toy pigs, each of which has a dot on one side. Each pig can land in one of six positions: \n\t1. On its side \n\t1a. Side with dot down \n\t1b. Side with dot up \n\t2. Razorback (on its back) \n\t3. Trotter (on all four feet) \n\t4. Snouter (balanced on front two feet and its snout) \n\t5. Leaning jowler (balanced on one foot, snout, and ear) \nAfter the pigs have come to rest, the player gains or loses points based on the way the pigs land: \n\tDouble (both pigs in the same position) \n\t\t1. Sider (either both with the spot facing upward or both with the spot facing downward): 1 point \n\t\t2. Double Razorback: 20 points \n\t\t3. Double Trotter: 20 points \n\t\t4. Double Snouter: 40 points \n\t\t5. Double Leaning Jowler: 60 points \n\t\t6. Pig Out: 0 Points!! If both pigs are lying on their sides, one with the spot facing upwards and one with the spot facing downwards the score for that turn is reset to 0 and the turn changes to the next player \n\tMixed Combo: A combination not mentioned above is the sum of the single pigs' scores. Single pigs' scores: \n\t\t1. The pig is lying on its side: 0 points \n\t\t2. Razorback: 5 points \n\t\t3. Trotter: 5 points \n\t\t4. Snouter: 10 points \n\t\t5. Leaning Jowler: 15 points \nEach player's turn continues until the player decides to stop their turn (accumulating points), or rolls a Pig Out. The player's score is updated and the turn is passed to the next player. The game ends when a player reaches a predetermined number of points (usually 100)." << endl << endl;
}

bool isValidWinningScore(int winningScore) {
	
	if (winningScore > 0 && winningScore <= 1000) {
		cout << "Game point is " << winningScore << "." << endl;
		return true;
	}
	else {
		cout << "Invalid number. Please enter another integer: ";
		return false;
	}
}

int getValidWinningScore() {

	int winningScore = 0;
	bool isValid = false;

	cin >> winningScore;
	
	isValid = isValidWinningScore(winningScore);
	
	if (isValid == true) {
		cout << "Let's play a game!" << endl << endl;
		return winningScore;
	}
	else {
		getValidWinningScore();
	}
}

string rollPig() {

	int pigRoll = 0;
	string positionPig = "";
	
	pigRoll = rand() % 100 + 1;
	
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

string determineRollResult(string pig1, string pig2) {
	
	string rollResult = "";
	
	if (pig1 == "SIDE" && pig2 == "SIDE") {
		cout << "You rolled a sider." << endl;
		rollResult = "SIDER";
	}
	else if (pig1 == "SIDE-D" && pig2 == "SIDE-D") {
		cout << "You rolled a sider." << endl;
		rollResult = "SIDER";
	}
	else if (pig1 == "RZR" && pig2 == "RZR") {
		cout << "You rolled a double razorback." << endl;
		rollResult = "DBL-RAZR";
	}
	else if (pig1 == "TROT" && pig2 == "TROT") {
		cout << "You rolled a double trotter." << endl;
		rollResult = "DBL-TROT";
	}
	else if (pig1 == "SNOUT" && pig2 == "SNOUT") {
		cout << "You rolled a double snouter." << endl;
		rollResult = "DBL-SNOUT";
	}
	else if (pig1 == "LEAN" && pig2 == "LEAN") {
	cout << "You rolled a double leaning jowler." << endl;
		rollResult = "DBL-LEAN";
	}
	else if (pig1 == "SIDE" && pig2 == "SIDE-D") {
		cout << "You rolled a pigout." << endl;
		rollResult = "PIGOUT";
	}
	else if (pig1 == "SIDE-D" && pig2 == "SIDE") {
		cout << "You rolled a pigout." << endl;
		rollResult = "PIGOUT";
	}
	else {
		rollResult = "MIXED";
	}
	return rollResult;
}

int calculateTotalRollPoints(string pig1, string pig2, string rollResult) {

	int totalRollPoints = 0;
	
	if (rollResult == "SIDER") {
		totalRollPoints += 1;
	}
	else if (rollResult == "DBL-RAZR") {
		totalRollPoints += 20;
	}
	else if (rollResult == "DBL-TROT") {
		totalRollPoints += 20;
	}
	else if (rollResult == "DBL-SNOUT") {
		totalRollPoints += 40;
	}
	else if (rollResult == "DBL-LEAN") {
		totalRollPoints += 60;
	}
	else if (rollResult == "PIGOUT") {
		totalRollPoints += 0;
	}
	else if (rollResult== "MIXED") {
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
			else if (pig1 == "LEAN") {
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
			else if (pig1 == "LEAN") {
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
			else if (pig1 == "LEAN") {
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
			else if (pig1 == "LEAN") {
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
			else if (pig1 == "LEAN") {
				cout << "You rolled a snouter and a leaning jowler." << endl;
				totalRollPoints += 15;
			}
		}
		else if (pig1 == "LEAN") {
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
			else if (pig2 == "SNOUT") {
				cout << "You rolled a leaning jowler and a snouter." << endl;
				totalRollPoints += 10;
			}
		}
	}
	return totalRollPoints;
}

//string displayChatterMessages() {

	//string chatterMessages = "";
	
	//if ()	
	
//}

int main() {

	int winningScore = 0;
	string Player1Name = "";
	string Player2Name = "";
	string pig1 = "";
	string pig2 = "";
	string rollResult = "";
	int Player1Points = 0;
	int turnPoints = 0;
	int Player2Points = 0;
	bool Player1Turn = true;
	bool Player2Turn = false;
	char PlayerChoice;
	
	srand(time(0));
	
	displayGameRules();
	
	cout << "Enter Player1 name: ";
	cin >> Player1Name;
	cout << "Enter Player2 name: ";
	cin >> Player2Name;
	cout << "Enter the total number of points representing a winning score that is an integer greater than 0 and less than or equal to 100: ";
	winningScore = getValidWinningScore();
	
	while (Player1Points <= winningScore && Player2Points <= winningScore) {
		while (Player1Points <= winningScore && Player2Points <= winningScore && Player1Turn == true) {
			pig1 = rollPig();
			pig2 = rollPig();

			rollResult = determineRollResult(pig1, pig2);
			
			turnPoints += calculateTotalRollPoints(pig1, pig2, rollResult);
			
			Player1Points = turnPoints;
						
			if (rollResult == "PIGOUT" && Player1Turn == true) {
				cout << "You need to pass the pig!" << endl << endl;
				Player1Turn = false;
				Player2Turn = true;
				break;
			}
			
			cout << Player1Name << " has a total of: " << Player1Points << " points." << endl;
		
			if (Player1Points >= winningScore) {
				break;
			}
			
			cout << "Would you like to keep rolling, pass, or quit? (r,p,q): ";
			cin >> PlayerChoice;
			cout << endl;
			
			if (PlayerChoice == 'r') {
				Player1Turn = true;
				Player2Turn = false;
				turnPoints = 0;
				turnPoints += calculateTotalRollPoints(pig1, pig2, rollResult);
				if (rollResult == "PIGOUT" && Player1Turn == true) {
					cout << "You need to pass the pig!" << endl << endl;
					Player1Turn = false;
					Player2Turn = true;
					Player1Points -= turnPoints;
					break;
				}
			}
			else if (PlayerChoice == 'p') {
				Player1Turn = false;
				Player2Turn = true;
			}
			else {
				Player1Turn = false;
				Player2Turn = false;
				cout << Player2Name << " wins by default!" << endl;
			}
		}
		
		while (Player1Points <= winningScore && Player2Points <= winningScore && Player2Turn == true) {
			pig1 = rollPig();
			pig2 = rollPig();

			rollResult = determineRollResult(pig1, pig2);
			
			turnPoints += calculateTotalRollPoints(pig1, pig2, rollResult);
			
			Player2Points = turnPoints;
			
			if (rollResult == "PIGOUT" && Player2Turn == true) {
				cout << "You need to pass the pig!" << endl << endl;
				Player2Turn = false;
				Player1Turn = true;
				break;
			}
			
			cout << Player2Name << " has a total of: " << Player2Points << " points." << endl;
			
			if (Player2Points >= winningScore) {
				break;
			}
			
			cout << "Would you like to keep rolling, pass, or quit? (r,p,q): ";
			cin >> PlayerChoice;
			cout << endl;
			
			if (PlayerChoice == 'r') {
				Player1Turn = false;
				Player2Turn = true;
				turnPoints = 0;
				turnPoints += calculateTotalRollPoints(pig1, pig2, rollResult);
				if (rollResult == "PIGOUT" && Player2Turn == true) {
					cout << "You need to pass the pig!" << endl << endl;
					Player1Turn = true;
					Player2Turn = false;
					Player2Points -= turnPoints;
					break;
				}
			}
			else if (PlayerChoice == 'p') {
				Player1Turn = true;
				Player2Turn = false;
			}
			else {
				Player1Turn = false;
				Player2Turn = false;
				cout << Player1Name << " wins by default!" << endl;
			}
		}
		if (PlayerChoice == 'q') {
			break;
		}
	}
	
	if (Player1Points >= winningScore) {
		cout << Player1Name << " wins the game!" << endl;
	}
	
	if (Player2Points >= winningScore) {
		cout << Player2Name << " wins the game!" << endl;
	}
			
	return 0;
}
