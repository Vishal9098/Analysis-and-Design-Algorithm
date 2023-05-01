#include <bits/stdc++.h>
#include<vector>
#include<stdlib.h>
using namespace std;

struct treenode {
   
   struct treenode *rchild;
   struct treenode *lchild;
   int weight;
};

struct treenode *pt;

int Tree(vector <int> a,int n) {

    int count = 0;
    for (int i = 0 ; i < n - 1 ; i++) {
        pt = new treenode;
        pt -> lchild = a[i];
        pt -> rchild = a[i+1];
        pt -> weight = ((pt -> lchild) -> weight) + ((pt -> rchild) -> weight);
        count += pt -> weight;
        
    }
    return count;

}

int main() {
    int n; 
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++ ){
        cin >> a[i];
    }

    cout << "Minimum = " << Tree(a,n);
    return 0;
}