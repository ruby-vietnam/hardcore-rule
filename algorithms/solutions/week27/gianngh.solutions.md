# Problem 1

```javascript
var subdomainVisits = function(cpdomains) {
  let obj = {};
  let response = [];
  for (let str of cpdomains) {
    let temp = str.split(" ");
    let num = parseInt(temp[0]);
    let domain = temp[1].split(".");
    let key = domain.pop();
    obj[key] = obj[key] ? obj[key] + num : num;

    while (domain.length > 0) {
      key = domain.pop() + "." + key;
      obj[key] = obj[key] ? obj[key] + num : num;
    }
  }

  for (let i in obj) {
    response.push(obj[i] + " " + i);
  }

  return response;
};
```
