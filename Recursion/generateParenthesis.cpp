// Generate parenthesis (Recursive)

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void generate(string &s,int open,int close)
{
    if(open == 0 && close == 0)
    {
        ans.push_back(s);
        return;
    }
    if(open > 0)
    {
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
    }

    if(close > 0)
    {
        if(open < close)
        {
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }
    }
}

int main()
{
    string s;
    generate(s,2,2);
    for(auto ele : ans)
    {
        cout << ele << endl;
    }
    return 0;
}
