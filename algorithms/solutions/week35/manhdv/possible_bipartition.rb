# https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

def find_all_dislikes(persons, dislikes_hash)
  persons.each_with_object([]) do |person, dislikes|
    dislikes.concat(dislikes_hash[person] || [])
  end.uniq
end

# @param {Integer} n
# @param {Integer[][]} dislikes
# @return {Boolean}
def possible_bipartition(n, dislikes)
  dislikes_hash = dislikes.each_with_object({}) do |(person1, person2), hash|
    hash[person1] ||= []
    hash[person1] << person2
    hash[person2] ||= []
    hash[person2] << person1
  end

  return true if dislikes_hash.empty?

  first_dislikes = dislikes_hash.first[1]
  loop do # Find a cicle of dislikes
    next_dislikes = find_all_dislikes(first_dislikes, dislikes_hash)
    return false unless (first_dislikes & next_dislikes).empty?

    next_next_dislikes = find_all_dislikes(next_dislikes, dislikes_hash)
    return false unless (next_dislikes & next_next_dislikes).empty?

    return true if next_next_dislikes == first_dislikes

    first_dislikes = next_next_dislikes
  end
end