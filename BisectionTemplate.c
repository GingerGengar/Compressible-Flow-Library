#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Bisection Variables
#define HIGHERROR 0.0000000001
double prod; double guess1; double yval1; 
double guess2; double yval2; double yval3; double guess3;

/*If the two numbers have different signs, return true, if not, return false*/
bool DiffSign(double num1, double num2){
    prod = num1*num2; if (prod<0) {return true;} else {return false;}}

/*Function x*/
double y(double x){return x - 0.0324;}

/*Update Bisection*/
void BisectionUpdate(){guess3 = (guess1+ guess2)/2.; yval3 = y(guess3); return;}

/*Bisection Solver*/
void BisectionMethod(){
    //From initial x value, find the initial bisection
    guess3 = (guess1+ guess2)/2.;
    //From bisection in x, find the corresponding y at the bisection
    yval1= y(guess1); yval2 = y(guess2); yval3 = y(guess3);
    while(fabs(yval1)> HIGHERROR){BisectionUpdate(); 
    if (DiffSign(yval1, yval3)) {guess2 = guess3; yval2 = yval3;}
    else if (DiffSign(yval2,yval3)) {guess1= guess3; yval1= yval3;}
    else {printf("Bisection method fails"); break;}}return;}

int main(void){guess1= -7; guess2 = 10;
    BisectionMethod();
    printf("guess: %lf\n guess2: %lf\n", guess1, guess2);
    return 0;}
