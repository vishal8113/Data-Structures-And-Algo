#include<bits/stdc++.h>
using namespace std;
int zeroesCount(int n,int count)
{
    if(n == 0)
    {
        return count;
    }
    if(n % 10 == 0)
    {
        count++;
    }

    return zeroesCount(n/10,count);
}
int main()
{
    cout << zeroesCount(12001001,0);
    return 0;
}