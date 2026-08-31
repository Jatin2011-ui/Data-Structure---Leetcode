class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPos = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while(curr->next != NULL){
            if((curr->val < prev->val && curr->val < curr-> next->val) ||
            (curr->val > prev->val && curr->val > curr->next->val)){
                if(previousCriticalIndex == 0){ 
                    previousCriticalIndex = currPos;
                    firstCriticalIndex = currPos;
                }else{
                    minDist = min(minDist, currPos - previousCriticalIndex);
                    previousCriticalIndex = currPos;
                }
            }
            currPos++;
            prev = curr;
            curr = curr->next;
        }
        if(minDist == INT_MAX){
            return {-1,-1};
        }
        int maxDist = previousCriticalIndex - firstCriticalIndex;
        return {minDist, maxDist};
    }
};