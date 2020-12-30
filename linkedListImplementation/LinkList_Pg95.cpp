#include "iostream"
#include "LinkList_Pg95.h"
#include "set"
using namespace std;

void removeDupes_2_1(link_list* removeMyDupes) 
{
	set<int> dupeSet;
	node* head = removeMyDupes->head;
	node* current = head;
	node* prev = head;
	pair<set<int>::iterator, bool> ret;

	link_list* testList = new link_list();

	testList->pushBack(1);
	testList->pushBack(1);
	testList->pushBack(2);
	testList->pushBack(3);
	testList->pushBack(1);
	testList->pushBack(1);
	testList->pushBack(2);
	testList->pushBack(2);
	testList->pushBack(2);
	testList->pushBack(2);
	testList->pushBack(1);
	testList->pushBack(1);
	testList->pushBack(1);
	testList->pushBack(4);
	testList->pushBack(4);
	testList->pushBack(4);
	testList->pushBack(4);

	while(current->next!=NULL)
	{
		ret = dupeSet.insert(current->data);
		if (ret.second==false)
		{
			if (current==head) 
			{
				head = current->next;
			}
			else 
			{
				prev->next  = current->next;
				current = current->next;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	
	if (ret.second == false) 
	{
		prev->next = current->next;
	}

}



int findKthElement_2_2(node* head, int index, int& counter) 
{
	//static int counter = 0;
	int indexToReturn = 0;

	if (head == NULL) 
	{
		return NULL;
	}
	//cout << counter;
	
	findKthElement_2_2(head->next, index, counter);

	//cout << counter;
	counter++;

	if (index == counter)
	{
		//cout << index;
		cout << head->data;
		return head->data;
	}
}

int findKthElement_2_2(node* head, int index)
{
	int i = 0;
	return findKthElement_2_2(head, index, i);
}

void deleteMiddleNode_2_3(node* nodeToDelete)
{
	nodeToDelete->data = nodeToDelete->next->data;
	nodeToDelete->next = nodeToDelete->next->next;
}

node * partitionList_2_4(link_list* listToPartition, int pivot)
{
	node* current = listToPartition->head;
	node* head = listToPartition->head;
	node* prev = listToPartition->head;

	link_list* lowerPart = new link_list();
	link_list* upperPart = new link_list();

	while (current->next!=NULL)
	{
		if (current->data<pivot) 
		{
			lowerPart->pushBack(current->data);
		}
		else if (current->data >= pivot)
		{
			upperPart->pushBack(current->data);
		}

		prev = current;
		current = current->next;
	}

	current = lowerPart->head;

	while (current->next!=NULL)
	{
		current = current->next;
	}

	current->next = upperPart->head;

	return lowerPart->head;
}