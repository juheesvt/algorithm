# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def returnLeef(self, node: TreeNode, depth: int) -> int:
        if node is None:
            return depth
        
        if node.left is None and node.right is None:
            return depth

        left_depth = right_depth = depth
        if node.left:
            left_depth = self.returnLeef(node.left, depth + 1)
        if node.right:
            right_depth = self.returnLeef(node.right, depth + 1)
        
        return max(left_depth, right_depth)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0 
        return self.returnLeef(root, 1)


        
        