#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
using namespace std;
class clsClientsListScreen :protected clsScreen
{


private :
  static void _PrintClients(clsBankClient Client)   
	{
      cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
      cout << "| " << setw(20) << left << Client.FullName();
      cout << "| " << setw(12) << left << Client.Phone;
      cout << "| " << setw(20) << left << Client.Email;
      cout << "| " << setw(10) << left << Client.PinCode;
      cout << "| " << setw(12) << left << Client.AccountBalance;


	}

public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::eShowClientList))
        {
            return; 
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << setw(20) << left << "Client Name";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(20) << left << "Email";
        cout << "| " << setw(10) << left << "Pin Code";
        cout << "| " << setw(12) << left << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient C : vClients)
            {

               _PrintClients(C);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

