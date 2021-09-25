# Medium 1: https://leetcode.com/problems/reveal-cards-in-increasing-order/submissions/
## Approach:
- Go backward from the target (sorted array) and construct the necessary output
  * Store the index of the card and simulate the action to take and move the next to the back.
  * Use queue to store the index so an index can be polled + enqueued again to the back
## Code
```
class Solution {
    fun deckRevealedIncreasing(deck: IntArray): IntArray {
        val sortedDeck = deck.sortedArray()
        val indexQueue = LinkedList<Int>()
        for (i in 0 until deck.size) {
            indexQueue.add(i)
        }
        val output = IntArray(deck.size)
        for (card in sortedDeck) {
            output[indexQueue.pollFirst()] = card
            if (!indexQueue.isEmpty()) {
                indexQueue.add(indexQueue.pollFirst())
            }
        }
        return output
    }
}
```
