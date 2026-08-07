class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 1;

        while (mask <= (unsigned int)num)
            mask <<= 1;

        mask--;

        return num ^ mask;
    }
};