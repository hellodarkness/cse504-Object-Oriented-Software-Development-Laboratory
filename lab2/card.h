//
// Jianing Sun 
//

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

// less than operator which determine the card order
bool operator< (const Card& card1, const Card& card2);

// determine if the cards are same
bool operator==(const Card& card1, const Card& card2);

//function decleration
int getRank(int a, Card::Rankenum &rank);
int getSuit(char a, Card::Suitenum &suit);
int parseFile(vector<Card> &outputcard, char* filename);
int deckRanking(const vector<Card> &inputdeck);
