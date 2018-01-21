# Problem 1
```c
int* getRow(int rowIndex, int* returnSize) {
	int* result = malloc(sizeof(int) * (rowIndex + 1));
	int* temp = malloc(sizeof(int) * (rowIndex + 1));
	int* swap;

	for (int i = 0; i <= rowIndex; i++) {
		result[i] = 0;
		temp[i] = 0;
	}	

	temp[0] = 1;
	result[0] = 1;

	for (int i = 1; i <= rowIndex; i++) {
		swap = temp;
		temp = result;
		result = swap;

		for (int j = 1; j <= i ; j++) {
			result[j] = temp[j] + temp[j - 1];
		}
	}

	*returnSize = rowIndex + 1;
	return result;
}
```

# Problem 2
```c
bool checkValidString(char* s) {
	int minOpen = 0;
	int maxOpen = 0;

	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == '(')
			minOpen++;
		else
			minOpen--;
		if (s[i] != ')')
			maxOpen++;
		else
			maxOpen--;
		if (maxOpen < 0)
			return false;
		if (minOpen < 0)
			minOpen = 0;
	}
	return minOpen == 0;
}
```

# Problem 3
```c
void sort(int** envelopes, int envelopesRowSize, int envelopesColSize) {
	int* swap;
	for (int i = 0; i < envelopesRowSize; ++i) {
		for (int j = i+1;  j < envelopesRowSize; ++j) {
			if (envelopes[i][0] > envelopes[j][0]){
				swap = envelopes[i];
				envelopes[i] = envelopes[j];
				envelopes[j] = swap;
			} else if (envelopes[i][0] == envelopes[j][0]) {
				if (envelopes[i][1] > envelopes[j][1]){
					swap = envelopes[i];
					envelopes[i] = envelopes[j];
					envelopes[j] = swap;
				}
			}	
		}
	}
}

int maxEnvelopes(int** envelopes, int envelopesRowSize, int envelopesColSize) {
	sort(envelopes, envelopesRowSize, envelopesColSize); 
	int* count = malloc(sizeof(int) * envelopesRowSize);
	for (int i = 0; i < envelopesRowSize; ++i) {
		count[i] = 1;	
	}

	for (int i = 1; i < envelopesRowSize; ++i) {
		for (int j = 0; j < i; j++) {
			if (envelopes[i][0] > envelopes[j][0] &&
					envelopes[i][1] > envelopes[j][1] &&
					count[i] < count[j] + 1)
				count[i] = count[j] + 1;
		}
	}
	int max = 0;
	for (int i = 0; i < envelopesRowSize; ++i) {
		if (max < count[i])
			max = count[i];
	}

	return max;
}
```
