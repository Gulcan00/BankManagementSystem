/** \file BankManagementSystem.cpp
*   \brief A bank system to manage accounts in a binary file
*   \description The system can add, modify, remove and display accounts from the file
*   \author Gulcan Damdelen
*   \date 11/09/2021
*/

#include <fstream>
#include <iomanip>
#include "LINKED_LIST.h"
using namespace std;

//Function prototypes
int menu();
void fileToList(List<Account> &records);
void recordToFile(Account &record);
void print(Account &);
void header();  

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
            records.insert(record);

            file.open("BankRecords.dat", ios::in | ios::binary);
            if (file.fail())
            {
                file.close();
                file.open("BankRecords.dat", ios::out | ios::binary);//create file if it does not exist
                file.close();
            }
            if(!file.fail()) {
                file.close();
                recordToFile(record);
                records.clear();
                fileToList(records);
                file.open("BankRecords.dat", ios::out | ios::binary);
                file.close();
                records.traverse(recordToFile);
            }
           
            break;
        case 2: //deposit
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter amount to deposit: ";
            cin >> record.balance;
            records.clear();
            fileToList(records);
            if (records.modify("DEPOSIT", record) == success)
            {
                cout << "Balance has been updated";
                file.open("BankRecords.dat", ios::out | ios::binary);
                file.close();
                records.traverse(recordToFile);
            }
            else cout << "Account not found";
            break;
        case 3: //withdraw 
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            cout << "Enter amount to withdraw: ";
            cin >> record.balance;
            records.clear();
            fileToList(records);
            if (records.modify("WITHDRAW", record) == success)
            {
                cout << "Balance has been updated";
                file.open("BankRecords.dat", ios::out | ios::binary);
                file.close();
                records.traverse(recordToFile);
            }
            else cout << "Account not found";
            break;
        case 4: //show record
        {
            records.clear();
            fileToList(records);
            cout << "Enter the account number: ";
            cin >> record.account_no;
            if (records.search(record) == success)
            {
                header();
                print(record);
            }
            else cout << "Account does not exist!";
            break;
        }
        case 5: //show all records
            records.clear();
            fileToList(records);
            header();
            records.traverse(print);
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
            records.clear();
            fileToList(records);
            if (records.modify("UPDATE", record) == success)
            {
                cout << "Account has been updated";
                file.open("BankRecords.dat", ios::out);
                file.close();
                records.traverse(recordToFile);
            }
            else cout << "Account does not exist!";
            break;

        case 7: //delete record
            cout << "\nEnter account number: ";
            cin >> record.account_no;
            records.clear();
            fileToList(records);
            if (records.remove(record) == success)
            {
                cout << "Account has been deleted.";
                file.open("BankRecords.dat", ios::out);
                file.close();
                records.traverse(recordToFile);
            }
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

/**
* <code>fileToList</code> takes all records from file and adds them to a list 
* @param records The list which the records will be added to 
*/
void fileToList(List<Account>& records)
{
    fstream file;
    file.open("BankRecords.dat", ios::in | ios::binary);
    Account record;
    while (file.read(reinterpret_cast<char*> (&record), sizeof(Account)))
    {
        records.insert(record);
    }
    file.close();
}

/**
* <code>recordToFile</code> writes a record to the binary file
* @param record The account struct containing user bank details
*/
void recordToFile(Account &record)
{
    fstream binaryio;
    binaryio.open("BankRecords.dat", ios::app | ios::binary);
    binaryio.write(reinterpret_cast<char*>(&record), sizeof(Account));
    binaryio.close();
}


/**
* <code>print</code> print displays the bank record of a user
* @param item The struct containg details of bank record
*/
void print(Account& item)
{
    cout << item.account_no << setw(10) << " " << item.first_name << setw(10) << " " << item.last_name << setw(10);
    cout << " "  << item.balance << endl;
}

/**
* <code>header</code> prints the header line 
*/
void header()
{
    cout << "---------------------------------------------------------------------------\n";
    cout << "ACC. ID    |    NAME       |   SURNAME    |   BALANCE" << endl;
    cout << "---------------------------------------------------------------------------\n";
}
