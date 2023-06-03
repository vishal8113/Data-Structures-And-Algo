// Euclidean Algorithm
// suppose we have two numbers n1,n2
// then, gcd(n1,n2) => gcd(n1-n2,n2), where n1 > n2
// gcd(20,5) => 5
// 20 - 1,2,4,5,10,20
// 5 - 1,5
// gcd(20,5) => gcd(15,5) => gcd(10,5) => gcd(5,5) => gcd(0,5)
// gcd(52%10,10)
// gcd(52,10) => gcd(42,10) => gcd(32,10) => gcd(22,10) =>
// gcd(12,10) => gcd(2,10) => gcd(10,2) => gcd(8,2) => gcd(6,2) => gcd(4,2)
//  => gcd(2,2) => gcd(0,2) => gcd(10%2,2)
// no of steps => 5
// 52/10 -> 2
// 10 * 5 = 50 + 2
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a;
int b;
cin >> a >> b;
while(a > 0 && b > 0)
{
if(a > b)
{
a = a % b;
} else {
b = b % a;
}
}
if(a == 0)
{
cout << b << endl;
} else {
cout << a << endl;
}
}

// Time complexity -> O(log0(min(a,b)))

