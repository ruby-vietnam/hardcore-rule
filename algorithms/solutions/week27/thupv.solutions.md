## Problem 1
Link: https://leetcode.com/problems/subdomain-visit-count

 * 52 / 52 test cases passed.
 * Status: Accepted
 * Runtime: 76 ms
 
```ruby
def subdomain_visits(cpdomains)
    result_hash = {};
    cpdomains.each do |cpdomain|
        normal_cpdomain = cpdomain.split(' ')
        number = normal_cpdomain[0]
        domain = normal_cpdomain[1]
        splitted_domains = domain.split('.');
        while splitted_domains.length > 1 do
			merged_domain = splitted_domains.join('.')
            result_hash[merged_domain] = 0 if result_hash[merged_domain].nil?
            result_hash[merged_domain] += number.to_i
			splitted_domains -= [splitted_domains[0]]
        end
		merged_domain = splitted_domains.join('.')
		result_hash[splitted_domains[0]] = 0 if result_hash[merged_domain].nil?
		result_hash[splitted_domains[0]] += number.to_i
    end
    result = [];
    result_hash.each do |key, value|
        result << "#{value} #{key}"
    end
    result
end
```
