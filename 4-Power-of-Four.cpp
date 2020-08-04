class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
};
//(num-1) % 3 condition is used to distinguish multiples of 2 from multiples of 4