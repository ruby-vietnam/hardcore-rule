## 1. Min Stack
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 200ms    | ???%        | 16.7 MB  | 10.83%    |

### 1.2. Source code
```cpp
struct Node {
  int value;
  Node *next, *prev;
  Node(int value) : value(value), next(NULL), prev(NULL) {}
  Node(int value, Node* next) : value(value), next(next), prev(NULL) {}
  Node(int value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}
};

class MinStack {
public:
  Node *head, *tail;
  /** initialize your data structure here. */
  MinStack() {
    this->head = NULL;
    this->tail = NULL;
  }

  void push(int val) {
    Node *newNode = new Node(val, NULL, this->tail);
    if (this->head == NULL) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
  }

  void pop() {
    assert(this->tail != NULL);
    Node* snapshot = this->tail;
    this->tail = this->tail->prev;
    if (this->tail == NULL) {
      this->head = NULL;
    } else {
      this->tail->next = NULL;
    }
    delete snapshot;
  }

  int top() {
    assert(this->tail != NULL);
    return this->tail->value;
  }

  int getMin() {
    assert(this->head != NULL);
    int m = this->head->value;
    for (Node* i = this->head->next; i != NULL; i = i->next) {
      m = min(m, i->value);
    }
    return m;
  }
};
```

## 2. Number of Islands
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 48ms     | 5.47%       | 12.3 MB  | 9.20%     |

### 2.2. Source code
```cpp
typedef pair<int, int> ii;

const int N = 307;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

class Solution {
public:
  int n, m;
  vector< vector<char> > grid;
  vector< vector<bool> > vis;

  Solution() {
    this->vis.resize(N);
    for (int i = 0; i < vis.size(); i++) {
      vis[i].resize(N);
    }
  }

  bool inBoard(int x, int y) {
    return (0 <= x && x < this->n && 0 <= y && y < this->m);
  }

  void traverse(const int &i, const int &j) {
    queue<ii> q;
    q.push(ii(i, j));
    vis[i][j] = true;

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (this->inBoard(u, v) && !vis[u][v] && this->grid[u][v] == '1') {
          q.push(ii(u, v));
          vis[u][v] = true;
        }
      }
    }
  }

  int numIslands(const vector<vector<char>> &grid) {
    this->grid = grid;
    this->n = grid.size();
    this->m = grid[0].size();

    int cnt = 0;
    for (int i = 0; i < this->n; i++) {
      for (int j = 0; j < this->m; j++) {
        if (this->grid[i][j] == '1' && !vis[i][j]) {
          this->traverse(i, j);
          cnt++;
        }
      }
    }

    return cnt;
  }
};
```
