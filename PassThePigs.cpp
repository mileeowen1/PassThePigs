#include "PassThePigs.h"
/*************************************************************
 * Function: displayGameRules()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function displays the rules of the game.
 * Input parameters: None
 * Returns: Nothing
 * Pre: Nothing
 * Post: Cout statement that displays the rules.
 *************************************************************/
void displayGameRules() {
	cout << "The rules of the game are straightforward. A player tosses two toy pigs, each of which has a dot on one side. Each pig can land in one of six positions: \n\t1. On its side \n\t\t1a. Side with dot down \n\t\t1b. Side with dot up \n\t2. Razorback (on its back) \n\t3. Trotter (on all four feet) \n\t4. Snouter (balanced on front two feet and its snout) \n\t5. Leaning jowler (balanced on one foot, snout, and ear) \nAfter the pigs have come to rest, the player gains or loses points based on the way the pigs land: \n\tDouble (both pigs in the same position) \n\t\t1. Sider (either both with the spot facing upward or both with the spot facing downward): 1 point \n\t\t2. Double Razorback: 20 points \n\t\t3. Double Trotter: 20 points \n\t\t4. Double Snouter: 40 points \n\t\t5. Double Leaning Jowler: 60 points \n\t\t6. Pig Out: 0 Points!! If both pigs are lying on their sides, one with the spot facing upwards and one with the spot facing downwards the score for that turn is reset to 0 and the turn changes to the next player \n\tMixed Combo: A combination not mentioned above is the sum of the single pigs' scores. Single pigs' scores: \n\t\t1. The pig is lying on its side: 0 points \n\t\t2. Razorback: 5 points \n\t\t3. Trotter: 5 points \n\t\t4. Snouter: 10 points \n\t\t5. Leaning Jowler: 15 points \nEach player's turn continues until the player decides to stop their turn (accumulating points), or rolls a Pig Out. The player's score is updated and the turn is passed to the next player. The game ends when a player reaches a predetermined number of points (usually 100)." << endl << endl;
}
/*************************************************************
 * Function: isValidWinningScore()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function compares input to a range of
 *				numbers.
 * Input parameters: The winning score as an integer.
 * Returns: A bool of true or false.
 * Pre: The winning score of the game had to have been inputed
 *				by the user.
 * Post: A bool of true or false is returned if the input is
 *				not within range.
 *************************************************************/
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
/*************************************************************
 * Function: getValidWinningScore()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function determines if the winning score 
 *				input is valid or not.
 * Input parameters: None
 * Returns: The winning score as an integer.
 * Pre: Nothing
 * Post: The winning score as an integer is returned.
 *************************************************************/
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
/*************************************************************
 * Function: rollPig()
 * Date Created: 03/20/19
 * Date Last Modified: 03/20/19
 * Description: This function assigns a pig position depending
 *				on the random number generator function.
 * Input parameters: None
 * Returns: The position of the pig as a string.
 * Pre: Nothing
 * Post: The position of the pig as a string is returned.
 *************************************************************/
string rollPig() {
	// assign variables with data types
	int pigRoll = 0;
	string positionPig = "";
	// random roll generator
	pigRoll = rand() % 100 + 1;
	// number categories for position
	if (pigRoll == 1) {
		positionPig = "LEAN";
	}
	else if (pigRoll <= 4) {
		positionPig = "SNOUT";
	}
	else if (pigRoll <= 13) {
		positionPig = "TROT";
	}
	else if (pigRoll <= 35) {
		positionPig = "RZR";
	}
	else if (pigRoll <= 65) {
		positionPig = "SIDE-D";
	}
	else {
		positionPig = "SIDE";
	}
	return positionPig;
}
/*************************************************************
 * Function: determineRollResult()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function assigns a roll result depending
 *				on the position of the pigs.
 * Input parameters: The position of the pigs for both rolls.
 * Returns: The roll result of the pig as a string.
 * Pre: The position of the pigs for both rolls had to have
 *            	been inputed in by the user.
 * Post: The position of the pig as a string is returned.
 *************************************************************/
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
/*************************************************************
 * Function: calculateTotalRollPoints()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function calculates the total points of 
 *				all the pig rolls for a player.
 * Input parameters: The position of the pigs for both rolls
 *				and the roll result.
 * Returns: The total roll points for the pigs as an integer.
 * Pre: The position of the pigs for both rolls and the roll
 *				result had to have been inputed in by the user.
 * Post: The total roll points for the pigs as an integer is
 *				returned.
 *************************************************************/
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
/*************************************************************
 * Function: displayPointMessages()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function displays messages about the
 *				player's points.
 * Input parameters: Each players' points and names.
 * Returns: Nothing
 * Pre: Each players' points and names had to have been inputed in by the        
 *            	user.
 * Post: Cout statement that displays a message.
 *************************************************************/
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
/*************************************************************
 * Function: displayRollResultMessages()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function displays messages about the
 *				roll result.
 * Input parameters: The roll result as a string.
 * Returns: Nothing
 * Pre: The roll result had to have been inputed in by the        
 *            	user.
 * Post: Cout statement that displays a message.
 *************************************************************/
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
/*************************************************************
 * Function: displayPlayerChoiceMessages()
 * Date Created: 03/14/19
 * Date Last Modified: 03/14/19
 * Description: This function displays messages about the
 *				player's choice.
 * Input parameters: The player's choice as yes or no.
 * Returns: Nothing
 * Pre: The player's choice had to have been inputed in by the        
 *            	user.
 * Post: Cout statement that displays a message.
 *************************************************************/
void displayPlayerChoiceMessages(char PlayerChoice) {

	if (PlayerChoice == 'r') {
		cout << "Keep it rollin'." << endl;
	}
	else {
		cout << "You're a pussy cat." << endl;
	}
}
