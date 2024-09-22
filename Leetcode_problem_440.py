class Solution(object):
    def findKthNumber(self, n, k):
        curr = 1
        i = 1

        def count(cur):
            res = 0
            nei = cur + 1
            while cur <= n:
                res += min(nei, n+1) - cur
                cur *= 10
                nei *= 10
            return res

        while i < k:
            steps = count(curr)
            if i + steps <= k:
                curr += 1
                i += steps
            else:
                curr *= 10
                i += 1
        return curr
