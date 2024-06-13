#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsShowClientsList.h"
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include "clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include "clsShowTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include"Global.h"
#include"clsShowLoginScreen.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
private:

    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
       // cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientsListScreen::ShowClientsList(); 


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAbbNewClient::AddNewClint(); 

    }

    static void _ShowDeleteClientScreen()
    {
        clsBeleteClient::ShowDeleteClientScreen(); 

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen(); 

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen(); 
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionMainScreen::ShowTransactionMenu(); 
        _GoBackToMainMenue(); 
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUserScreen::ShowManageUserScreen(); 

    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", ""); 

    }
   
    static void _PerformMainMenuOption(enMainMenuOptions  MainMenuOption)
    {
        switch (MainMenuOption)
        {
            case clsMainScreen::eListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
             }
            case clsMainScreen::eAddNewClient:
            {
                system("cls");
                _ShowAddNewClientsScreen();
                _GoBackToMainMenue(); 
                break;
            }

            case clsMainScreen::eDeleteClient:
            {
                system("cls"); 
                _ShowDeleteClientScreen(); 
                _GoBackToMainMenue(); 
                break;
            }
            case clsMainScreen::eUpdateClient:
            {
                system("cls");
                _ShowUpdateClientScreen(); 
                _GoBackToMainMenue();
                break;
            }
            case clsMainScreen::eFindClient:
            {
                system("cls");
                _ShowFindClientScreen(); 
                _GoBackToMainMenue();
                break;
            }
            case clsMainScreen::eShowTransactionsMenue:
            {
                system("cls");
                _ShowTransactionsMenue(); 
                _GoBackToMainMenue();
                break;
            }
            case clsMainScreen::eManageUsers:
            {
                system("cls");
                _ShowManageUsersMenue(); 
                _GoBackToMainMenue();
                break;
            }
            case clsMainScreen::eExit:
            {
                system("cls");
                _Logout();
                break;
            }
       
        }



    }


public:

	static void ShowMainMenu()
	{
        system("cls"); 
		clsScreen::_DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
       
        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenueOption());
    
    }






};


