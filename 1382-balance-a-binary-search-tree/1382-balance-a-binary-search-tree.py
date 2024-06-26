class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def rotateLeft(x: TreeNode, p: TreeNode) -> TreeNode:
            y = x.right
            x.right = y.left
            y.left = x
            
            if p.left == x:
                p.left = y
            else:
                p.right = y
            
            return y
            
        def rotateRight(x: TreeNode, p: TreeNode) -> TreeNode:
            y = x.left
            x.left = y.right       
            y.right = x
            
            if p.left == x:
                p.left = y
            else:
                p.right = y
            
            return y
        
        def getHeight(node: TreeNode) -> int:
            if not node:
                return 0
            
            return max(getHeight(node.left), getHeight(node.right)) + 1
        
        def recBalance(node: TreeNode, p: TreeNode) -> tuple:
            if not node:
                return 0,0
            
            left_height, left_balance = recBalance(node.left, node)
            right_height, right_balance = recBalance(node.right, node)        
            
            node_balance = left_height - right_height
            
            if node_balance > 1:
                if left_balance < 0:
                    rotateLeft(node.left, node)
                return recBalance(rotateRight(node, p), p)
            elif node_balance < -1:
                if right_balance > 0:
                    rotateRight(node.right, node)
                return recBalance(rotateLeft(node, p), p)
            else:
                left_height, right_height = getHeight(node.left), getHeight(node.right)
                return max(left_height, right_height) + 1, left_height - right_height
    
        dummy = TreeNode(None)
        dummy.right = root
        recBalance(dummy.right, dummy)
        return dummy.right
