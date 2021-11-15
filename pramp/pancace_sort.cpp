#include <iostream>
#include <vector>

using namespace std;

void flip(vector<int> &v, int k) {
	for (int i = 0; i <= k/2; ++i) {
		int tmp = v[i];
		v[i] = v[k-i];
		v[k-i] = tmp;
	}
}

int findMaxNum(const vector<int>& arr, int k) {
	int j = 0;
	for (int i = 0; i <= k; ++i) {
		if (arr[j] <= arr[i]) {
			j = i;
		}
	}
	return j;
}

void printV(vector<int> v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

vector<int> pancakeSort( const vector<int>& arr )
{
	vector<int> v = arr;
	for (int i = v.size()-1; i > 1; --i) { // O(n)
		int maxNumIdx = findMaxNum(v, i); // O(n)
		flip(v, maxNumIdx); // put the highest number in the beginning // O(n)
		flip(v, i); // put the highest number in the i-th place // O(n)
	}
	// Time: O(n) * [O(n) + O(n) + O(n)] = O(n2)
	// Space: O(n)
	return v;
}

int main() {
	vector<int> v = {1,5,4,3,2};
	vector<int> sorted = pancakeSort(v);
	printV(sorted);
	return 0;
}
