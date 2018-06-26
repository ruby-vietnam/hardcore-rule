Problem1: https://leetcode.com/problems/subdomain-visit-count/description/

We can use Map to store the count of each domain. Then later just loop through each domain and return the list of results.

Time complexity is O(n) as length of each domain not exceed 100.
Space complexity is O(n)

```java
 public List<String> subdomainVisits(String[] cpdomains) {
    Map<String, Integer> countMap = new HashMap<>();
    List<String> results = new ArrayList<>();
    for (String cpdomain: cpdomains) {
      String[] cpdomainArr = cpdomain.split(" ");
      int accessTimes = Integer.parseInt(cpdomainArr[0]);
      String[] subDomains = cpdomainArr[1].split("\\.");
      String cur = "";
      for (int i = subDomains.length - 1; i >= 0; --i) {
          cur = subDomains[i] + (i < subDomains.length - 1 ? "." : "") + cur;
          countMap.put(cur, countMap.getOrDefault(cur, 0) + accessTimes);
      }
    }
    
    results = countMap.keySet().stream()
                      .map(domain -> countMap.get(domain) + " " + domain)
                      .collect(Collectors.toList());
    return results;             
  }
```
