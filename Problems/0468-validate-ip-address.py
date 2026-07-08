class Solution(object):
    def validIPAddress(self, queryIP):
        if '.' in queryIP:
            parts = queryIP.split('.')

            if len(parts) != 4:
                return "Neither"

            for p in parts:
                if not p or len(p) > 3:
                    return "Neither"

                if len(p) > 1 and p[0] == '0':
                    return "Neither"

                num = 0
                for c in p:
                    if c < '0' or c > '9':
                        return "Neither"
                    num = num * 10 + ord(c) - 48

                if num > 255:
                    return "Neither"

            return "IPv4"

        if ':' in queryIP:
            parts = queryIP.split(':')

            if len(parts) != 8:
                return "Neither"

            for p in parts:
                if len(p) == 0 or len(p) > 4:
                    return "Neither"

                for c in p:
                    if not ('0' <= c <= '9' or
                            'a' <= c <= 'f' or
                            'A' <= c <= 'F'):
                        return "Neither"

            return "IPv6"

        return "Neither"