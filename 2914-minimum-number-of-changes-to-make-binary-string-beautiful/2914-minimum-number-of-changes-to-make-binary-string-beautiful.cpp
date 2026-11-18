class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        char curr = s[0];
        int count = 0;
        int changes = 0;

        //Iterate through each character in the string
        for(int i=0;i<n;i++){
            if(s[i] == curr){
                count++;
                continue;
            }
            if(count % 2 == 0){//even
                count = 1;
            }else{//odd
                count = 0;
                changes++;

            }
            curr = s[i];
        }
        return changes;
    }   
};
