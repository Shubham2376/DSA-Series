#include<bits/stdc++.h>
using namespace std;
vector<int> isSubsetPoss(int arr[],int sum, int n){
    // bottom up approach
    int t[n+1][sum+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0) t[i][j] = false;
            if(j == 0) t[i][j] = true;
        }
    }
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
    vector<int> v; //creating vector to store all the elements of last row of dp table which is all possible subset sum with n elements
    for(int i = 0; i<=sum; i++){
        if(t[n][i] == true){
            v.push_back(i); //store only those subset sum who is exist (true)
        }
    }
    return v;
}
int minimumDifference(int arr[],int n){
    int range = 0;
    for(int i = 0; i<n; i++){
        range += arr[i];
    }
    vector<int> v = isSubsetPoss(arr,range,n);
    int mini = INT_MAX;
    for(int i = 0; i<v.size(); i++){ //iteraing the vector which store all possible subset sum with n elements and determine the minimum subset sum difference
        mini = min(mini,abs(range-2*v[i]));
    }
    return mini;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout << minimumDifference(arr,n) << endl;
    return 0;
}

// Time complexity : O(n) + O(n*sum) + O(sum) + O(sum) -> O(n*sum) overall time complexity is dominated by dp table 
// Space complexity : O(n*sum) + O(sum) -> O(n*sum) 
//   as i use vector to store all possible subset sum which take space O(sum)