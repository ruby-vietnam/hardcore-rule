#Bai 1: https://leetcode.com/problems/maximum-product-of-three-numbers/solution/


Solution from interviewcake:
https://www.interviewcake.com/question/cpp/highest-product-of-3#_=_

```
  int highestProductOf3(const vector<int>& vectorOfInts)
{
    if (vectorOfInts.size() < 3) {
        throw invalid_argument("Less than 3 items!");
    }

    // we're going to start at the 3rd item (at index 2)
    // so pre-populate highests and lowests based on the first 2 items.
    // we could also start these as null and check below if they're set
    // but this is arguably cleaner
    int highest = max(vectorOfInts[0], vectorOfInts[1]);
    int lowest  = min(vectorOfInts[0], vectorOfInts[1]);

    int highestProductOf2 = vectorOfInts[0] * vectorOfInts[1];
    int lowestProductOf2  = vectorOfInts[0] * vectorOfInts[1];

    // except this one--we pre-populate it for the first *3* items.
    // this means in our first pass it'll check against itself, which is fine.
    int highestProductOf3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];

    // walk through items, starting at index 2
    for (size_t i = 2; i < vectorOfInts.size(); ++i) {
        int current = vectorOfInts[i];

        // do we have a new highest product of 3?
        // it's either the current highest,
        // or the current times the highest product of two
        // or the current times the lowest product of two
        highestProductOf3 = max(max(
            highestProductOf3,
            current * highestProductOf2),
            current * lowestProductOf2);

        // do we have a new highest product of two?
        highestProductOf2 = max(max(
            highestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new lowest product of two?
        lowestProductOf2 = min(min(
            lowestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new highest?
        highest = max(highest, current);

        // do we have a new lowest?
        lowest = min(lowest, current);
    }

    return highestProductOf3;
}
```
