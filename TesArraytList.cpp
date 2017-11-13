#include<iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList<int> test(7);
	int array[7] = {4,2,5,1,6,3};

	for (int i = 0; i < 6; i++)
	{
		test.Insert(array[i],i);
	}
	test.Print();
	test.InsertSort(test);
	test.Print();

	cin.get();
	return 0;

}