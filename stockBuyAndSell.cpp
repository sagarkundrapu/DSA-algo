// calculate the maximum profit by buying and selling the stocks

#include<bits/stdc++.h>
using namespace std;

// brute force approach evaluates every stock price with other stocks prices which takes O(n^2) time complexity
void calMaxProfit(vector<int> prices){
    int buy=0;
    int maxprofit=0;

    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
            buy=prices[i];
            if(prices[j]>buy){
                maxprofit=max(maxprofit,prices[j]-buy);
            }
        }
    }
    cout<<"brute force: "<<maxprofit<<endl;
}

// optimized approach evaluates by buyying the stocks every day and selling them for the maxprofit which takes O(n) time complexity
void optimizedApproach(vector<int> prices){
    int maxprofit=0;
    int bestBuy=prices[0];

    for(int i=0;i<prices.size();i++){
        if(prices[i]>bestBuy){
            maxprofit=max(maxprofit,prices[i]-bestBuy);
        }
        bestBuy=min(bestBuy,prices[i]);
    }
    cout<<"optimized: "<<maxprofit;
}

//main function
int main(){
    vector<int> stockPrice = {7,1,5,3,6,4};
    calMaxProfit(stockPrice);   // brute force O(n^2)
    optimizedApproach(stockPrice);      //optimized O(n)

    return 0;
}