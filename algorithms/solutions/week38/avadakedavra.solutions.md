##Problem 2:

#Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

#Integers in each row are sorted in ascending from left to right.
#Integers in each column are sorted in ascending from top to bottom.

# Ruby
# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}

def search_matrix(mattrix, target)
  i = 0
  j = mattrix[0].size - 1
  while i < mattrix.size && j >= 0 do
    return true if target == mattrix[i][j]
    target > mattrix[i][j] ? i += 1 : j -= 1
  end
  false
end