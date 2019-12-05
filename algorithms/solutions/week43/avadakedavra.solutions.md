##Problem 1:
# Implement Stack using Queues
class MyStack

  def initialize
		@queue, @last = [], nil   
  end


  def push(x)
    @queue << @last if @last!=nil
    @last = x
  end

  def pop()
	  return if @last==nil
    tmp = []
    tmp << @queue.shift while @queue.size > 1
    @last = @queue.shift
    @queue = tmp
  end


  def top()
    @last
  end

	def empty()
  	 @last == nil
  end
end
