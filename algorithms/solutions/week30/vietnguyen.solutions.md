## [Problem 1: HackerRank: Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)
      
  def miniMaxSum(arr):
      arr.sort()
      total = sum(arr)
      minSum = total - arr[-1]
      maxSum = total - arr[0]
      print(minSum, maxSum)

## [Problem 2: HackerRank: Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)
      
  def matchingStrings(strings, queries):
      # brute force: traverse queries:
      # for each query, check how many strings matched. Append the result into a result array. 
      res = [] 
      for q in queries:
          count = 0 
          for s in strings: 
              if q == s: 
                  count += 1 
          res.append(count)
      return res 



