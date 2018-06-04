/*
 *
 * Link: https://leetcode.com/problems/max-points-on-a-line
 *
 * 36 / 36 test cases passed.
 * Status: Accepted
 * Runtime: 10 ms
 * Your runtime beats 77.22 % of cpp submissions.
 *
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int answer = -1;

        int n = points.size();
        if (n <= 2) {
            return n;
        }

        int curMax, overlapPoints, verticalPoints;
        map<pair<int, int>, int> slopes;
        for(int i = 0; i < n; i++) {
            curMax = overlapPoints = verticalPoints = 0;

            for(int j = i+1; j < n; j++) {
                Point a = points[i];
                Point b = points[j];

                if (isIdentical(a, b)) {
                    overlapPoints++;
                } else if (a.x == b.x) {
                    verticalPoints++;
                } else {
                    int dy = b.y - a.y;
                    int dx = b.x - a.x;
                    int g = __gcd(dx, dy);

                    dy /= g;
                    dx /= g;

                    slopes[make_pair(dx, dy)]++;
                    curMax = max(curMax, slopes[make_pair(dx, dy)]);
                }

                curMax = max(curMax, verticalPoints);
            }

            answer = max(answer, curMax + overlapPoints + 1);
            slopes.clear();
        }

        return answer;
    }

private:
    bool isIdentical(Point a, Point b) {
        return (a.x == b.x && a.y == b.y);
    }
};