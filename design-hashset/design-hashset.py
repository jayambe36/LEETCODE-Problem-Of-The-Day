class MyHashSet(object):

    def __init__(self):
        self.data = [False] * 1000001

    def add(self, key):
        self.data[key] = True
        """
        :type key: int
        :rtype: None
        """
        

    def remove(self, key):
        self.data[key] = False
        """
        :type key: int
        :rtype: None
        """
        

    def contains(self, key):
        return self.data[key]
        """
        :type key: int
        :rtype: bool
        """
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)