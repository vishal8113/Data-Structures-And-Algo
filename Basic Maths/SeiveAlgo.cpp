// sieve of eratosthenes algorithm
// Find 1 to 30 prime Number
// 1(cross) 2 3 4* 5 6* 7 8* 9* 10*
// 11 12* 13 14* 15* 16* 17 18* 19 20*
// 21* 22* 23 24* 25* 26* 27* 28* 29 30*
// First step -> assume all numbers as a prime number

#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
// precompute the values till 10^7
int main()
{
// step 1 -> Assume all numbers are prime numbers    
vector<bool> isPrime(N,1);
// step 2 -> mark 0 and 1 as non prime number
isPrime[0] = isPrime[1] = false;
for(int i = 2; i < N; ++i)
{
if(isPrime[i] == true)
{
// mark all multiples of prime number as non prime    
for(int j = 2 * i; j < N; j+=i){
isPrime[j] = false;
}
}
}

// Run the algorithm for q queries
int q;
cin >> q;
while(q--)
{
int n;
cin >> n;
if(isPrime[n] == true)
{
cout << "prime" << endl;
} else {
cout << "Not Prime" << endl;
}
}
}

// Time complexity -> O(n(log log n)) (we can prove using taylor series)
// Inner loop -> n/2 + n/3 + n/4 + n/5 ------ + n/n
// n(1/2 + 1/3 + 1/4 + 1/5 + ------ + 1/n) (hp series) -> n(log n)
// when we include if condition(n/2 + n/3 + n/5 + n/7 + -----) = n(log log n)