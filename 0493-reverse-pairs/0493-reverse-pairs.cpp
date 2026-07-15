class Solution {
public:
    int ans = 0;

    void merge(vector<int>& a, int l, int m, int r) {
        int leftSize = m - l + 1;
        int rightSize = r - m;

        vector<int> left(leftSize), right(rightSize);

        // Copy left half
        for (int i = 0; i < leftSize; i++) {
            left[i] = a[l + i];
        }

        // Copy right half
        for (int i = 0; i < rightSize; i++) {
            right[i] = a[m + 1 + i];
        }

        // Count reverse pairs
        int j = 0;
        for (int i = 0; i < leftSize; i++) {
            while (j < rightSize && left[i] > 2LL * right[j]) {
                j++;
            }
            ans += j;
        }

        // Merge two sorted arrays
        int i = 0;
        j = 0;
        int k = l;

        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
            }
        }

        while (i < leftSize) {
            a[k++] = left[i++];
        }

        while (j < rightSize) {
            a[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& a, int l, int r) {
        if (l >= r)
            return;

        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};