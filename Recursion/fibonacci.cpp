#include<bits/stdc++.h>
using namespace std;
int fiboTerm(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return fiboTerm(n-1) + fiboTerm(n-2);
}
int main()
{
    int n;
    cin >> n;

    cout << fiboTerm(n);
    return 0;
}