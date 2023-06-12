#include<bits/stdc++.h>
using namespace std;
int printMaximum(int* arr,int n,int i)
{
	if(i == n-1)
	{
		return arr[i];
	}

	return max(arr[i],printMaximum(arr,n,i+1));
}
int main()
{
	int arr[] = {25,12,78,56,11};
	int n = 5;

	int ans = printMaximum(arr,n,0);
	cout << ans << endl;
	return 0;
}