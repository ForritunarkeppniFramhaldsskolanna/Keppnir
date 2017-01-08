#include<iostream>
#include<string>

using namespace std;

int inversions(int* list, int length)
{
	int count = 0;
	for(int i = 0; i < length - 1; i++)
	{
	    for(int j = i + 1; j < length; j++)
	    {
            if(list[i] > list[j])
            {
                ++count;
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
		cout << inversions(train, length) << "\n";
	}
	return 0;
}
