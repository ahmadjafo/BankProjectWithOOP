
#include <iostream>
#include "ClsSreen.h" ;
#include "iomanip" ;

#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;
using namespace std;

class clsCleintListScrren : protected clsScreen
{
private:
    static void PrintClientRecoredLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(9) << Client.PinCode;
        cout << "| " << left << setw(10) << Client.AccountBalance;

    }
public:
    static  void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\tClient List Screen";
        string SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n\n";


        cout << "\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(9) << "Pin Code";
        cout << "| " << left << setw(10) << "Balance";
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;
        if (vClients.size() == 0)
            cout << "No Clients Available in the system :-(\n";
        else
        {
            for (clsBankClient Clients : vClients)
            {
                PrintClientRecoredLine(Clients);
                cout << endl;
            }

        }
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;


    }
};