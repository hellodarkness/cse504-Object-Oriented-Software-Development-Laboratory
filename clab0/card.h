#pragma once
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//define card struct to  represent a "playing card"

struct Card
{
	enum Suitenum { clubs, diamonds, hearts, spades };
	enum Rankenum {
		two, three, four, five, six, seven, eight, 
		nine, ten, jack, queen, king, ace
	};

	Suitenum suit;
	Rankenum rank;

	Card(Rankenum cardrank, Suitenum cardsuit) {
		rank = cardrank;
		suit = cardsuit;
	}

};

Card::Rankenum getRank(int a);
Card::Suitenum getSuit(char a);
int parseFile(vector<Card> &outputcard, char* filename);

