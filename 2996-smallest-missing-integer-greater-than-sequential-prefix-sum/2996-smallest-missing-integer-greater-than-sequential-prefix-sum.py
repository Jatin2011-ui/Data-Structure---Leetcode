class Solution(object):
    def missingInteger(self, nums):
        n = len(nums)
        seen = set(nums)
        sum = nums[0]

        for i in range(1,n):
            if nums[i] == nums[i-1] + 1:
                sum += nums[i]
            else:
                break
        
        while sum in seen:
            sum += 1
        return sum
        