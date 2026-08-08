class Solution(object):
    def secondHighest(self, s):
        digits = list(set(int(c) for c in s if c.isdigit()))
        if len(digits) < 2:
            return -1
        digits.sort()
        return digits[-2]
        
        """
        arr = list(set(arr))
        arr.sort
        return arr[-2]"""
        