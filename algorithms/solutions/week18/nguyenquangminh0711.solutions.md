## Problem 2

https://leetcode.com/problems/restore-ip-addresses/description/

Just normal loop. O(1)

```ruby
# @param {String} s
# @return {String[]}
def restore_ip_addresses(s)
    result = []
    len = s.length;
    i = 1
    while i < 4 && i < len - 2
        j = i + 1
        while j < i + 4 && j < len - 1
            k = j + 1
            while k < j + 4 && k < len
                s1 = s[0..i-1]
                s2 = s[i..j-1]
                s3 = s[j..k-1]
                s4 = s[k..len - 1]
                if is_valid(s1) && is_valid(s2) && is_valid(s3) && is_valid(s4)
                    result << "#{s1}.#{s2}.#{s3}.#{s4}"
                end
                k += 1
            end
            j += 1
        end
        i += 1
    end
    result
end
            
def is_valid(s)
    if s.length >3 || s.length ==0 || (s[0] =='0' && s.length > 1) || s.to_i > 255
        return false
    end
    true
end
```
