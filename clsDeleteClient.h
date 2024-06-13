#pragma once
#include <iostream>
#include "clsScreen.h"

#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsBeleteClient :protected clsScreen
{
private:

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

	static void ShowDeleteClientScreen()
	{
        if (!CheckAccessRights(clsUser::eDeleteClient))
        {
            return;
        }
		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumbre = "";
		cout << "Enter Account Number : ";
		AccountNumbre = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumbre))
		{
			cout << "\nAccount Number Is Not Found , Choose Another Account Number : ";
			AccountNumbre = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumbre);

		cout << "\nAre you sure you want to delete this client y/n : ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Delete(AccountNumbre))
			{
				cout << "\n\nClient Deleted Successfully :-)\n";
			

			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}




		}


	}


};