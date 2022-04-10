//Newton_Method.c
#include "Header.h"

//Finds the Oblique Shock Angle
double ZeroExpanse(double x, double PMValue){
return pow(((gam+1.)/(gam-1.)),0.5) * atan(pow(((gam-1.)/(gam+1.)*(pow(x,2.)-1.)),0.5)) - atan(pow((pow(x,2.)-1.),0.5)) - PMValue;}

/*Function to find ExpanseGrad*/
double ExpanseGrad(double x, double PMValue){
    return (ZeroExpanse(x+dx, PMValue)-ZeroExpanse(x, PMValue))/dx;}

/*Function to guess where the solution might be*/
double newPMMach(double  c, double  m){return -c/m;}

/*Newton Method Solver, Computes Shock ANgle Beta from turn angle theta*/
double PMInverse_Newton(double PMValue, double MachGuess){guess = MachGuess;
    yval = ZeroExpanse(guess, PMValue); while(fabs(yval)> ERROR){
    m = ExpanseGrad(guess, PMValue); c = yval-m*guess;
    guess = newPMMach(c,m); yval = ZeroExpanse(guess, PMValue);} return guess;}
