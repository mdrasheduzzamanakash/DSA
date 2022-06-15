# Author: LC/wz2326
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for i in range(n + 1)]
        dp[0].append("")
        for i in range(1, n + 1):
            for j in range(i):
                dp[i] += ["(" + x + ")" + y for x in dp[j] for y in dp[i - j - 1]]
        return dp[n]
