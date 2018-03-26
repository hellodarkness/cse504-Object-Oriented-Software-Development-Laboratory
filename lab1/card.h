//
// Jianing Sun lab1
//

#ifndef LAB1_CARD_H
#define LAB1_CARD_H

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

	bool operator< (const Card & secondcard)
	{
		if (rank == secondcard.rank)
		{
			return (suit < secondcard.suit);
		}
		return (rank < secondcard.rank);
	}

	Card(Rankenum cardrank, Suitenum cardsuit) {
		rank = cardrank;
		suit = cardsuit;
	}
};

int getRank(int a, Card::Rankenum &rank);
int getSuit(char a, Card::Suitenum &suit);
int parseFile(vector<Card> &outputcard, char* filename);
int deckRanking(const vector<Card> &inputdeck);

#endif //LAB1_CARD_H
