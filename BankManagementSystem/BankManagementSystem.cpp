/** \file BankManagementSystem.cpp
*   \brief A bank system to manage accounts in a file
*   \description The system can add, modify, remove and display accounts from the file
*   \author Gulcan Damdelen
*   \date 11/09/2021
*/

#include <fstream>
#include "LINKED_LIST.h"
using namespace std;

//Function prototypes
int menu();
void addToFile();
void printAllFile();
void header(); //print titles of columns 

/**
* <code>main</code> is the main function of the program
* <BR>
* @return Returns 0 if success, any other value otherwise
*/
int main()
{
    int choice;
    fstream file;
    Account record;
    List<Account> records;
    do {
        choice = menu();
        switch (choice)
        {
        case 1: //new record 
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter first name: ";
            cin >> record.first_name;
            cout << "Enter last name: ";
            cin >> record.last_name;
            cout << "Enter balance: ";
            cin >> record.balance;

            //file.open("BankRecords.txt", ios::)//use binary file (c++ book pg 531)
            /*
            * 1)check if file exits, if not create file
            * 2)if there is stuff on file add to list
            * 3) clear file and send all from list to file
            */
            records.insert(record);
            break;
        case 2: //deposit
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter amount to deposit: ";
            cin >> record.balance;
            records.modify("DEPOSIT", record);
            cout << "Balance has been updated";
            break;
        case 3: //withdraw 
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter amount to withdraw: ";
            cin >> record.balance;
            records.modify("WITHDRAW", record);
            cout << "Balance has been updated";
            break;
        case 4: //show record
        {
            cout << "Enter the account number: ";
            cin >> record.account_no;
            if (records.search(record) == success)
            {

            }
            else cout << "Account does not exist!";
            break;
        }
        case 5: //show all records
            //print from file or list 
            break;
        case 6: //update record
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter first name: ";
            cin >> record.first_name;
            cout << "Enter last name: ";
            cin >> record.last_name;
            cout << "Enter balance: ";
            cin >> record.balance;
            if (records.modify("UPDATE", record) == success)
                cout << "Account has been updated";
            else cout << "Account does not exist!";
            break;
        case 7: //delete record
            //filetolist function if the file exists and list is empty
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            if (records.remove(record) == success)
                cout << "Account has been deleted.";
            else cout << "Account does not exist!";
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