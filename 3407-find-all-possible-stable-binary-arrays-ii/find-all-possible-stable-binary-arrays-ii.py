class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7
        
        # dp[i][j][0] = stable arrays with i zeros, j ones, ending in 0
        # dp[i][j][1] = stable arrays with i zeros, j ones, ending in 1
        dp = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        
        # Base cases: arrays of all zeros or all ones (valid only if <= limit)
        for i in range(1, min(limit, zero) + 1):
            dp[i][0][0] = 1
        for j in range(1, min(limit, one) + 1):
            dp[0][j][1] = 1
        
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                # Place a 0: previous state had (i-1) zeros, j ones
                # Sum of both endings from (i-1, j)
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD
                
                # Subtract invalid: run of (limit+1) zeros
                # The element before these limit+1 zeros must be a 1
                # That state is dp[i-limit-1][j][1]
                if i > limit:
                    dp[i][j][0] = (dp[i][j][0] - dp[i-limit-1][j][1]) % MOD
                
                # Place a 1: previous state had i zeros, (j-1) ones
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD
                
                # Subtract invalid: run of (limit+1) ones
                if j > limit:
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-limit-1][0]) % MOD
        
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD