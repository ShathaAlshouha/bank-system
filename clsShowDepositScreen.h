#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsDepositScreen : protected clsScreen
{

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}


public :

	static void Deposit()
	{
        
		clsScreen::_DrawScreenHeader("Deposit Screen"); 

		string AccountNumber = ""; 

		cout << "Please Enter Account Number : "; 
		AccountNumber = clsInputValidate::ReadString(); 

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient Whith [ " << AccountNumber << "] is not exist . "; 
			cout << "\nPlease Enter Another Account : "; 
			AccountNumber = clsInputValidate::ReadString();

		}
		system("cls"); 
		clsBankClient Client = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client); 
		
		 
		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::ReadDblNumber();
		
		char Answer; 
		cout << "Are you sure you want to perform this transaction ? Y/N ? ";
		cin >> Answer; 

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}




	}


};

