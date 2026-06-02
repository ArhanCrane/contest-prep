class Solution {
public:
    //Fixed Size Sliding Window
    double findMaxAverage(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());

        double addition{};
        for (int i{}; i < k; i++) {addition += nums[i];}// k <= n, O (k)

        double max_average{addition / k}; // k != 0

        int l{};
        for (int r{k}; r < n; r++) { // O (n)
            addition += nums[r];
            addition -= nums[l];
            l++;
            max_average = std::max(max_average, (addition / k)); // k != 0
        }

        return max_average;
    }
};
