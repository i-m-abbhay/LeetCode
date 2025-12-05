/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        let res = undefined;
        
        for(let i = functions.length-1;i>=0;i--){
            if(!res) res = functions[i](x);
            else res = functions[i](res);
        }
        return res? res: x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */