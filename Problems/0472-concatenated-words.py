class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        words.sort(key=len)
        st = set()
        ans = []

        for word in words:
            if not word:
                continue

            n = len(word)
            dp = [False] * (n + 1)
            dp[0] = True

            for i in range(1, n + 1):
                for j in range(i):
                    if dp[j] and word[j:i] in st:
                        dp[i] = True
                        break

            if dp[n]:
                ans.append(word)

            st.add(word)

        return ans