#include <iostream>
#include "../include/input.h"
using namespace std;

int getValidInput(const string& prompt){
    int x;
    
    while(true){
        cout << prompt;
        cin >> x;

        if(!cin.fail()){
            return x;
        }

        cout << "Enter valid input "<< endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}