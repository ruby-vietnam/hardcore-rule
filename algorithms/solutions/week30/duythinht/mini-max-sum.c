#include <stdio.h>

void miniMaxSum(int n, int* a) {
    long sum = 0, min = a[0], max = a[0];
    for (int i=0; i < n; i++) {
        sum += a[i];
        if (a[i] < min) {
            min = a[i];
        } else if (a[i] > max){
            max = a[i];
        }
    }
    printf("%ld %ld ", sum - max, sum - min);
}
