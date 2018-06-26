## Problem 1

```javascript
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
const subdomainVisits = ds => {
	if (!Array.isArray(ds) || ds.length === 0) return [];
	
	const nd = {};
  for (x of ds) {
  	 const [i, d] = x.split(' ');
  	 const n = +i;
  	 nd[d] = nd[d] ? nd[d] + n : n;
  	 
  	 const [d1, d2, d3] = d.split('.');
  	 
  	 if (d3) {
  	 	  const d23 = `${d2}.${d3}`;
  	 	  nd[d23] = nd[d23] ? nd[d23] + n : n;
  	 	  nd[d3] = nd[d3] ? nd[d3] + n : n;
  	 } else {
  	 	  nd[d2] =nd[d2] ? nd[d2] + n : n;
  	 }
  }
  
  return Object.keys(nd).map(k => 
  	  `${nd[k]} ${k}`);
};
```
