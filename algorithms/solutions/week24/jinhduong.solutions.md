# #1
``` csharp
public class Solution {
    private string[] keyboards = new string[] { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
    public string[] FindWords(string[] words) {
        List<string> result = new List<string>();
            foreach (var word in words)
            {
                var isCorrect = false;
                if (keyboards[0].IndexOf(word.ToLower()[0]) > -1)
                    isCorrect = isInclude(word, 0);
                else if (keyboards[1].IndexOf(word.ToLower()[0]) > -1)
                    isCorrect = isInclude(word, 1);
                else
                    isCorrect = isInclude(word, 2);

                if (isCorrect) result.Add(word);
            }

            return result.ToArray();
    }
    public bool isInclude(string word, int rowIndex)
        {
            foreach (var c in word)
                if (keyboards[rowIndex].IndexOf(Char.ToLower(c)) < 0)
                    return false;
            return true;
        }
}
```