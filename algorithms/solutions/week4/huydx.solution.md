
# Problem 2
```
class Solution {
    public void sortColors(int[] nums) {
        int w = 0;
        int r = 0;
        int b = 0;
        for (int i : nums) {
            if (i == 0) { r++; }
            else if (i == 1) { w++; }
            else if (i == 2) { b++; }
        }

        for (int i = 0; i < r; i++) {
            nums[i] = 0;
        }
        for (int i = r; i < r+w; i++) {
            nums[i] = 1;
        }
        for (int i = r+w; i < r+w+b; i++) {
            nums[i] = 2;
        }
    }
}
```

# Problem 3

```sh
cat words.txt | tr \[:space:\] "\n" | sed '/^$/d' | sort | uniq -c | sort -nr | awk '{print $2,$1}'
```
