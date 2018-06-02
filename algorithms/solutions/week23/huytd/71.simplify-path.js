/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 252/252 cases passed (60 ms)
 *  ✔ Your runtime beats 97.1 % of javascript submissions
 */

var simplifyPath = function(path) {
    let stack = [];
    path.split("/").forEach(token => {
        if (token !== "" && token !== ".") {
            if (token === "..") {
                stack.pop();
            } else {
                stack.push(token);
            }
        }
    });
    return "/" + stack.join("/");
};

//console.log(simplifyPath("/home/a/./c/../d///e"));
