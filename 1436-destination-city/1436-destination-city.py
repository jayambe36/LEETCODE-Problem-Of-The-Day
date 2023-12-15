class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        outgoing = set()
        incoming = set()
        for u,v in paths:
            outgoing.add(u)
            incoming.add(v)

        for u in incoming:
            if u not in outgoing:
                return u
