class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum = 0
        for i, char in enumerate(s):
            sum += (i+1)*(26-(ord(char) - ord('a')))
        return sum
        