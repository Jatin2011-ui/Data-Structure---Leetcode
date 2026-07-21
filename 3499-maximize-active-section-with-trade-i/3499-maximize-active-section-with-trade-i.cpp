class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int activecount = count(begin(s),end(s),'1');

        vector<int> inactiveBlock;
        int i=0;
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0') i++;

                inactiveBlock.push_back(i-start);
            }else{
                i++;
            }
        }  
        
        int maxpairsum = 0;
        for(int i=1;i<inactiveBlock.size();i++){
            maxpairsum = max(maxpairsum, inactiveBlock[i] + inactiveBlock[i-1]);
        }
        return maxpairsum + activecount;
    }
};