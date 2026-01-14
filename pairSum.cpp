#include<bits/stdc++.h>
using namespace std;

// brute force approach to return pairs of elements whose sum is equal to a given target sum

// fetching all possible pairs and verifying it with target takes O(n^2) time complexity

void verifyAllPairs(int a[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==target){
                cout<<a[i]<<" "<<a[j];
            }
        }
    }
}

// optimized approach using 2 pointers would take O(n) time complexity

void verifyAllPairsOptimized(int a[],int n,int target){
    int i=0;
    int j=n-1;
    while(i<j){
        if(a[i]+a[j]==target){
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;
            j--;
        }
        else if(a[i]+a[j]<target){
            i++;
        }
        else{
            j--;
        }
    }
}

// main function

int main(){
    int a[] = {2,7,11,15};
    int n=sizeof(a)/sizeof(a[0]);
    int target=9;
    verifyAllPairs(a,n,target);     // bruteforce O(n^2)
    return 0;
}