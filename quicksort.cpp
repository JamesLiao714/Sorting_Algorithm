#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void partition(vector<int>& arr, int beg, int end, int& loc)
{
	int left = beg, right = end, flag = 0;
	loc = beg;
	while(flag == 0)
	{
		while(arr[loc] <= arr[right] && loc!=right)
		{
			right-=1;
		}
		if(loc == right)
			flag = 1;

		else if(arr[loc] > arr[right])
		{
			swap(arr[loc], arr[right]);
			loc = right;
		}
		if(flag == 0)
		{
			while(arr[loc] >= arr[left] && loc!=left)
			{
				left+=1;
			}
			if(loc == left)
				flag = 1;
			else if(arr[loc] < arr[left])
			{
				swap(arr[loc], arr[left]);
				loc = left;
			}
		}
	}
	for(int i = 0; i < arr.size(); ++i)
	{
		if(i == 0)
			cout << arr[0];
		else
			cout << " " <<arr[i];
	}
	cout << endl;
}

void quick_sort(vector<int>& arr, int beg, int end)
{
	int loc = 0;
	if(end > beg)
	{
		partition(arr, beg, end, loc);
		quick_sort(arr, beg, loc - 1);
		quick_sort(arr, loc + 1, end);
	}
}

int main()
{
	int num;
	while(cin >> num)
	{
		vector<int> arr;
		for(int i = 0; i < num; ++i)
		{
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		quick_sort(arr, 0,  num - 1);
	}
}