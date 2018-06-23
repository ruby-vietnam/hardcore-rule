## Problem 1
https://leetcode.com/problems/subdomain-visit-count/description/

```
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    var hash = {}
    for(var cpdomain of cpdomains) {
        var domainAndCount = cpdomain.split(' ')
        var count = domainAndCount[0]
        var domain = domainAndCount[1]
        var arr = domain.split('.')
        var possibleDomains = []
        if (arr.length === 2) {
            possibleDomains = [domain, arr[1]]
        } else {
            possibleDomains = [domain, arr[2], [arr[1], arr[2]].join('.')]
        }
        for (var j of possibleDomains) {
            hash[j] = hash[j] || 0
            hash[j] += parseInt(count)
        }
    }
    var result = []
    for(k of Object.keys(hash)) {
        result.push(hash[k] + " " + k)
    }
    return result
};
```
