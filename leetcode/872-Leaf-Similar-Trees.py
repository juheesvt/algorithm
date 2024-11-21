# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):    
        self.leaf1 = []
        self.leaf2 = []

    def returnLeaf(self, node, flag) -> int:
        if node is not None:
            if node.left is None and node.right is None:
                self.leaf1.append(node.val) if flag == 1 else self.leaf2.append(node.val)
                    
            self.returnLeaf(node.left, flag)
            self.returnLeaf(node.right, flag)
        
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.returnLeaf(root1, 1)
        self.returnLeaf(root2, 0)

        return True if self.leaf1 == self.leaf2 else False


        