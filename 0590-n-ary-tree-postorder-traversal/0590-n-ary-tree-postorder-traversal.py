class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        path = []
        for chaild in root.children:
            path += self.postorder(chaild)
        path.append(root.val)
        return path
