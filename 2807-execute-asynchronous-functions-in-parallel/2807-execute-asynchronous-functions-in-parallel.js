/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise(async(res, rej)=> {
        let len = functions.length, cnt = 0;
        const ans = new Array(len);
        for(let i = 0; i< len; ++i)
        {
            functions[i]().then((val)=>{
            ans[i]=val;
            
            cnt++;
            if(cnt===len)
                res(ans);
            }).catch(err =>
                rej(err)
            )
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */