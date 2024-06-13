#pragma once
#include<iostream>
#include<vector>
#include"clsInputValidate.h"
#include"clsUser.h"
#include "clsScreen.h"
using namespace std; 

class clsShowAddNewUser : protected  clsScreen
{
   
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::eShowClientList; 
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eAddNewClient; 
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eDeleteClient; 
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eUpdateClient; 
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eFind; 
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eTransactions; 
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eManageUsers; 
        }

        return Permissions;

    }
    static void _ReadUserInfo( clsUser & User)
    {
    
        cout << "Enter First Name :"; 
        User.FirstName = clsInputValidate::ReadString(); 
        cout << "Enter Last Name  : "; 
        User.LastName = clsInputValidate::ReadString(); 
        cout << "Enter Email      :"; 
        User.Email= clsInputValidate::ReadString();
        cout << "Enter Phone      : "; 
        User.Phone = clsInputValidate::ReadString();
        cout << "Enter Password     :"; 
        User.Password= clsInputValidate::ReadString();
        cout << "Enter Permission : "; 
        User.Permissions = _ReadPermissionsToSet(); 


    }

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
	static void AddNewUserScreen()
	{

        clsScreen::_DrawScreenHeader("\t Add New User Screen "); 
        string UserName; 
        cout << "Please Enter User Name : "; 
        UserName = clsInputValidate::ReadString(); 

        while (clsUser::IsUserExist(UserName))
        {
            cout << " User name is already used , choocse another one : "; 
            UserName = clsInputValidate::ReadString();

        }
        clsUser NewUser = clsUser::GetAddNewUserObject(UserName); 

        _ReadUserInfo(NewUser); 

        clsUser::enSaveResults  eSave = NewUser.Save(); 

     
        switch (eSave)
        {
        case clsUser::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::svSucceeded:
        {
            system("cls"); 
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        }

      

	}



};
