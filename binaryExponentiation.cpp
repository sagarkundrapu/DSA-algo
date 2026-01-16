// A number 'n' which is in decimal form has 'logn(base2)+1' number of digits in binary form
// ex: n=8 (decimal) => 1000 (binary) [logn(base2)+1 => log8(base2)+1 = 3+1 = 4 digits] 

#include<bits/stdc++.h>
using namespace std;

// brute force approach is multipling n(given power) times to the given number to calculate the given exponent. which takes O(n) time complexity
void calPower(int num, int pow){
    int ans=1;
    for(int i=0;i<pow;i++){
        ans*=num;
    }
    cout<<"brute force output: "<<ans<<endl;
}

// optimized approach is by calculating the binary form of given pow which has log(pow)(base2)+1 digits which takes O(logn) time complexity
// working steps:
//      ex: calculate 3^5 
//              normal exponentiation  -> 3*3*3*3*3 (in general) takes O(n) time complexity
//              binary exponentiation steps:
                    // calculate binary form for given 'pow' (here pow=5 -> 101 (binary form))
                    // here each digit in binary has index (here 1(x^4)0(x^2)1(x^1) => 1(3^4)0(3^2)1(3^1) => (3^4)(3^1) => 3^5) here it takes only O(logn) time complexity which is the number of digits in the binary form.
                    // u may get doubt in calculating x^4,x^8,x^16 ..... which has to be calculated again in the regular mannar, but here is the catch we can use the value obtained from previous power value by just squaring it.
                    // which is x^1 => val=x,  x^2=> val = val*val, x^4=val*val,...... 

void binaryExponentiation(int num, int pow){
    int binform = pow;
    if(pow<0){
        num=1/num;
        binform=-binform;
    }
    int ans = 1;  
    
    while(binform>0){
        if(binform%2==1){
            ans*=num;
        }
        num*=num;
        binform/=2;
    }
    cout<<"optimized output: "<<ans;
}

//main function 
int main(){
    int num=3;
    int pow=5;
    calPower(num,pow);      // brute force O(n)
    binaryExponentiation(num,pow);      //optimized O(logn)
    return 0;
}