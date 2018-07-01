# Problem 1

```java
public static List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String cpdomain: cpdomains) {
            String[] domains = cpdomain.split(" ");
            String[] strSplits = domains[1].split("\\.");
            int count = Integer.valueOf(domains[0]);
            String s = "";
            for (int i = strSplits.length - 1; i >= 0; i--) {
                s = strSplits[i] + (i < strSplits.length - 1 ? "." : "") + s;
                map.put(s, map.getOrDefault(s, 0) + count);
            }
        }

        List<String> result = new ArrayList<>();
        for (String str: map.keySet()) {
            result.add(map.get(str) + " " + str);
        }
        return result;
    }
```