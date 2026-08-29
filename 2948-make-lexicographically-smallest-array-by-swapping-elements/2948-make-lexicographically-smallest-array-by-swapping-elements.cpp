class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(begin(vec),end(vec));

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> grouptoList;
        grouptoList[groupNum].push_back(vec[0]);//O(n)

        for(int i=1;i<n;i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNum += 1;
            }
            numToGroup[vec[i]] = groupNum;
            grouptoList[groupNum].push_back(vec[i]);
        } 
        //build the merge groups
        vector<int> result(n);
        for(int i= 0;i<n;i++){
            int num = nums[i];
            int group = numToGroup[num];

            result[i] = *grouptoList[group].begin();
            grouptoList[group].pop_front();
        }
        return result;
    }
};