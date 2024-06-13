#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsShowListUsersScreen.h"
#include "clsShowAddNewUserScreen.h"
#include "clsShowDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsShowFindUserScreen.h"
using namespace std;

class clsManageUserScreen :protected clsScreen
{

	enum enManageMenuOption
	{
		ListUser = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, ManeMenu = 6
	}; 

	static int _ReadOption()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 6? ");
		return Choice;
	}
	
    static void _GoBackToManageMenu()
    {
        system("pause");
        ShowManageUserScreen();
    }

	static void _ShowUsersList()
	{
		clsShowListUsers::ShowUsersList(); 

	}
	
	static void _ShowAddNewUser()
	{
        clsShowAddNewUser::AddNewUserScreen(); 
	}

	static void _ShowDeleteUser()
	{
        clsDeleteUser::DeleteUser(); 
	}

	static void _ShowUpdateUser()
	{
        clsUpdateUser::UpdateUserScreen(); 
	}

	static void _ShowfindUser()
	{
        clsFindUser::FindUserScreen(); 


	}

	static void _ShowManeMenu()
	{

	}

	static void _PerformManageMenuOption(enManageMenuOption eManageOption)
	{

		switch (eManageOption)
		{
		    case clsManageUserScreen::ListUser:
		    {
			    system("cls"); 
			    _ShowUsersList();
			    _GoBackToManageMenu(); 
                break;
		    }
		    case clsManageUserScreen::AddUser:
		    {
			    system("cls");
                _ShowAddNewUser(); 
			    _GoBackToManageMenu();
                break;
		    }
		    case clsManageUserScreen::DeleteUser:
	        {
			    system("cls");
			    _ShowDeleteUser();
			    _GoBackToManageMenu();
                break;
		    }
		    case clsManageUserScreen::UpdateUser:
		    {
			    system("cls");
			    _ShowUpdateUser(); 
			    _GoBackToManageMenu();
                break;
		    }
		    case clsManageUserScreen::FindUser:
		    {
			    system("cls");
			    _ShowfindUser(); 
			    _GoBackToManageMenu();
                break;
		    }
		    case clsManageUserScreen::ManeMenu:
		    {
                break;
		    }
		}
	}


public:

	static void ShowManageUserScreen()
	{
        if (!CheckAccessRights(clsUser::eManageUsers))
        {
            return;
        }

        system("cls");
		clsScreen::_DrawScreenHeader("\t Manage Users Screen"); 

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menu\n"; 
		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t[1] List Users.\n"; 
		cout << setw(37) << left << "" << "\t[2] Add New User.\n"; 
		cout << setw(37) << left << "" << "\t[3] Delete User.\n"; 
		cout << setw(37) << left << "" << "\t[4] Update User.\n"; 
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageMenuOption((enManageMenuOption)_ReadOption()); 
	}


};
