// linkedListImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "naiveLinkList.h"
#include<windows.h>
#include "LinkList_Pg95.h"

using namespace std;

int main()
{
	link_list * testList = new link_list();

	testList->pushBack(3);
	testList->pushBack(25);
	testList->pushBack(36);
	testList->pushBack(44);
	testList->pushBack(2);
	testList->pushBack(5);
	testList->pushBack(8);
	testList->pushBack(12);
	testList->pushBack(2);
	testList->pushBack(1);
	testList->pushBack(4);
	testList->pushBack(11);
	testList->pushBack(17);
	testList->pushBack(15);
	testList->pushBack(7);
	testList->pushBack(8);

	//testList->displayLinkList();
	node* head;

	head = partitionList_2_4(testList, 8);

	testList->displayLinkList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
