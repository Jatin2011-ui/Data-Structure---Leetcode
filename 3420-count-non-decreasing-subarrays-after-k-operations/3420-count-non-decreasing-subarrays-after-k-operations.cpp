class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> cumsum(n);
        cumsum[0] = nums[0];
        for(int i=1;i<n;i++){
            cumsum[i] = nums[i] + cumsum[i-1];
        }

        //range sum
        auto rangesum = [&](int i, int j) -> long long{
            if(i > j)
                return 0;
            
            return cumsum[j] - ((i > 0) ? cumsum[i-1] : 0);
        };

        //NGR[i] = n
        vector<int> NGR(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                NGR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        //operation[i] = total operns to make [i....n-1] non - decreasing 
        vector<ll> operations(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int m = NGR[i];

            // i to segemnt 
            ll segementoperns = (1LL * nums[i] * (m-i)) - rangesum (i,m-1);
            operations[i] = segementoperns + operations[m];
        }

        //ready for sliding window maximum
        deque<int> deq;
        ll result = 0;
        int i=0;
        int j=0;

        while(j<n){
            while(!deq.empty() && nums[deq.back()] < nums[j]){//decreasing order maintained - monotonic ds
                deq.pop_back();
            }
            deq.push_back(j);

            //shrink if required 
            while(i <= j){
                int m = deq.front();// fayda hain sliding window maximum

                //i..........j
                ll opernscount  = (operations[i] - operations[m]) + (1LL * nums[m] * (j-m+1)) - rangesum(m,j);

                if(opernscount <= k)
                    break;
                
                i++;
                if(deq.front() < i){
                    deq.pop_front();
                }
            }
            result += (j-i+1);
            j++;
        }
        return result;
    }
};