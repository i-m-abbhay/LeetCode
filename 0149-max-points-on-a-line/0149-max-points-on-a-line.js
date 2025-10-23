/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    const n = points.length;
    if(n<=2) return n;

    let globalMax = 1;
    for(let i = 0; i<n;i++){
        const [x1,y1] = points[i];
        const counts = new Map();
        let duplicates = 0;
        let localMax = 0;
        for(let j = i+1; j<n;j++){
            const [x2, y2] = points[j];
            let dx = x2-x1;
            let dy = y2-y1;
            if(dx===0 && dy===0){
                duplicates++;
                continue;
            }
            if(dx==0){
                dy = 1; dx = 0;
            } else if (dy===0){
                dy = 0; dx = 1;
            } else {
                const g = gcd(Math.abs(dy), Math.abs(dx));
                dy /= g;
                dx /= g;
                if(dx<0){dx = -dx; dy = -dy;}
            }
            const key = `${dy}/${dx}`;
            const val = (counts.get(key)||0)+1;
            counts.set(key, val);
            if(val>localMax) localMax = val;
        }
        globalMax = Math.max(globalMax, localMax);
        if(globalMax >= n - i) break;
    }
    return globalMax+1;
};

function gcd(a, b){
    while(b!==0){
        const t = b;
        b = a%b;
        a = t;
    }
    return a;
}