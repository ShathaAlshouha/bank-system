#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include"clsUser.h"
#include "clsScreen.h"
using namespace std; 

class clsShowListUsers : protected clsScreen

{
private:
 static	void _PrintUser(clsUser User)
	{
     cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
     cout << "| " << setw(25) << left << User.FullName();
     cout << "| " << setw(12) << left << User.Phone;
     cout << "| " << setw(20) << left << User.Email;
     cout << "| " << setw(10) << left << User.Password;
     cout << "| " << setw(12) << left << User.Permissions;
	}


	public :

		static void ShowUsersList()
		{
			
			vector<clsUser> vUsers = clsUser::GetUsersList();
			string SubTitel = "\t(" + to_string(vUsers.size()) + ") User(s)"; 
			clsScreen::_DrawScreenHeader("\t User List Screen", SubTitel); 

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
            cout << "| " << left << setw(25) << "Full Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Password";
            cout << "| " << left << setw(12) << "Permissions";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
			if (vUsers.size() != 0)
			{
				for (clsUser& U : vUsers)
				{
					_PrintUser(U); 
					cout << endl;
				}

			}
			else
			{
				cout << "        No users available in this system"; 
			}
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
		}





};