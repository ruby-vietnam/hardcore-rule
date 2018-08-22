## Problem 1
Link: http://acm.timus.ru/problem.aspx?space=1&num=1009

 * Status: Accepted

```ruby
def k_based_number(k, n)
	a = []
	a[0] = []
	a[0] << 0
	a[0] << k -1
	(1..n-1).each do |i|
		a[i] = []
		a[i] << a[i-1][1]
		a[i] << (k-1)*(a[i-1][0] + a[i-1][1])
	end
	a[n-1][0] + a[n-1][1]
end
n = gets.to_i
k = gets.to_i
puts k_based_number(k, n)
```
