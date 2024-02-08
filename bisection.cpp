// Bisection Method
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float function(float x) {
    return sin(x) + x*x + 5*x - 9;
}

int main() {
    float num1,num2;
    do{
        cout << "Enter a number which will give positive output: ";
        cin >> num1;
        if(function(num1)<0){
        cout<<"Invalid Input!";
        }
    }while(function(num1)<0);
        
    do{
        cout << "Enter a number which will give negative output: ";
        cin >> num2;
        if(function(num2)>0){
            cout<<"Invalid Input!";
        }
    }while(function(num2)>0);
    
    cout << endl;
    int c;
    float  xu,fxu,xl,fxl,xm,fxm,error,xmold;
    c = 1;
  

    cout << "Iteration\txu\tf(xu)\txl\tf(xl)\txm\tf(xm)\tError\n";
    
    do {
        xu=num1;
        xmold=xm;
  
        fxu=function(xu);
        xl=num2;
        fxl=function(xl);
        xm=(xu+xl)/2;
        fxm=function(xm);
        
        
        if(fxm>0){
            num1=xm;
        } else{
            num2=xm;
        }
        
        error = (xm-xmold) / xm;
        
        if (error < 0) {
            error = -error;
        }

        cout << fixed << setprecision(3) << c << "\t\t" << xu << "\t" << fxu << "\t" << xl << "\t" << fxl << "\t" << xm << "\t" << fxm << "\t" << error << "\n";
        c = c + 1;
        
        
        
    } while (error>0.05);

    cout << endl << "Final output: " << fixed << setprecision(2) << xm;
    return 0;
}