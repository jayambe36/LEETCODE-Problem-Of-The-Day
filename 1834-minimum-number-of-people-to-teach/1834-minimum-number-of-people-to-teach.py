class Solution:
    def minimumTeachings(self, n, languages, friendships):
                                                            # Example:
        l = list(map(set,languages))                        #  friendships = [[1,4],[1,2],[3,4],[2,3]]
                                                            #    languages = [[2]  ,[1,3],[1,2],[1,3]]
        users = set(chain(*((i-1,j-1) for i,j in 
                       friendships if not l[i-1]&l[j-1])))  #  users = {0,1,3} <- zero-indexed

        if not users: return 0

        ctr = Counter(chain(*[languages[i] for i in users])) #  ctr = {1:2, 3:2, 2:1}
        
        return len(users) - max(ctr.values())                #  return len({0,1,3}) - max(2,2,1) = 3 - 2 = 1