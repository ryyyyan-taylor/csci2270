#include <iostream>
using namespace std;

struct Distance{

     int inches;
     int feet;
     Distance();
     Distance(int n, int x){
          feet = n;
          inches = x;
     }
};

//int main(){
//
//     Distance d(8, 11);
//     Distance g(13, 3);
//     Distance* ptr;
//
//     ptr = &d;
//     cout<<ptr->feet<<"ft "<<ptr->inches<<"in"<<endl;
//
//     ptr = &g;
//     cout<<ptr->feet<<"ft "<<ptr->inches<<"in"<<endl;
//
//     return 0;
//}

int main(){

     int a[] = {1, 2, 3};

     cout<<a<<endl;
     cout<<a+1<<endl;

     return 0;
}
