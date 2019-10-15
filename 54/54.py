from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        for i in matrix:
            for j in i - 1:
                print (j)

        return list(1,2,3)
l = Solution()
l.spiralOrder(list(list(1,2,3),list(1,2,3),list(1,2,3)))