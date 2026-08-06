class Solution(object):
    def moveZeroes(self, nums):
        write = 0
        for i in nums:
            if i != 0:
                nums[write] = i
                write += 1
        while write < len(nums):
            nums[write] = 0
            write += 1
