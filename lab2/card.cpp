//
// Created by Jianing Sun 
//
#include "stdafx.h"
#include "card.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

enum returnValue { cannotOpenFile = -1, success = 0, invalidCardContent = 1, missFileName = 2, notEnoughCard = 3, moreThanOneInpput = 4, noCardContent = 5 };

//get rank of single card
int getRank(int a, Card::Rankenum &rank) {
	switch (a)
	{
	case '2':
		rank = Card::Rankenum::two;
		return success;
		break;
	case '3':
		rank = Card::Rankenum::three;
		return success;
		break;
	case '4':
		rank = Card::Rankenum::four;
		return success;
		break;
	case '5':
		rank = Card::Rankenum::five;
		return success;
		break;
	case '6':
		rank = Card::Rankenum::six;
		return success;
		break;
	case '7':
		rank = Card::Rankenum::seven;
		return success;
		break;
	case '8':
		rank = Card::Rankenum::eight;
		return success;
		break;
	case '9':
		rank = Card::Rankenum::nine;
		return success;
		break;
	case '10':
		rank = Card::Rankenum::ten;
		return success;
		break;
	case '11':
		rank = Card::Rankenum::jack;
		return success;
		break;
	case '12':
		rank = Card::Rankenum::queen;
		return success;
		break;
	case '13':
		rank = Card::Rankenum::king;
		return success;
		break;
	case '14':
		rank = Card::Rankenum::ace;
		return success;
		break;
	default:
		break;
		return invalidCardContent;
	}
	return invalidCardContent;
}

//get suit of single card
int getSuit(char a, Card::Suitenum &suit) {
	switch (a)
	{
	case 'c':
	case 'C':
		suit = Card::Suitenum::clubs;
		return success;
		break;
	case 'd':
	case 'D':
		suit = Card::Suitenum::diamonds;
		return success;
		break;
	case 'h':
	case 'H':
		suit = Card::Suitenum::hearts;
		return success;
		break;
	case 's':
	case 'S':
		suit = Card::Suitenum::spades;
		return success;
		break;
	default:
		break;
		return invalidCardContent;
	}
	return invalidCardContent;
}

//parseFile function of lab0
int parseFile(vector<Card> &outputhand, char* filename) {

	ifstream ifs;
	ifs.open(filename);
	string line, t_card;

	if (!ifs.is_open()) {
		cerr << "Cannot open file" << endl;
		return cannotOpenFile;
	}

	else {
		while (getline(ifs, line)) {
			istringstream iss(line);
			char inputsuit = ' ';
			int inputrank = 0;
			vector<Card> hand;
			int rankError, suitError;
			while (iss >> t_card && t_card != "//") {
				if (t_card.size() == 3) {
					if (t_card[0] == '1' && t_card[1] == '0') {
						inputrank = '10';
						inputsuit = t_card[2];
						rankError = 0;
					}
					else rankError = 1;
				}
				else if (t_card.length() == 2) {
					inputrank = t_card[0];
					inputsuit = t_card[1];
					rankError = 0;
				}
				else {
					rankError = 1;
				}

				if (t_card[0] == 'J' || t_card[0] == 'j') {
					inputrank = '11';
				}
				if (t_card[0] == 'Q' || t_card[0] == 'q') {
					inputrank = '12';
				}
				if (t_card[0] == 'K' || t_card[0] == 'k') {
					inputrank = '13';
				}
				if (t_card[0] == 'A' || t_card[0] == 'a') {
					inputrank = '14';
				}

				Card::Rankenum r;
				Card::Suitenum s;
				rankError = getRank(inputrank, r);
				suitError = getSuit(inputsuit, s);

				if (rankError || suitError) {
					cout << "Invalid card content" << endl;
					continue;
				}
				else {
					Card getcard = { r, s };
					hand.push_back(getcard);
				}
			}

			if (hand.size() == 5)
			{
				for (auto i : hand)
				{
					outputhand.push_back(i);
				}
			}
			else if ((hand.size() != 0) && (hand.size() < 5) || hand.size() > 5)
			{
				if (!(rankError || suitError)) {
					cerr << "Invalid card number " << endl;
				}
			}
		}
		ifs.close();
		return success;
	}
}

//print all card
int pirntCard(vector<Card> &input) {
	string rankmap[13] = { "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "jack", "queen", "king", "ace" };
	string suitmap[4] = { "clubs", "diamonds", "hearts", "spades" };

	if (input.size() > 0) {
		for (Card card : input) {
			cout << rankmap[card.rank] << " " << "of" << " " << suitmap[card.suit] << endl;
		}
		return success;
	}
	else {
		cerr << "No card content" << endl;
		return noCardContent;
	}
}

bool operator< (const Card& card1, const Card& card2)
{
	if (card1.rank == card2.rank)
	{
		return (card1.suit < card2.suit);
	}
	return (card1.rank < card2.rank);
}

bool operator==(const Card& card1, const Card& card2){
    if (card1.rank == card2.rank) {
		return (card1.suit == card2.suit);
	}
	return false;
}

//get deck ranking of lab1
int deckRanking(const vector<Card> &inputdeck) {
	string rankmap[13] = { "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "jack", "queen", "king", "ace" };
	string suitmap[4] = { "clubs", "diamonds", "hearts", "spades" };
	string deckrank;
	vector<Card> sortedcard = inputdeck;
	if (sortedcard.size() < 5) {
		cout << "Not enough cards" << endl;
		return notEnoughCard;
	}
	else {
		for (size_t i = 0; i < (sortedcard.size() - 4); i = i + 5)
		{
			std::sort(sortedcard.begin() + i, sortedcard.begin() + i + 5);
			if (sortedcard[i + 1].rank == sortedcard[i].rank + 1 && sortedcard[i + 2].rank == sortedcard[i].rank + 2 && sortedcard[i + 3].rank == sortedcard[i].rank + 3 && sortedcard[i + 4].rank == sortedcard[i].rank + 4)
			{
				if (sortedcard[i].suit == sortedcard[i + 1].suit && sortedcard[i].suit == sortedcard[i + 2].suit && sortedcard[i].suit == sortedcard[i + 3].suit && sortedcard[i].suit == sortedcard[i + 4].suit)
				{
					deckrank = "straight flush";
				}
				else
				{
					deckrank = "straight";
				}
			}
			else
			{
				if (sortedcard[i].suit == sortedcard[i + 1].suit && sortedcard[i].suit == sortedcard[i + 2].suit && sortedcard[i].suit == sortedcard[i + 3].suit && sortedcard[i].suit == sortedcard[i + 4].suit)
				{
					deckrank = "flush";
				}
				else if ((sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i].rank == sortedcard[i + 2].rank && sortedcard[i].rank == sortedcard[i + 3].rank) || (sortedcard[i + 1].rank == sortedcard[i + 2].rank && sortedcard[i + 1].rank == sortedcard[i + 3].rank && sortedcard[i + 1].rank == sortedcard[i + 4].rank))
				{
					deckrank = "four of a kind";
				}
				else if ((sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i].rank == sortedcard[i + 2].rank && sortedcard[i + 3].rank == sortedcard[i + 4].rank) || (sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i + 2].rank == sortedcard[i + 3].rank && sortedcard[i + 3].rank == sortedcard[i + 4].rank))
				{
					deckrank = "full house";
				}
				else if ((sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i].rank == sortedcard[i + 2].rank) || (sortedcard[i + 1].rank == sortedcard[i + 2].rank && sortedcard[i + 1].rank == sortedcard[i + 3].rank) || (sortedcard[i + 2].rank == sortedcard[i + 3].rank && sortedcard[i + 2].rank == sortedcard[i + 4].rank))
				{
					deckrank = "three of a kind";
				}
				else if ((sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i + 2].rank == sortedcard[i + 3].rank) || (sortedcard[i + 1].rank == sortedcard[i + 2].rank && sortedcard[i + 3].rank == sortedcard[i + 4].rank) || (sortedcard[i].rank == sortedcard[i + 1].rank && sortedcard[i + 3].rank == sortedcard[i + 4].rank))
				{
					deckrank = "two pairs";
				}
				else if ((sortedcard[i].rank == sortedcard[i + 1].rank) || (sortedcard[i + 1].rank == sortedcard[i + 2].rank) || (sortedcard[i + 2].rank == sortedcard[i + 3].rank) || (sortedcard[i + 3].rank == sortedcard[i + 4].rank))
				{
					deckrank = "one pair";
				}
				else
				{
					deckrank = "no rank";
				}
			}
			cout << deckrank << endl;

		}
		for (Card card : sortedcard) {
			cout << rankmap[card.rank] << " " << "of" << " " << suitmap[card.suit] << endl;
		}
		return success;
	}
}

