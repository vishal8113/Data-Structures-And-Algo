// floor and ceil in sorted array
// floor -> largest no in an array <= x
// ceil -> smallest no. in an array >= x

// arr[] = {10,20,25,30,45}

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {
			ans = arr[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1; 
		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = arr[mid];
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main()
{
    int arr[] = {10,20,25,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 25;

    int floor = findFloor(arr,n,x);
    int ceil = findCeil(arr,n,x);

    cout << floor << '\n' << ceil << endl;
    return 0;
}