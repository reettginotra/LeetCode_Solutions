class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        rem = 0

        for b in data:
            if rem == 0:
                if b >> 7 == 0:
                    continue
                elif b >> 5 == 0b110:
                    rem = 1
                elif b >> 4 == 0b1110:
                    rem = 2
                elif b >> 3 == 0b11110:
                    rem = 3
                else:
                    return False
            else:
                if b >> 6 != 0b10:
                    return False
                rem -= 1

        return rem == 0