#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std; 

class  clsBankClient : public clsPerson
{

private :

	string _AccountNumber; 
	string _PinCode; 
	double _AccountBalance; 
	bool _MarkedForDelete = false; 

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 }; 
	enMode _Mode; 

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

    static clsBankClient _GetEmptyClientObject()
    {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0); 
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClients; 

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); 
  
		if (MyFile.is_open())
		{

			string Line; 
			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line); 
				vClients.push_back(Client); 

			}
		}
		MyFile.close(); 
		return vClients; 
	}

	static string _ConvertClientRecordToLine(clsBankClient Client, string Seperator = "#//#")
    {
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static void _SaveClientDataToFile(vector<clsBankClient> _vClients)
	{
		fstream MyFile; 
		MyFile.open("Clients.txt", ios::out); 
		
		string DataLine; 
		if (MyFile.is_open())
		{
			for (clsBankClient& C : _vClients)
			{

				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConvertClientRecordToLine(C); 
					MyFile << DataLine << endl;

				}
			}
			MyFile.close(); 
		}




	}
	
	void _Update()
	{

		vector<clsBankClient> _vClients = _LoadClientDataFromFile(); 
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this; 
				break; 
			}

		}

		_SaveClientDataToFile(_vClients); 

	}

	void _AddDataLineToFiel(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app); 

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close(); 

		}


	}
	
	void _AddNew()
	{
		_AddDataLineToFiel(_ConvertClientRecordToLine(*this)); 

	}

	

public : 

	

	clsBankClient(enMode Mode,string FirstName,string LastName, string Email, string Phone ,
		string AccountNumber, string PinCode, double AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode; 
		_AccountNumber = AccountNumber; 
		_PinCode = PinCode; 
		_AccountBalance = AccountBalance; 


	}

	string AccountNumber()
	{
		return _AccountNumber; 
	}
	
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode; 
	}

	string GetPinCode()
	{
		return _PinCode; 
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode; 

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName     : " << FirstName;
		cout << "\nLastName      : " << LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << Email;
		cout << "\nPhone         : " << Phone;
		cout << "\nAccountNumber : " << _AccountNumber;
		cout << "\nPassword      : " << _PinCode;
		cout << "\nBalance       : " << _AccountBalance;
		cout << "\n___________________\n";

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	enum enSaveResults
	{
		svFiledEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists = 2
	}; 

	enSaveResults Save()
	{


		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if(IsEmpty())
			return enSaveResults::svFiledEmptyObject; 
			break;
		}

		case enMode::UpdateMode: 

			_Update(); 
			return enSaveResults::svSucceeded; 

		case enMode::AddNew:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFiledEmptyObject; 
			}
			else
			{
				_AddNew(); 
				_Mode = enMode::UpdateMode; 
				return enSaveResults::svSucceeded; 
				break; 
			}

		}



		}


	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}
	
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}


	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClints; 

		fstream MyFile; 
		MyFile.open("Clients.txt", ios::in); 

		if (MyFile.is_open())
		{
			string Line; 
			while (getline(MyFile, Line))
			{
				clsBankClient Clinet = _ConvertLinetoClientObject(Line); 
				if (Clinet.AccountNumber() == AccountNumber)
				{
					MyFile.close(); 
					return Clinet; 
				}
				
			}

			MyFile.close(); 


		}


		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}
	
    bool Delete(string AccountNumber)
	{
		vector <clsBankClient>	vClients; 
		vClients = _LoadClientDataFromFile(); 

		for (clsBankClient& C : vClients)
		{

			if (C.AccountNumber() == AccountNumber)
			{
				C._MarkedForDelete = 1; 
				break; 

			}
		}
		_SaveClientDataToFile(vClients); 

		*this = _GetEmptyClientObject(); 

		return 1; 
	}

    static vector<clsBankClient> GetClientsList()
 {
	 return _LoadClientDataFromFile(); 
 }
 
	static double GetTolatalBalance()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double Balance = 0;
		for (clsBankClient& C : vClients)
		{
			Balance += C.AccountBalance;
		}
		return Balance;

	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();

	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

	}


};

