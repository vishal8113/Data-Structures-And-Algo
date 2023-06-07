// 1 to N
// 0 1 2 3 4
// 3,5,2,1,4 => index = value - 1
// initially check for first element, if it was at not at correct position, swap 
// it with correct position , else move the pointer ahead
//        0,1,2,3,4
// ans = {1,2,3,4,5};

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,8,1,2,5,7,6,4};
    int n = 8;

    int i = 0;
    while(i < n)
    {
        int correctIndex = arr[i] - 1;
        if(i != correctIndex)
        {
            swap(arr[i],arr[correctIndex]);
        }

        if(i == correctIndex)
        {
            i++;
        }
    }

    for(int k : arr)
    {
        cout << k << " ";
    }
    return 0;
}