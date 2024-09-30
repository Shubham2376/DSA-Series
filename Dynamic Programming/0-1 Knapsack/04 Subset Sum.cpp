#include<iostream>
using namespace std;
// bottom up approach
bool isSubsetPossible(int arr[], int sum, int n){
    bool t[n+1][sum+1]; //DP matrix
    // here we set first row and first column
    // i denotes the size of the array
    // j denotes the subset sum(target sum)
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
    }
}
// here we start from 1 since we already set first row and first column
for(int i = 1; i<n+1; i++){
    for(int j = 1; j<sum+1; j++){
        if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum]; //at last return T/F
}
int main(){
    int n,sum;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> sum;
    isSubsetPossible(arr,sum,n) ? cout << "true\n" : cout << "false\n";
    return 0;
}

// time complexity : O(n*sum) -> there are n*sum subproblem and each subproblem perform constant time operations
// space complexity : O(n*sum) -> size of 2-D array is n*sum
