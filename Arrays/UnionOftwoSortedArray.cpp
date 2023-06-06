// union of two sorted arrays
// arr1[] = {1,1,2,3,4,5}
// arr2[] = {2,3,4,4,5}
// Duplicates was not allowed in union array
// union[] = {1,2,3,4,5}

// Brute Force Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // set<int> s;  // O(n1 + n2)

    int n1;
    cin >> n1;
    int arr1[n1];
    for(int i = 0; i < n1; ++i)  // O(n1logn)
    {
        cin >> arr1[i];
        // s.insert(arr1[i]);
    }

    int n2;
    cin >> n2;
    int arr2[n2];
    for(int i = 0; i < n2; ++i)  // O(n2logn)
    {
        cin >> arr2[i];
        // s.insert(arr2[i]);
    }

    // int uni[s.size()];  // O(n1 + n2) (In order to solve the problem(returning an answer)) 

    // int i = 0;
    // for(auto it : s)   // O(n1 + n2)
    // {
    //     uni[i] = it;
    //     i++;
    // }

    // T.C = O(n1logn) + O(n2logn) + O(n1 + n2)
    // s.C = O(n1 + n2) + O(n1 + n2)

    // Optimized Approach

    vector<int> uni;
    int i = 0;
    int j = 0;

    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j]){
            if(uni.size() == 0 || uni.back() != arr1[i]){
                uni.push_back(arr1[i]);
            }
            i++;
        } else {
            if(uni.size() == 0 || uni.back() != arr2[j]){
                uni.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j < n2)
    {
        if(uni.size() == 0 || uni.back() != arr2[j])
        {
            uni.push_back(arr2[j]);
        }
        j++;
    }

    while(i < n1)
    {
        if(uni.size() == 0 || uni.back() != arr1[i])
        {
            uni.push_back(arr1[i]);
        }
        i++;
    }

    // T.C => O(n1 + n2)
    // S.C => O(n1 + n2) (returning an answer)

    for(int ele : uni)
    {
        cout << ele << " ";
    }

    return 0;
}