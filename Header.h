//Include Guards
#ifndef CLOUD
#define CLOUD

//For Printing outputs
#include <stdio.h>

//For accepting Command Line Arguments
#include <stdlib.h>

//For Mathematical Computations
#include <math.h>

//For Boolean types
#include <stdbool.h>

//Accuracy of the Newton Method Solver
#define ERROR 0.0000000000012
#define dx 0.0000000000000017

//Variable Prototypes
extern double gam;
extern double R;
extern double guess;
extern double yval;
extern double m;
extern double c;
extern double y_supposed;

//Function Prototypes
//Var
void Initialize();
//In Ideal Gas
double PT2d(double P,double T);
//In Isentropic
double SoundSpeed(double T);
double IseCon(double M);
double Ts2T0(double T,double M);
double T02Ts(double T0,double M);
double Ps2P0(double P,double M);
double P02Ps(double P0,double M);
double Ds2D0(double rho, double M);
double D02Ds(double rho0, double M);
double AAstarRatio(double M);
double AAstarRInv(double Ratio, double guess);
//In Shocks
double ShoCon1(double Mach);
double ShoCon2(double Mach);
double MachNormal(double Mach, double beta);
double ShockMach(double Mach);
double beta2theta(double Mach, double beta);
double MachTrue(double NMach, double beta, double theta);
double PAftNShock(double Mach, double Pressure);
double TAftNShock(double Mach, double Temperature);
double P0AftNShock(double Mach, double Pressure);
double PMfunc(double Mach);
double MAftExpansion(double Mach, double theta);
//In Oblique Angle Solver
double OblAngle(double x, double Mach, double theta);
double  OblShockGrad(double x, double Mach, double theta);
double newOblAng(double  c, double  m);
double theta2beta_Newton(double Mach, double theta, double betaguess);
//In Prandtl-Meyer Expansion Mach Solver
double ZeroExpanse(double x, double PMValue);
double ExpanseGrad(double x, double PMValue);
double newPMMach(double  c, double  m);
double PMInverse_Newton(double PMValue, double MachGuess);
//In Isentropic CD Area Inverse
double AAstarRInv_Newton(double Ratio, double guess);
//In Data Comparison
double PercDiff(double TrueQ, double ApproxQ);
double deg2rad(double deg);
double rad2deg(double rad);

#endif
