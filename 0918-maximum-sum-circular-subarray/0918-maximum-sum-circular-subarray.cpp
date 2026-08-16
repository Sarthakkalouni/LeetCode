class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int maxSum = nums[0];
        int curMax = 0;

        int minSum = nums[0];
        int curMin = 0;

        for (int x : nums) {

            // Kadane for maximum subarray
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // Kadane for minimum subarray
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);

            total += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        // Normal vs circular
        return max(maxSum, total - minSum);
    }
};