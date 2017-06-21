class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        self.combinationSum3_1(k,n,0,[],res)
        return res

    def combinationSum3_1(self, k, n, low, arr, res):
        if k == 1:
            if (n > low and n <= 9):
                arr.append(n)
                res.append(list(arr))
                arr.pop()
        else:
            for i in range(low+1,10):
                arr.append(i)
                self.combinationSum3_1(k-1,n-i,i,arr,res)
                arr.pop()
        return    

