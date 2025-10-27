class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        current = 0 # current layer count of 1s
        last = 0 # last layer count of 1s (layer which contains at least one 1)
        total = 0 # sum to iterate

        for layer in bank: # loop through all the 
            current = layer.count('1') # find amount of 1s in current layer
            if current == 0: continue # if no 1s, skip layer
            if last != 0 and current != 0: total += (last * current) 
            if current != 0: last = current
            current = 0 
        
        return total

        