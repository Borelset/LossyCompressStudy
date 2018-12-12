//
// Created by xdnzx on 2018/12/11.
//

#ifndef SZ_FITMETHODS_H
#define SZ_FITMETHODS_H

static double m0(double x1, double x2, double x3){
    return x3;
}

static double m1(double x1, double x2, double x3){
    return x3 * 2 - x2;
}

static double m2(double x1, double x2, double x3){
    return (x1 + x2 + x3) / 3;
}

static double m3(double x1, double x2, double x3){
    return 0.0;
}

static double m4(double x1, double x2, double x3){
    return x3 * x2 / x1;
}

static double m5(double x1, double x2, double x3){
    return x1;
}

static double(*methodArray[])(double, double, double) = {
        m0, m1, m2, m3, m4, m5
};


#endif //SZ_FITMETHODS_H
