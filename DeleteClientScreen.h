
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;


#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsDeleteClientScreen : protected clsScreen
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


    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        string AccountNumber = "";
        string Titile = "\tUpdate Client";
        _DrawScreenHeader(Titile, "");
        cout << "\n\n";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeVildate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputeVildate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _DrawScreenHeader("\t Delete Client ", "");
        Client.Print();

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _Print(Client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};