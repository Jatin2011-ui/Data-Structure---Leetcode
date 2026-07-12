class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        unique_sorted = sorted(set(arr))
        ranks = {ele:rank for rank, ele in enumerate(unique_sorted,1)}

        return [ranks[ele] for ele in arr]
        