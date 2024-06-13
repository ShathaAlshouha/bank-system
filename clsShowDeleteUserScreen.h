#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"

class clsDeleteUser :protected clsScreen
{

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public : 

    static void DeleteUser()
    {
      

        clsScreen::_DrawScreenHeader("\tDelete User Screen "); 

        cout << "Enter User Name : "; 
        string UserName = clsInputValidate::ReadString(); 

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User is not found, Enter another User Name : "; 
            string UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName); 
        _PrintUser(User); 

        char Answer; 
        cout << "\nAre you sure you want to delete this user ? Y/N ? "; 
        cin >> Answer; 

        if (Answer == 'Y' || Answer == 'y')
        {
            if (User.Delete())
            {
                system("cls"); 
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
       



    }




};
