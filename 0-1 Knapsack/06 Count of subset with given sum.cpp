// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include<iostream>
using namespace std;
// bottom up approach
int countSubsetsWithSum(int arr[],int sum,int n){
        int t[n+1][sum+1];
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i == 0) t[i][j] = 0; //when array is empty then there is no meaning of sum of elements so return 0
                if(j == 0) t[i][j] = 1; //when array sum(j) is 0 then there is always a chance of empty subset so return 1
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(arr[i-1] <= j){ //when elements in list is less than or equal to target sum
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j]; //either exclude or include and add both of them
                }
                else if(arr[i-1] > j){
                    t[i][j] = t[i-1][j]; //exclude when element in list is greater than target sum
                }
            }
        }
        return t[n][sum]; //finally return last row and last column element
}
int main(){
    int n, sum;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> sum;
    cout << countSubsetsWithSum(arr,sum,n) << endl;
    return 0;
}
// Time complexity : O(n*sum)
// space complexity : O(n*sum)