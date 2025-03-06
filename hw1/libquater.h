#pragma once

class Quaternion{
    private:
        double a, b, c, d;
    public:
        Quaternion(double a=1, double b=0, double c=0, double d=0);
        Quaternion(const Quaternion &qua);
        void set_a(double a); void set_b(double b); void set_c(double c); void set_d(double d);
        void set_all(double a, double b, double c, double d);
        double get_a(); double get_b(); double get_c(); double get_d();
        void print();
        double norm();
        Quaternion conjugation();
        Quaternion normalize();
        Quaternion inversion();
};

Quaternion operation(Quaternion q1, Quaternion q2, char z);
double scalar_prod(Quaternion q1, Quaternion q2);
double euclid_dist(Quaternion q1, Quaternion q2);
double Chebyshev_norm(Quaternion q1, Quaternion q2);