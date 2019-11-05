//
// Created by juheeSVT on 2019-11-05.
//

#include <iostream>
using namespace std;

void festival(double const *cost, int minDay, int size){
    double minCost = cost[minDay]/minDay;
    for(int i = minDay; i < size; i++) {
        for (int k = 0; k + i <= size; k++) {
            if (minCost > (cost[k + i] - cost[k]) / i)
                minCost = (cost[k + i] - cost[k]) / i;
        }
    }
        printf("%.10lf\n" ,minCost);
}

int main(){

    int t, day, borrowedTeam;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> day >> borrowedTeam;
        auto * cost = new double[day+1]();
        double tmp;
        cost[0] = 0;
        for( int k = 0; k < day; k++){
            cin >> tmp;
            cost[k+1] = cost[k]+tmp;
        }
        festival(cost, borrowedTeam, day);
    }
}