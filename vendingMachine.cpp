#include <iostream>
#include <string>
#include <map>

using namespace std;

class UniversityVendingMachine
{
public:
	map<string, int> items;
	map<string, string> itemCodes;

	int moneyAvailable = 0;
	UniversityVendingMachine()
	{
      itemCodes["A1"] = "cookie";
    	itemCodes["A2"] = "iPhone charger";
    	itemCodes["C5"] = "potato chips";
    	itemCodes["D4"] = "chewing gum";
    
    	items["cookie"] = 100;
    	items["iPhone charger"] = 1500;
    	items["potato chips"] = 200;
    	items["chewing gum"] = 150;
		
	}

	string getItemPrice(string x)
	{

		for(auto it = itemCodes.begin(); it != itemCodes.end(); it++)
		{
			if( it->first == x )
			{
				string ret = it->second + " - " + to_string(items[it->second]);
				return ret;
			}
		}

		return "Item is not available or the item number not valid";

	}

	void addMoney(int amount)
	{
		moneyAvailable += amount;
	}

	string buy(string item)
	{
		if(moneyAvailable < items[itemCodes[item]])
		{
			return "Please add enough \'sp\'";
		}
		else
		{
			moneyAvailable -= items[itemCodes[item]];
			string ret = "Vend Successful!";
			ret += "\n";
			ret += "Balance: sp " ;
			ret += to_string(moneyAvailable); 
      return ret;
		}
	}

};

void listMenu()
{
    cout << "Menu" << endl;
    cout << "1. getItemPrice" << endl;
    cout << "2. addMoney" << endl;
    cout << "3. buy" << endl;
    cout << "Enter the operation number" << endl;
}

int main()
{
    
    UniversityVendingMachine obj1;
    listMenu();
    int operation;
    cin >> operation;
    bool quit = false;
    while (!quit)
    {
        if(operation == 1)
        {

			for(auto it = obj1.itemCodes.begin(); it != obj1.itemCodes.end(); it++)
			{
				cout << it->first << ": " << it->second << ". ";
			}
			cout << endl;
            cout << "Enter ItemCode" << endl;
            string ic;
            cin >> ic;
            cout << obj1.getItemPrice(ic) << endl;
            listMenu();
            cin >> operation;
        }
        else if(operation == 2)
        {
            cout << "Enter amount to be added: ";
            int amt;
            cin >> amt;
            obj1.addMoney(amt);
            listMenu();
            cin >> operation;
        }
        else if (operation == 3)
        {
            cout << "Enter ItemCode to be bought: ";
            string ic;
            cin >> ic;
            
            cout << obj1.buy(ic) << endl;
            quit = true;
        }
        
        
    }
    return 0;
}
