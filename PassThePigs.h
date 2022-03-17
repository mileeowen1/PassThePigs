#ifndef PASS_THE_PIGS_H
#define PASS_THE_PIGS_H
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
// function prototypes
void displayGameRules();
bool isValidWinningScore(int winningScore);
int getValidWinningScore();
string rollPig();
string determineRollResult(string pig1, string pig2);
int calculateTotalRollPoints(string pig1, string pig2, string rollResult);
void displayPointMessages(int Player1Points, int Player2Points, string Player1Name, string Player2Name);
void displayRollResultMessages(string rollResult);
void displayPlayerChoiceMessages(char PlayerChoice);
#endif
