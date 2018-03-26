//
// Created by Jianing Sum on 3/23/18.
//

#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

enum returnValue { cannotOpenFile = -1, success = 0, invalidCardContent = 1, missFileName = 2, twoArgumentWithShuffle = 3, moreThanRepquiredInpput = 4, twoArgumentWithoutShuffle = 5 };
int usageMessage() {
	cout << "This program read and print card suit and card rank from file" << endl;
	cout << "For example run lab2.exe test_file.txt";
	return missFileName;
}

int usageMessage2()
{
	cout << "More than required arguments" << endl;
	cout << "the arguments should be two or three";
	return moreThanRepquiredInpput;
}

int main(int argc, char *argv[])
{
	const int max_arg = 3;
	const int min_arg = 2;
	string cmd = "-shuffle";
	vector<Hand> hands; 
	Hand h;
	const int hand_num = 9;
	const int card_num = 5;

	if (argc < min_arg) {
		int toreturn = usageMessage();
		return toreturn;
	}
	else if (argc > max_arg) {
		usageMessage2();
		return moreThanRepquiredInpput;
	}
	else if (argc == min_arg) {
		string argu(argv[1]);
		if (argu.find(cmd) != std::string::npos) {
			cout << "two Argument With Shuffle" << endl;
			return twoArgumentWithShuffle;
		}
		else {
			try {
				Deck deck;
				int loaderror = deck.load(argv[1]);

				for (int i = 0; i < hand_num; ++i)
				{
					hands.push_back(Hand());
				}

				for (int j = 0; j < card_num; ++j)
				{
					for (int i = 0; i < hand_num; ++i)
					{
						hands[i] << deck;
					}
				}
				//normal sort
				sort(hands.begin(), hands.end());
				cout << "Result after sorting cards:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}

				//poker rank sort
				sort(hands.begin(), hands.end(), pokerRank);
				cout << "Result after sorting by poker rank:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}
				return success;
			}
			catch (runtime_error) {
				cout << "cannot open file" << endl;
				return cannotOpenFile;
			}
		}
	}
	else {
		string argu(argv[1]);
		string argu2(argv[2]);

		if	((argc == max_arg) && (argu.find(cmd) != std::string::npos)){
		string argu(argv[1]);		
			try {
				Deck deck;
				int loaderror = deck.load(argv[2]);
				deck.shuffle();
				for (int i = 0; i < hand_num; ++i)
				{
					hands.push_back(Hand());
				}

				for (int j = 0; j < card_num; ++j)
				{
					for (int i = 0; i < hand_num; ++i)
					{
						hands[i] << deck;
					}
				}
				//normal sort
				sort(hands.begin(), hands.end());
				cout << "Result after sorting cards:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}

				//poker rank sort
				sort(hands.begin(), hands.end(), pokerRank);
				cout << "Result after sorting by poker rank:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}
				return success;
			}
			catch (runtime_error) {
				cout << "cannot open file" << endl;
				return cannotOpenFile;
			}
		}
		else if ((argc == max_arg) && (argu2.find(cmd) != std::string::npos)) {
			try {
				Deck deck;
				int loaderror = deck.load(argv[1]);
				deck.shuffle();
				for (int i = 0; i < hand_num; ++i)
				{
					hands.push_back(Hand());
				}

				for (int j = 0; j < card_num; ++j)
				{
					for (int i = 0; i < hand_num; ++i)
					{
						hands[i] << deck;
					}
				}
				//normal sort
				sort(hands.begin(), hands.end());
				cout << "Result after sorting cards:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}

				//poker rank sort
				sort(hands.begin(), hands.end(), pokerRank);
				cout << "Result after sorting by poker rank:" << endl;
				for (int i = 0; i < hand_num; ++i)
				{
					cout << "hand" << i + 1 << ": " << hands[i] << endl;
				}
				return success;
			}
			catch (runtime_error) {
				cout << "cannot open file" << endl;
				return cannotOpenFile;
			}

		}
	else {
		cout << "Two argument but no shuffle command" << endl;
		return twoArgumentWithoutShuffle;
	}	
	}
}