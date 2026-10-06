class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = 0
        open = 0
        for ch in s:
            if ch == '(':
                size += 1
            elif size>0:
                size -= 1
            else:
                open += 1
        return open+size
        