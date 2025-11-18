/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    arr1.sort((a,b)=>a.id-b.id);
    arr2.sort((a,b)=>a.id-b.id);
    const res = [];
    let l = 0, r = 0;
    while(l<arr1.length && r<arr2.length){
        const o1 = arr1[l];
        const o2 = arr2[r];

        if(o1.id === o2.id){
            res.push({...o1, ...o2});
            l++;
            r++;
        }
        else if(o1.id<o2.id){
            res.push({...o1});
            l++;
        }
        else {
            res.push({...o2});
            r++;
        }
    }
    while(l<arr1.length) res.push({...arr1[l++]});
    while(r<arr2.length) res.push({...arr2[r++]});
    return res;

};

// var join = function(arr1, arr2) {
//     const map = new Map();
//     for(const obj of arr1){
//         map.set(obj.id, {...obj});
//     }
//     for(const obj of arr2){
//         if(map.has(obj.id)){
//             map.set(obj.id, {
//                 ...map.get(obj.id), ...obj
//             });
//         }
//         else{
//             map.set(obj.id, {...obj});
//         }
//     }
//     return Array.from(map.values()).sort((a,b)=> a.id - b.id);
// };