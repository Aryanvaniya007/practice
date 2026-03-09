class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7

        # dp0[i][j] = number of arrays ending with 0 using i zeros and j ones
        # dp1[i][j] = number of arrays ending with 1 using i zeros and j ones
        dp0 = [[0] * (one + 1) for _ in range(zero + 1)]
        dp1 = [[0] * (one + 1) for _ in range(zero + 1)]

        # Base cases: arrays starting with blocks of 0s or 1s
        for k in range(1, min(limit, zero) + 1):
            dp0[k][0] = 1
        for k in range(1, min(limit, one) + 1):
            dp1[0][k] = 1

        for i in range(zero + 1):
            for j in range(one + 1):
                # Extend with zeros (switch from ending with 1)
                if dp1[i][j]:
                    for k in range(1, min(limit, zero - i) + 1):
                        dp0[i + k][j] = (dp0[i + k][j] + dp1[i][j]) % MOD

                # Extend with ones (switch from ending with 0)
                if dp0[i][j]:
                    for k in range(1, min(limit, one - j) + 1):
                        dp1[i][j + k] = (dp1[i][j + k] + dp0[i][j]) % MOD

        return (dp0[zero][one] + dp1[zero][one]) % MOD