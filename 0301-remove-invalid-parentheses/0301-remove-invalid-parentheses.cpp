class Solution {
private:
    unordered_set<string> st;
    int n;

    void solve(string& s, int i, string& curr, int count , int& maxlen){
        if(count < 0){
            return;
        }
        if(i == n){
            if(count == 0){
                if(curr.length() > maxlen){
                    maxlen = curr.length();
                    st.clear();
                }
                if(curr.length() == maxlen ){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s, i+1, curr, count , maxlen);
            curr.pop_back();
            return;
        }
        //do
        curr.push_back(s[i]);

        //explore
        solve(s, i+1, curr, count + (s[i] == '(' ? 1 : -1 ), maxlen );

        //undo & explore
        curr.pop_back();
        solve(s, i+1, curr, count , maxlen);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int maxlen = 0;
        string curr = "";
        solve(s,0,curr, 0, maxlen);

        return vector<string>(begin(st),end(st));

    }
};