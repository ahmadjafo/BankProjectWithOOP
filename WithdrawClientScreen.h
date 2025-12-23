
#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsWithdrawScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nEnter Account  Number: ";
        cin >> AccountNumber;
        return AccountNumber;

    }
public:


    static void WithdrawScreen()
    {
        _DrawScreenHeader("\Withdraw Screen", "");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n Client with " << "[" << AccountNumber << "] is not exsit.\n";
            cout << "Please enter AccountNumber ?";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);
        double Amount = 0;
        cout << "Please enter  Withdraw Amount  ?";
        Amount = clsInputeVildate::ReadDblNumber();
        cout << " Are you sure you want to Withdraw from this account ?";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\n Amount Withdraw. Successfully!\n";
                cout << "\n New Balance is :" << Client1.AccountBalance;

            }
            else
            {
                cout << "\nCannot Withdraw, Insuffecient Balance!\n";
                cout << "\n Amount to withdraw is : " << Amount;
                cout << "\n Your  Balance is :" << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "\n Operation was cancelled.\n";
        }






    }
};