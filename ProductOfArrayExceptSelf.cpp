// product of array except itself means , we have to return an array in which each element is obtained by multipling remaining elements except itself
// And the worst part we should not use '/' operator and should br solved using O(1) space complexity

#include<bits/stdc++.h>
using namespace std;

// brute force approach evalutes using double loop mulipling each element except itself which takes O(n^2) time complexity O(1) space complexity
void BruteforceApproach(vector<int> a){
    int n=a.size();
    vector<int> ans(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                ans[i]*=a[j];
            }
        }
    }

    cout<<"brute force output: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

// slight optimized approach calculates the prefix and suffix product arrays for each element and multiplying them later which takes O(n) time complexity and O(n) space complexity
void slightOptimized(vector<int> a){
    int n=a.size();
    vector<int> ans(n,1);
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);

    // prefix
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*a[i-1];
    }
    // suffix
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*a[i+1];
    }

    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
    }
    cout<<"slightly optimized output: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

// final optimized approach includes not storing in extra vectors instead using the ans vector directly to store results which takes O(n) time complexity and O(1) space complexity
void optimized(vector<int> a){
    int n=a.size();
    vector<int> ans(n,1);

    // prefix => ans
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*a[i-1];
    }
    // suffix
    int suffix=1;
    for(int i=n-2;i>=0;i--){
        suffix*=a[i+1];
        ans[i]*=suffix;
    }

    cout<<"optimized output: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}


// main function
int main(){
    vector<int> a={1,2,3,4};
    BruteforceApproach(a);      // brute force O(n^2) TC, O(n) SC
    slightOptimized(a);     //slightly optimized O(n) TC, O(n) SC
    optimized(a);     // optimized O(n) TC, O(1) SC
    return 0;
}