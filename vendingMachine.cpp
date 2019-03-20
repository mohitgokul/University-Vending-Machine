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
	
	//Input the Items and their Respected ItemCodes 
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

	//Added a getItemPrice method for getting the values of the respected items
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
	
	//addMoney for adding the money to the Vending Machine
	void addMoney(int amount)
	{
		moneyAvailable += amount;
	}

	//Condition - If there is less money add the required money to get the item and then of you have added more money it will return back the balance amount
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

//listMenu method where you have to perform the operations which you need
void listMenu()
{
    cout << "Menu" << endl;
    cout << "1. getItemPrice" << endl;
    cout << "2. addMoney" << endl;
    cout << "3. buy" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter the operation number" << endl;
}

//Print the Output and the operations for the code
int main()
{    
    UniversityVendingMachine obj1;
    listMenu();
    int operation;
    cin >> operation;
    while (operation != 4)
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
        }
        else if(operation == 2)
        {
            cout << "Enter amount to be added: ";
            int amt;
            cin >> amt;
            obj1.addMoney(amt);
        }
        else if (operation == 3)
        {
            cout << "Enter ItemCode to be bought: ";
            string ic;
            cin >> ic;
            
            cout << obj1.buy(ic) << endl;
        }
        listMenu();
        cin >> operation;
    }
    return 0;
}
