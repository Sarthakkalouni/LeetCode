class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        // n should be power of 2 and the only set bit should be at even position
        return (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};