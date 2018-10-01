# Week 38 write up

### Path sum III (easy)

#### Naive method

Về cơ bản ta có thể giải bài toán bằng DFS với 2 hàm:

- pathSum: đếm số path có tổng bằng N (có thể bắt đầu từ bất kì node nào)
- pathSumFromNode: đếm số path có tổng bằng N (bắt đầu từ 1 node xác định)

Hàm pathSumFromNode có thể được viết dễ dàng với DFS

```js
function pathSumFromNode(node, sum) {
  if (!node) return 0;
  const countLeftRight =
    pathSumFromNode(node.left, sum - node.val) +
    pathSumFromNode(node.right, sum - node.val);
  if (node.val === sum) return 1 + countLeftRight;
  return countLeftRight;
}
```

Hàm pathSum có thể được viết bằng cách

```js
function pathSum(root, sum) {
  if (!root) return 0;
  return (
    pathSumFromNode(root, sum) +
    pathSum(root.left, sum) +
    pathSum(root.right, sum)
  );
}
```

#### Prefix sum method

Phương pháp Naive có 1 nhược điểm là với mỗi path trong cây, ta phải xét 2 lần:

- 1 lần xem cả path đang xét có tổng = N hay ko
- 1 lần để xem có path con nào có tổng = N hay ko
  Trong đó bài toán xem có path con nào có tổng = N hay không có thể được tính nhanh bằng cách dùng HashMap (lấy ý tưởng từ bài toán: từ 1 array cho trước, tìm subarray có tổng bằng N):

  - Tạo 1 HashMap để lưu tổng từ root tới 1 node bất kì
  - Tổng của 1 path con (xi, xj) với (0 <= i <j < len(path)) = Tổng của path con (0, xj) - Tổng của path con (0,xi)

Tổng kết lại ta có cách giải sau (source: huydx)

```java
class Solution {
    public int pathSum(TreeNode root, int sum) {
        if (root == null) { return 0; }
        Map<Integer, Integer> prefix = new HashMap<>();
        prefix.put(0,1);
        return traverse(root, 0, sum, prefix);
    }

    private int traverse(TreeNode cur, int curSum, int targetSum, Map<Integer, Integer> prefix) {
        if (cur == null) { return 0; }
        curSum += cur.val;
        int path = prefix.getOrDefault(curSum - targetSum, 0);
        prefix.put(curSum, prefix.getOrDefault(curSum, 0) + 1);
        int res = path + traverse(cur.left, curSum, targetSum, prefix) +
                    traverse(cur.right, curSum, targetSum, prefix);
        prefix.put(curSum, prefix.get(curSum) - 1);
        return res;
    }
}
```

### Search in 2D Matrix (Medium)

Matrix size m x n
Để giải được nó 1 cách tối ưu, ta sẽ ko bắt đầu duyệt Matrix từ vị trí (0,0) hoặc (m,n) như thông thường :D
Với 1 matrix bất kì, giá trị ở điểm D luôn là lớn nhất

```
A . . B
. . . .
C . . D
```

Xét mảng con từ (0,0) => D(i,j) với điểm D bắt đầu từ (0,n)

- Nếu `D > target` => cần thu hẹp submatrix lại => `i = i - 1`
- Nếu `D < target` => cần mở rộng submaxtrix ra => `j = j + 1`
- Nếu `D = target` => return
  Tổng kết lại ta có cách giải sau (source: ledongthuc)

```go
func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return false
    }

    if len(matrix) == 1 && len(matrix[0]) == 1 {
        return matrix[0][0] == target
    }

    x, y := 0, len(matrix[0])-1
    for x < len(matrix) && y >= 0 {
        if matrix[x][y] == target {
            return true
        }
        if matrix[x][y] < target {
            x++
        } else {
            y--
        }
    }
    return false
}
```

### Daily temperature (Medium)

Bài toán có thể giải bằng cách dùng Stack. Đối với mỗi phần tử, trước khi được push vào Stack, ta sẽ pop toàn bộ các phần tử trước đó cho đên khi nào `element < top_stack`
Tổng kết lại ta có cách giải sau (source: linxgnu)

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] stack = new int[temperatures.length];
        int top = -1;
        int[] ret = new int[temperatures.length];
        for(int i = 0; i < temperatures.length; i++) {
            while(top > -1 && temperatures[i] > temperatures[stack[top]]) {
                int idx = stack[top--];
                ret[idx] = i - idx;
            }
            stack[++top] = i;
        }
        return ret;
    }
}
```

### Basic calculator (Hard)

Về cơ bản bài này có thể giải được bằng cách viết parser > build AST > evaluate như 1 compiler (tham khảo [link](https://github.com/jamiebuilds/the-super-tiny-compiler/blob/master/the-super-tiny-compiler.js))
Tuy nhiên do chỉ có 2 operand là “+” và “-“ nên có thể giải 1 cách đơn giản như sau:

```java
int total = 0;
int lastNumber = 0;
int lastSign = 1;
if(Character.isDigit(c)){
	lastNumber = 10 * lastNumber + convertCharToNum(c);
}else if(c == '+'){
	total += lastSign * lastNumber;
	lastNumber = 0;
	lastSign = 1;
}else if(c == '-'){
	total += lastSign * lastNumber;
	lastNumber = 0;
	lastSign = -1;
}
```

Nếu có thêm operand là “(“ và “)”, ta có thể sử dụng thêm Stack để lưu giá trị tạm (tương tự như context switching)
Tổng kết lại ta có cách giải sau (source: lmduc)

```java
struct MathNode {
  int val;
  bool number;
  bool opening;
  bool closed;
  char sign;
  MathNode(int x, bool n, bool o, bool c, char s) : val(x), number(n), opening(o), closed(c), sign(s) {}
};

class Solution {
private:
  int getNumber(char c) {
    return (int)c - (int)'0';
  }

  bool isNumber(char c) {
    int r = getNumber(c);
    return (0 <= r && r <= 9);
  }

  void calculate(vector<MathNode>& nodes) {
    long int sum = 0;
    stack<MathNode> st;
    while (!nodes.empty()) {
      MathNode node = nodes.back();
      nodes.pop_back();
      if (node.number)
        st.push(node);
      if (node.opening) break;
      if (node.sign == '-') {
        sum = sum - st.top().val;
        st.pop();
      }
      if (node.sign == '+') {
        sum = sum + st.top().val;
        st.pop();
      }
    }
    while (!st.empty()) {
      sum = sum + st.top().val;
      st.pop();
    }
    nodes.push_back(MathNode(sum, true, false, false, ' '));
  }

  MathNode getMathNode(string& s, int& si) {
    while (si < s.size() && s[si] == ' ') ++si;
    if (s[si] == '(') {
      ++si;
      return MathNode(0, false, true, false, ' ');
    }
    if (s[si] == ')') {
      ++si;
      return MathNode(0, false, false, true, ' ');
    }
    if (s[si] == '-' || s[si] == '+') {
      return MathNode(0, false, false, false, s[si++]);
    }
    if (si == s.size()) return MathNode(0, false, false, false, ' ');
    int r = 0;
    while (si < s.size() && isNumber(s[si]))
      r = r*10 + getNumber(s[si++]);
    return MathNode(r, true, false, false, ' ');
  }

public:
  int calculate(string s) {
    long int sum = 0;
    vector<MathNode> nodes;

    int si = 0;
    while (si < s.size()) {
      MathNode node = getMathNode(s, si);
      if (node.closed)
        calculate(nodes);
      else
        nodes.push_back(node);
    }
    calculate(nodes);
    return nodes[0].val;
  }
};
```
