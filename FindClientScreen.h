
#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;

#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsFindClient: protected clsScreen
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
public:
    static void ShowFindClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        string Titile = "\tFind Client";
        _DrawScreenHeader(Titile, "");
        cout << "\n\n";
        string AccountNumber = "";


        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeVildate::ReadString();
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _Print(Client);
    }

};