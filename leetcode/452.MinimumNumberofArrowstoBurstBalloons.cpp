class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int arrows = points.size();
        int minEnd = INT_MAX;
        for (int i = 0; i < points.size()-1; ++i) {
            if (points[i][1] >= points[i+1][0] && points[i+1][0] <= minEnd) {
                minEnd = min({minEnd, points[i][1], points[i+1][1]});
                --arrows;
            } else {
                minEnd = points[i][1];
            }
        }
        for (auto v : points) {
            cout << "[" << v[0] << " " << v[1] << "] ";
        }
        cout << endl;
        return arrows;
    }
};
