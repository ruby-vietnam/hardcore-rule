# https://leetcode.com/problems/largest-number/description/

def build_number(value, length)
  # Build a custom number with struct:
  # number = {
  #   value: String,
  #   comparing_value: String,
  #   first_digit_greater_last: Boolean
  # }
  # Eg:
  #   Input: value = 3, length = 5.
  #   Output: { value: '3', comparing_value: '33333', first_digit_greater_last: false }
  #
  #   Input: value = 355, length = 5.
  #   Output: { value: '355', comparing_value: '35555', first_digit_greater_last: false }
  #
  #   Input: value = 352, length = 5.
  #   Output: { value: '352', comparing_value: '35233', first_digit_greater_last: true }

  value_to_s = value.to_s
  first_digit = value_to_s[0]
  last_digit = value_to_s[-1]
  first_digit_greater_last = first_digit > last_digit
  addition_digit = first_digit_greater_last ? first_digit : last_digit
  comparing_value = value_to_s + addition_digit * (length - value_to_s.size)

  {
    value: value_to_s,
    comparing_value: comparing_value,
    first_digit_greater_last: first_digit_greater_last
  }
end

def greater?(number_a, number_b)
  case
  when number_a[:comparing_value] > number_b[:comparing_value]
    -1
  when number_a[:comparing_value] < number_b[:comparing_value]
    1
  else
    # Eg: number_a[:value] == '8308' vs number_b[:value] = '830'
    # then number_b should be after number_a
    if number_a[:value] > number_b[:value]
      number_b[:first_digit_greater_last] ? -1 : 1
    else
      number_a[:first_digit_greater_last] ? 1 : -1
    end
  end
end

# @param {Integer[]} nums
# @return {String}
def largest_number(nums)
  max_number_length = nums.max.to_s.size
  new_numbers = nums.map { |num| build_number(num, max_number_length) }
  new_numbers_desc = new_numbers.sort do |number_a, number_b|
    greater?(number_a, number_b)
  end

  new_numbers_desc.reduce('') do |memo, number|
    memo == '0' && number[:value] == '0' ? memo : memo << number[:value]
  end
end
