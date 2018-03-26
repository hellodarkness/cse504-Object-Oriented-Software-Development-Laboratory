//
// Created by Jianing Sun on 3/20/18.
//

#include "stdafx.h"
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <algorithm>
#include <time.h>
using namespace std;

enum returnValue { cannotOpenFile = -1, success = 0, invalidCardContent = 1, missFileName = 2, notEnoughCard = 3, moreThanRepquiredInpput = 4, noCardContent = 5 };

Deck::Deck(char* filename) {

	int errorcode =
		load(filename);

	if (errorcode != success) {
		throw runtime_error("Cannot open the file.");
	}

}

//load method that takes a file name, opens up the file, reads in valid card definition strings from the file
int Deck::load(char *filename) {
	const int minStringSize = 2;
	const int maxStringSize = 3;
	int cardsAdded = 0;
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
				if (t_card.size() == maxStringSize) {
					if (t_card[0] == '1' && t_card[1] == '0') {
						inputrank = '10';
						inputsuit = t_card[2];
						rankError = 0;
					}
					else rankError = 1;
				}
				else if (t_card.length() == minStringSize) {
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
					cards.push_back(getcard);
					cardsAdded++;
				}
			}

		}
		ifs.close();
		return success;
	}
}

void Deck::shuffle() {
	int seed = (int)time(0);
	std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

int Deck::size() const
{
	return cards.size();
}

ostream& operator<<(ostream& out, const Deck& deck) {
	string rankmap[13] = { "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "jack", "queen", "king", "ace" };
	string suitmap[4] = { "clubs", "diamonds", "hearts", "spades" };

	for (auto i = deck.cards.cbegin(); i != deck.cards.cend(); i++) {
		out << rankmap[i->rank] << suitmap[i->suit] << endl;
	}
	return out;
}

