# Problem 1

```ruby
def subdomain_visits(cpdomains)
  data = {}
  cpdomains.each do |cp|
    count, domain = cp.split(' ')
    data[domain] ||= 0
    data[domain] += count.to_i

    prdomains = domain.split('.')
    data[prdomains.last] ||= 0
    data[prdomains.last] += count.to_i

    next if prdomains.size < 3
    prdomain1 = "#{prdomains[1]}.#{prdomains[2]}"
    data[prdomain1] ||= 0
    data[prdomain1] += count.to_i
  end
  result = []
  data.each do |k, v|
    result << "#{v} #{k}"
  end
  result
end
```
