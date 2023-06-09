// Find the repeating and Missing Number in an array (1 -> N)
// Ex:- {2,4,5,2,1} , N = 5
// Repeating => 2
// Missing => 3

// Brute Force
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,4,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int duplicate = 0;
    int missing = 0;

    for(int i = 1; i <= n; ++i)  // O(n)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j) // O(n)
        {
            if(i == arr[j])
            {
                cnt++;
            }
        }

        if(cnt == 2)
        {
            duplicate = i;
        }

        if(cnt == 0)
        {
            missing = i;
        }
    }

    // T.C => O(n*n) => O(n^2)
    // S.C => O(1)

    cout << duplicate << " " << missing << endl;
    return 0;
}

// Better Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  arr[] = {2,4,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int hsh[n + 1];

    for(int i = 0; i < n; ++i)  // O(n)
    {
        hsh[arr[i]]++;
    }

    int duplicate = 0;
    int missing = 0;

    for(int i = 1; i <= n; ++i) // O(n)
    {
        if(hsh[i] == 2)
        {
            duplicate = i;
        }

        if(hsh[i] == 0)
        {
            missing = i;
        }
    }

    // T.C => O(n) + O(n) => O(2n)
    // S.C => O(n)

    cout << duplicate << " " << missing << endl;

    return 0;
}

// Optimal Approach -> There are 3 different optimized approach
// to solve the problem :- 1) Cyclic Sort, 2) Sum, 3) Xor
// In cyclic sort we have to modify the given array itself , while
// in others 2 method we dont need to modify the given array as well

// Using Cyclic sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,4,5,2,1}; // 4 2 5 2 1 // 2 2 5 4 1 // 2 2 1 4 5 // 1 2 2 4 5
    int n = sizeof(arr)/sizeof(arr[0]);

    int duplicate = 0;
    int missing = 0;

    int i = 0;
    while(i < n) // O(n)
    {
        int correctIndex = arr[i] - 1;
        if(i != correctIndex && arr[correctIndex] != correctIndex + 1)
        {
            swap(arr[i],arr[correctIndex]);
        }else {
            i++;
        }
        
    }

    for(int k = 0; k < n; ++k) // O(n)
    {
        if(arr[k] != k + 1)
        {
            duplicate = arr[k];
            missing = k + 1;
            break;
        }

    }

    // T.C => O(n) + O(n) +> O(2n)
    // S.C => O(1)

    cout << duplicate << " " << missing << endl;
    return 0;
}


// Using sum method
// x -> repeating Number
// y -> Missing Number

// if the array was this -> {2,4,2,5,1}
// For 1st equation
// sn => sum of first n natural Numbers
// s => sum of all elements of the array
// we do sn - s

// (2 + 4 + 2 + 5 + 1) - (1 + 2 + 3 + 4 + 5)
// S - Sn => 2 - 3 => (-1)
// x - y = -1 ------- equn 1

// for 2nd equation
// s2n => sum of sqaure of a number upto n
// s2 => sum of sqaure of array elements

// (2^2 + 4^2 + 2^2 + 5^2 + 1^2) - (1^2 + 2^2 + 3^2 + 4^2 + 5^2)
// (2^2) - (3^2) = -5
// (x^2) - (y^2) = -5
// (x+y)(x-y) = -5
// x+y = -5/-1 => 5  ------- equn 2

// From 2 equations, we have
// x - y = -1
// x + y = 5
// 2x = 4
// x = 2 (duplicate Number)
// Now substituting the value of x in in equn 2
// x + Y = 5 -> 2 + y = 5 => y = 3 (Missing Number)

// Formulas: sn = (n*(n+1))/2
//           s2n = (n*(n+1)(2n+1))/6

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,4,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sn = (n*(n+1))/2;
    int s2n = (n*(n+1)*(2*n+1))/6;

    int s = 0;
    int s2 = 0;

    for(int i = 0; i < n; ++i) // O(n)
    {
        s+=arr[i];
        s2+=arr[i] * arr[i];
    }

    int equ1 = s - sn;
    int equ2 = s2 - s2n;

    equ2 = equ2 / equ1;
    int x = (equ1 + equ2)/2;
    int y = x - equ1;

    int duplicate = x;
    int missing = y;

    // T.C => o(n)
    // S.C => O(1)

    cout << duplicate << " " << missing << endl;
    return 0;
}

// Using XOR Method
// if the array was {2,4,5,2,1}
// x = duplicate number
// y = missing number

// (2^4^5^2^1) ^ (1^2^3^4^5)
// 1^5 = 4
// x^y = 4        1 -> 0 0 1
//                5 -> 1 0 1
//                     1 0 0 (2nd bit is the bit that creates difference)
// our task is to find that the bit that will create the difference from
// rightmost side
// possible values of 2nd bit (0 and 1)
// zero club elements
// zero -> 3 2 1 1 1 2 3 (xor all these elements) => 1
// one club elements
// one -> 4 6 4 5 6 (xor all these elements) => 5
// Now, after finding the zero and one , we last iterate the array 
// and find which is duplicate and missing from these two

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,4,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int xor1 = 0;
    int xor2 = 0;
    int xr = 0;
    int duplicate = 0;
    int missing = 0;
    for(int i = 0; i < n; ++i)  // O(n)
    {
        xor1^=arr[i];
        xor2^=(i+1);
    }

    xr = xor1 ^ xor2;

    int bitNo = 0;
    while(1) // O(n)
    {
        if((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;

    for(int i = 0; i < n; ++i) // O(n)
    {
        if((arr[i] & (1 << bitNo)) != 0)
        {
            one = one ^ arr[i];
        }else {
            zero = zero ^ arr[i];
        }
    }

    for(int i = 1; i <= n; ++i) // O(n)
    {
        if((i & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i) // O(n)
    {
        if(arr[i] == zero)
        {
            cnt++;
        }
    }

    if(cnt == 2)
    {
        duplicate = zero;
        missing = one;
    }else {
        duplicate = one;
        missing = zero;
    }

    // T.C => nearly about O(5n) => O(n)
    // S.C => O(1)

    // slightly better than sum method 

    cout << duplicate << " " << missing << endl;

    return 0;

}