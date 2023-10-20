class NestedIterator:
    array=[]
    index=-1
    
    def __init__(self, nestedList: [NestedInteger]):
        def f(nestedList):
            for L in nestedList:
                if L.isInteger(): self.array.append(L.getInteger())
                else: f(L.getList())
        self.array.clear()
        f(nestedList)
        self.index=0
    
    def next(self) -> int:
        self.index+=1
        return self.array[self.index-1]
    
    def hasNext(self) -> bool:
        return self.index<len(self.array)