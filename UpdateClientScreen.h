#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;


#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;

class clsUpdateClientScreen : protected clsScreen
{
private:


    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputeVildate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputeVildate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputeVildate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputeVildate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputeVildate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputeVildate::ReadFloatNumber();
    }

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
public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputeVildate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputeVildate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";


        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }

};

