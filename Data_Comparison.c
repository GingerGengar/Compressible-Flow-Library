//
#include "Header.h"

/*Find the percentage difference between true quantity and Approximate Quantity*/
double PercDiff(double TrueQ, double ApproxQ){
    return fabs((TrueQ-ApproxQ)/TrueQ)*100.;}
