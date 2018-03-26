//
// Created by Jianing Sun on 3/12/18.
//
#pragma once
#include "card.h"
#include "hand.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Hand;
class Deck {

	friend void operator<< (Hand& hand, Deck& deck);
	friend ostream & operator<<(ostream& out, const Deck& deck);

public:

	//constructor
	Deck() = default;
	Deck(char* filename);

	//using vector dont need a deconstructor 
	//system handle that memory

	// reads in valid card definition strings from the file
	int load(char *filename);

	//randomizes the order of all the cards in the container member variable
	void shuffle();

	//const "size" method that returns the number of elements in the container member variable.
	int size() const;

private:
	vector<Card> cards;

};

//insertion operator decleration
ostream& operator<<(ostream& out, const Deck& deck);

