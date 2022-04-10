//Var.c
#include "Header.h"

/*Definition of Specific Heats Ratio*/
double gam;

/*Definition of Gas Constant*/
double R;

//Initial Guess
double guess;

//The function evaluation corresponding to "guess"
double yval;

//The approximate derivative of the function
double m;

//The approximate constant 'c' in the linear approximation of function
double c;

//The target value of y
double y_supposed;

//Initialize the Problem Variables
void Initialize(){gam = 1.4; R = 287.058; return;}
