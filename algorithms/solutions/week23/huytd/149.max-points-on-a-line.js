/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * Status:
 *  ✔ Acceptedr judge result
 *  ✔ 36/36 cases passed (144 ms)
 *  ✔ Your runtime beats 34.15 % of javascript submissions
 *
 */
var gcd = function(a,b) {
    return a ? (a / Math.abs(a) * Math.abs(gcd((b % a) |0, a))) |0 : b;
};

var maxPoints = function(points) {
    let result = 0;
    for (let i = 0; i < points.length; i++) {
        let count = {};
        let same = 1;
        let mx = 0;
        for (let j = i + 1; j < points.length; j++) {
            let x = points[i].x - points[j].x;
            let y = points[i].y - points[j].y;
            let g = gcd(x, y);
            if (!g) {
                same++;
                continue;
            }
            x /= g |0;
            y /= g |0;
            let key = x + "" + y;
            if (!count[key]) count[key] = 0;
            mx = Math.max(mx, ++count[key]);
        }
        result = Math.max(result, mx + same);
    }
    return result;
};
