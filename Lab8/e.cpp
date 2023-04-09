#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> freq;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max = -1;
    for(int i = 0; i < m; i++){
        if(freq.find(a[i]) != freq.end()){
            freq[a[i]]++;
            if(freq[a[i]] == k){
                if(a[i] > max){
                    max = a[i];
                }
            }
            else if(a[i] == max){}
        }
        else{
            freq.insert({a[i], 1});
            if (freq[a[i]] == k)
            {
                if (a[i] > max)
                {
                    max = a[i];
                }
            }
        }
    }
}