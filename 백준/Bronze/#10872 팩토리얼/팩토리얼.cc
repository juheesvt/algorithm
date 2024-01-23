//
// Created by juheeSVT on 2019-09-03.
//
#include <iostream>

int factorial(int n){
    int result =1;
    for( int i =2; i<=n; i++){
        result*=i;
    }

    return result;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << factorial(n);
}