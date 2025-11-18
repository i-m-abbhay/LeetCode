/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return arguments.length;
};


//note arrow functions have no arguments so we need to use args.length instead
/**
 * argumentsLength(1, 2, 3); // 3
 */