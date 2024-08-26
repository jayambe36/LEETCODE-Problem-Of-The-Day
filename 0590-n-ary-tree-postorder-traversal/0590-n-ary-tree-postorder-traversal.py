class Solution:
    def postorder(self, root: 'Node') -> List[int]:  
        return sum((self.postorder(chaild) for chaild in root.children), []) + [root.val] if root else []
