class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        self.comb(candidates,target,0,[],res)
        return res
    def comb(self, candidates, target,index,cand,res):
        if target < 0:
            return
        if target == 0:
            res.append(list(cand))
            return
        for i in range(index,len(candidates)):
            cand.append(candidates[i])
            self.comb(candidates,target-candidates[i],i,cand,res)
            cand.pop()



