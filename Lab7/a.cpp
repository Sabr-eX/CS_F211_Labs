#include <iostream>
#include <queue>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<int> heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }

    while(m){
        int a = heap.top();
        a /= 2;
        m--;
        heap.pop();
        heap.push(a);
    }
    int sum = 0;

    while(!heap.empty()){
        int a = heap.top();
        sum += a;
        heap.pop();
    }
    cout << sum << endl;
    return 0;
}
