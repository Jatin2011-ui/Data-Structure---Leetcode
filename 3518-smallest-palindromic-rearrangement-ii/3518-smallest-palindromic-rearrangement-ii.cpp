class Solution {
public:
    long long nCr(int n,int r, int k){
        //nCr == nC(n-r)
        //5C3 = 5C2
        //5C2 = 5C(5-2) = 5C3
        r = min(r,n-r); // nCr == nC(n-r)
        long long result = 1;
        for(int i=1;i<=r;i++){
            result = result * (n-r+i)/i;

            if(result >= k)
                return k;   
        } 
        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2 == 1){//odd lenght
            mid = s[n/2];
        }

        vector<int> count(26,0);
        for(int i=0;i<n;i++){
            if(n%2 == 1 && i == n/2) continue;
            count[s[i] - 'a']++;
        }

        for(int i=0;i<26;i++){
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i=0;i<half;i++){
            bool placecharacter = false;
            for(int j=0;j<26;j++){
                if(count[j] > 0){
                    count[j] -= 1;

                    // count number of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c=0;c<26;c++){
                        letters += count[c]; 
                    }
                    for(int c=0;c<26;c++){
                        if(count[c] > 0){
                            ways *= nCr(letters, count[c],k); //log2(k)
                            letters -= count[c];
                        }
                        if(ways >= k){
                            break;
                        }
                    }
                    if(ways >= k){
                        halfResult.push_back(j + 'a' );
                        placecharacter = true;
                        break;
                    }
                    k -= ways;
                    count[j] += 1;
                }
            }
            if(placecharacter == false)
                return "";
        }
       string rev = halfResult;
       reverse(begin(rev),end(rev));

       if(mid != ' '){
        halfResult.push_back(mid);
       }
       return halfResult + rev;
    }
};