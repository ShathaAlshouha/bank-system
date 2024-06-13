#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include"clsInputValidate.h"


class clsAbbNewClient :protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name	   : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name     : " ;
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email         : " ;
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone         : " ;
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode       : " ;
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccoutnBalance: " ;
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}
	
	void _Print(clsBankClient Client)
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
    static	void AddNewClint()
    {
        if (!CheckAccessRights(clsUser::eAddNewClient))
        {
            return;
        }
		_DrawScreenHeader("\tAdd New Client Screen");

		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Already Used , Choose  Another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			system("cls"); 
			cout << "\nAccount Updated Successfully :-)\n";
			NewClient.Print();
			break;
		}
		case clsBankClient::enSaveResults::svFiledEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}

	}



};
