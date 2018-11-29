#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void insertion_sort(vector<int>& arr, int n)
{
	for(int i = 1; i < n; ++i)
	{
		int temp = arr[i];
		int j = i -1;
		while(temp <= arr[j]&& j >= 0)
		{
			arr[j+1] = arr[j];	
			j--;
		}
		arr[j + 1] = temp;

		for(int i = 0; i < arr.size(); ++i)
		{
			if(i == 0)
		   		cout << arr.at(i); 
		   	else
		   		cout <<" " <<arr.at(i);
		}
		puts("");
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
		insertion_sort(arr, arr.size());
	}
}