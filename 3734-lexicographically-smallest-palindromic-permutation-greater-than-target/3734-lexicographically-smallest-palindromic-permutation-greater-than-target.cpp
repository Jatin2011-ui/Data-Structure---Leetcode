//T.C = O(n)
//S.C = O(n)

class Solution {
public:
    string result = "";
    char midchar = '$';
    int half = 0;
    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater){
        if(i == half){
            string candidate = curr; //left half
            string righthalf = candidate;
            reverse(begin(righthalf), end(righthalf));//right half

            if(midchar != '$')  
                candidate += midchar;//mid character 
            
            candidate += righthalf;
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }
        for(char ch = 'a';ch<='z';ch++){
            if(count[ch-'a'] == 0)
                continue;
            if(!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || ch > target[i];
            if(solve(curr,count, target, i+1, isGreater))
                return true;
            
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26,0);

        for(char ch : s)
            count[ch - 'a']++;

        int oddcount = 0;
        for(int c =0;c<26;c++){
            if(count[c] % 2 == 1){
                oddcount++;
                midchar = c+'a';
            }
        }
        if(oddcount > 1){
            return "";
        }
        //left-half count + middle char (only when n is odd)
        vector<int> halfcount(26,0);
        for(int c=0;c<26;c++){
            halfcount[c] = count[c] / 2;
        }
        half = n / 2;
        string curr;
        solve(curr, halfcount, target, 0, false);
        return result;
    }
};