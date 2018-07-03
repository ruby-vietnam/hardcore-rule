# Problem 2

```java
    class Solution {
        List<List<Integer>> result;

        public List<List<Integer>> permute(int[] nums) {
            result = new ArrayList<>();

            permute(nums, 0);

            return result;
        }

        public void permute(int[] nums, int index) {
            if (index == nums.length){
                List<Integer> list = new ArrayList<>(nums.length);
                for(int i : nums){
                    list.add(i);
                }
                result.add(list);
            } else {
                for (int j = index; j < nums.length; j++){
                    int temp = nums[index];
                    nums[index] = nums[j];
                    nums[j] = temp;

                    permute(nums, index + 1);

                    temp = nums[index];
                    nums[index] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
```