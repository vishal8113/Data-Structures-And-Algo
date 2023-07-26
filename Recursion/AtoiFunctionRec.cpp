// Implementation of Atoi function using recursion

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while(index < s.length() && s[index] == ' ')
        {
            index++;
        }

        int sign = 1;
        if(index < s.length() && s[index] == '+' || s[index] == '-'){
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        return recursiveAtoi(s,index,sign,0);
}
private:
    int recursiveAtoi(string &s,int index,int sign,int ans)
    {
        if(index == s.size() || !isdigit(s[index])){
            return ans * sign;
        }
        int digit = s[index] - '0';

        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX%10)){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        return recursiveAtoi(s,index+1,sign,ans);
    }
};