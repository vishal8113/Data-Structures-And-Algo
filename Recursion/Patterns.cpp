// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

#include<bits/stdc++.h>
using namespace std;
void pattern(int n)
{
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }
    cout << endl;

    pattern(n-1);

    for(int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    pattern(5);
    return 0;
}

// 1
// 1 2 
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1 
// 1 2 3 4 5 
// 1 2 3 4
// 1 2 3
// 1 2 
// 1

