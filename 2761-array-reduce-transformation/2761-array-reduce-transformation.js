/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var param = init; 
    for(let i = 0; i<nums.length; i++){
        param = fn(param, nums[i]);
    }
    return param;
};