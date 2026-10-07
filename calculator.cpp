#include <iostream>
#include <fstream>
using namespace std;
double add(double num1, double num2){
    return (num1 + num2);
    
};
double multiply(double num1, double num2){
    return (num1 * num2);
    
};
double subtract(double num1, double num2){
    return (num1 - num2);
    
};
double divide(double num1, double num2){
    if (num2 != 0){
    return (num1 / num2);
        
    }
    else{
        cout<<"Division by 0 is invalid."<<endl<<"\n";
        return 0;
    }
};
int main() {
    cout<<"======================================="<<endl;
    cout<<"              C++ CALCULATOR           "<<endl;
    cout<<"======================================="<<endl;
    int op;
    double x, y;
    do{
        string s[] = {"1. Addition", "2. Subtraction", "3. Multiplication", "4. Division", "5. Show History", "6. Exit"};
        cout<<"\nList of Operations -->\n";
        for (int i = 0; i < 6; i++){
            cout<<s[i]<<endl;
        }
        cout<<"Choose the serial number of operation you want to perform: "<<endl;
        cin>>op;
        if (op >= 1 && op <= 4){
        cout<<"Enter first number: "<<endl;
        cin>>x;
        cout<<"Enter second number: "<<endl;
        cin>>y;
        }
        ofstream f;
        ifstream o;
        string r;
        switch(op){
            case 1:
            cout<<"Sum of both numbers is: "<<add (x, y)<<"\n";
            f.open("history.txt", ios :: app);
            f<<x<<"+"<<y<<"="<<add(x, y)<<endl;
            f.close();
            break;
            case 2:
            cout<<"Difference of both numbers is: "<<subtract (x, y)<<"\n";
            f.open("history.txt", ios :: app);
            f<<x<<"-"<<y<<"="<<subtract(x, y)<<endl;
            f.close();
            break;
            case 3:
            cout<<"Product of both numbers is: "<<multiply (x, y)<<"\n";
            f.open("history.txt", ios :: app);
            f<<x<<"*"<<y<<"="<<multiply(x, y)<<endl;
            f.close();
            break;
            case 4:
            cout<<"Division of both numbers is: "<<divide (x, y)<<"\n";
            f.open("history.txt", ios :: app);
            f<<x<<"/"<<y<<"="<<divide(x, y)<<endl;
            f.close();
            break;
            case 5:
            o.open("history.txt");
            while (getline(o, r)){
                cout<<r<<endl;
            }
            o.close();
            break;
            case 6:
            cout<<"Exiting from calculator."<<endl;
            cout<<"---------------------------------------"<<endl;
            break;
            default:
            cout<<"Invalid number. Please enter a number between 1 and 6 as your choice."<<endl;
            break;
        }
    }
    while(op != 6);

    return 0;
}