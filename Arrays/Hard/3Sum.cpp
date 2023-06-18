// 3 Sum Problem
// arr[i] + arr[j] + arr[k] = 0;
// i != j != k

// Brute Force
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {-1,0,1,2,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    set<vector<int>> s;
    vector<int> temp;

    for(int i = 0; i < n; ++i){  // O(n)
        for(int j = i + 1; j < n; ++j)   // O(n)
        {
            for(int k = j + 1; k < n; ++k)   // O(n)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(),temp.end());
                    s.insert(temp);   // O(logn)
                    temp.clear();
                }
            }
        }
    }

    // T.C => O(n*n*n)
    // S.C => O(no. of triplet) * 2

    for(auto it : s)
    {
        vector<int> triplet = it;
        for(int i = 0; i < 3; ++i)
        {
            cout << triplet[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


// OPtimal Approach

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {-1,0,1,2,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    set<vector<int>> st;
    vector<int> temp;

    for(int i = 0; i < n; ++i)
    {
        set<int> s;
        for(int j = i + 1; j < n; ++j)
        {
            int third = -(arr[i] + arr[j]);
            if(s.find(third) != s.end())
            {
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(third);
                sort(temp.begin(),temp.end());
                st.insert(temp);
                temp.clear();
            }
            s.insert(arr[j]);
        }
    }

    for(auto it : st)
    {
        vector<int> triplet = it;
        for(int i : triplet)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // T.C => O(n*nlogn)
    // S.C => O(n) + O(no. of triplets)
    return 0;
}


// More Optimized Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {-1,0,1,2,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+n);

    vector<int> temp;
    vector<vector<int>> ans;

    for(int i = 0; i < n; ++i)
    {
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0)
            {
                j++;
            }else if(sum > 0){
                k--;
            } else {
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                ans.push_back(temp);
                temp.clear();
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]){
                    j++;
                }
                while(j < k && arr[k] == arr[k+1])
                {
                    k--;
                }
            }
        }
    }

    for(auto i : ans)
    {
        for(auto k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
