#pragma once
#include <iostream>
#include "clsScreen.h"

#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std; 

class clsUpdateClientScreen :protected clsScreen
{
static	void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter FirstName	  : " << endl;
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName       : " << endl;
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email          : " << endl;
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone          : " << endl;
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode        : " << endl;
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter AccoutnBalance : " << endl;
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}

static void _Print(clsBankClient Client)
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
	static void ShowUpdateClientScreen()
	{
        if (!CheckAccessRights(clsUser::eUpdateClient))
        {
            return;
        }
		_DrawScreenHeader("Update Client Screen");
		string AccountNumber = "";
		cout << "Please Enter Client Account Number : " << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found , Enter Another AccountNumber : " << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();

		cout << "     Update Info " << endl;
		cout << "----------------------" << endl;
		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{

			cout << " Account Updated Successfully :-) " << endl;
			_Print(Client); 
			break;

		}

		case clsBankClient::svFiledEmptyObject:
		{
			cout << " Error account was not saved because its Empty :-( ";
			break;
		}


		}





	}

};