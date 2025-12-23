
#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;

#include "E://learnc++/Library/LibraryForCourse11/MyClsUtil.h" ;



#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsTotalBalanceScreen : protected clsScreen
{
private:
    static void _PrintClientRecoredBalancesLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;


    }
public:
    static  void ShowTotalBalanceList()
    {



        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        cout << "\n\t\t\t\t Client List (" << vClients.size() << ") Clinet(s).";
        cout << "\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(10) << "Balance";
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;
        double T = 0;
        T += clsBankClient::GetTotalBalances();
        if (vClients.size() == 0)
            cout << "No Clients Available in the system :-(\n";


        else
        {

            for (clsBankClient Clients : vClients)
            {
                _PrintClientRecoredBalancesLine(Clients);
                cout << endl;
            }

        }
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;


        cout << "\t\t\t\t Total Balances = " << T << endl;
        cout << "\t\t\t\t" << " ( " << clsUtil::NumberToText(T) << ")" << endl;




    }

};
