
#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;
#include "WithdrawClientScreen.h" ;
#include"DepositClientScreen.h" ;
#include"TotalClientBalance.h" ;


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
        clsScreen::_DrawHeaderScreen("\tTranseactions Screen", "");
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

