// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<iostream>
using namespace std;
int knapsack(int wt[], int val[], int W, int n){
    // DP matrix
    int t[n+1][W+1];
    // here i denotes the size of array
    // j denotes the weight capacity of knapsack
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<W+1; j++){
            // when i = 0 -> there was nothing in array so maximum profit becomes to be 0
            // when j = 0 -> there was no capacity of knapsack so maximum profit becomes to be 0
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
            else if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
                }
            else if(wt[i-1] > j){
                    t[i][j] = t[i-1][j];
                }
            }
        }
    return t[n][W];
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
    cout << knapsack(wt,val,W,n) << endl;
    return 0;
}

// Time complexity : O(n*W) -> where n is size of the array and W is the capacity(weight) of knapsack
// Space complexity: O(n*W)  -> size of 2-D array is n*W