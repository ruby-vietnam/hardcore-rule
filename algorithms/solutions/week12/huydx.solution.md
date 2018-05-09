# Problem 1

Generic solution (not pass in very big num)

```
class Solution {
    private Map<Integer, Boolean> cache = new HashMap<>();
    public boolean canWinNim(int n) {
        if (n == 4) return false;
        if (n < 4) return true;

        cache.put(0, true);
        cache.put(1, true);
        cache.put(2, true);
        cache.put(3, true);
        cache.put(4, false);
        
        for (int i = 4; i <= n; i++) {
            boolean r = !cache.get(i-1) || !cache.get(i-2) || !cache.get(i-3);
            cache.put(i, r);
        }
        return cache.get(n);
    }
}
```

Tricky solution

```
class Solution {
    private Map<Integer, Boolean> cache = new HashMap<>();
    public boolean canWinNim(int n) {
      return !(n%4==0)
    }
}
```
