
// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// This function returns the required number
// of triangles
int countTriangles(pair<int, int> P[], int N)
{
    // Hash Map to store the frequency of
    // slope corresponding to a point (X, Y)
    map<pair<int, int>, int> mp;
    int ans = 0;

    // Iterate over all possible points
    for (int i = 0; i < N; i++)
    {
        mp.clear();

        // Calculate slope of all elements
        // with current element
        for (int j = i + 1; j < N; j++)
        {
            int X = P[i].first - P[j].first;
            int Y = P[i].second - P[j].second;

            // find the slope with reduced
            // fraction
            int g = __gcd(X, Y);
            X /= g;
            Y /= g;
            mp[{X, Y}]++;
        }
        int num = N - (i + 1);

        // Total number of ways to form a triangle
        // having one point as current element
        ans += (num * (num - 1)) / 2;

        // Subtracting the total number of ways to
        // form a triangle having the same slope or are
        // collinear
        for (auto j : mp)
            ans -= (j.second * (j.second - 1)) / 2;
    }
    return ans;
}

// Driver Code to test above function
int main()
{
    int n;
    cin >> n;

    pair<int, int> P[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].first >> P[i].second;
    }
    cout << countTriangles(P, n) << endl;
    return 0;
}