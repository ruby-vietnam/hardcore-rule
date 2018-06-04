/*
 *
 * Link: https://leetcode.com/problems/split-array-with-same-average
 *
 * 88 / 88 test cases passed.
 * Status: Accepted
 * Runtime: 94 ms
 * Your runtime beats 44.61 of cpp submissions.
 *
 */

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() == 1) {
            return false;
        }

        int h = A.size() / 2;

        vector<pair<int, int>> numbers = normalize(A);

        set<pair<int, int>> lhs = generate(vector<pair<int, int>>(numbers.begin(), numbers.begin() + h));
        if (lhs.find(make_pair(0, 1)) != lhs.end()) {
            return true;
        }

        set<pair<int, int>> rhs = generate(vector<pair<int, int>>(numbers.begin() + h, numbers.end()));
        if (rhs.find(make_pair(0, 1)) != rhs.end()) {
            return true;
        }

        pair<int, int> l_sum = sum(vector<pair<int, int>>(numbers.begin(), numbers.begin() + h));
        pair<int, int> r_sum = sum(vector<pair<int, int>>(numbers.begin() + h, numbers.end()));

        for (auto x: lhs) {
            auto it = rhs.find(make_pair(-x.first, x.second));
            if (it != rhs.end() && x != l_sum && (*it) != r_sum) {
                return true;
            }
        }

        return false;
    }

private:
    int gcd(int a, int b) {
        while(b) a %= b, swap(a, b);
        return a;
    }

    set<pair<int, int>> generate(vector<pair<int, int>> numbers) {
        set<pair<int, int>> result;
        int m = numbers.size();

        result.insert(numbers[0]);
        for(int mask = 1, mx = 1 << m; mask < mx; ++mask) {
            int numerator = 0, denominator = 1;

            for (int j = 0; j < m; ++j) {
                int t_numerator, t_denominator;
                if (mask & (1 << j)) {
                    t_numerator = numerator * numbers[j].second + denominator * numbers[j].first;
                    t_denominator = denominator * numbers[j].second;

                    numerator = t_numerator / gcd(t_numerator, t_denominator);
                    denominator = t_denominator / gcd(t_numerator, t_denominator);
                }
            }

            if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
                numerator = -numerator;
                denominator = -denominator;
            }

            result.insert(make_pair(numerator, denominator));
        }

        return result;
    }

    int sum(vector<int> numbers) {
        int sum = 0;

        for(int i = 0; i < numbers.size(); i++) {
            sum += numbers[i];
        }

        return sum;
    }

    pair<int, int> sum(vector<pair<int, int>> numbers) {
        int numerator = 0;
        int denominator = 1;

        for(int i = 0; i < numbers.size(); i++) {
            int t_numerator = numerator * numbers[i].second + denominator * numbers[i].first;
            int t_denominator = denominator * numbers[i].second;

            numerator = t_numerator / gcd(t_numerator, t_denominator);
            denominator = t_denominator / gcd(t_numerator, t_denominator);
        }

        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
            numerator = -numerator;
            denominator = -denominator;
        }

        return make_pair(numerator, denominator);
    }

    pair<int, int> average(vector<int> numbers) {
        int _sum = sum(numbers);
        int n = numbers.size();

        int numerator = _sum / gcd(_sum, n);
        int denominator = n / gcd(_sum, n);

        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
            numerator = -numerator;
            denominator = -denominator;
        }

        return make_pair(numerator, denominator);
    }

    vector<pair<int, int>> normalize(vector<int>& numbers) {
        pair<int, int> mean = average(numbers);
        int a = mean.first;
        int b = mean.second;

        vector<pair<int, int>> normalized_numbers;
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int t = numbers[i] * b - a;
            int numerator = t / gcd(t, b);
            int denominator = b / gcd(t, b);

            if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)) {
                numerator = -numerator;
                denominator = -denominator;
            }

            normalized_numbers.push_back(make_pair(numerator, denominator));
        }

        return normalized_numbers;
    }
};
