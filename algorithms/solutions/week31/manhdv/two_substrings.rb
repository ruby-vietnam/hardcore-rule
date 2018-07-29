# http://codeforces.com/contest/550/problem/A

def get_input
  gets.chomp
end

def result(sub1_found_idxs, sub1_length, sub2_found_idxs, sub2_length)
  return false if sub1_found_idxs.empty? || sub2_found_idxs.empty?

  case1 = sub1_found_idxs.first < sub2_found_idxs.last && # Avoid overlapping
          (sub2_found_idxs.last - sub1_found_idxs.first) >= sub1_length
  case2 = sub1_found_idxs.last > sub2_found_idxs.first && # Avoid overlapping
          (sub1_found_idxs.last - sub2_found_idxs.first) >= sub2_length

  case1 || case2
end

# Checking str contains both sub1 and sub2 without overlapping in general
def contain_substrings?(str, sub1, sub2)
  sub1_length = sub1.size
  sub2_length = sub2.size
  start_idx_sub1 = 0
  start_idx_sub2 = 0
  sub1_found_idxs = []
  sub2_found_idxs = []

  0.upto(str.size - 1) do |current_idx|
    # Find all indexes of sub1 in str
    if str[start_idx_sub1..current_idx] == sub1
      sub1_found_idxs << start_idx_sub1
      start_idx_sub1 = current_idx + 1
    elsif current_idx - start_idx_sub1 >= sub1_length - 1
      start_idx_sub1 += 1
    end

    # Find all indexes of sub2 in str
    if str[start_idx_sub2..current_idx] == sub2
      sub2_found_idxs << start_idx_sub2
      start_idx_sub2 = current_idx + 1
    elsif current_idx - start_idx_sub2 >= sub2_length - 1
      start_idx_sub2 += 1
    end
  end

  result(sub1_found_idxs, sub1_length, sub2_found_idxs, sub2_length) ? 'YES' : 'NO'
end

# puts contain_substrings?('ABA', 'AB', 'BA') => NO
# puts contain_substrings?('BACFAB', 'AB', 'BA') => YES
# puts contain_substrings?('AXBYBXA', 'AB', 'BA') => NO

puts contain_substrings?(get_input, 'AB', 'BA')