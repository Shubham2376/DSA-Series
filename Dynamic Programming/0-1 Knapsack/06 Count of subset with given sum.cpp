// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include<iostream>
using namespace std;
// bottom up approach
int countSubsets(int arr[],int sum,int n){

}
int main(){
    int n, sum;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> sum;
    cout << countSubsets(arr,sum,n) << endl;
    return 0;
}