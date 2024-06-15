//
// Created by juheeSVT on 2019-08-10.
//


#include <iostream>
using namespace std;


int sum(int a, int b){
    return a+b;
}

int main(){

    int t;
    int a,b;

    cin >> t;
    for (int i =0; i<t; i++){
        cin >> a >> b;
        cout <<"Case #" << i+1<< ": "<<a<< " + " << b <<" = " <<sum(a,b)<<endl;
    }
}