
#pragma once
#include <iostream>
#include "ClsSreen.h" ;

#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;

#include "E://learnc++/Library/LibraryForCourse11/MyClsVildateInput.h" ;
class clsUserListScreen : protected clsScreen
{
private:
    static void PrintUserRecoredLine(clsUser User)
    {
        cout << "| " << left << setw(15) << User.UserName;
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(9) << User.Password;
        cout << "| " << left << setw(10) << User.Permissions;
    }
public:


    static  void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\tUser List Screen";
        string SubTitle = "\t (" + to_string(vUsers.size()) + ") Users(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n\n";


        cout << "\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;

        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(9) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;
        if (vUsers.size() == 0)
            cout << "No Users Available in the system :-(\n";
        else
        {
            for (clsUser Users : vUsers)
            {
                PrintUserRecoredLine(Users);
                cout << endl;
            }

        }
        cout << "\n\n--------------------------------------------------------";
        cout << "----------------------------------------\n" << endl;


    }

};
