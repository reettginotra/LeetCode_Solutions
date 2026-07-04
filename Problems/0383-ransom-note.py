class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        cnt = [0] * 26

        for c in magazine:
            cnt[ord(c) - 97] += 1

        for c in ransomNote:
            idx = ord(c) - 97
            cnt[idx] -= 1
            if cnt[idx] < 0:
                return False

        return True