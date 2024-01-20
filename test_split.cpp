/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int userInput = 0;
	bool value = true;

	cout << "Enter Value: ";
	cin >> userInput;

	Node* head_ = new Node(userInput, nullptr);
	Node* steve = head_;

	while (value == true)
	{
		cout << "Enter Value: ";
		cin >> userInput;

		if (userInput < 0) break;

		Node* temp = new Node(userInput, nullptr);
		steve->next = temp;
		steve = steve->next;
	}

	Node* odds = NULL;
	Node* evens = NULL;

	split(head_, odds, evens);

	while (evens != nullptr)
	{
		Node* evensDelete = evens;
		cout << evens->value << " ";
		evens = evens->next;
		delete evensDelete;
	}

	cout << endl;

	while (odds != nullptr)
	{
		Node* oddsDelete = odds;
		cout << odds->value << " ";
		odds = odds->next;
		delete oddsDelete;
	}

	return 0;
}