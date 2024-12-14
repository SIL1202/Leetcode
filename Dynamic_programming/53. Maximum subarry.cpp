class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int total = 0;
    int Max = nums[0];
    for (int n : nums) {
      if (total < 0)
        total = 0;

      total += n;
      Max = max(total, Max);
    }
    return Max;
  }
};
