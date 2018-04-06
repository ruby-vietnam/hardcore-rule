Group = Struct.new(:char, :count) do
  def to_s
    r = []
    self.count.times { r << self.char }
    r.join("")
  end
end

State = Struct.new(:groups, :inputs) do
  def clone
    n_groups = self.groups.map { |g| g.clone }
    n_inputs = self.inputs.clone
    State.new(n_groups, n_inputs)
  end

  def to_s
    [self.groups.map(&:to_s).join(""), self.inputs.join("")].to_s
  end
end

# remove groups with count 3
# pack groups with same char together
def regroup(groups)
  return if groups.empty?

  index = groups.count - 2
  while true
    break if index < 0
    if groups[index + 1] && groups[index].char == groups[index + 1].char
      groups[index].count += groups[index + 1].count
      groups.delete_at(index + 1)
    end
    if groups[index].count > 2
      groups.delete_at(index)
    end
    index -= 1
  end

  if groups[0] && groups[0].count > 2
    groups.detele_at(0)
  end
end

# @param {String} board
# @param {String} hand
# @return {Integer}
def find_min_step(board, hand)
  groups = board.chars.reduce([]) do |acc, char|
    last = acc.last
    if last && last.char == char
      last.count += 1
    else
      acc << Group.new(char, 1)
    end

    acc
  end

  inputs = hand.chars
  original_input_length = inputs.count

  state = State.new(groups, inputs)
  queue = []
  queue.push(state)

  while true
    return -1 if queue.empty?
    cur_state = queue.shift

    if cur_state.groups.empty?
      return original_input_length - cur_state.inputs.count
    end
    cur_state.inputs.each_with_index do |input, input_index|
      cur_state.groups.each_with_index do |group, index|
        if group.char == input && group.count > 1
          #puts "Trying input (deleting): #{input} on #{cur_state.groups.map(&:to_s).join("")}"
          state = cur_state.clone
          state.groups.delete_at(index)
          state.inputs.delete_at(input_index)
          regroup(state.groups)
          queue.push(state)
          #puts "Result: #{state.groups.map(&:to_s).join("")}"
        elsif group.char == input
          #puts "Trying input: #{input} on #{cur_state.groups.map(&:to_s).join("")}"
          state = cur_state.clone
          state.inputs.delete_at(input_index)
          state.groups[index].count += 1
          queue.push(state)
          #puts "Result: #{state.groups.map(&:to_s).join("")}"
        end
      end
    end
  end
end

require 'minitest/autorun'
class TestResult < MiniTest::Unit::TestCase
  def test_1
    assert_equal(-1, find_min_step("WRRBBW", "RB"))
  end
  def test_2
    assert_equal(2, find_min_step("WWRRBBWW", "WRBRW"))
  end
  def test_3
    assert_equal(3, find_min_step("RBYYBBRRB", "YRBGB"))
  end
end

