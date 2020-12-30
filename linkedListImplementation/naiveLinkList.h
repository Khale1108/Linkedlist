#pragma once

#include "stdlib.h"
#include "iostream"

using namespace std;


#ifndef LINK_LIST_H
#define LINK_LIST_H

struct node
{
	node* next = NULL;
	int data = 0;

	node(int dataIn)
	{
		next = NULL;
		data = dataIn;
	};
};

class link_list
{

public:
	node* head;
	link_list()
	{
		head = NULL;
	};

	int popBack(int* elementToPop);																//Passes element from last node by references then removes that last node in the list and frees it from memory
	int pushBack(int elementToAdd);																//Creates a node a pushes a new element to the end of the link list
	int pushFront(int elementToAdd);															//Adds a Node to the front of the Linked List with a given element
	int getElement(int indexOfNode, int * elementToGet);										//Returns a element from a given index of the linked list

	int insertNode(int indexToInsert, int elementToInsert);										//Inserts a node at a given index of a linked list
	int deleteNode(int indexToDelete);															//Deletes as node at a given index of the link list

	int displayLinkList(void);																	//Cout on the entire linked list including the head.
	
	
};

#endif