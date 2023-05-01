#include <iostream>
using namespace std;

int a[6] = {45,7,23,65,56,12};
int i = 0, j = 5;
int MaxMin(int i, int j, int max, int min){ 
    if(i == j){
        return max = min = a[i];
    }
    else if(i = j - 1){ 
        
        if(a[i] < a[j]){
        max = a[j];
        min = a[i];
        }
            else{
                max = a[i];
                min = a[j];
            }
}
    else{
        int max1 = 0, min1 = 0;
        int mid = (i+j)/2;
        MaxMin(i,mid,max,min);
        MaxMin(mid + 1, j, max1, min1);

        if (max < max1){
            return max = max1;
        }
        if(min > min1){
            return min = min1;
        }
    }
}
int main(){

}  