/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 252/252 cases passed (60 ms)
 */

fn simplify_path(path: &str) -> String {
    let mut stack = vec![""];
    let tokens = path.split("/");
    for token in tokens {
        if token.ne("") && token.ne(".") {
            if token.eq("..") {
                stack.pop();
            } else {
                stack.push(token);
            }
        }
    }
    stack.join("/")
}

fn main() {
    assert!(simplify_path("/home/a/./c/../d///e") == "/home/a/d/e");
}
