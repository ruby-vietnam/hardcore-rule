/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
var wordBreak = function(s, wordDict) {
  // For saving result
  const cache = {};

  // Try to split string str
  const attemp = (str) => {
    // If we got cache, then out
    if (cache[str]) { return cache[str]; }

    // Otherwise, we compute & save cache
    cache[str] = str === ''
      // If str is empty, we stop
      ? ['']
      // Otherwise
      : wordDict
        // Get all words could go further
        .filter(word => str.indexOf(word) === 0)
        // Then go & combine results using reduce()
        .reduce((results, word) => ([
          ...results,
          ...attemp(
            // Remove word from string
            str.slice(word.length)
          ).map(
            // Build sentence after going by add word prefix
            sentence => `${word} ${sentence}`.trim()
          )
        ]), []);

    // Then return the computed cache
    return cache[str];
  }

  // Let's go
  return attemp(s);
};
