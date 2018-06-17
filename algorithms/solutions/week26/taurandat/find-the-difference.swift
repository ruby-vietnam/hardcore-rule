class Solution {
    func findTheDifference(_ s: String, _ t: String) -> Character {
        var sum: UInt32 = 0

        for c in t.unicodeScalars {
            sum += c.value
        }

        for c in s.unicodeScalars {
            sum -= c.value
        }

        return Character(UnicodeScalar(sum)!)
    }
}
