/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
     const n = nums.length;
  if (n === 0) return 0;

  nums.sort((a, b) => a - b);
  let maxW2k = 1;
  for (let L = 0, R = 0; R < n; R++) {
    while (nums[R] - nums[L] > 2 * k) L++;
    maxW2k = Math.max(maxW2k, R - L + 1);
  }
  let ans = Math.min(maxW2k, numOperations); 
  let L = 0, R = 0;
  for (let i = 0; i < n; ) {
    const v = nums[i];
    const start = i;
    while (i + 1 < n && nums[i + 1] === v) i++;
    const end = i;
    const c = end - start + 1;

    const lower = v - k;
    const upper = v + k;

    while (L < n && nums[L] < lower) L++;
    while (R + 1 < n && nums[R + 1] <= upper) R++;
    if (R < end) R = end;
    const W = R - L + 1;
    const extra = W - c;
    const canAdd = Math.min(numOperations, extra);
    ans = Math.max(ans, c + canAdd);

    i++;
  }

  return ans;
};