#include <iostream>
using namespace std;

int main() {
    int arr[7] = {1,7,10,4,8,2,11};
    int j, count = 0;
    for(int i = 1; i <= 7 - 1; i++){

        int temp = arr[i];
        for(j= i - 1; j >= 0; j--){

            if(arr[j] > temp){
                arr[j+1] = arr[j];
                count++;
            }
            else {
                break; 
            }
        }
        arr[j+1] = temp;
    } 
    for(int i = 0; i < 7; i++){
        cout << arr[i];
        cout << " ";
    }
}