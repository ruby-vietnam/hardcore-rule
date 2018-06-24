class FindSolution
  def initialize(matrix)
    @a = matrix
    @len = @a.count
    @checked = Array.new(@len, false)
    @count = 0
  end

  def call
    @a.each.with_index do |value, i|
      if !@checked[i]
        @count += 1
        mark_circle(i)
      end
    end
  end

  def mark_circle(i)
    @q = [i]
    loop do
      break if @q.empty?
      cur = @q.shift
      @checked[cur] = true
      @a[cur].each_with_index do |is_friend, index|
        if is_friend > 0 && !@checked[index]
          @q.push(index)
        end
      end
    end
  end
end

# @param {Integer[][]} m
# @return {Integer}
def find_circle_num(m)
  FindSolution.new(m).call()
end

find_circle_num([[1,1,0], [1,1,1], [0,1,1]])
find_circle_num([[1,1,0], [1,1,0], [0,0,1]])
find_circle_num([[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]])
[[1,0,0,1],
 [0,1,1,0],
 [0,1,1,1],
 [1,0,1,1]]

Matrix[[2, 0, 1, 2], 
       [0, 2, 2, 1], 
       [1, 2, 3, 2], 
       [2, 1, 2, 3]]
