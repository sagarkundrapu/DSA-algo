// this algo is used to find the maximum sum subarray in an array in O(n) time complexity
#include<bits/stdc++.h>
using namespace std;

// brute force approach would be to print all subarrays , which takes O(n^3) time complexity


void printAllSubarrays(int a[], int n){
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}

// brute force approach would be to check for all subarrays and calculate their sums which would take O(n^2) time complexity

void calculateSubarraysSum(int a[], int n){
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            maxsum = max(sum,maxsum);
        }
    }
    cout<<maxsum;
}

// optimized way is kadane's algorithm which takes O(n) time complexity
// Add each element to a running sum.
// Keep updating the maximum sum found so far.
// If the running sum becomes negative, reset it to 0.

void kadaneAlgo(int a[], int n){
    int cursum=0;
    int maxsum=INT_MIN;

    for(int i=0;i<n;i++){
        cursum+=a[i];
        maxsum=max(cursum,maxsum);
        if(cursum<0){
            cursum=0;
        }
    }
    cout<<maxsum;
}

int main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);

    printAllSubarrays(a,n);     // O(n^3)
    calculateSubarraysSum(a,n);     //O(n^2)
    kadaneAlgo(a,n);        //O(n)

    return 0;
}