class Solution {
public:
    typedef long long ll;
    ll countSmaller(ll mid, vector<int>& coins){
        ll correctedcoins = 0;
        ll n = coins.size();

        //2^n * n * log(maxcoin)
        for(int exp=1; exp <= pow(2,n)-1;exp++){//2^n-1 expression
            ll lcm = 0;
            ll order = 0;//even or odd order of expression
            for(int i=0;i<n;i++){
                if(exp & (1 << i)){
                    order++;//we have taken ith coin
                    
                    if(lcm == 0){
                        lcm = coins[i];
                    }else{
                        lcm = lcm* coins[i] / gcd(lcm,coins[i]);
                    }
                }
            }

            if(order % 2 == 0){ //even then substract
                correctedcoins -= mid/lcm;
            }else{
                correctedcoins += mid/lcm;
            }
        }
        return correctedcoins;

    }
    ll findKthSmallest(vector<int>& coins, int k) {
       ll result = -1;
       ll l = 0;
       ll r = (ll)(*max_element(begin(coins),end(coins))) * k;

        //log(maxCoin * k) * 2^n * n * log(maxCoin) 
       while(l<=r){
        ll mid = l + (r-l) / 2;
        if(countSmaller(mid,coins) >= k){//left side we can find kth smallest element 
            result = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
       } 
       return result;
    }
};