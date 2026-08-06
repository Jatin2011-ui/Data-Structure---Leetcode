class Solution {
public:
    int digitproduct(int num){
        int product = 1;

        while(num>0){
            product *= (num%10);
             num /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitproduct(n) % t == 0){
                return n;
            }
            n++;
        }
    }
};