## Problem 2

https://www.spoj.com/problems/ELEVTRBL/

BFS. Start at the starting floor. Each step, add up floor and down floor from the current location to the queue, until we reach the end.


```ruby
def main
	max_height, start, goal, up, down = gets.split(' ').map(&:to_i)
	
	steps = Array.new(max_height + 1, 0)
	queue = [start]
	steps[start] = 0
	
	while !queue.empty? do
		floor = queue.shift
		
		if floor == goal
			puts steps[floor]
			return
		end
		
		up_floor = floor + up
		if up_floor <= max_height && steps[up_floor] == 0
			steps[up_floor] = steps[floor] + 1
			queue.unshift(up_floor)
		end
		
		down_floor = floor - down
		if down_floor >= 1 && steps[down_floor] == 0
			steps[down_floor] = steps[floor] + 1
			queue.unshift(down_floor)
		end
	end
	
	puts "use the stairs"
end

main
```
