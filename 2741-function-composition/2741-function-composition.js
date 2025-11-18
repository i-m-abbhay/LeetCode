/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        var param = x;
        for(let i = functions.length - 1; i>=0; i--){
            param = functions[i](param);
        }   
        return param; 
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */