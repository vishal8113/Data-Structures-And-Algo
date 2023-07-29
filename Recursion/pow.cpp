// pow(x,n) using binary exponential (recusrion)

#include<bits/stdc++.h>
using namespace std;

int power(int x,int n,int ans)
{
    if(n == 0)
    {
        return ans;
    }
    if(n % 2 == 0)
    {
        return power(x*x,n/2,ans);
    }else{
        return power(x,n-1,x*ans);
    }
}

int main()
{
    int x;
    int n;
    cin >> x >> n;
    if(n < 0)
    {
        n = n * -1;
        double res = power(x,n,1);
        cout << (double)1/res << endl;
    }else{
        int res = power(x,n,1);
        cout << res << endl;
    }

    // T.C => log(2)n
    // S.C => O(1)
}
