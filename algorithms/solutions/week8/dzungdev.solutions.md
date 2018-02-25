Problem1

We just loop through the word and each word will check whether the array contains all the partitially part of the word. Time complexity is O(n^2)

```java
public boolean isWord(String word, String[] words) {
    char[] chars = word.toCharArray();
    for (int i = 1; i <= chars.length;i++) {
      String wordPart = new String(chars, 0, i);
      boolean result = Arrays.stream(words).anyMatch(wordPart::equals);
      if (result == false) return false;
    }
    return true;
  }
  
  public String longestWord(String[] words) {
    
    Comparator<String> sortByLengthAndLexico = (String str1, String str2) -> {
        if (str1.length() == str2.length()) return str1.compareTo(str2);
        return str2.length() - str1.length();
    };
    Arrays.sort(words, sortByLengthAndLexico);
    for (String word: words) {
      if (isWord(word, words)) {
        return word;//return the longest, we sorted already so just get the first one
      }
    }
    return null;
  }
```
