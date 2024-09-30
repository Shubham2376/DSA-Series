#include <iostream>
using namespace std;
const int D = 100;
int t[D][D];
int knapsack(int wt[], int val[], int n, int W){
    if(n == 0 || W == 0) return 0;
    if(t[n][W] != -1) {
        return t[n][W];
    }
    else{
        if(wt[n-1] <= W){
        t[n][W] = max(val[n-1] + knapsack(wt,val,n-1,W-wt[n-1]),knapsack(wt,val,n-1,W));
    }
    else{
        t[n][W] = knapsack(wt,val,n-1,W);
    }
    return t[n][W];
    }
}
int main(){
    int n, W;
    cin >> n;
    int wt[n],val[n];
    for(int i = 0; i<n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i<n; i++){
        cin >> val[i];
    }
    cin >> W;
    // matrix initalization
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=W; j++){
            t[i][j] = -1;
        }
    }
    cout << knapsack(wt,val,n,W);
    return 0;
}

// Time Complexity : O(n * W)  -> there are n*W subproblem and each subproblem do constant amount of work
// space Complexity : O(n * W) + O(n) - > o(n*W) for table and O(n) for recursive stack