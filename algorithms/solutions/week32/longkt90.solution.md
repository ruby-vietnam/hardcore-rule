# Problem 1 : Leaf similar trees

URL: https://leetcode.com/problems/leaf-similar-trees/description/


Status:
```
  ✔ Accepted
```
Codes:
```ruby
def leaf_similar(root1, root2)
  leaves_of(root1) == leaves_of(root2)
end

def leaves_of(root)
  leaves = []
  visit(root, leaves)
  leaves
end

def visit(node, leaves)
  if node.left.nil? && node.right.nil?
    leaves << node.val
  elsif node.right.nil?
    visit(node.left, leaves)
  elsif node.left.nil?
    visit(node.right, leaves)
  else
    visit(node.left, leaves)
    visit(node.right, leaves)
  end
end

```
