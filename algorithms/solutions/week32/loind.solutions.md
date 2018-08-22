# Problem1

```ruby
def get_leaf_nodes(root, arr)
    return if root.nil?
    if root.left.nil? && root.right.nil?
        arr << root.val
        return arr
    end

    get_leaf_nodes(root.left, arr) if root.left
    get_leaf_nodes(root.right, arr) if root.right
    arr
end

def leaf_similar(root1, root2)
    arr1 = get_leaf_nodes(root1, [])
    arr2 = get_leaf_nodes(root2, [])
    arr1 == arr2
end
```
