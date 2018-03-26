//
// Created by Jianing Sum on 3/23/18.
//

#include "stdafx.h"
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// default constructor
Hand::Hand() = default;

//copy constructor
Hand::Hand(const Hand & hand2)
{
	cards = hand2.cards;
}
// assignment operator
Hand &Hand::operator=(const Hand & hand2) {
	this->cards.clear();
	cards = hand2.cards;
	return *this;
}

//return card size in hand 
int Hand::size() const
{
	return cards.size();
}

//equivalence operator
bool Hand::operator==(const Hand &hand2) const {
	return (cards == hand2.cards);
}

//less than operator
bool Hand::operator<(const Hand &hand2) const
{
	for (size_t i = 0; i < cards.size(); ++i)
	{
		if (hand2.cards.size() > i)
		{
			if (cards[i] < hand2.cards[i])
			{
				return true;
				break;
			}
			else if (hand2.cards[i] < cards[i])
			{
				return false;
				break;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}


//returns card(by value) as C++ style string
string Hand::asString() const {
	string rankmap[13] = { "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "jack", "queen", "king", "ace" };
	string suitmap[4] = { "clubs", "diamonds", "hearts", "spades" };

	stringstream result;
	for (auto i = this->cards.begin(); i != cards.end(); i++) {
		result << rankmap[i->rank] << suitmap[i->suit] << " ";
	}
	return result.str();
}


ostream & operator<<(ostream & out, const Hand &hand) {
	out << hand.asString();
	return out;
}

void operator<< (Hand & hand, Deck & deck)
{
	hand.cards.push_back(deck.cards.back());
	deck.cards.pop_back();
	sort(hand.cards.begin(), hand.cards.end());
}

enum ranks { NoRank = 1, OnePair = 2, TwoPairs = 3, ThreeOfaKind = 4, Straight = 5, Flush = 6, FullHouse = 7, FourOfaKind = 8, StraightFlush=9 };

//get handrank type
int ranking(const Hand & hand) {
	int handRank = 0;
	if (hand.cards[1].rank == hand.cards[0].rank + 1 && hand.cards[2].rank == hand.cards[0].rank + 2 &&
		hand.cards[3].rank == hand.cards[0].rank + 3 && hand.cards[4].rank == hand.cards[0].rank + 4) {
		if (hand.cards[0].suit == hand.cards[1].suit && hand.cards[0].suit == hand.cards[2].suit &&
			hand.cards[0].suit == hand.cards[3].suit && hand.cards[0].suit == hand.cards[4].suit) {
			handRank = StraightFlush;
		}
		else {
			handRank = Straight;
		}
	}
	else {
		if (hand.cards[0].suit == hand.cards[1].suit && hand.cards[0].suit == hand.cards[2].suit &&
			hand.cards[0].suit == hand.cards[3].suit && hand.cards[0].suit == hand.cards[4].suit) {
			handRank = Flush;
		}
		else if ((hand.cards[0].rank == hand.cards[1].rank && hand.cards[0].rank == hand.cards[2].rank &&
			hand.cards[0].rank == hand.cards[3].rank) ||
			(hand.cards[1].rank == hand.cards[2].rank && hand.cards[1].rank == hand.cards[3].rank &&
				hand.cards[1].rank == hand.cards[4].rank)) {
			handRank = FourOfaKind;
		}
		else if ((hand.cards[0].rank == hand.cards[1].rank && hand.cards[0].rank == hand.cards[2].rank &&
			hand.cards[3].rank == hand.cards[4].rank) ||
			(hand.cards[0].rank == hand.cards[1].rank && hand.cards[2].rank == hand.cards[3].rank &&
				hand.cards[3].rank == hand.cards[4].rank)) {
			handRank = FullHouse;
		}
		else if ((hand.cards[0].rank == hand.cards[1].rank && hand.cards[0].rank == hand.cards[2].rank) ||
			(hand.cards[1].rank == hand.cards[2].rank && hand.cards[1].rank == hand.cards[3].rank) ||
			(hand.cards[2].rank == hand.cards[3].rank && hand.cards[2].rank == hand.cards[4].rank)) {
			handRank = ThreeOfaKind;
		}
		else if ((hand.cards[0].rank == hand.cards[1].rank && hand.cards[2].rank == hand.cards[3].rank) ||
			(hand.cards[1].rank == hand.cards[2].rank && hand.cards[3].rank == hand.cards[4].rank) ||
			(hand.cards[0].rank == hand.cards[1].rank && hand.cards[3].rank == hand.cards[4].rank)) {
			handRank = TwoPairs;
		}
		else if ((hand.cards[0].rank == hand.cards[1].rank) || (hand.cards[1].rank == hand.cards[2].rank) ||
			(hand.cards[2].rank == hand.cards[3].rank) || (hand.cards[3].rank == hand.cards[4].rank)) {
			handRank = OnePair;
		}
		else {
			handRank = NoRank;
		}
	}
	return handRank;
}

// compare Hands by Rank and Within each Rank
bool pokerRank(const Hand & hand1, const Hand & hand2) {
	int cardnumber = 5;
	int rank1 = ranking(hand1);
	int rank2 = ranking(hand2);

	//if ranks are different, simply return rank1 > rank2
	if (rank1 != rank2) {
		return (rank1 > rank2);
	}
	//compare Within each Rank
	else if (rank1 == NoRank || rank1 == Flush) {
		if (hand1.cards[4].rank == hand2.cards[4].rank) {
			if (hand1.cards[3].rank == hand2.cards[3].rank) {
				if (hand1.cards[2].rank == hand2.cards[2].rank) {
					if (hand1.cards[1].rank == hand2.cards[1].rank) {
						return (hand1.cards[0].rank > hand2.cards[0].rank);
					}
					else {
						return (hand1.cards[1].rank > hand2.cards[1].rank);
					}
				}
				else {
					return (hand1.cards[2].rank > hand2.cards[2].rank);
				}
			}
			else {
				return (hand1.cards[3].rank > hand2.cards[3].rank);
			}
		}
		else {
			return (hand1.cards[4].rank > hand2.cards[4].rank);
		}
	}
	else if (rank1 == ThreeOfaKind || rank1 == FourOfaKind || rank1 == Straight || rank1 == StraightFlush) {
		return (hand1.cards[2].rank > hand2.cards[2].rank);
	}
	else if (rank1 == FullHouse) {
		int hand1_three_rank, hand1_two_rank, hand2_three_rank, hand2_two_rank;
		if (hand1.cards[0].rank == hand1.cards[1].rank && hand1.cards[0].rank == hand1.cards[2].rank) {
			hand1_three_rank = hand1.cards[0].rank;
			hand1_two_rank = hand1.cards[3].rank;
		}
		else {
			hand1_three_rank = hand1.cards[3].rank;
			hand1_two_rank = hand1.cards[0].rank;
		}
		if (hand2.cards[0].rank == hand2.cards[1].rank && hand2.cards[0].rank == hand2.cards[2].rank) {
			hand2_three_rank = hand2.cards[0].rank;
			hand2_two_rank = hand2.cards[3].rank;
		}
		else {
			hand2_three_rank = hand1.cards[3].rank;
			hand2_two_rank = hand1.cards[0].rank;
		}
		if (hand1_three_rank == hand2_three_rank) {
			return (hand1_two_rank > hand2_two_rank);
		}
		else {
			return (hand1_three_rank > hand2_three_rank);
		}
	}
	else if (rank1 == TwoPairs) {
		int hand1_pair1, hand1_pair2, hand2_pair1, hand2_pair2, hand1_single_rank, hand2_single_rank;

		hand1_pair1 = hand1.cards[3].rank;
		hand1_pair2 = hand1.cards[1].rank;
		hand2_pair1 = hand2.cards[3].rank;
		hand2_pair2 = hand2.cards[1].rank;

		// find the rank of two pairs and one no-pair card 
		if ((hand1.cards[0].rank == hand1.cards[1].rank) && (hand1.cards[2].rank == hand1.cards[3].rank)) {
			hand1_single_rank = hand1.cards[4].rank;
		}
		else if ((hand1.cards[1].rank == hand1.cards[2].rank) && (hand1.cards[3].rank == hand1.cards[4].rank)) {
			hand1_single_rank = hand1.cards[0].rank;
		}
		else {
			hand1_single_rank = hand1.cards[2].rank;
		}

		if ((hand2.cards[0].rank == hand2.cards[1].rank) && (hand2.cards[2].rank == hand2.cards[3].rank)) {
			hand2_single_rank = hand2.cards[4].rank;
		}
		else if ((hand2.cards[1].rank == hand2.cards[2].rank) && (hand2.cards[3].rank == hand2.cards[4].rank)) {
			hand2_single_rank = hand2.cards[0].rank;
		}
		else {
			hand2_single_rank = hand2.cards[2].rank;
		}

		if (hand1_pair1 == hand2_pair1) {
			if (hand1_pair2 == hand2_pair2) {
				return (hand1_single_rank > hand2_single_rank);
			}
			else {
				return (hand1_pair2 > hand2_pair2);
			}
		}
		else {
			return (hand1_pair1 > hand2_pair1);
		}
	}
	// rank1 == OnePair
	else {
		int hand1_pair, hand2_pair, hand1_single1, hand1_single2, hand1_single3, hand2_single1, hand2_single2, hand2_single3;
		// find the rank of one pair and three no-pair card 
		if (hand1.cards[0].rank == hand1.cards[1].rank) {
			hand1_pair = hand1.cards[0].rank;
			hand1_single1 = hand1.cards[4].rank;
			hand1_single2 = hand1.cards[3].rank;
			hand1_single3 = hand1.cards[2].rank;
		}
		else if (hand1.cards[1].rank == hand1.cards[2].rank) {
			hand1_pair = hand1.cards[1].rank;
			hand1_single1 = hand1.cards[4].rank;
			hand1_single2 = hand1.cards[3].rank;
			hand1_single3 = hand1.cards[0].rank;
		}
		else if (hand1.cards[2].rank == hand1.cards[3].rank) {
			hand1_pair = hand1.cards[2].rank;
			hand1_single1 = hand1.cards[4].rank;
			hand1_single2 = hand1.cards[1].rank;
			hand1_single3 = hand1.cards[0].rank;
		}
		else {
			hand1_pair = hand1.cards[3].rank;
			hand1_single1 = hand1.cards[2].rank;
			hand1_single2 = hand1.cards[1].rank;
			hand1_single3 = hand1.cards[0].rank;
		}

		if (hand2.cards[0].rank == hand2.cards[1].rank) {
			hand2_pair = hand2.cards[0].rank;
			hand2_single1 = hand2.cards[4].rank;
			hand2_single2 = hand2.cards[3].rank;
			hand2_single3 = hand2.cards[2].rank;
		}
		else if (hand2.cards[1].rank == hand2.cards[2].rank) {
			hand2_pair = hand2.cards[1].rank;
			hand2_single1 = hand2.cards[4].rank;
			hand2_single2 = hand2.cards[3].rank;
			hand2_single3 = hand2.cards[0].rank;
		}
		else if (hand2.cards[2].rank == hand2.cards[3].rank) {
			hand2_pair = hand2.cards[2].rank;
			hand2_single1 = hand2.cards[4].rank;
			hand2_single2 = hand2.cards[1].rank;
			hand2_single3 = hand2.cards[0].rank;
		}
		else {
			hand2_pair = hand2.cards[3].rank;
			hand2_single1 = hand2.cards[2].rank;
			hand2_single2 = hand2.cards[1].rank;
			hand2_single3 = hand2.cards[0].rank;
		}

		if (hand1_pair == hand2_pair) {
			if (hand1_single1 == hand2_single1) {
				if (hand1_single2 == hand2_single2) {
					return (hand1_single3 > hand2_single3);
				}
				return (hand1_single2 > hand2_single2);
			}
			return (hand1_single1 > hand2_single1);
		}
		return (hand1_pair > hand2_pair);
	}
}