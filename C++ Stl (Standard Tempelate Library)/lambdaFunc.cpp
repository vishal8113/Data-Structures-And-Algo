// Lambda Functions are short and temporary finctions

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Syntax
    // [](parameter datatype){operation}(parameter);

    // cout << [](int x){return x + 2;}(2) << endl;

    // Assigning lambda function to a variable
    auto sum;
    sum = [](int x,int y){return x + y;}(10,5);
    cout << sum << endl;
    return 0;
}
