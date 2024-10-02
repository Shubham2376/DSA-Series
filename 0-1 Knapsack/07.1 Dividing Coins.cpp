// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=367&page=show_problem&problem=503

// This problem is based on minimum subset sum difference 
#include<bits/stdc++.h>
using namespace std;
vector<int> isSubsetPoss(int arr[],int sum,int n){

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
    vector<int> v;
    for(int i = 0; i<=sum/2; i++){
        if(t[n][i] == true){
            v.push_back(i);
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
    for(int i = 0; i<v.size(); i++){
        mini = min(mini,range-2*v[i]);
    }
    return mini;
}

int main(){
    int n;
    cin >> n;
    while(n--){
    int m;
    cin >> m;
    int arr[m];
    for(int i = 0; i<m; i++){
        cin >> arr[i];
    }
    cout<< minimumDifference(arr,m)<< endl;
    }
    return 0;
}