#include<bits/stdc++.h>
using namespace std;

// brute force approach evaluates every possible container and find max area among them which takes O(n^2) time complexity
void calEveryContainer(vector<int> a){
    int area=0;
    int maxarea=0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            area=(j-i)*min(a[i],a[j]);
            maxarea=max(maxarea,area);
        }
    }
    cout<<"brute force output: "<<maxarea<<endl;
}

// optimized approach use two pointers to calculate max area which takes O(n) time complexity
// working steps:
    // two pointers (i,j) points to start and end index. and calculates the area which is basically area = min(ht[i],ht[j])*(j-i)
    // now the rules for moving the pointers are
        // if we move right pointer j--, here:- (ht[i] < ht[j]):
            // case1: ht[j--] < ht[j] then ar[i,j] > ar[i,j--] coz width decreases and the height still stays the same, here it is ht[i] <= ht[j--]
            // case2: ht[j--] > ht[j] then ar[i,j] > ar[i,j--] coz width decreases and the height still stays the same, here it is ht[i] < ht[j--]
            // case3: ht[j--] = ht[j] then ar[i,j] > ar[i,j--] coz width decreases and the height still stays the same, here it is ht[i] < ht[j--]
            // so if i(min) then i++ and if j(min) then j--
        // if we move left pointer i++, here:- (ht[i] > ht[j]):
            // case1: ht[i++] > ht[i] then ar[i,j] > ar[i++,j] coz width decreases and the height still stays the same, here it is ht[i++] > ht[j]
        // so on evaluating the above cases moving the pointer with max height has no value , so always move pointer with min height.
void TwoPointerApproach(vector<int> a){
    int n=a.size();
    int lp=0,rp=n-1,maxarea=0;
    int w=0,ht=0,area;

    while(lp<rp){
        w=rp-lp;
        ht=min(a[lp],a[rp]);
        area=w*ht;
        maxarea=max(maxarea,area);
        a[lp]<a[rp]?lp++:rp--;
    }
    cout<<"optimized output: "<<maxarea;
}

//main function
int main(){
    vector<int> a={1,8,6,2,5,4,8,3,7};
    calEveryContainer(a);       // brute force O(n^2)
    TwoPointerApproach(a);      // optimized O(n)
    return 0;
}