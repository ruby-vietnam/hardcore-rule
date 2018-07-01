## Problem 1 - [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/description/)

```go
func subdomainVisits(cpdomains []string) []string {
    m := make(map[string]int, len(cpdomains))
    
    for i := range cpdomains {
        num, domain := parseDomain(cpdomains[i])
        counting(m, num, domain)    
    }
    
    result := make([]string, len(m))
    n := 0
    for k, v := range m {
        result[n] = fmt.Sprintf("%d %s", v, k)
        n++
    }
    
    return result
}

func parseDomain(domain string) (num int, realDomain string) {
    realDomain = domain
    
    for i := range domain {
        if domain[i] == ' ' {
            num, _ = strconv.Atoi(domain[:i])
            realDomain = domain[i+1:]
            return
        }
    }
    
    return
}

func counting(m map[string]int, n int, realDomain string) {
    m[realDomain] += n
    for i := range realDomain {
        if realDomain[i] == '.' {
            m[realDomain[i+1:]] += n
        }
    }
}
```


## Problem 2 - [Directions Reduction](https://www.codewars.com/kata/directions-reduction/java)

```java
import java.util.*;

public class DirReduction {
    public static String[] dirReduc(String[] arr) {
        LinkedList<String> result = new LinkedList<>();
        
        boolean shouldRemove = false;
        for (String dir: arr) {
           if (result.size() == 0)
               result.add(dir);
           else {
              String last = result.getLast();
              switch (dir) {
                 case "NORTH":
                     shouldRemove = last.equals("SOUTH");
                     break;
                 case "SOUTH":
                     shouldRemove = last.equals("NORTH");
                     break;
                 case "EAST":
                     shouldRemove = last.equals("WEST");
                     break;
                 case "WEST":
                     shouldRemove = last.equals("EAST");
                     break;
              }
              if (shouldRemove) result.pollLast(); else result.add(dir);
           }
        }
        
        return result.toArray(new String[0]);
    }
}
```