class Solution {
public:
    bool isPalindrome(long long n) {
        
        long long original = n, rev=0;
        if(n<0) return false;
        while(n>0){
            rev  = rev*10 + n % 10 ;
            n /= 10;
        }
        return original == rev;
        
    }
};