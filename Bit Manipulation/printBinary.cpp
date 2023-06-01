#include<bits/stdc++.h>
using namespace std;
// function for printing the binary numbers
void printBinary(int n)
{
    for(int i = 31; i >= 0; --i)
    {
        cout << ((n >> i) & 1);
    }
}
int main()
{
    printBinary(9);
    return 0;
}
