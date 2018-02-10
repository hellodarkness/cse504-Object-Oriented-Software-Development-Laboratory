// clab0.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "card.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Card::Rankenum getRank(int a) {
	switch (a)
	{
	case '2':
		return Card::two;
		break;
	case '3':
		return Card::Rankenum::three;
		break;
	case '4':
		return Card::Rankenum::four;
		break;
	case '5':
		return Card::Rankenum::five;
		break;
	case '6':
		return Card::Rankenum::six;
		break;
	case '7':
		return Card::Rankenum::seven;
		break;
	case '8':
		return Card::Rankenum::eight;
		break;
	case '9':
		return Card::Rankenum::nine;
		break;
	case '10':
		return Card::Rankenum::ten;
		break;
	case '11':
		return Card::Rankenum::jack;
		break;
	case '12':
		return Card::Rankenum::queen;
		break;
	case '13':
		return Card::Rankenum::king;
		break;
	case '14':
		return Card::Rankenum::ace;
		break;
	default:
		cout << "Rank name error" << endl;
		break;
	}
}

 Card::Suitenum getSuit(char a) {
	 switch (a)
	 {
	 case 'c':
	 case 'C':
		 return Card::Suitenum::clubs;
		 break;
	 case 'd':
	 case 'D':
		 return Card::Suitenum::diamonds;
		 break;
	 case 'h':
	 case 'H':
		 return Card::Suitenum::hearts;
		 break;
	 case 's':
	 case 'S':
		 return Card::Suitenum::spades;
		 break;
	 default:
		 cout << "Suit name error" << endl;
		 break;
	  }
	}

	int parseFile(vector<Card> &outputcard, char* filename) {

		ifstream ifs;
		ifs.open(filename);
		char inputsuit;
		int inputrank;

		if (!ifs.is_open()) {
			cout << "Cannot open file" << endl;
			return 1;
		}

		else {
			string cardinput;
			while (ifs >> cardinput) {
				if (cardinput.length() == 3) {
					if (cardinput[0] == 1 && cardinput[1] == 0) {
						inputrank = '10';
						inputsuit = cardinput[2];
					}
				}
				else if (cardinput.length() == 2) {
					inputrank = cardinput[0];
					inputsuit = cardinput[1];
				}
				else if (cardinput.length() < 3 || cardinput.length() > 2) {
					cout << "Cardinput length error" << endl;
					continue;
				}

				if (cardinput[0] == 'J' || cardinput[0] == 'j') {
					inputrank = '11';
				}
				if (cardinput[0] == 'Q' || cardinput[0] == 'q') {
					inputrank = '12';
				}
				if (cardinput[0] == 'K' || cardinput[0] == 'k') {
					inputrank = '13';
				}
				if (cardinput[0] == 'A' || cardinput[0] == 'a') {
					inputrank = '14';
				}
				    
				Card getcard = { getRank(inputrank), getSuit(inputsuit) };
				outputcard.push_back(getcard);
				}
			}
		return 0;
	}

 int pirntCard(vector<Card> &input) {
	 string rankmap[13] = { "two", "three", "four", "five", "six", "seven",
		 "eight", "nine", "ten", "jack", "queen", "king", "ace" };
	 string suitmap[4] = { "clubs", "diamonds", "hearts", "spades" };
	 
	 try {
		 for (Card card : input) {
			 cout << rankmap[card.rank] << " " << "of" << " " << suitmap[card.suit] << endl;
		 }
		 return 0;
	 }
	 catch (exception a) {
		 cout << "Cannot print cards" << endl;
		 return 1;
	 }
 }

 int usageMessage() {
	 cout << "This program read and print card suit and card rank from file" << endl;
	 cout << "For example run clab0.exe and input card_file.txt";
	 return 1;
 }

int main(int argc, char *argv[])
{
	try {
		vector<Card> outputcard;
		parseFile(outputcard, argv[1]);
		pirntCard(outputcard);
		return 0;
	}
	catch (exception b) {
		usageMessage();
		return 1;
	}
}