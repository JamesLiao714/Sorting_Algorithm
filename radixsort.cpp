#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int getmax(vector<int> arr)
{
	int max = arr[0];
	for(int i = 0; i < arr.size(); ++i)
	{
		if(arr[i] > max)
			max =arr[i];
	}
		return max;
}

void countsort(vector<int>& arr, int e )
{
	int op[arr.size()];
	int i = 0;
	int count[10] = {0};

	for(int i = 0; i < arr.size(); ++i)
	{
		count[(arr[i]/e)%10]++;
	}

	for(int i = 1; i < 10; i++)
	{
		count[i] += count[i-1];
	}

	for(int i =arr.size()-1; i>=0; --i)
	{
		op[count[(arr[i]/e)%10] - 1] = arr[i];
		count[(arr[i]/e)%10]--;
	}
	for (i = 0; i < arr.size(); i++)
	{ 
        arr[i] = op[i]; 
        i==0? cout << arr[i] : cout << " "<<arr[i];
     }
     puts("");
}

void radix_sort(std::vector<int>& arr, int n)
{
	int max = getmax(arr);
	for (int exp = 1; max/exp > 0; exp *= 10) 
        countsort(arr, exp); 
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
		radix_sort(arr, num - 1);
	}
}