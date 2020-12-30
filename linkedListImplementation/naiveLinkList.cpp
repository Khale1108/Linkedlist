#include "stdlib.h"
#include "iostream"

#include "naiveLinkList.h"

using namespace std;

///////////////////////////////////////////////////////////////Review These 2 Functions///////////////////////////////////////////////////////
//Inserts element at desired index of linked list
//Time Complexity   O(N)
//Space Complexity  O(1)
//This one was no bueno and took me a long time.
//I ended up referencing an online solution.
//It was difficult because of the 1st and last position inserts.
//It is also referenced as 1 as the beggining not 0.
int link_list::insertNode(int indexToInsert, int elementToInsert)
{
	node* current = head;
	node* prev = head;
	node* nodeToInsert = new node(elementToInsert);

	int index = 0;

	if (head != NULL)
	{
		if (indexToInsert != 0)
		{
			indexToInsert -= 1;
		}

		while (index != indexToInsert && current->next != NULL)
		{
			prev = current;
			current = current->next;
			++index;
		}

		if (index == 0)
		{
			nodeToInsert->next = head;
			head = nodeToInsert;
		}
		else if (current->next == NULL && indexToInsert == index + 1)
		{
			current->next = nodeToInsert;
		}
		else if (indexToInsert > index + 1)
		{
			current->next = nodeToInsert;
		}
		else
		{
			prev->next = nodeToInsert;
			nodeToInsert->next = current;
		}
	}
	else
	{
		head = nodeToInsert;
	}

	return 0;
}

//deletes element at a given position
//Time Complexity	O(N)
//Space Complexity  O(1)
//Referenced the insert node function
//The indexing works the same way.
int link_list::deleteNode(int indexToDelete)
{
	node* current = head;
	node* prev = head;
	int index = 0;

	if (indexToDelete != 0)
	{
		indexToDelete -= 1;
	}

	while (indexToDelete != index && current->next != NULL)
	{
		prev = current;
		current = current->next;
		++index;
	}

	if (index == 0)
	{
		head = head->next;
	}
	else if (current->next == NULL && index == indexToDelete + 1)
	{
		prev->next = NULL;
		delete(current);
	}
	else if (index > indexToDelete + 1)
	{

	}
	else
	{
		prev->next = current->next;
		delete(current);
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Remove Element In Back ---- 
	//Time Complexity: O(N)
	//Space Complexity: O(1)
	//NOTES:
	//Issue that came up is removing last element caused an issue when freeing with delete. 
	//This caused me to free the head memory. Fixed by handling declaring head to NULL;
int link_list::popBack(int * elementToPop)	
{
	node* current = head;
	node* prev = head;

	if (head == NULL) 
	{
		*elementToPop = -1;
		return -1;
	}

	while (current->next!=NULL)
	{
		prev=current;
		current = current->next;
	}

	*elementToPop = current->data;
	prev->next = NULL;
	
	if (prev != current) 
	{
		delete(current);
	}
	else
	{
		head = NULL;
	}
	return 0;
}

	//add Element to Back
	//Time Complexity  O(N)
	//Space Complexity O(1)
int link_list::pushBack(int elementToAdd)
	{
		node* temp = NULL;

		if (head == NULL)
		{
			head = new node(elementToAdd);
			return 0;
		}

		temp = head;

		
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}

		if (temp->next==NULL)
		{
			node* next = new node(elementToAdd);
			temp->next = next;
		}

		return 0;
	}

	//Time Complexity  O(N)
	//Space Complexity O(1)
	//Prints out entire link list
int link_list::displayLinkList(void)
{
	node* temp = head;

	cout << temp->data << " , ";

	while (temp->next !=NULL)
	{
		temp = temp->next;
		cout << temp->data << " , ";
	}

	cout << "\n";

	return 0;
}


	//Adds an element to the front of the link list
	//Time Complexity  O(N)
	//Space Complexity O(1)
int link_list::pushFront(int elementToAdd)
{	
	node* newNode = new node(elementToAdd);

	newNode->next = head;
	head = newNode;

	return 0;
}

	//Returns element of linked list given an index
	//The bounding of this is tricky. Need to check if the end is NULL since I'm iterating with a int in a for loop.
	//Changed from indexed at 0 to indexed at 1. 0 Still returns the 1st index.
	//Changed to while loop to check when it reaches the end just retun end element
	//Time Complexity   O(N)
	//Space Complexity  O(1)
int link_list::getElement(int indexOfNode, int * elementToGet)
{
	node* temp = head;
	int index = 0;

	if (indexOfNode!=0)
	{
		indexOfNode -= 1;
	}

	while (index < indexOfNode && temp->next!=NULL)
	{
		temp = temp->next;
		++index;
	}

	*elementToGet = temp->data;

	return 0;
}
