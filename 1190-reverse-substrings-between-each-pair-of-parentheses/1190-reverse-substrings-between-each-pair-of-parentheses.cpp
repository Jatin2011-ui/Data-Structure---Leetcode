class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkip;
        string result;
        for(char currentChar:s){
            if(currentChar == '('){
                lastSkip.push(result.length());
            }else if(currentChar == ')'){
                int start = lastSkip.top();
                lastSkip.pop();
                reverse(result.begin() + start, result.end());
            }else{
                result += currentChar;
            }
        }
        return result;
    }
};