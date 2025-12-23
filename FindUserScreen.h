#pragma once
#include <iostream>
#include "ClsSreen.h" ;



#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;
#include  "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsFindUserScreen : protected clsScreen
{

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
    static void ShowFindUser()
    {
        string Titile = "\tFind User";
        _DrawScreenHeader(Titile);
        cout << "\n\n";
        string UserName = "";


        cout << "\nPlease Enter User Name: ";
        UserName = clsInputeVildate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not Found cchosse anthoer one: ";
            UserName = clsInputeVildate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\n User Found :-)\n";
        }
        else
        {
            cout << "\n User Was not Found :-(\n";
        }

        _Print(User);
    }

};