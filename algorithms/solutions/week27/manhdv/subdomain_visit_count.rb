# https://leetcode.com/problems/subdomain-visit-count/description/

def counting(domains_counter, domain, times)
  # Counting for lowest level domain
  domains_counter[domain] ||= 0
  domains_counter[domain] += times

  domain_parts = domain.split('.')
  part = domain_parts.last
  # Counting for top level domain
  domains_counter[part] ||= 0
  domains_counter[part] += times

  (domain_parts.size - 2).downto(1) do |level|
    part = domain_parts[level] + '.' + part
    # Counting for middle level domain
    domains_counter[part] ||= 0
    domains_counter[part] += times
  end
end

# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
  # Format: { domain: visited_times }
  domains_counter = {}

  cpdomains.each do |domain_info|
    visited_times, domain = domain_info.split(' ')
    counting(domains_counter, domain, visited_times.to_i)
  end

  domains_counter.map do |domain, visited_times|
    "#{visited_times} #{domain}"
  end
end
