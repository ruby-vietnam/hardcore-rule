#Problem 1 
``` Java 
    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int num : arr){
            sum+=num;
            if (num > max)
                max = num;
            if (num < min){
                min = num;
            }
        } 
        System.out.print((sum - max) + " " + (sum - min));
    }
}
```
