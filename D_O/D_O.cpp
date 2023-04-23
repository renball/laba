#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

double func(double x, double r) {
    return (r * x ) / (1 + x * x * x);
}

double func_pr(double x, double r) {
    return abs(r * (1-2*x*x*x)) / ((1 + x * x * x) * (1 + x * x * x));
}

int main()
{
    int k;
    fstream tx_r,tx_r2;
    cin >> k;
    double X[1000]; X[0] = 0.001;
    double r=0.0;
    if (k == 1) {
        tx_r.open("results.txt");
        for (r = 0.0; r < 2600; r++) {
            for (int i = 1; i < 1000; i++) {
                X[i] = func(X[i - 1], r / 100);
            }
            for (int i = 0; i < 20; i++) {
                cout << r / 100 << " " << X[999 - i] << "\n";
                tx_r << r / 100 << " " << X[999 - i] << "\n";
            }
        }
        tx_r.close();
    }
    else if (k == 2) {
        double X[1500]; X[0] = 0.001;
        double r = 4;

        tx_r.open("results2.txt");
        tx_r2.open("results2_2.txt");
        for (int i = 1; i < 1500; i++) {
            X[i] = func(X[i - 1], r );
            tx_r << X[i - 1] << " " << X[i] << "\n";
        }
        int i = 0;
        int j = 0;
        while (i<1500 || j<1500){
            cout << X[i] << " " << X[j] << "\n";
            tx_r2 << X[i] << " " << X[j] << "\n";
            j++;
            cout << X[i] << " " << X[j] << "\n";
            tx_r2 << X[i] << " " << X[j] << "\n";
            i++;
        }

        tx_r.close();
    }

    else if (k == 3) {
        int n = 100000;
        long double A;
        tx_r.open("results3.txt");
        double X[100000]; X[0] = 0.001;
        double r = 0.0;
        for (r = 0.0; r < 5000; r++) {
            for (int i = 1; i < 100000; i++) {
                X[i] = func(X[i - 1], r/100);
            }
            A = 0.0;
            for (int i = 0; i < 100000; i++) {
                A += log(func_pr(X[i], r/100));
            }
            A = A / n;
            cout << r / 100 << " " << A << "\n";
            tx_r << r / 100 << " " << A << "\n";
        }
        tx_r.close();
    }

}
