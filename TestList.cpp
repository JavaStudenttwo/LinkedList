#include<iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList<int> test(16);
	int array[5] = {1,2,3,4,5};

	for (int i = 0; i < 5; i++)
	{
		test.Insert(array[i],0);
	}

	int i = test.InterpolateSearch(4);
	//test.Insert(1,0);
	cout << i << endl;
	test.Print();



	cin.get();
	return 0;

}