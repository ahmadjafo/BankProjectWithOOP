#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;

class clsDepositScreen : protected clsScreen
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
    static void DepositScreen()
    {
        _DrawScreenHeader("\tDeposit Screen", "");
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
        cout << "Please enter  Deposit Amount  ?";
        Amount = clsInputeVildate::ReadDblNumber();
        cout << " Are you sure you want to deposit from this account ?";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\n Amount Dposited saccessfully.\n";
            cout << "\nNew Balances is " << Client1.AccountBalance;
        }
        else
        {
            cout << "\n Operation was cancelled.\n";
        }






    }



};