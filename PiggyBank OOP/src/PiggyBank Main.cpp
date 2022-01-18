/*
Matthias Kim
Piggy Bank Lab OOP
12/11/2020
Extra: allows user to enter the projected amount of years they want to save for
*/

#include <iostream>
#include "Header.h"
#include <iomanip> 
#include <vector>


using namespace std;

int main()
{
    //variables
    int p = 0, n = 0, d = 0, q = 0, wks = 0, yrs = 0;
    string name = " ", choice = " ", h;
    bool flag = false;
    

    //print welcome
    cout << "Welcome to the Piggy Bank!\n" << endl;

    //error trap for user name
    flag = false;
    PiggyBank uN(name);
    name = uN.checkName(name);

    //ask for weeks saved
    do {
        flag = false;
        cout << "\nHow many weeks have you been saving for?  ";
        cin >> h;
        for (char i : h) {
            if (!isdigit(i)) {
                flag = true;
                cout << "Please enter a number.\n" << endl;
                break;
            }
        }
    } while (flag);
    wks = stoi(h);
    PiggyBank wk(wks);
    //wk.checkingWeeks(h);

    //extra
    PiggyBank y;
    flag = false;
    std::cout << "\nPress Y if you'd like to see how much you are projected to save in x years.   ";
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        yrs = stoi(y.forYears(h));
    }
    else {
        cout << "\nThat will be okay, continuing...\n" << endl;
    }
    
    //for loop to put the name of the coin based on the i position
    PiggyBank huh(name, 0, 0, 0, 0, wks, yrs);
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            h = "pennies";
            huh.checkingInput(h);
        }
        else if (i == 1) {
            h = "nickels";
            huh.checkingInput(h);
        }
        else if (i == 2) {
            h = "dimes";
            huh.checkingInput(h);
        }
        else if (i == 3) {
            h = "quarters";
            huh.checkingInput(h);
        }
    }
    
    //print savings statement
    huh.printSavingsStatement();

    cout << huh.toString();
    if (yrs > 0) {
        cout << huh.printYears();
    }
}
