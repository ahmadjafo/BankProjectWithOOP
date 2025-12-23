
#pragma once
#include <iostream>
#include "ClsSreen.h" ;
#include "E://learnc++/Library/LibraryForCourse11/clsBankClient.h.h" ;


#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
#include "E://learnc++/Library/LibraryForCourse10/MyClsStringLib.h" ;
#include <string>
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

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
public:
    static void ShowDeleteUserScreen()
    {
        string UserName = "";
        string Titile = "\t Delete User ";
        _DrawScreenHeader(Titile);
        cout << "\n\n";
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputeVildate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n UserName is not found, choose another one: ";
            UserName = clsInputeVildate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _Print(User);



        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (User.Delete())
            {
                cout << "\n User Deleted Successfully :-)\n";

                _Print(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }
};
