# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        result = []

        def pre_order(node,level):
            if not node:
                return
            
            if len(result) < level:
                result.append(node.val)
            
            pre_order(node.right,level+1)
            pre_order(node.left,level+1)
        
        pre_order(root,1)
        return result
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        