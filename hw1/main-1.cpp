#include <iostream>
#include <cmath>
using namespace std;

class ellips{
    private:
        double V1[2], V2[2], F1[2], F2[2];
        double LR, e;
        int x0, y0; 
        double a, b, c;

        int bm = 0;
    

        void V(){
            if (bm == 0){
                V1[0] = x0 - a;
                V1[1] = y0;
                V2[0] = x0 + a;
                V2[1] = y0;
            }
            else{
                V1[0] = x0;
                V1[1] = y0 - a;
                V2[0] = x0;
                V2[1] = y0 + a;
            }
        }

        void F(){
            if (bm == 0){
                F1[0] = x0 - c;
                F1[1] = y0;
                F2[0] = x0 + c;
                F2[1] = y0;
            }
            else{
                F1[0] = x0;
                F1[1] = y0 - c;
                F2[0] = x0;
                F2[1] = y0 + c;
            }
        }

        void HORD(){
            LR = 2 * b*b / a;
        }

        void ex(){
            e = c/a;
        }
    public:
        ellips(double a_, double b_, int x_0 = 0, int y_0 = 0): x0(x_0), y0(y_0){ // Конструктор
            if (a_ < b_){
                bm = 1;
                swap(a_, b_);
            }
            a = a_;
            b = b_;
        }

        ellips(const ellips &help){
            a = help.a;
            b = help.b;
            x0 = help.x0;
            y0 = help.y0;
        }

        

        void set(double a_, double b_, int x_0 = 0, int y_0 = 0){ // Изменение значений
            if (a_ < b_){
                bm = 1;
                swap(a_, b_);
            }
            a = a_;
            b = b_;
            x0 = x_0;
            y0 = y_0;
        }

        double get_a(){
            return a;
        }
        double get_b(){
            return b;
        }
        double get_c(){
            return c;
        }
        int get_x0(){
            return x0;
        }
        int get_y0(){
            return y0;
        }
        double get_LR(){
            return LR;
        }
        double get_e(){
            return e;
        }
        double* get_V1(){
            return V1;
        }
        double* get_V2(){
            return V2;
        }
        double* get_F1(){
            return F1;
        }
        double* get_F2(){
            return F2;
        }

        void print(){ // ВЫВОД ХАРАКТЕРНЫХ ТОЧЕК
            V();
            F();
            cout << "x^2/" << a << "^2 + y^2/" << b << "^2 = 1" << endl;
            cout << "Center " << "(" << x0 << ", " << y0 << ")" << endl;
            cout << "V1 " << "(" << V1[0] << ", " << V1[1] << ")" << endl;
            cout << "V2 " << "(" << V2[0] << ", " << V2[1] << ")" << endl;
            cout << "F1 " << "(" << F1[0] << ", " << F1[1] << ")" << endl;
            cout << "F2 " << "(" << F2[0] << ", " << F2[1] << ")" << endl;
        }

        double giper(){ // гиперпараметр
            c = pow((a*a + b*b), (0.5)); 
            return c;
        }

        double S(){ // Площадь
            return 3.14 * a * b;
        }

        double P(){ // Периметр
            return 4 * (3.14 * a * b + (a - b))/(a + b);
        }

        char tochka(double x, double y){ // Проверка лежит ли точка в эллипсе 
            if ((pow(x, 2) / pow(a, 2) + pow(y, 2) / pow(b, 2)) < 1){
                return 'I'; // IN
            }
            else{
                return 'O'; // OUT
            }
        }

        pair<double, double> E(double z_, int xy_){ // E если xy_ = 0, то дана х, иначе дана у 
            if (xy_ == 0){
                double xy = z_;
                double yx = pow(((1 - xy*xy/(a*a))/(b*b)), 0.5); 
                //double *res;
                //cout << res[0] << endl;
                return pair<double, double>(yx+y0, -yx+y0);
            }
            else{
                double yx = z_;
                double xy = pow((1 - yx*yx/(b*b))/(a*a), 0.5); 
                //double res[2] = {xy, -xy};
                //cout << res[0] << endl;
                return pair<double, double>(xy+x0, -xy+x0);
            }
        }
};

int main()
{
    ellips el(3, 4); // Конструктор
    cout << el.giper() << endl; // гиперпараметр
    el.print(); // вывод того что есть, вершины фокусы
    el.set(5, 7, 2, 3); // переделка значений
    cout << el.P() << endl; // периметр
    cout << el.S() << endl; // площадь
    auto AAA = el.E(4, 1);
    cout << AAA.first << " " << AAA.second << endl; // вторая координата [11]
    cout << el.tochka(2, 3) << endl; // лежит ли внутри точка
    cout << el.get_a() << endl;
    cout << el.get_LR() << endl;
    return 0;

}