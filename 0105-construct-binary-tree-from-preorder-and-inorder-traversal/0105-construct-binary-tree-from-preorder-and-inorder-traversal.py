# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        inorder_map = {val:idx for idx, val in enumerate(inorder)}
        self.pre_idx = 0

        def solve(start,end):
            if start>end:
                return None
            
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1
            root = TreeNode(root_val)

            mid = inorder_map[root_val]

            root.left = solve(start,mid-1)
            root.right = solve(mid+1,end)

            return root
        return solve(0,len(inorder)-1)



        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """
        