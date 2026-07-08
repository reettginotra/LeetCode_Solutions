class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        if n1 == 0:
            return 0

        recall = {}
        s1cnt = s2cnt = index = 0

        while True:
            s1cnt += 1

            for c in s1:
                if c == s2[index]:
                    index += 1
                    if index == len(s2):
                        index = 0
                        s2cnt += 1

            if s1cnt == n1:
                return s2cnt // n2

            if index in recall:
                pre_s1cnt, pre_s2cnt = recall[index]

                pre_loop_s2 = pre_s2cnt

                in_loop_s1 = s1cnt - pre_s1cnt
                in_loop_s2 = s2cnt - pre_s2cnt

                ans = pre_loop_s2

                remain = n1 - pre_s1cnt
                ans += (remain // in_loop_s1) * in_loop_s2

                rest = remain % in_loop_s1

                for _ in range(rest):
                    for c in s1:
                        if c == s2[index]:
                            index += 1
                            if index == len(s2):
                                index = 0
                                ans += 1

                return ans // n2

            recall[index] = (s1cnt, s2cnt)