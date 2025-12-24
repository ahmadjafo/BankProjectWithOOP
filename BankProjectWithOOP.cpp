// ShowMainMenue.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
#include"ClientListScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include"FindClientScreen.h" ;
#include "iomanip" ;
#include "WithdrawClientScreen.h" ;
#include"DepositClientScreen.h" ;
#include"TotalClientBalance.h" ;
#include "UpdateUserScreen.h";
#include "FindUserScreen.h" ;
#include "AddNewUserScreen.h" ;
#include "DeleteUserScreen.h" ;
#include "UserListScreen.h" ;
using namespace std;
class clsUserManageScreen : protected clsScreen
{
private:
    enum enManageUsersMenueOptions { enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMenue = 6 };
    static void _ShowListUsersScreen()
    {
        //cout << "List Users Screen Will be here in the soon";
        clsUserListScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "Add New User Screen Will be here in the soon";
        clsAddNewUserScreen::ShowAddNewUserstScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "Delete User Screen Will be here in the soon";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "Update User Screen Will be here in the soon";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        // cout << "Find User Screen Will be here in the soon";
        clsFindUserScreen::ShowFindUser();
    }
    static void _ShowMainMenueScreen()
    {


    }

    static short ReadNumberForManageUsersMenueOptions()
    {
        cout << "\nChoose what do you want to do ? [1 to 6]";
        short Number = clsInputeVildate::ReadIntNumberBetween(1, 6, "Wrong PLease enter Again");


        return Number;
    }
    static  void _GoBackToManageUsersMenue()
    {
        cout << "\nPress any key to go back to Manage Users Menue....";
        system("pause>0");

        ShowManageUserScreen();
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions Choose)
    {
        switch (Choose)
        {
        case enManageUsersMenueOptions::enListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();


            break;
        }

        case enManageUsersMenueOptions::enAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();

            break;

        }


        case enManageUsersMenueOptions::enDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();

            break;
        }

        case enManageUsersMenueOptions::enUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue(); ;
            break;
        }


        case enManageUsersMenueOptions::enFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue(); ;
            break;
        }


        case enManageUsersMenueOptions::enMainMenue:
        {
            system("cls");
            _ShowMainMenueScreen();

            break;
        }


        }
    }

public:

    static void ShowManageUserScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        clsScreen::_DrawScreenHeader("Manage Users Menue");
        cout << "\n\n";
        cout << "\n\t\t\t\t================================================";
        cout << "\n\t\t\t\t\t\t Manage Users Menue ";
        cout << "\n\t\t\t\t================================================";
        cout << "\n\t\t\t\t\t\t [1] List Uesrs.";
        cout << "\n\t\t\t\t\t\t [2] Add New User.";
        cout << "\n\t\t\t\t\t\t [3] Delete User.";
        cout << "\n\t\t\t\t\t\t [4] Update User.";
        cout << "\n\t\t\t\t\t\t [5] Find User.";
        cout << "\n\t\t\t\t\t\t [6] Main Menue .";
        cout << "\n\t\t\t\t================================================";
        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadNumberForManageUsersMenueOptions());

    }
};

class clsTranseationsScreem : protected clsScreen
{
private:
    enum enManageUsersMenueOptions {
        enDeposit = 1, enWithDraw = 2
        , enShowTotalBalances = 3, enShowMainMenue = 4
    };

    static short ReadNumberForTranseactionsMenueOptions()
    {
        cout << "\nChoose what do you want to do ? [1 to 4]";
        short Number = clsInputeVildate::ReadIntNumberBetween(1, 4, "Wrong PLease enter Again");


        return Number;
    }


    static  void _GoBackToTranseactionsMenue()
    {
        cout << "\nPress any key to go back to Transeactions Menue....";
        system("pause>0");

        ShowTranseactionsScreen();
    }


    static void _ShowDepositScreen()
    {
        //cout << "The Deposit Screen will be here later ...";
        clsDepositScreen::DepositScreen();
    }



    static void _ShowWithDrawScreen()
    {
        clsWithdrawScreen::WithdrawScreen();

    }


    static void _ShowTotalBalanceScreen()
    {
        // cout << "The Total Balance Screen will be here later ...";
        clsTotalBalanceScreen::ShowTotalBalanceList();
    }


    static void _ShowMainMenueScreen()
    {
        //cout << "The Deposit Screen will be here later ...";

    }

    static void _PerformTranseactionsMenueOption(enManageUsersMenueOptions Choose)
    {
        switch (Choose)
        {
        case enManageUsersMenueOptions::enDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTranseactionsMenue();


            break;
        }

        case enManageUsersMenueOptions::enWithDraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTranseactionsMenue();

            break;

        }


        case enManageUsersMenueOptions::enShowTotalBalances:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTranseactionsMenue();

            break;
        }

        case enManageUsersMenueOptions::enShowMainMenue:
        {
            system("cls");
            _ShowMainMenueScreen();
            break;
        }
        }
    }




public:


    static void ShowTranseactionsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        clsScreen::_DrawScreenHeader("\tTranseactions Screen");
        cout << "\n\n";
        cout << "\n\t\t\t\t================================================";
        cout << "\n\t\t\t\t\t\t Transeactions Menue ";
        cout << "\n\t\t\t\t================================================";
        cout << "\n\t\t\t\t\t\t [1] Deposit.";
        cout << "\n\t\t\t\t\t\t [2] Withdraw.";
        cout << "\n\t\t\t\t\t\t [3] Total Balance.";
        cout << "\n\t\t\t\t\t\t [4] Main Menue.";
        _PerformTranseactionsMenueOption((enManageUsersMenueOptions)ReadNumberForTranseactionsMenueOptions());
    }



};





class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputeVildate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsCleintListScrren::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewScreen::AddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
        

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClient::ShowFindClient();

    }

    static void _ShowTransactionsMenue()
    {
       // cout << "\nTransactions Menue Will be here...\n";
        clsTranseationsScreem::ShowTranseactionsScreen();
    }

    static void _ShowManageUsersMenue()
    {
      //  cout << "\nUsers Menue Will be here...\n";
        clsUserManageScreen::ShowManageUserScreen();
       
    }

    static void _ShowEndScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};


class clsLoginScreen : protected clsScreen
{
private:

    static void _Login()
    {
        bool LoginFailed = true;
        string UserName, Password;
        short TryCount = 3;

        do
        {
            cout << "Please enter user Name: ";
            cin >> UserName;

            cout << "Please enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();

            if (LoginFailed)
            {
                TryCount--;
                cout << "\nInvalid UserName/Password\n";

                if (TryCount > 0)
                    cout << "You have " << TryCount << " tries left.\n\n";
            }

        } while (TryCount > 0 && LoginFailed);

        if (!LoginFailed)
            clsMainScreen::ShowMainMenue();
        else
            cout << "You are locked after 3 failed trials\n";
    }

public:
    static void ShowLoginScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("\t Login Screen");
        cout << "\n";
        _Login();
    }
};



int main()
{ 
   
  
        clsLoginScreen::ShowLoginScreen();
   
    //clsMainScreen::ShowMainMenue();
    system("pause >0");
}

