#include<iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList<int> list;
	
	for (int i = 0; i < 20; i++)
	{
		list.Insert(i*4,i);
	}
	for (int i = 0; i < 5; i++){
		list.Insert(i,i*4);
	}
	list.Print();

	cin.get();
	return 0;

}