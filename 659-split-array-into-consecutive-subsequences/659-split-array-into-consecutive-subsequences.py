class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        occur,last=defaultdict(int),defaultdict(int)
        for num in nums:
            occur[num]+=1
        for num in nums:
            if occur[num]==0:
                continue
            elif last[num]>0:
                last[num]-=1
                last[num+1]+=1
            elif occur[num+1] and occur[num+2]:
                occur[num+1]-=1
                occur[num+2]-=1
                last[num+3]+=1
            else:
                return False
            occur[num]-=1
        return True