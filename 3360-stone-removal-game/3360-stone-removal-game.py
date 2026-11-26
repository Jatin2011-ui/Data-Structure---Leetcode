class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        k = int((21 - math.sqrt(441 - 8*n)) // 2)
        return k % 2 == 1 # odd : alice wins
        