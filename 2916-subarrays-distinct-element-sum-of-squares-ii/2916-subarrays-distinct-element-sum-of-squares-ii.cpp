class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int n;
    vector<ll> sqsumseqTree;
    vector<ll> sumseqTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r, ll val ){
        ll len = (r-l+1);

       sqsumseqTree[i] = (sqsumseqTree[i] + 2 * val * sumseqTree[i] % MOD + len * val % MOD * val) % MOD;
        sumseqTree[i] = (sumseqTree[i] + len * val) % MOD;
    }

    void updateRange(int start, int end, int i, int l, int r, ll val){
        if(lazyTree[i] != 0){
            lazyAddition(i,l,r,lazyTree[i]);
            
            if(l != r){
              lazyTree[2*i+1] = (lazyTree[2*i+1] + lazyTree[i]) % MOD;
              lazyTree[2*i+2] = (lazyTree[2*i+2] + lazyTree[i]) % MOD;
          }     
            lazyTree[i] = 0;
        }
        //out of range
        if(l > end || r < start || l > r){
            return;
        }
        // Completely within range
      if(l >= start && r <= end){
          lazyAddition(i, l, r, val);

          if(l != r){
              lazyTree[2*i+1] = (lazyTree[2*i+1] + val) % MOD;
              lazyTree[2*i+2] = (lazyTree[2*i+2] + val) % MOD;
          }
          return;
      }

      // Partial overlap: recurse on children
      int mid = l + (r - l) / 2;
      updateRange(start, end, 2*i+1, l, mid, val);
      updateRange(start, end, 2*i+2, mid+1, r, val);

      // Merge children results
      sumseqTree[i] = (sumseqTree[2*i+1] + sumseqTree[2*i+2]) % MOD;
      sqsumseqTree[i] = (sqsumseqTree[2*i+1] + sqsumseqTree[2*i+2]) % MOD;
            
        }
    
    
    int sumCounts(vector<int>& nums) {
        n  = nums.size();
        sqsumseqTree.assign(4*n, 0);
        sumseqTree.assign(4*n,0);
        lazyTree.assign(4*n, 0);

        vector<int> lastseenIdx(100005,-1);
        ll result = 0;
        for(int i=0;i<n;i++){
            int start = lastseenIdx[nums[i]]+1;
            int end = i;

            updateRange(start,end,0,0,n-1,1);
            result = (result+sqsumseqTree[0]) % MOD;

            lastseenIdx[nums[i]] = i;
        }
        return result;
    }
};