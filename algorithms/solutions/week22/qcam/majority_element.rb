def majority_element(numbers)
  cache = {}

  numbers.each do |number|
    if cache.has_key?(number)
      cache[number] += 1
    else
      cache[number] = 1
    end
  end

  cache.max_by { |_key, value| value }.first
end
