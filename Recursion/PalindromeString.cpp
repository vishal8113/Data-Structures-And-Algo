#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s,int n,int start,int end)
{
    if(start > end)
    {
        return true;
    }
    if(s[start] != s[end]){
        return false;
    }else {
        return isPalindrome(s,n,++start,--end);
    }


}
int main()
{
    string s = "abcba";
    int n = s.size();
    int start = 0;
    int end = n - 1;

    bool ans = isPalindrome(s,n,start,end);
    if(ans)
    {
        cout << "Palindrome" << endl;
    }else {
        cout << "Non Palindrome" << endl;
    }
    return 0;
}