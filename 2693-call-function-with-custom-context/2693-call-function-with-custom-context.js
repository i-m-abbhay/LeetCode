/**
 * @param {Object} context
 * @param {Array} args
 * @return {null|boolean|number|string|Array|Object}
 */
Function.prototype.callPolyfill = function(obj, ...args) {
    const context = obj === null || obj === undefined ? globalThis : Object(obj);
    const uniqueKey = Symbol('tempMethod');
    context[uniqueKey] = this;
    const result = context[uniqueKey](...args);
    delete context[uniqueKey];
    return result;
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */