#include "Header.h"

/*Function to find root of*/
double ARZero(double x, double Ratio){
return (1./x)*pow((2./(gam+1)*(1.+(gam-1.)/2.*x*x)),((gam+1.)/(2.*(gam-1.)))) - Ratio;}

/*Function to find AreaRatioGrad*/
double AreaRatioGrad(double x, double Ratio){return (ARZero(x+dx, Ratio)-ARZero(x, Ratio))/dx;}

/*Function to guess where the solution might be*/
double newAreaRatio(double c, double m){return -c/m;}

/*Inverse the Area Ratio Relations, guess<0 (sub), guess>0 (sup)*/
double AAstarRInv_Newton(double Ratio, double guess){
    yval = ARZero(guess,Ratio); while(fabs(yval)> ERROR){
    m = AreaRatioGrad(guess,Ratio); c = yval-m*guess;
    guess = newAreaRatio(c,m); yval = ARZero(guess,Ratio);}
    return guess;}
