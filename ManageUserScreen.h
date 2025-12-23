#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "clsBankClient.h.h" ;
#include "clsUser.h.h" ;
#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;


#include "UpdateUserScreen.h" ;
#include "FindUserScreen.h" ;
#include "AddNewUserScreen.h" ;
#include "DeleteUserScreen.h" ;
#include "UserListScreen.h" ;
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
        clsScreen::_DrawHeaderScreen("Manage Users Menue");
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