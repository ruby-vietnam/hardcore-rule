int singleNumber(int* nums, int numsSize) {
  int answer = 0;
  for(int i = 0; i < numsSize; i++) {
    answer ^= nums[i];
  }
  return answer;
}
