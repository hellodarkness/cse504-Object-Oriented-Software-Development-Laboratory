//
// Created by Jianing Sum on 3/23/18.
//

#pragma once
#include <iostream>
#include "card.h"
#include "deck.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Deck;
class Hand {
	friend ostream &operator<<(ostream &out, const Hand &hand);
	friend void operator<<(Hand &hand, Deck &deck);
	friend int ranking(const Hand & hand);
	friend bool pokerRank(const Hand & hand1, const Hand & hand2);

public:
	//constructor
	Hand();

	//copy constructor
	Hand(const Hand &);

	//using vector dont need a deconstructor 
	//system handle that memory

	// assignment operator
	Hand &operator=(const Hand &);

	//returns the number of elements in the container
	int size() const;

	//equivalence operator
	bool operator==(const Hand &) const;

	//less than operator
	bool operator<(const Hand &) const;

	//returns card(by value) as C++ style string
	string asString() const;

private:
	vector<Card> cards;
};

//function decleration
ostream & operator<<(ostream & out, const Hand & hand);
void operator<<(Hand & hand, Deck & deck);
bool pokerRank(const Hand & hand1, const Hand & hand2);
int ranking(const Hand & h);

