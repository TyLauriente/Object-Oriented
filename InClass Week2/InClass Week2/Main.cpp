#include <fstream>
#include <vector>
#include <list>
#include <array>
#include <iostream>
#include "StopWatch.h"
#include <iomanip> 

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

	float timeVec[4], timeList[4];

	//Create an array<int> of SIZE

	array<int, SIZE> randNumArray;
	for (int i = 0; i < SIZE; ++i)
		randNumArray[i] = (rand() % 1000) + 1;

	list<int> numList;
	vector<int> numVec;

	//Noraml Sorting of Vector and List


	loadBoth(numList, numVec, randNumArray);
	cout << "-----------Sorting using default sorting operator-----------" << endl;
	sw.Start();
	sortVector(numVec, TypeSort::normal);
	sw.Stop();
	timeVec[0] = sw.GetElapsedSeconds();
	cout << "Time to sort Vector was " << std::setprecision(3) << timeVec[0] << " seconds" << endl;
	
	sw.Reset();
	sw.Start();
	sortList(numList, TypeSort::normal);
	sw.Stop();
	timeList[0] = sw.GetElapsedSeconds();
	cout << "Time to sort List was " << timeList[0] << " seconds" << endl;
	cout << endl;

	//Function Sorting of Vecotr and List

	sw.Reset();
	loadBoth(numList, numVec, randNumArray);
	cout << "-----------Sorting using custom made function-----------" << endl;
	sw.Start();
	sortVector(numVec, TypeSort::function);
	sw.Stop();
	timeVec[1] = sw.GetElapsedSeconds();
	cout << "Time to sort Vector was " << timeVec[1] << " seconds" << endl;
	sw.Reset();
	sw.Start();
	loadBoth(numList, numVec, randNumArray);
	sortList(numList, TypeSort::function);
	sw.Stop();
	timeList[1] = sw.GetElapsedSeconds();
	cout << "Time to sort List was " << timeList[1] << " seconds" << endl;
	cout << endl;

	//Class Sorting of Vector and List

	sw.Reset();
	loadBoth(numList, numVec, randNumArray);
	cout << "-----------Sorting using a class-----------" << endl;
	sw.Start();
	sortVector(numVec, TypeSort::object);
	sw.Stop();
	timeVec[2] = sw.GetElapsedSeconds();
	cout << "Time to sort Vector was " << timeVec[2] << " seconds" << endl;

	sw.Reset();
	sw.Start();
	sortList(numList, TypeSort::object);
	sw.Stop();
	timeList[2] = sw.GetElapsedSeconds();
	cout << "Time to sort List was " << timeList[2] << " seconds" << endl;
	cout << endl;

	//Lambda Sorting of Vector and List
	auto prop = [](int a, int b) { return a < b; };
	sw.Reset();
	cout << "-----------Sorting using a lambda-----------" << endl;
	sw.Start();
	std::sort(numVec.begin(), numVec.end(), prop);
	sw.Stop();
	timeVec[3] = sw.GetElapsedSeconds();
	cout << "Time to sort Vector was " << timeVec[3] << " seconds" << endl;

	sw.Reset();
	sw.Start();
	numList.sort(prop);
	sw.Stop();
	timeList[3] = sw.GetElapsedSeconds();
	cout << "Time to sort List was " << timeList[3] << " seconds" << endl;
	cout << endl << endl;

	std::ofstream file;
	file.open("Output.txt", std::ios::out);

	float timeV = timeVec[0] + timeVec[1] + timeVec[2] + timeVec[3];
	float timeL = timeList[0] + timeList[1] + timeList[2] + timeList[3];

	cout << "Total time to sort all Vectors: " << timeV << " seconds" << endl;
	file << std::setprecision(3) << "Total time to sort all Vectors: " << timeV << " seconds" << endl;
	cout << "Total time to sort all Lists:   " << timeL << " seconds" << endl;
	file << "Total time to sort all Lists:   " << timeL << " seconds" << endl;
	if (timeV < timeL)
	{
		cout << "Vectors sort faster on average" << endl;
		file << "Vectors sort faster on average" << endl;
	}
	else
	{
		cout << "Lists sort faster on average" << endl;
		file << "Lists sort faster on average" << endl;
	}


	cout << endl << endl;
	file << endl << endl;
	
	cout << "            Vector    List" << endl;
	file << "            Vector    List" << endl;
	cout << "Default:    " << timeVec[0] << "   " << timeList[0] << " seconds" << endl;
	file << "Default:    " << timeVec[0] << "   " << timeList[0] << " seconds" << endl;
	cout << "Function:   " << timeVec[1] << "   " << timeList[1] << " seconds" << endl;
	file << "Function:   " << timeVec[1] << "   " << timeList[1] << " seconds" << endl;
	cout << "Class:      " << timeVec[2] << "   " << timeList[2] << " seconds" << endl;
	file << "Class:      " << timeVec[2] << "   " << timeList[2] << " seconds" << endl;
	cout << "Lambda:     " << timeVec[3] << "   " << timeList[3] << " seconds" << endl;
	file << "Lambda:     " << timeVec[3] << "   " << timeList[3] << " seconds" << endl;
	cout << endl;
	file << endl;

	cout << "The fastest sort method for Vectors is the ";
	file << "The fastest sort method for Vectors is the ";
	if (timeVec[0] < timeVec[1] && timeVec[0] < timeVec[2] && timeVec[0] < timeVec[3])
	{
		cout << "Default sorting method" << endl;
		file << "Default sorting method" << endl;
	}
	else if (timeVec[1] < timeVec[0] && timeVec[1] < timeVec[2] && timeVec[1] < timeVec[3])
	{
		cout << "Custom Function sorting method" << endl;
		file << "Custom Function sorting method" << endl;
	}
	else if (timeVec[2] < timeVec[0] && timeVec[2] < timeVec[1] && timeVec[2] < timeVec[3])
	{
		cout << "Class sorting method" << endl;
		file << "Class sorting method" << endl;
	}
	else
	{
		cout << "Lambda sorting method" << endl;
		file << "Lambda sorting method" << endl;
	}

	cout << "The fastest sort method for Lists is the ";
	file << "The fastest sort method for Lists is the ";
	if (timeList[0] < timeList[1] && timeList[0] < timeList[2] && timeList[0] < timeList[3])
	{
		cout << "Default sorting method" << endl;
		file << "Default sorting method" << endl;
	}
	else if (timeList[1] < timeList[0] && timeList[1] < timeList[2] && timeList[1] < timeList[3])
	{
		cout << "Custom Function sorting method" << endl;
		file << "Custom Function sorting method" << endl;
	}
	else if (timeList[2] < timeList[0] && timeList[2] < timeList[1] && timeList[2] < timeList[3])
	{
		cout << "Class sorting method" << endl;
		file << "Class sorting method" << endl;
	}
	else
	{
		cout << "Lambda sorting method" << endl;
		file << "Lambda sorting method" << endl;
	}
	file.close();

	system("pause");
	return 0;
}