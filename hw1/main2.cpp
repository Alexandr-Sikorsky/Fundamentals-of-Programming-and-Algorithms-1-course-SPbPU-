#include <iostream>
#include "libquater.h"

using namespace std;

int main(){
    Quaternion q1(1,1,1,1), q2(4,5,8);

    cout<<endl<<"--- Quaternion 1 ---"<<endl;
    q1.print();
    cout<<"Norm: "<<q1.norm()<<endl;

    cout<<"--- Quaternion 2 ---"<<endl;
    q2.print();


    cout<<endl<<"--- Quaternion 1 after changes ---"<<endl;
    q1.set_all(4,6,8,10);
    q1.print();
    cout<<"Changed Norm: "<<q1.norm()<<endl;

    cout<<endl<<"--- Quaternion 2 after changes ---"<<endl;
    q2.set_d(9);
    q2.print();


    cout<<"--- Conjugation for Quaternion 1 ---"<<endl;
    q1.conjugation().print();

    cout<<endl<<"--- Normalised Quaternion 1 ---"<<endl;
    q1.normalize().print();

    cout<<endl<<"--- Inversion of Quaternion 1 ---"<<endl;
    q1.inversion().print();

//////////////////////////////////////////////////////////////////////

    Quaternion q3(2,5,2,6), q4(1,1,1,1);

    cout<<endl<<"--- Quaternion 1 * Quaternion 2 ---"<<endl;
    operation(q1, q2, '*').print();

    cout<<endl<<"--- Quaternion 3 / Quaternion 4 ---"<<endl;
    operation(q3, q4, '/').print();

    cout<<endl<<"--- Quaternion 2 ^ Quaternion 3 ---"<<endl;
    operation(q2, q3, '^').print();


    cout<<endl<<"--- Scalar product of Quaternion 2 and Quaternion 4 ---"<<endl;
    cout<<scalar_prod(q2,q4)<<endl;

    cout<<endl<<"--- Euclid Dist between Quaternion 1 and Quaternion 3 ---"<<endl;
    cout<<euclid_dist(q1,q3)<<endl;

    cout<<endl<<"--- Chebushev norm of Quaternion 1 and Quaternion 4 ---"<<endl;
    cout<<Chebyshev_norm(q1,q4)<<endl;

    return 0;
}