## Problem 1

```ruby
def build_domains(domain)
  init = ''

  domain.split('.').reverse.map do |part|
    init = if init == ''
      part
    else
      "#{part}.#{init}"
    end
  end
end

def subdomain_visits(cpdomains)
  hash = Hash.new { 0 }

  cpdomains.each do |cp_domain|
    count, domain = cp_domain.split(' ')
    count = count.to_i

    build_domains(domain).each do |dm|
      hash[dm] += count
    end
  end

  hash.inject([]) do |result, (key, value)|
    result << "#{value} #{key}"
  end
end
```
