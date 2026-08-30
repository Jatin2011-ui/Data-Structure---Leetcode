class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        min_Idx = nums.index(min(nums))
        max_Idx = nums.index(max(nums))

        left = min(min_Idx,max_Idx)
        right = max(min_Idx,max_Idx)


        return min(left+1+n-right, right+1, n-left)