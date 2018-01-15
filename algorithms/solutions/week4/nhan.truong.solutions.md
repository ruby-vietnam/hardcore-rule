### Submissions

Code: https://gist.github.com/nhantv94/7d26cf8d642e8fc469060d6cf7791418

# Problem 1: Jump Game II

https://leetcode.com/problems/jump-game-ii/description/

```ruby
def jump(nums)
  nums_length = nums.length
  # return 0 nếu nums = [x] hoặc [].
  return 0 if nums_length <= 1
  nums_cost = Array.new(nums_length, 0)

  # Tính khoảng cách còn lại so với đích của từng phần tử.
  # nums = [1,3,3,2,2] => nums_cost = [3,0,-1,-1,-2].
  nums.each.with_index(1) do |num, index|
    nums_cost[index - 1] = nums_length - num - index
  end

  current_index = 0 # Vị trí đứng hiện tại.
  next_index = 0    # Vị trí đứng kế tiếp.
  min_cost = nums_length

  # Đến đây thì cần ít nhất một lần nhảy nên ta gán jumps_number = 1.
  jumps_number = 1
  nums_cost.each.with_index do |num_cost, index|
    # Tìm vị trí kế tiếp để nhảy, vị trí kế tiếp là vị trí có khoảng cách còn lại nhỏ nhất[1].
    if min_cost > num_cost
      next_index = index
      min_cost = num_cost
    end

    # Nhảy đến vị trí kế tiếp khi index quá tầm nhảy của vị trí hiện tại
    # hoặc tại index ta có thể nhảy về đích đồng thời tăng jumps_number thêm 1.
    if nums[current_index] + current_index <= index || (num_cost <= 0 && index > 0)
      current_index = next_index 
      jumps_number += 1
    end
    # Dừng nếu tại index có thể nhảy về đích.
    break if num_cost <= 0
  end
  jumps_number
end
```
[1]: - Ví dụ ta có `nums[2] = 3`, thì vị trí tiếp theo có thể nhảy đến là `nums[3]`, `nums[4]` hoặc `nums[5]`,
    ta chọn vị trí nhảy kế tiếp là vị trí có khoảng cách còn lại với đích là nhỏ nhất.
     - Giả sử `nums[4]` nhỏ nhất, ta sẽ nhảy đến `nums[4]` và sẽ tính tiếp khoảng cách nhỏ nhất của `nums[6]`, `nums[7]`, ...
    ta tính vị trí nhảy kế tiếp của `nums[4]` tương tự như `nums[2]` và tính như vậy cho đến đích.
    // Ta không so sánh `nums[4]` với `nums[5]` lại vì ta đã so sánh lúc nãy rồi.

# Problem 2: Sort Colors

https://leetcode.com/problems/sort-colors/description/

```ruby
def sort_colors(nums)
  colors_count = [0, 0, 0]

  # Đếm có bao nhiêu màu đỏ, trắng và xanh
  nums.each do |num|
    colors_count[num] += 1
  end

  color_code = 0
  nums.each.with_index do |num, index|
    # Đổi màu khác nếu màu hiện tại đã hết
    color_code += 1 while colors_count[color_code] == 0 # O(1)
    nums[index] = color_code      # Gán lại giá trị màu.
    colors_count[color_code] -= 1 # Giảm số lượng của màu đã gán đi một.
  end
end
```
Cảm nhận của bản thân là cách này hơi trickly.

# Word Frequency

https://leetcode.com/problems/word-frequency/description/

Em chưa biết code Bash -_-".

