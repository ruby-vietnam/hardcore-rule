## Problem 1

```js
// Use more memory

var hasCycle = function(head) {
    var result = new WeakMap;
    var iterator = head;

    if (iterator == null) {
        return false;
    }

    while (iterator != null && result.get(iterator) == undefined) {
        result.set(iterator, 1);
        iterator = iterator.next;
    }

    return iterator != null;
};

// Use less memory

var hasCycle = function(head) {
    var fast = head;
    var slow = head;

    while (fast != null && slow != null) {
        if (fast.next == null) {
            return false;
        } else if (fast.next == slow) {
            return true;
        }
        fast = fast.next.next
        slow = slow.next

        if (fast == slow) {
            return true;
        }
    }

    return false;
};
```

## Problem 2

Created base on the hint in a discussion:

- Sort the array descending
- Split into 2 halves
- The small half are put at odd position, big half are put at even position

```ruby
def wiggle_sort(nums)
  new_nums = nums.sort { |a, b| b <=> a }
  size = nums.size
  half = (size - 1) / 2
  flag = size.odd? ? 0 : 1

  (0..half).each do |n|
    nums[n * 2] = new_nums[half + n + flag]

    if n * 2 + 1 < size
      nums[n * 2 + 1] = new_nums[n]
    end
  end
end
```

## Problem 3

Use Array

```ruby

def to_a(head)
  array = []
  node = head

  while node do
    array << node.val
    node = node.next
  end

  array
end

def from_a(array)
  previous_node = nil

  array.reverse.each do |element|
    node = ListNode.new(element)
    node.next = previous_node
    previous_node = node
  end

  previous_node
end

def odd_even_list(head)
  elements = to_a(head)
  size = elements.size
  odds = []
  (0..size - 1).step(2) do |index|
    odds << elements[index]
  end

  evens = []
  (1..size - 1).step(2) do |index|
    evens << elements[index]
  end

  sum = odds + evens

  from_a(sum)
end
```

Use List

```ruby
def odd_even_list(head)
  node = head
  index = 1
  head_even = odd = even = nil

  while node do
    if index.odd?
      if odd
        odd = odd.next = node
      else
        odd = node
      end
    else
      if even
        even = even.next = node
      else
        head_even = even = node
      end
    end

    node = node.next
    index += 1
  end

  if odd
    odd.next = head_even
    if even
      even.next = nil
    end
  end

  head
end
```
