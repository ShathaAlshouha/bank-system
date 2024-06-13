#pragma once
#include <iostream>
#include "clsInputValidate.h" 
#include "clsUser.h"
#include "clsScreen.h" 


class clsFindUser : protected clsScreen
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




public:
    static void FindUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t\t Find User Screen"); 

        cout << "Enter User Name : "; 
        string UserName = clsInputValidate::ReadString(); 

        while (!clsUser::IsUserExist(UserName))
        {
            cout << " User is not found , please enter another user : ";
            UserName = clsInputValidate::ReadString();

        }

        clsUser User = clsUser::Find(UserName); 

        if (!User.IsEmpty())
        {
            cout << " User Found :-)"; 
        }
        else
        {
            cout << " User Is Not Found :-( "; 
        }

        _PrintUser(User); 


    }



};


