class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
                int firstCriticalIndex = 0;
                int previousCriticalIndex = 0;

                int prevVal = 0;
                int currVal = 0;
                int nextVal = 0;

                int minDist = INT_MAX;
                int index = 0;
                vector<int> result = {-1,-1};

                while(head != NULL){
                    prevVal = currVal;
                    currVal = nextVal;
                    nextVal = head->val;

                    if(prevVal != 0 && currVal != 0 && nextVal != 0 && 
                    (prevVal > currVal && currVal < nextVal || 
                    prevVal < currVal && currVal > nextVal)){
                        if(firstCriticalIndex == 0){
                            firstCriticalIndex = index;
                        }else{
                            minDist = min(minDist, index - previousCriticalIndex);
                            result = {minDist, index - firstCriticalIndex};
                        }
                        previousCriticalIndex = index;
                    }
                    index++;
                    head = head->next;
                }
                return result;
    }
};