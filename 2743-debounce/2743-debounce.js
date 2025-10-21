/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    var timeoutId=null;
    return function(...args){
        if(timeoutId!==null){
            clearTimeout(
                timeoutId
            );
        }
        timeoutId = setTimeout(()=>fn(...args), t);    
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */