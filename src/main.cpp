#include <iostream>
#include <exception>
#include "../include/calculator.h"
#include "../include/menu.h"
#include "../include/input.h"
using namespace std;


int main() {
    calculator calc;
    
    while (true){
        print();
        int choice = getValidInput("Enter calculation choice : ");
        
        if( choice == 0){
            cout << " ======= Exiting calculator ======= \n ";
            break;
        }
        if (choice < 0 || choice > 5) {
            cout << "❌ Invalid menu choice. Try again.\n";
            continue;
        }

        int a = getValidInput("Enter the value of a : ");
        int b = getValidInput("Enter the value of b : ");
        bool success = false;
        while(!success){
            try{
                switch (choice){
                case 1:
                    cout << "Result == " << calc.add(a,b) << endl; 
                    success = true;
                    break;
                case 2:
                    cout << "Result == " << calc.sub(a,b) << endl; 
                    success = true;
                    break;
                case 3:
                    cout << "Result == " << calc.multiply(a,b) << endl;
                    success = true; 
                    break;
                case 4:
                    cout << "Result == " << calc.divide(a,b) << endl; 
                    success = true;
                    break;
                case 5:
                    cout << "Result == " << calc.remainder(a,b) << endl; 
                    success = true;
                    break;
                }
            }
            catch (const exception& e) {
                cout << "⚠️  Error: " << e.what() << endl;
                cout << "Re - enter the values : " << endl;

                a = getValidInput("Enter the value of a : ");
                b = getValidInput("Enter the value of b : ");
            }
        }
        
    }

    return 0;
}