# Problem 1

## [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/description/)
```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i < cpdomains.length; i++) {
            count(map, cpdomains[i]);
        }
        List<String> result = new ArrayList<>();
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            result.add(entry.getValue() + " " + entry.getKey());
        }
        return result;
    }

    private void count(Map<String, Integer> map, String domain) {
        String[] eles = domain.split(" ");
        int time = Integer.parseInt(eles[0]);
        String[] subDomains = eles[1].split("\\.");
        String subDomain = subDomains[subDomains.length-1];
        if(map.containsKey(subDomain)) {
            map.put(subDomain, map.get(subDomain) + time);
        } else {
            map.put(subDomain, time);
        }
        for(int i = subDomains.length - 2; i >= 0; i--) {
            subDomain = subDomains[i] + "." + subDomain;
            int count = time;
            if(map.containsKey(subDomain)) {
                count += map.get(subDomain);
            }
            map.put(subDomain, count);
        }
    }
}
```
