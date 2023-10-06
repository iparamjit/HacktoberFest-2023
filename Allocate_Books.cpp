#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int mid, int B, vector<int> &A) {
	int cnt = B, sum = 0;
	for (int i = 0; i < A.size(); i++) {
		if (sum + A[i] <= mid) {
			sum = sum + A[i];
		} else {
			sum = 0;
			cnt -= 1;
			if (cnt == 0) {
				return false;
			}
			i -= 1;
		}
	}
	return true;
}

int books(vector<int> &A, int B) {
	if (B > A.size()) {
		return -1;
	}
	int l = 1, r = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (isPossible(mid, B, A)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
