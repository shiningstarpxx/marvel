/*
1775. Equal Sum Arrays With Minimum Number of Operations
Medium

171

3

Add to List

Share
You are given two arrays of integers nums1 and nums2, possibly of different
lengths. The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any
value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in
nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not
possible to make the sum of the two arrays equal.



Example 1:

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations.
All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
Example 2:

Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum
of nums2 to make them equal. Example 3:

Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations.
All indices are 0-indexed.
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].


Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6

*/

class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (6 * min(nums1.size(), nums2.size()) <
        1 * max(nums1.size(), nums2.size()))
      return -1;

    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    if (sum1 > sum2) swap(nums1, nums2);
    int diff = abs(sum1 - sum2);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), std::greater<int>());

    int step = 0;
    int left = 0, right = 0;
    while (diff > 0) {
      int inc = left < nums1.size() ? 6 - nums1[left] : 0;
      int dec = right < nums2.size() ? nums2[right] - 1 : 0;
      if (inc > dec) {
        diff -= inc;
        ++left;
      } else {
        diff -= dec;
        ++right;
      }
      ++step;
    }
    return step;
  }
};