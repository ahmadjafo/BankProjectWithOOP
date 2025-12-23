#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;


#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsAddNewScreen : protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client)
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
    static void AddNewClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeVildate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputeVildate::ReadString();
        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);


        ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _Print(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }


};