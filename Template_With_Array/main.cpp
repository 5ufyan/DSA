#include <iostream>
#include "array.hh"

using namespace std;

int main()
{
    int i;
    Array<int> a(10);
    Array<float> b(5);

    for(i=0;i<4;i++){
        a.add(i);
        b.add(i*0.01f);
    }

    for(i=0;i<4;i++){
        cout <<"a["<<i<<"]= "<<a.get(i)<<",\tb["<<i<<"]= "<<b.get(i)<< endl;
    }

    a.clear();
    b.clear();
    return 0;
}
