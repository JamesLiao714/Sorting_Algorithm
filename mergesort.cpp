#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


void merge(vector<int>& arr, int left_low, int left_high, int right_low, int right_high) 
{ 
    int length = right_high-left_low+1;
    int temp[length];
    int left = left_low;
    int right = right_low;
    for (int i = 0; i < length; ++i) { 
        if (left > left_high)
            temp[i] = arr[right++];
        else if (right > right_high)
            temp[i] = arr[left++];
        else if (arr[left] <= arr[right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++]; 
    }
    
    for (int i=0; i< length; ++i) 
    {
    	if(i == length - 1)
    		cout << temp[i] <<endl;
    	else
    		cout << temp[i] <<" ";
        arr[left_low++] = temp[i];
    }
 }
	


void merge_sort(vector<int>& arr, int b, int e)
{
	//cout << "Running merge sort: " <<endl;
	int mid;
	if(e - b == 1)
		cout << arr[b] << endl << arr[e]<<endl;
	if(b < e)
	{
		mid = (b + e)/2;
		merge_sort(arr, b, mid);
		merge_sort(arr, mid + 1, e);
		merge(arr, b, mid, mid + 1, e);
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
		merge_sort(arr, 0,  num - 1);

	}


}