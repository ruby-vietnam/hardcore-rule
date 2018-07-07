## Problem 1
Link: https://leetcode.com/problems/count-and-say

 * 18 / 18 test cases passed.
 * Status: Accepted
 * Runtime: 60 ms
 
```ruby
# @param {Integer} n
# @return {String}
def count_and_say(n)
	counted = Hash.new
	counted['1'] = '1';
	(2..n).each do |i|
	   counted[i.to_s] = count(counted[(i-1).to_s])
	end
	return counted[n.to_s]
end

def count(str)
	return '11' if str == '1'
	result = ''
	currentCount = [1, str[0]]
	(1..str.length-1).each do |i|
		if currentCount[1] != str[i]
			result << "#{currentCount[0]}#{currentCount[1]}"
			currentCount = [1, str[i]]
		else
			currentCount[0] += 1
		end
	end
	result << "#{currentCount[0]}#{currentCount[1]}"
	return result;
end
```
