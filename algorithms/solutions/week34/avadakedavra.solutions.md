## Problem 1: House Robber
# Define an array arr[0]. Arr[i] is the maximum amount of money stolen up to house[i]
# With each house(i) in array houses, add N to arr with N is max in ( arr.[i],  arr[i-2] + house(i))

def house_robber(houses)
  return 0 unless houses.any?
  return houses.max if houses.size < 3
  arr = [0]
  arr << houses.first
  (2..houses.size).each do |i|
    arr << [arr.last, arr[i-2] + houses[i-1]].max
  end
  arr.last
end
