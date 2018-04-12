#include <vector>
#include <list>
#include <array>
#include <iostream>
#include "StopWatch.h"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::array;

enum TypeSort
{
	normal,
	function,
	object
};

const int SIZE = 1000000;

bool CustomLessThan(int a, int b)
{
	return a < b;
}

class CompareInt
{
public:
	bool operator()(int a, int b) { return a < b; }
};

void sortVector(vector<int> &v, TypeSort type)
{
	if (type == TypeSort::normal)
		std::sort(v.begin(), v.end(), std::less<int>());
	else if (type == TypeSort::function)
		std::sort(v.begin(), v.end(), CustomLessThan);
	else
	{
		CompareInt ci;
		std::sort(v.begin(), v.end(), ci);
	}
}

void loadVector(vector<int> &v, array<int, SIZE> &a)
{
	for (int i = 0; i < SIZE; ++i)
	{
		v.push_back(a[i]);
	}
}

void sortList(list<int> &l, TypeSort type)
{
	if (type == TypeSort::normal)
		l.sort();
	else if (type == TypeSort::function)
		l.sort(CustomLessThan);
	else
	{
		CompareInt ci;
		l.sort(ci);
	}
}

void loadList(list<int> &l, array<int, SIZE> &a)
{
	for (int i = 0; i < SIZE; ++i)
	{
		l.push_back(a[i]);
	}
}

void loadBoth(list<int> &l, vector<int> &v, array<int, SIZE> &a)
{
	loadVector(v, a);
	loadList(l, a);
}



int main()
{
	StopWatch sw;
	srand(time(0));

	array<int, SIZE> randNumArray;
	for (int i = 0; i < SIZE; ++i)
		randNumArray[i] = (rand() % 1000) + 1;

	list<int> numList;
	vector<int> numVec;

	//Noraml Sorting of Vector and List


	loadBoth(numList, numVec, randNumArray);

	sw.Start();
	sortVector(numVec, TypeSort::normal);
	sw.Stop();
	cout << "Time to sort Vector was " << sw.GetElapsedSeconds() << " seconds using normal sort" << endl;
	
	sw.Reset();
	sw.Start();
	sortList(numList, TypeSort::normal);
	sw.Stop();
	cout << "Time to sort List was " << sw.GetElapsedSeconds() << " seconds using normal sort" << endl;

	//Function Sorting of Vecotr and List

	sw.Reset();
	loadBoth(numList, numVec, randNumArray);
	sw.Start();
	sortVector(numVec, TypeSort::function);
	sw.Stop();
	cout << "Time to sort Vector was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	sw.Reset();
	sw.Start();
	loadBoth(numList, numVec, randNumArray);
	sortList(numList, TypeSort::function);
	sw.Stop();
	cout << "Time to sort List was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	//Class Sorting of Vector and List

	sw.Reset();
	loadBoth(numList, numVec, randNumArray);
	sw.Start();
	sortVector(numVec, TypeSort::object);
	sw.Stop();
	cout << "Time to sort Vector was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	sw.Reset();
	sw.Start();
	sortList(numList, TypeSort::object);
	sw.Stop();
	cout << "Time to sort List was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	//Lambda Sorting of Vector and List
	auto prop = [](int a, int b) { return a < b; };
	sw.Reset();
	sw.Start();
	std::sort(numVec.begin(), numVec.end(), prop);
	sw.Stop();
	cout << "Time to sort Vector was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	sw.Reset();
	sw.Start();
	numList.sort(prop);
	sw.Stop();
	cout << "Time to sort List was " << sw.GetElapsedSeconds() << " seconds using function sort" << endl;

	system("pause");
	return 0;
}