// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=367&page=show_problem&problem=503
#include<iostream>
using namespace std;
bool isSubsetPossible(int arr[],int sum,int n){
    int t[n+1][sum+1];
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
    return t[n][sum];
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
    int sum = 0;
    for(int i = 0; i<m; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        cout << 1 << endl;
    }
    else if(isSubsetPossible(arr,sum/2,m)){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }

    }
    return 0;
}