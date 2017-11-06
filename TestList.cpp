#include<iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList<int> test(7);
	int array[7] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; i++)
	{
		test.Insert(array[i],i);
	}
	test.Print();

	test.InterpolateSearch(3);
	test.InterpolateSearch(6);
	test.InterpolateSearch(1);
	test.InterpolateSearch(5);
	test.InterpolateSearch(4);


	cin.get();
	return 0;

}