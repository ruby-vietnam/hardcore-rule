#include <iostream>

using namespace std;

struct Interval {
  int l, r;

  bool inside(Interval b) {
    return b.l<=l && r<=b.r;
  }

  bool intersect(Interval b) {
    return !(r<b.l || b.r<l);
  }

  int mid() {
    return l + (r-l) / 2;
  }
};

// Reference:
// http://vnoi.info/wiki/algo/data-structures/segment-tree-extend#2-lazy-propagation
struct Node {
  Interval range;
  Node *left, *right;
  int value, lazy;
  Node(Interval range): range(range), left(nullptr), right(nullptr), value(0), lazy(0) {}
  ~Node() { delete left; delete right; }

  void lazy_down() {
    if (!left) {
      int mid = range.mid();
      left = new Node({range.l, mid});
      right = new Node({mid+1, range.r});
    }
    left->value += lazy;
    left->lazy += lazy;
    right->value += lazy;
    right->lazy += lazy;
    lazy = 0;
  }

  void update(Interval r, int val) {
    if (!range.intersect(r)) return;
    if (range.inside(r)) value += val, lazy += val;
    else {
      lazy_down();
      left->update(r, val);
      right->update(r, val);
      value = max(left->value, right->value);
    }
  }

  int get_max(Interval r) {
    if (!range.intersect(r)) return 0;
    if (range.inside(r)) return value;
    lazy_down();
    return max(left->get_max(r), right->get_max(r));
  }
};

int main() {
  int n, m, p;
  cin >> n >> m;

  Node node({1, n});

  while(m--) {
    int l, r, v; cin >> l >> r >> v;
    node.update({l, r}, v);
  }

  cin >> p;
  while(p--) {
    int l, r; cin >> l >> r;
    cout << node.get_max({l, r}) << endl;
  }

  return 0;
}
