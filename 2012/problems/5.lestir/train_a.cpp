#include<iostream>
#include<string>
using namespace std;

int bubble(int* list, int length)
{
	bool sorted = false;
	int count = 0;
	while(!sorted)
	{
		sorted = true;
		for(int i = 0; i < length - 1; i++)
		{
			if(list[i] > list[i+1])
			{
				swap(list[i], list[i+1]);
				sorted = false;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int times;
	int train[51];
	cin >> times;
	for(int i = 0; i != times; i++)
	{
		int length;
		cin >> length;
		for(int j = 0; j != length; j++)
		{
			cin >> train[j];
		}
		cout << bubble(train, length) << "\n";
	}
	return 0;
}
