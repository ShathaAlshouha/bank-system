#include <iostream>
#include"clsShowLoginScreen.h"
#include "clsShowLoginScreen.h"
using namespace std; 


int main()
{
    while(true)
    {
        if(!clsShowLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }
}

