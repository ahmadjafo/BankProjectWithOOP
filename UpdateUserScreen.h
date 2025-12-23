#pragma once
#include <iostream>
#include "ClsSreen.h" ;

#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;

class clsUpdateUserScreen : protected clsScreen
{

private:
    static void _ReadUserInfo(clsUser& user)
    {
        cout << "\nEnter FirstName: ";
        user.FirstName = clsInputeVildate::ReadString();

        cout << "\nEnter LastName: ";
        user.LastName = clsInputeVildate::ReadString();

        cout << "\nEnter Email: ";
        user.Email = clsInputeVildate::ReadString();

        cout << "\nEnter Phone: ";
        user.Phone = clsInputeVildate::ReadString();

        cout << "\nEnter Password: ";
        user.Password = clsInputeVildate::ReadString();

        cout << "\nEnter Permissions: ";
        user.Permissions = _ReadPermissions();
    }

    static void _Print(clsUser User)
    {

        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nUser Name     : " << User.UserName;
        cout << "\nFull Name     : " << User.FullName();
        cout << "\nEmail         : " << User.Email;
        cout << "\nPhone         : " << User.Phone;

        cout << "\nPassword      : " << User.Password;
        cout << "\nPermissions   : " << User.Permissions;
        cout << "\n___________________\n";


    }

    static int _ReadPermissions()
    {
        char Answer = 'n';
        int Permissions = 0;
        cout << "\n Do you want to give full access ? y\n ?";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            return  -1;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\n show Clients List? y/n";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }


    }


public:
    static void ShowUpdateUserScreen()
    {
        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputeVildate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputeVildate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);


        _Print(User);

        cout << "Are You sure  you want to update this User Y/n ? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n Update User :";
            cout << "\n----------------------\n";
            _ReadUserInfo(User);
            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";
                _Print(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsUser::enSaveResults::svFaildUserExists:
            {
                cout << "\nError User was not saved because account number is used!\n";
                break;

            }
            }
        }
    }

};
