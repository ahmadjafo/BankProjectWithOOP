#include "MainMenueScreen.h" ;
#include "ClsSreen.h" ;



#include "E://learnc++/Library/LibraryForCourse11/clsUser.h.h" ;



class clsLoginScreen : protected clsScreen
{
private:
    static void _Login()
    {
        bool LoginFailed = false;
        string UserName, Password;
        do
        {

            if (LoginFailed)
            {
                cout << "\nInvilde UserName/Password\n\n";

            }

            cout << "Please enter user Name ?";
            cin >> UserName;

            cout << "Please enter Password ?";
            cin >> Password;
            CurrentUser = clsUser::Find(UserName, Password);
            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        clsMainScreen::ShowMainMenue();
        //clsLoginScreen::ShowLoginScreen();

    }
public:
    static void ShowLoginScreen()
    {
        system("cls");
        _DrawHeaderScreen("\t Login Screen");
        cout << "\n";
        _Login();
    }
};

