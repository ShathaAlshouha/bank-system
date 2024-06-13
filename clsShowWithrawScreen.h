#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std; 
class clsWithDrawScreen : protected clsScreen
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

public:
	static void Withdraw()
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
		cout << "\nPlease enter Withdraw amount? ";
		Amount = clsInputValidate::ReadDblNumber();
		
		char Answer;
		cout << "Are you sure you want to perform this transaction ? ";  
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;

			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}




	}



};
