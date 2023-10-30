class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:

        def count_ones(num):
            count = 0
            while num:
                num &= (num - 1)
                count += 1
            return count

        one_list = []
        for n in arr:
            ones = count_ones(n)
            one_list.append((ones, n))

        heapq.heapify(one_list)
        res = []

        while one_list:
            res.append(heapq.heappop(one_list)[1])

        return res        