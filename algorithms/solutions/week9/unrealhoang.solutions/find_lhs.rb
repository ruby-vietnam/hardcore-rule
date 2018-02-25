# @param {Integer[]} nums
# @return {Integer}
def find_lhs(nums)
    nums.sort!
    cur_count = 0
    max_count = 0
    group_count = []
    last_num = nil
    last_group = nil
    nums.each do |num|
      if last_num.nil? || last_num != num
        last_group = [num, 1]
        group_count << last_group
      else
        last_group[1] += 1
      end
      last_num = num
    end

    last_num = nil
    last_count = 0
    group_count.each do |num, count|
      if last_num && num - last_num == 1 && count + last_count > max_count
          max_count = count + last_count
      end
      last_num = num
      last_count = count
    end
    max_count
end

require 'minitest/autorun'
class TestResult < MiniTest::Unit::TestCase
  def test_correct_answer
    input = [1,3,2,2,5,2,3,7]
    assert_equal(5, find_lhs(input))
  end
end
