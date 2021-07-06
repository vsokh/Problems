
#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define nl "\n"

#define ull unsigned long long
#define ll long long

#define f first
#define s second
#define mp make_pair
#define pb push_back

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vl vector<ll>
#define sl set<ll>
#define pl pair<ll, ll>

void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

class Solution {
public:
	template<typename T>
	void print_queue(T q) {
		cout << "PQ: " << nl;
		while (!q.empty()) {
			auto el = q.top(); q.pop();
			cout << "(e: " << el[0] << ", p: "<< el[1] << ", i: " << el[2] <<  ")" << nl;
		}
		cout << nl;
	}
    vector<int> getOrder(vector<vector<int>>& tasks) {
		// O (n)
		for (int i=0;i<tasks.size();++i)
			tasks[i].push_back(i);

		// O (n)
        int T = tasks[0][0];
        for (int i = 1; i < tasks.size(); ++i)
            T = min(T, tasks[i][0]);

		auto cmp_by_enq = [](vector<int> a, vector<int> b)
		{ return a[0] < b[0]; };

		sort(tasks.begin(), tasks.end(), cmp_by_enq);
		for (auto t: tasks) {
			cout << "(e: " << t[0] << ", p: "<< t[1] << ", i: " << t[2] <<  ")" << nl;
		}

		auto cmp = [&T](vector<int> a, vector<int> b)
		{ return b[1] < a[1] || b[0] <= a[0]; };

		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> PQ(cmp);
		// O (n log n)
		for (auto t : tasks)
			PQ.push(t);

        vector<int> order;
		// O (n log n)
		while (!PQ.empty()) {
			cout << "T: " << T << endl;
			print_queue(PQ);

			auto task = PQ.top();
			int task_processing_time = task[1], task_idx = task[2];
			T += task_processing_time;
			order.push_back(task_idx);

			PQ.pop();
		}
		return order;
    }
};

int main()
{
	Solution s;
	/* vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}}; */
	vector<vector<int>> tasks{{19,13},{16,9},{21,10},{32,25},{37,4},{49,24},{2,15},{38,41},{37,34},{33,6},{45,4},{18,18},{46,39},{12,24}};
	vector<int> order = s.getOrder(tasks);
	for (int &e : order)
		cout << e << " ";
	cout << nl;
	return 0;
}
