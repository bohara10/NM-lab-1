// Secant Method 

#include<iostream>
// Secant Method

#include<iomanip>
#include<cmath>

using namespace std;

float function(float x) {
    return sin(x) + x*x + 5*x - 9;
}

float formula(float x,float y,float z,float w){
    return x-((x-y)/(z-w))*z;
}

int main() {
    float num1,num2;

        cout << "Enter a number: ";
        cin >> num1;

        cout << "Enter a number: ";
        cin >> num2;
        
    
    cout << endl;
    int c;
    float  xi,fxi,xii,fxii,xiii,fxiii,error;
    c = 1;
  

    cout << "Iteration\txi-1\tf(xi-1)\txi\tf(xi)\txi+1\tf(xi+1)\tError\n";
    
    do {
        xi=num1;
        fxi=function(xi);
        
        xii=num2;
        fxii=function(xii);
        
        xiii=formula(xii,xi,fxii,fxi);
        fxiii=function(xiii);
        
        num1=xii;
        num2=xiii;
        
        error = (xii-xiii) / xiii;
        
        if (error < 0) {
            error = -error;
        }

        cout << fixed << setprecision(4) << c << "\t\t" << xi << "\t" << fxi << "\t" << xii << "\t" << fxii << "\t" << xiii << "\t" << fxiii << "\t" << error << "\n";
        c = c + 1;
        
        
        
    } while (error>0.05);

    cout << endl << "Final output: " << fixed << setprecision(2) << xiii;
    return 0;
}