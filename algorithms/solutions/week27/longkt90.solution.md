# Problemm 1: Subdomain Visit Count

URL: https://leetcode.com/problems/subdomain-visit-count/

Status;
```
  ✔ Accepted
```


```ruby
def subdomain_visits(cpdomains)
  visits_count = Hash.new(0)
  cpdomains.each do |cpdomain|
    visits, full_domain = cpdomain.split(' ')
    visits = Integer(visits)
    domains = full_domain.split('.')
    (1..domains.size).each do |level|
      visits_count[domains.last(level).join('.')] += visits
    end
  end
  visits_count.map { |domain, visit_count| [visit_count, domain].join(' ') }
end
```

# Problemm 2: Directions reduction

URL: https://www.codewars.com/kata/directions-reduction/ruby

Status;
```
  ✔ Accepted
```
```ruby
def dirReduc(arr)
  moves = []
  arr.each do |move|
    case move
    when 'NORTH'
      next moves.pop if moves.last == 'SOUTH'
    when 'SOUTH'
      next moves.pop if moves.last == 'NORTH'
    when 'EAST'
      next moves.pop if moves.last == 'WEST'
    else
      next moves.pop if moves.last == 'EAST'
    end

    moves << move
  end
  moves
end
```