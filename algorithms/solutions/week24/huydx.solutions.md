# Problem 1

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int low = 0;
        int high = (int)Math.sqrt(c);
        while (low <= high) {
            if (low*low + high*high == c) {
                return true;
            }
            if (low*low + high*high < c) {
                low++;
            } else {
                high--;
            }
        }
        return false;
    }
}
```

# Problem 2

```java
class Solution {
    public String largestNumber(int[] nums) {
        List<String> numsStr = toString(nums);
        Collections.sort(numsStr, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2) {
                return Long.compare(
                    Long.parseLong(o2+o1), Long.parseLong(o1+o2));
            }
        });
        String s = String.join("", numsStr);
        int idx = 0;
        while (s.charAt(idx) == '0' && idx < s.length()-1) {
            idx++;
        }
        return s.substring(idx);
    }
    
    private List<String> toString(int[] nums) {
        List<String> arr = new ArrayList<>();
        for (int n : nums) {
            arr.add(Long.toString(n));
        }
        return arr;
    }
}
```
