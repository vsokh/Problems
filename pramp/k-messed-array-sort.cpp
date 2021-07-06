/*
function sortKMessedArray(arr, k):
    n = arr.length

    # create an empty min-heap
    h = new MinHeap()

    # build the min-heap from the first k+1 elements of arr
    h.buildHeap(arr[0,...,k])

    for i from k+1 to n-1:
        # extract the top element from the min-heap and
        # assign it to the next available array index
        arr[i-(k+1)] = h.extractMin()

        # push the next array element into the min-heap
        h.insert(arr[i])

    # extract all remaining elements from the min-heap
    # and assign them to the next available array index
    for i from 0 to k:
        arr[n-k-1 + i] = h.extractMin()

    return arr
	*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long

vector<ll> sortKMessedArray(vector<ll> const &arr, ll k)
{
	vector<ll> v = arr;
	priority_queue<ll, vector<ll>, greater<ll>> minHeap(greater<ll>(),
			vector<ll>(v.begin(), v.begin()+k+1));
	for (ll i=k+1;i<v.size();++i) {
		v[i-(k+1)]=minHeap.top(); minHeap.pop();
		minHeap.push(v[i]);
	}
	for (ll i=0;i<=k;++i) {
		v[v.size()-k-1+i]=minHeap.top();minHeap.pop();
	}
	for(ll i:v) cout << i << " ";
	cout << endl;
	return v;
}

int main()
{
	sortKMessedArray({1,4,5,2,3,7,8,6,10,9}, 2);
	return 0;
}
