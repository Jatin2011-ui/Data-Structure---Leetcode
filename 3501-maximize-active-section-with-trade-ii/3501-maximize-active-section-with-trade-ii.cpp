void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]){
    if(l==r){
        segmentTree[i] = arr[l];
        return ;
    }
    int mid = l+(r-l) / 2;
    buildSegmentTree(2*i+1,l,mid,segmentTree,arr);
    buildSegmentTree(2*i+2,mid+1,r,segmentTree,arr);
    segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);

}

int* constructST(int arr[], int n){
    int* segmentTree = new int[4*n];
    buildSegmentTree(0,0,n-1,segmentTree,arr);
    return segmentTree;
}
int querySegmentTree(int start, int end, int i, int l, int r,int segmentTree[]){
    if(l > end || r < start){
        return INT_MIN;
    }
    if(l>=start && r<= end){
        return segmentTree[i];
    }

    int mid = l+(r-l) / 2;
    return max(querySegmentTree(start,end,2*i+1,l,mid,segmentTree),
                querySegmentTree(start,end, 2*i+2, mid+1,r, segmentTree));
}
int RMQ(int st[], int n , int a, int b){
    return querySegmentTree(a,b,0,0,n-1,st);
}


class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activecount = count(begin(s),end(s),'1');

        vector<int> blockstart;
        vector<int> blockend;
        int i = 0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i] == '0') i++;
                blockstart.push_back(start);
                blockend.push_back(i-1);
            }
            else {
                i++;
            }
        }
        int m = blockstart.size();
        if(m < 2){
            return vector<int>(queries.size(),activecount);
        }
        vector<int>blocksize(m);
        for(int i=0;i<m;i++){
            blocksize[i] = blockend[i] - blockstart[i] + 1;
        }
        int N = blocksize.size()-1;
        vector<int> pairSum(N);
        for(int i=0;i<N;i++){
            pairSum[i] = blocksize[i] + blocksize[i+1];
        }
        int *st = constructST(pairSum.data(),N);

        vector<int> result;
        for(auto &q:queries){
            int l =q[0];
            int r = q[1];
            
            int low = lower_bound(begin(blockend),end(blockend),l) - begin(blockend);
            int high = upper_bound(begin(blockstart),end(blockstart),r) - begin(blockstart) - 1;

            int maxPairSum = 0;
            if(low < high){
                int firstlen = blockend[low] - max(blockstart[low], l) + 1;
                int lastlen = min(blockend[high],r) - blockstart[high] + 1;

                if(high - low ==1){
                    maxPairSum = firstlen + lastlen;
                }else{
                    int pair1 = firstlen + blocksize[low+1];
                    int pair2 = blocksize[high-1] + lastlen;
                    int RMQMaxPairSum = RMQ(st,N,low+1,high-2);
                    maxPairSum = max({pair1,pair2,RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + activecount);
        }
        return result;
    }
};