#pragma once
#include <iostream>
#include "clsBankClient.h"
#include<iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std; 

class clsTotalBalaces : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{

		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}



public:
	static	void TotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList(); 
		
		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClient(C); 
cout << endl; 
			}
			
		}

		double TotalBalances = clsBankClient::GetTolatalBalance(); 
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";



	}




};
