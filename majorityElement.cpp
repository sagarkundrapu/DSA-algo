#include<bits/stdc++.h>
using namespace std;

// brute force approach would be to count all elements individually and check if count > n/2

// calculate frequency of each element by nested loop and verify which takes O(n^2) time complexity
void calFrequency(int a[],int n){
    for(int i=0;i<n;i++){
        int freq=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                freq++;
            }
        }
        if(freq >n/2){
            cout<<"calfreq output: "<<a[i]<<endl;
            break;
        }
    }
}


// sort the array and verify the frequency which takes O(nlogn) time complexity
void sortArrayAndVerify(int a[],int n){
    sort(a,a+n);
    int freq=1,ans=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            freq++;
        }else{
            freq=1;
            ans=a[i];
        }

        if(freq>n/2){
            cout<<"after sorting output: "<<ans<<endl;
        }
    }
}

// Moore's voting algo : Moore’s Voting Algorithm is used to find the majority element in an array — an element that appears more than n/2 times — in O(n) time and O(1) space.
// The algorithm works on the idea of pair cancellation:
//      If two different elements are paired, they cancel each other.
//      Since the majority element appears more than all others combined, it will remain after all cancellations.

void mooreVotingAlgo(int a[], int n){
    int freq=0,ans=0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=a[i];
        }
        if(ans==a[i]){
            freq++;
        }else{
            freq--;
        }
    }

    // edge case where there is no majority element
    int count=0;
    for(int i=0;i<n;i++){
        if(ans==a[i]){
            count++;
        }
    }

    if(count>n/2)
        cout<<"moore's output: "<<ans;
    else
        cout<<-1;
        
    cout<<"moore's output: "<<ans;
    
}

// main function
int main(){
    int a[]={1,2,2,1,1};
    int n=sizeof(a)/sizeof(a[0]);

    calFrequency(a,n);      // bruteforce O(n^2)
    sortArrayAndVerify(a,n);     // slightly optimized O(nlogn)
    mooreVotingAlgo(a,n);       //optimized O(n)
    return 0;
}