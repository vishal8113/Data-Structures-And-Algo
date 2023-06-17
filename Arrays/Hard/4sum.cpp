// 4 Sum Problem
// arr[i] + arr[j] + arr[k] + arr[l] = target
// i != j != k != l

// Brute Force Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,0,-1,0,-2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 0;

    set<vector<int>> s;

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                for(int l = k + 1; l < n; ++l)
                {
                    int sum = arr[i] + arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum == target)
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        temp.push_back(arr[l]);
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }

    for(auto i : s)
    {
        vector<int> quadruplet = i;
        for(auto k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {1,0,-1,0,-2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 0;

    set<vector<int>> s;
    vector<int> temp;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; ++j)
        {
            set<int> st;
            for(int k = j + 1; k < n; ++k)
            {
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                if(st.find(fourth) != st.end()){
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    temp.push_back(fourth);
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                    temp.clear();
                }

                st.insert(arr[k]);
            }
        }
    }

    for(auto it : s)
    {
        vector<int> ans = it;
        for(int k : ans)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}

// More Optimized Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,0,-1,0,-2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+n);

    int target = 0;
    vector<int> temp;
    vector<vector<int>> ans;

    for(int i = 0; i < n; ++i)
    {
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }
        for(int j = i + 1; j < n; ++j)
        {
            if(j != i + 1 && arr[j] == arr[j-1]){
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while(k < l)
            {
                int sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];

                if(sum == target)
                {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    temp.push_back(arr[l]);
                    ans.push_back(temp);
                    temp.clear();
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1])
                    {
                        k++;
                    }
                    while(k < l && arr[l] == arr[l+1]){
                        l--;
                    }
                } else if(sum < target)
                {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    for(auto k : ans)
    {
        for(auto i : k)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}