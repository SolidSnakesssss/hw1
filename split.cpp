/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void splitHelp(Node*& current, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
	/* Add code here */
	splitHelp(in, odds, evens);
	in = NULL;
	// WRITE YOUR CODE HERE
}

/* If you needed a helper function, write it here */
void splitHelp(Node*& current, Node*& odds, Node*& evens)
{
	if (current == nullptr)
	{
		odds = nullptr;
		evens = nullptr;
		return;
	}

	if (current->value % 2 == 0)
	{
		evens = current;
		splitHelp(current->next, odds, evens->next);
	}

	else
	{
		odds = current;
		splitHelp(current->next, odds->next, evens);
	}
}