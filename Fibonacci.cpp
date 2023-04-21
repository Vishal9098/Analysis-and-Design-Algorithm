#include <iostream>
using namespace std;

void fibonacci(int n){

int a = 0;
int b = 1;
int c = a + b;

for (int i = 0; i < n; i++){

    c = a + b;
    a = b;
    b = c;
    cout << "Number = " << c << " ";
}
}

int main() {
 
    fibonacci(4);

 return 0;
}