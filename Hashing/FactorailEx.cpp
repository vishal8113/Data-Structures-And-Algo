// Given T Test cases and in each test case, a number n, print it's factorial
// for each tes case %m
// where m = 10^9 + 7

// Constraints 
// 1 <= T <= 10^5
// 1 <= N <= 10^5

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int main()
{
    // Precompute the values
    long long fact[N];
    fact[0] = fact[1] = 1;
    
    for(int i = 2; i < N; ++i)
    {
        fact[i] = (fact[i - 1] * i)%M;
    }


    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        // long long fact = 1;
        // for(int i = 1; i <= n; ++i)
        // {
        //     fact = (fact * i)%M;
        // }
        // Directly fetch the values
        cout << fact[n] << endl;
    }
    return 0;
}