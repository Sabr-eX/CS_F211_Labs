#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int litBulbs = 0, unLitBulbs = 0;
    int l = 0, r = 0;

    if (a[0] == 1)
        litBulbs++;
    else
        unLitBulbs++;

    int answer = 0;

    // Use sliding window

    while (l <= r && r < n)
    {
        // If we have more k than needed we decrease left limit
        // O(1)
        if (litBulbs > k)
        {
            a[l] == 1 ? litBulbs-- : unLitBulbs--;
            l++;
        }

        // If we have less than or equal k than needed we increase right limit
        if (litBulbs <= k)
        {
            answer += (r - l) + 1;
            r++;
            a[r] == 1 ? litBulbs++ : unLitBulbs++;
        }
    }

    cout << answer << endl;

    return 0;
}