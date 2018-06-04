package duythinht

//https://leetcode.com/problems/sum-of-square-numbers/description/

func coinChange(coins []int, amount int) int {

	exchangeTable := make([]int, amount+1)

	for value := 1; value < len(exchangeTable); value++ {
		exchangeTable[value] = -1
		for _, coin := range coins {
			if coin > value {
				continue
			}
			count := 1 + exchangeTable[value-coin]
			if count > 0 && (count < exchangeTable[value] || exchangeTable[value] < 0) {
				exchangeTable[value] = count
			}
		}
	}
	return exchangeTable[amount]
}
