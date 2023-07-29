#include<bits/stdc++.h>
using namespace std;

void sequenceSum(int index,vector<int> &ds,int s,int sum,int arr[],int n)
{
    // Base case
    if(index == n)
    {
        if(s == sum){
            for(auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }

        return;
    }

    ds.push_back(arr[index]);
    s += arr[index];

    sequenceSum(index+1,ds,s,sum,arr,n);

    ds.pop_back();
    s -= arr[index];

    sequenceSum(index+1,ds,s,sum,arr,n);
}

int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    sequenceSum(0,ds,0,sum,arr,n);

    // T.C => O(2^N)
    // S.C => O(N)
    return 0;
}