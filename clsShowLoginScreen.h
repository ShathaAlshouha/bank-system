#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include "clsScreen.h"
#include"Global.h"
class clsShowLoginScreen :protected clsScreen
{
    static bool _Login()
    {
        bool LoginFaild = false; 

        string UserName, Password; 
        int counter = 0;
        do
        {
           
            if (LoginFaild)
            {
                counter++;
                cout << "\nInvales Username , Password ! ." << endl;
                cout << "you have " <<3- counter << " Trails to login." << endl;
            }
            if (counter == 3)
            {
                cout << "You are locked after 3 faild trails. " << endl;
                return false;
            }

            cout << "\nEnter Username : "; 
            cin >> UserName;

            cout << "Enter Password : "; 
            cin >> Password; 

            CurrentUser = clsUser::Find(UserName, Password); 

            LoginFaild = CurrentUser.IsEmpty(); 

           
        } while (LoginFaild );
      

        clsMainScreen::ShowMainMenu(); 
        return true; 


    }


public:
    static bool ShowLoginScreen()
    {
        system("cls"); 
        clsScreen::_DrawScreenHeader("\tShow Login Screen"); 
        return _Login();


    }



};
