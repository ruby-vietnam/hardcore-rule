string stonePiles(vector<int> arr) {
  int grundies[9] = {0, 0, 0, 1, 0, 2, 3, 4, 0};

  int res = 0;
	for(int i = 0; i < arr.size(); i++) {
		if (arr[i] < 9) {
			res ^= grundies[arr[i]];
		} else {
			res ^= arr[i] - 4;
		}
	}

  return (res != 0) ? "ALICE" : "BOB";
}
