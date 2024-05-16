class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root.val==3:
            return self.evaluateTree(root.left) and self.evaluateTree(root.right)
        elif root.val==2:
            return self.evaluateTree(root.left) or self.evaluateTree(root.right)
        return root.val
