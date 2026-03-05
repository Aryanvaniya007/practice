class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        
        # Pattern 1: starts with '0'
        count1 = 0
        for i in range(n):
            expected = '0' if i % 2 == 0 else '1'
            if s[i] != expected:
                count1 += 1
        
        # Pattern 2: starts with '1'
        count2 = 0
        for i in range(n):
            expected = '1' if i % 2 == 0 else '0'
            if s[i] != expected:
                count2 += 1
        
        # Minimum operations needed
        return min(count1, count2)