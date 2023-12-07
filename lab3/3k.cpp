#include <iostream>
#include <vector>

using namespace std;

int minSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLength = n + 1;

    for (int left = 0, right = 1; right <= n; ++right) {
        while (prefixSum[right] - prefixSum[left] >= k) {
            minLength = min(minLength, right - left);
            left++;
        }
    }

    return (minLength <= n) ? minLength : 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minSubarrayLength(nums, k);
    cout << result << endl;

    return 0;
}