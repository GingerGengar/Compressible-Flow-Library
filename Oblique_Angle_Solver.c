//Newton_Method.c
#include "Header.h"

//Finds the Oblique Shock Angle
double OblAngle(double x, double Mach, double theta){
return (2.0/tan(x)) * ((pow(Mach,2) * pow(sin(x),2) - 1.0)/(pow(Mach,2)*(gam + cos(2.0*x)) + 2.0)) - tan(theta);}

/*Function to find OblShockGrad*/
double OblShockGrad(double x, double Mach, double theta){
    return (OblAngle(x+dx, Mach, theta)-OblAngle(x, Mach, theta))/dx;}

/*Function to guess where the solution might be*/
double newOblAng(double  c, double  m){return -c/m;}

/*Newton Method Solver, Computes Shock ANgle Beta from turn angle theta*/
double theta2beta_Newton(double Mach, double theta, double betaguess){guess = betaguess;
    yval = OblAngle(guess, Mach, theta); while(fabs(yval)> ERROR){
    m = OblShockGrad(guess, Mach, theta); c = yval-m*guess;
    guess = newOblAng(c,m); yval = OblAngle(guess, Mach, theta);} return guess;}
