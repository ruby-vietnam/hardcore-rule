Problem1: https://leetcode.com/problems/keyboard-row/description/

We can use Map to store all the character. All characters are in same line will have same value. 
Then we loop through the string array and for each word, we loop through each character. 
We can check if one character has value different with previous character, then that word is not created by characters which are in same line in keyboard.

Time complexity is: O(n)
Space complexity is: O(1)

```java
private void addCharsToMap(Map<Character, Integer> charMap, char[] chars, int charRowNum) {
      for (char c: chars) {
        charMap.put(c, charRowNum);
      }
    }  
  
    public String[] findWords(String[] words) {
        Map<Character, Integer> charMap = new HashMap<>();
    addCharsToMap(charMap, new char[] { '~', '`', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '1', '2',
        '3', '4', '5', '6', '7', '8', '9', '0', '-', '=' }, 1);
    addCharsToMap(charMap, new char[] { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', '}', '[', ']' }, 2);
    addCharsToMap(charMap, new char[] { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', ':', '"' }, 3);
    addCharsToMap(charMap, new char[] { 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '<', ',', '>', '?' }, 4);
    List<String> results = new ArrayList<>();
    for (String word : words) {
      char[] chars = word.toLowerCase().toCharArray();
      boolean isSameLine = true;
      for (int j = 0; j < chars.length - 1; j++) {
        if (charMap.get(chars[j]).intValue() != charMap.get(chars[j + 1]).intValue()) {
          isSameLine = false;
          break;
        }
      }
      if (isSameLine) results.add(word);
    }
    return results.toArray(new String[] {});
    }
```

Problem2: https://leetcode.com/problems/friend-circles/description/

We can use DFS to check from each node. We just have on visited array to store visited node, if we start countting from new node which isn't visited, then increase the count.

Time complexity is: O(n^2) as we still need to check all nodes.
Space complexity is: O(n)

```java
public void dfs(int[][] M, int[] visited, int i) {
    for (int j = 0; j < M.length;j++) {
      if (M[i][j] == 1 && visited[j] == 0) {
        visited[j] = 1;
        dfs(M, visited,j);
      }
    }
  }
  
  public int findCircleNum(int[][] M) {
    
    int[] visited = new int[M.length];
    int count = 0;
    for (int i = 0; i < M.length;i++) {
      if (visited[i] == 0) {
        dfs(M, visited, i);
        count++;
      }
    }
    return count;
  }
```



