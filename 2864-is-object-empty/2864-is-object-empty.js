/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    var count = 0;
    for (const key in obj) {
        count++;
    }
    return !count;
};