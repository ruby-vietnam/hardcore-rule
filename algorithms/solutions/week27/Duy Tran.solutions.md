# Problem 1
#### [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/description/)
```cs
public class Solution {
        public IList<string> SubdomainVisits(string[] cpdomains)
        {
            var domainCount = new Dictionary<string, int>();
            foreach (var cpdomain in cpdomains)
            {
                var count = int.Parse(cpdomain.Split(' ')[0]);
                var domain = cpdomain.Split(' ')[1];
                do
                {
                    if (domainCount.ContainsKey(domain))
                    {
                        domainCount[domain] += count;
                    }
                    else
                    {
                        domainCount.Add(domain, count);
                    }
                    var dotIndex = domain.IndexOf(".");
                    domain = dotIndex < 0 ? string.Empty : domain.Substring(dotIndex + 1);
                }
                while (!string.IsNullOrEmpty(domain));
            }
            
            return domainCount.Select(x => x.Value + " " + x.Key).ToList();
        }
}

```

