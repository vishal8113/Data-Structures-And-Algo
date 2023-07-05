// Median of two sorted arrays

// ex: arr1 = {1,3,4,7,10,12}
// arr2 = {2,3,6,15}

// median = {1,2,3,3,4,6,7,10,12,15}
// ans = (4+6)/2 => 5

// Using Binary Search

// T.C => O(log(min(n,m)))
// S.C => O(1)

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> arr1,vector<int> arr2)
{
    if(arr1.size() > arr2.size())
    {
        return findMedian(arr2,arr1);
    }

    int n = arr1.size();
    int m = arr2.size();

    int start = 0;
    int end = n;

    while(start <= end)
    {
        int cut1 = (start + end) >> 1;
        int cut2 = (n + m + 1)/2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1)
        {
            if((n+m) % 2 == 0)
            {
                return (max(left1,left2) + min(right1,right2))/2.0;
            }else{
                return max(left1,left2);
            }
        } else if(left1 > right2)
        {
            end = cut1 - 1;
        }else{
            start = cut1 + 1;
        }
    }

    return 0.0;
}

int main()
{
    vector<int> arr1 = {1,3,5,7,10,12};
    vector<int> arr2 = {2,3,6,15};

    double ans = findMedian(arr1,arr2);

    cout << ans << endl;
    return 0;
}