#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include "clsShowDepositScreen.h"
#include "clsShowWithrawScreen.h"
#include "clsShowTotalBalanceScreen.h"
#include "clsMainScreen.h"

using namespace std; 

class clsTransactionMainScreen :protected clsScreen
{
    enum enTransactionMenuOptions
    {

        eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenu = 4

    }; 

    int static _ReadTransactionOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

   
    void static _GoBackToTransactionMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowTransactionMenu(); 
        
    }

    void static _ShowDepositScreen()
    {
        clsDepositScreen::Deposit(); 
    }
    
    void static _ShowWithdrawScreen()
    {
        clsWithDrawScreen::Withdraw(); 
    }
  
    void static _ShowTotalBalanceScreen()
    {
        clsTotalBalaces::TotalBalancesScreen(); 
    }

    void static _PervormTransactionMenuOption(enTransactionMenuOptions eTOption)
    {
        switch (eTOption)
        {
        case clsTransactionMainScreen::eDeposit:
        {
            system("cls"); 
            _ShowDepositScreen();
            _GoBackToTransactionMenu(); 
            break; 
        }
        case clsTransactionMainScreen::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen(); 
            _GoBackToTransactionMenu(); 
            break;
        }
        case clsTransactionMainScreen::eTotalBalances:
        {

            system("cls");
            _ShowTotalBalanceScreen(); 
            _GoBackToTransactionMenu();
            break;
        }
        case clsTransactionMainScreen::eMainMenu:
        {
          
            break;
        }
       
        }

    }





public :

	void static ShowTransactionMenu()
	{
        if (!CheckAccessRights(clsUser::eTransactions))
        {
            return;
        }
        system("cls"); 
		clsScreen::_DrawScreenHeader("\t\t\t\tTransaction Screen"); 

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTrabsaction Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PervormTransactionMenuOption((enTransactionMenuOptions)_ReadTransactionOption());




	}



};
