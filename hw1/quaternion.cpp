#include <iostream>
#include "libquater.h"
#include <cmath>
#include <algorithm>

using namespace std;

Quaternion::Quaternion(double a, double b, double c, double d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

Quaternion::Quaternion(const Quaternion &qua){
    this->a = qua.a;
    this->b = qua.b;
    this->c = qua.c;
    this->d = qua.d;
}

//setters
void Quaternion::set_a(double a){this->a = a;}
void Quaternion::set_b(double b){this->b = b;}
void Quaternion::set_c(double c){this->c = c;}
void Quaternion::set_d(double d){this->d = d;}

void Quaternion::set_all(double a, double b, double c, double d){
    set_a(a); set_b(b); set_c(c); set_d(d);
}

//getters
double Quaternion::get_a(){return this->a;}
double Quaternion::get_b(){return this->b;}
double Quaternion::get_c(){return this->c;}
double Quaternion::get_d(){return this->d;}


//print
void Quaternion::print(){
    cout<<get_a()<<" + "<<get_b()<<"i + "<<get_c()<<"j + "<<get_d()<<"k"<<endl;
}

//norm
double Quaternion::norm(){
    return(sqrt(a*a+b*b+c*c+d*d)); //^ - ne vozvedenie v stepen
}

//conjugation
Quaternion Quaternion::conjugation(){
        return Quaternion(a, -b, -c, -d);
}

//normalize
Quaternion Quaternion::normalize(){
    double n = norm();
    return Quaternion(a/n, b/n, c/n, d/n);
}

//inversion
Quaternion Quaternion::inversion(){
    double n2 = norm()*norm();
    return Quaternion(a/n2, -b/n2, -c/n2, -d/n2);
}

//operations
Quaternion operation(Quaternion q1, Quaternion q2, char z){
    if (z=='+'){
        return Quaternion (q1.get_a()+q2.get_a(), q1.get_b()+q2.get_b(), q1.get_c()+q2.get_c(), q1.get_d()+q2.get_d());
    }
    else if (z=='-'){
        return Quaternion (q1.get_a()-q2.get_a(), q1.get_b()-q2.get_b(), q1.get_c()-q2.get_c(), q1.get_d()-q2.get_d());
    }
    else if ((z=='*') or (z=='x')){
        if (z=='*'){
            cout<<"If you need a scalar product, use the function 'scalar prod' "<<endl;
        }
        return Quaternion (q1.get_a()*q2.get_a()+q1.get_b()*q2.get_b()+q1.get_c()*q2.get_c()+q1.get_d()*q2.get_d(),
        q1.get_a()*q2.get_b()+q1.get_b()*q2.get_a(),
        q1.get_a()*q2.get_c()+q1.get_c()*q2.get_a(),
        q1.get_a()*q2.get_d()+q1.get_d()*q2.get_a());
    }
    else if ((z=='/') or (z==':')){
        Quaternion q2inv = q2.inversion();
        return operation(q1, q2inv,'x');
    }
    else{
        cout<<"!!!!Not correct operation! The first introduced quaternion is output!!!!"<<endl;
        return q1;
    }
}

double scalar_prod(Quaternion q1, Quaternion q2){
    return (q1.get_a()*q2.get_a() + q1.get_b()*q2.get_b() + q1.get_c()*q2.get_c() + q1.get_d()*q2.get_d());
}

double euclid_dist(Quaternion q1, Quaternion q2){
    return (sqrt((pow((q1.get_a()-q2.get_a()), 2)) + (pow((q1.get_b()-q2.get_b()), 2)) + (pow((q1.get_c()-q2.get_c()), 2)) + (pow((q1.get_d()-q2.get_d()), 2))));
}

double Chebyshev_norm(Quaternion q1, Quaternion q2){
    return (max({abs(q1.get_a()-q2.get_a()), abs(q1.get_b()-q2.get_b()), abs(q1.get_c()-q2.get_c()), abs(q1.get_d()-q2.get_d())}));
}