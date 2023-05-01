#include <bits/stdc++.h>
using namespace std;

#define size 5
int main(){

float profit[size] = {30,40,45,77,90};
float weight[size] = {5,10,15,22,25};
int sack = 60;
int i = 0,j = 0;
float pr = 0;
float x[size] = {0};

float ratio[size] = {0};
    
    for(int a = 0; a<size ; a++){
    ratio[a] = profit[a]/weight[a];
    }
    
    for (int a = 0; a < size - 1; a++){
        for (j = 0; j < size - i - 1; j++){
            if (ratio[j] < ratio[j + 1]){
                swap(ratio[j], ratio[j + 1]);
                swap(profit[j],profit[j+1]);
                swap(weight[j],weight[j+1]);
            }
        }
    }
while (sack != 0){
    if(weight[i] <= sack){
        x[i] = 1.0;
        pr = pr + profit[i];
        sack = sack - weight[i];
    i++;
    }
    else{
        break;
    }
}
x[i] = sack/weight[i];
pr = pr + (x[i] * profit[i]);

cout << "Maximum profit = " << pr ;
}
