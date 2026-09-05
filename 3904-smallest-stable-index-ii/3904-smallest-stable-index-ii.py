class Solution(object):
    def firstStableIndex(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)

        minFromIndex = [0] * n
        minEl = float("inf")

        for i in range(n-1,-1,-1):
            minEl = min(minEl, nums[i])
            minFromIndex[i] = minEl
        
        maxEl = float("-inf")
        for i in range(n):
            maxEl = max(maxEl, nums[i])

            if maxEl - minFromIndex[i] <= k:
                return i

        return -1