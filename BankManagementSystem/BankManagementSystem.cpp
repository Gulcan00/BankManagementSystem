/** \file BankManagementSystem.cpp
*   \brief A bank system to manage accounts in a file
*   \description The system can add, modify, remove and display accounts from the file
*   \author Gulcan Damdelen
*   \date 11/09/2021
**/

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

//Function prototypes
int menu();
void addToFile();
void printAllFile();

struct account {
    int account_no;
    string first_name;
    string last_name;
    double balance;
};

/**
* <code>main</code> is the main function of the program
* <BR>
* @return Returns 0 if success, any other value otherwise
**/
int main()
{
    int choice;
    fstream file;
 //   List<account> bankRecord;
    account bankAcc;
    do {
        choice = menu();
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4: //show record
        {
            cout << "Enter the account number: ";
            cin >> bankAcc.account_no;
            //if (bankRecord.search(bankAcc) == success);
                //display bankAcc
            //else cout << "Bank account not found!\n";
            break;
        }
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8: //Quit the program
            break;
        default:
            cout << "Invalid option. Try again\n";
        }
    } while (choice != 8);

    cout << "\nGoodbye!";
    return 0;
}

/**
* <code>menu</code> displays menu of options to user and returns choice
* <BR>
* @return Returns the choice of user
*/
int menu()
{
    int choice;
    cout << "\n----BANK MANAGEMENT SYSTEM----\n";
    cout << "\n1) New record";
    cout << "\n2) Deposit";
    cout << "\n3) Withdraw";
    cout << "\n4) Show record";
    cout << "\n5) Show all records";
    cout << "\n6) Update record";
    cout << "\n7) Delete record";
    cout << "\n8) Quit";
    cout << "\nEnter choice: ";
    cin >> choice;
    return choice;
}

void addToFile()
{

}