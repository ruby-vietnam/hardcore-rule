# #1
``` js
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function (cpdomains) {
    let obj = {};
    cpdomains.forEach((cp, idx) => {
        const item = extract(cp);
        if (idx === 0)
            Object.assign(obj, item);
        else
            Object.keys(item).forEach(prop => obj[prop] = (obj[prop] || 0) + item[prop])
    });
    return Object.keys(obj).map(prop => {
        return `${obj[prop]} ${prop}`;
    })
};

/**
 * 
 * @param {string} input 
 */
var extract = function (input) {
    const appears = input.split(' ');
    const words = appears[1].split('.');
    let domains = {};
    words.forEach((val, idx) => {
        domains[(words.slice(idx, words.length).join('.'))] = Number(appears[0]);
    });
    return domains;
}
```