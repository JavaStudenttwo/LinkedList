#include<iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {
	DoubleLinkedList<int> list;

	for (int i = 0; i < 20; i++)
	{
		list.Insert(i * 4, i);
	}
	/*for (int i = 0; i < 5; i++){
	list.Insert(i,i*4);
	}*/
	//list.Insert(10, 0);
	list.Insert(100, 13);
	list.Remove(4);
	list.Print();

	cin.get();
	return 0;

}