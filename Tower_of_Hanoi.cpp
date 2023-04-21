#include <iostream>
using namespace std;

void TOW(int n, char X, char Y, char Z){

    if (n == 0){
        return;
    }
        TOW (n-1, X, Z, Y);
        cout << "Move Disk " << n << " from rod " << X << " to rod " << Y << endl;
        TOW (n-1, Z, Y, X);
}

int main(){

    TOW(2,'X','Z','Y');
    return 0;
}


