
/*********************
*Program: grocery.cpp
*Author: Tracy Stinghen
*Date Created: 4/23/14
*Last Date Modified: 4/23/14
*Description: Program allows a user to enter an item and location for items on their grocery list 
*and a location in the store (from a pre-determined list), and then prints out their list, 
*sorted by location. 
*Input: item name and location
*Output: list of items, sorted by location
*Resources: none 
***************************/

 



#include <iostream>
#include <vector> 
#include <string> 
#include <climits>
//#include <iterator>

using std::string; 										//I thought this program would be longer, so I chose to limit the amount of typing I had to do. 
using std::cout; 
using std::cin; 
using std::endl; 

struct grocery											//holds the details of a grocery item 
{
	string name; 
	string location; 

}; 

void print_zones();										//prints the list of aisles or zones in the store
void menu (std::vector<grocery> &list); 				//prints the menu, and manages the menu options
void enter_item(std::vector<grocery> &list); 			//accepts name and location of item and adds it to the list
void print_list(std::vector<grocery> &list);  			//prints the list, in order of zones in the store
string check_zones(string local);						//checks to make sure that the entered location is valid
string make_lower(string word); 						//takes a string and makes it lower-case
int check_selection(int choice); 						//checks to make sure that the menu selection is valid



int main ()
{

	std::vector<grocery> list; 							//initializes the empty grocery list vector

	print_zones(); 										//prints the list of acceptable locations 
	
	menu(list);  										//starts the menu
	
} 




/*****************************************
*Function: void print_zones()
*Description: Prints the list of the different areas of the store
*Parameters: none
*Pre-Conditions: nothing is printed
*Post-Conditions: list is printed 
******************************************/ 

void print_zones()
{
	string zones[10] = {"produce", "bakery", "dairy", "frozen", "deli", "canned goods", "dry goods", "meat", "household", "other"}; 	//list of locations
	
	cout<<"The sections of the store are: \n"; 				//indicates what the list is
	
	for (int i = 0; i < 10; i++) 							//for each item in the array
	{
		cout<<zones[i]<<endl; 								//print the name of the location
	
	}

}



/*****************************************
*Function: check_zones
*Description: checks an entered string against the list of acceptable strings 
*Parameters: a string 
*Pre-Conditions: string that may or may not be a member of the list
*Post-Conditions:  string is a member of the list 
******************************************/ 
string check_zones(string local)
{
	int match = 0;  											//indicates that there are 0 matches on the list 
		
	string zones[10] = {"produce", "bakery", "dairy", "frozen", "deli", "canned goods", "dry goods", "meat", "household", "other"};		//list of location
	
	local = make_lower(local); 									//calls function to make the string all lower case 	   	   	   	   	   
		
	for (int i = 0; i < 10; i++)								//for each item in the array
	{
		if (local == zones[i]) 									//if the string matches the string in the array
		{
			match++; 											//add 1 to match, representing a positive match 
			//cout<<"match!"; 				
		}
	
	}
	
	while(match == 0)											//after cycling through the array, if there was no match 
	{
	 
		
		cout<<"The sections of the store are: \n"; 				//print the list of acceptable entries
		for (int i = 0; i < 10; i++) 
		{
			cout<<zones[i]<<endl; 
		
		}
		
		cout<<"Enter a valid section name: "; 					//prompts to enter a new string
		cin>>local; 
		
		local = make_lower(local);								//calls function to make the string lower
		
		for (int i = 0; i < 10; i++)							//cycles through the array, checking for a match 
		{
			if (local == zones[i]) 								
			{
				match++;   
			}
	
		}
	}


	return local; 												//once the string is confirmed to match the array, return the string
	
}


/*****************************************
*Function: menu
*Description: offers 3 options and manages those three options once selected
*Parameters: vector type grocery
*Pre-Conditions: no options are availabe
*Post-Conditions:  actions are performed, menu is called again for another selection
******************************************/ 
void menu( std::vector<grocery> &list)
{
	int select; 											//stores the menu selection
	
	cout<<"\n\n1. Enter Item\n2. Print List\n3. Exit\n"; 	//Offers the three options
	cin>>select; 											//accepts selection
	select = check_selection(select); 						//checks to make sure that selection is 1, 2, or 3. 
	
	if (select == 1)										//if option 1 (Enter item)
	{
		
		enter_item(list); 	  								//calls function to perform action, passing it the vector 
		menu(list);											//calls the menu function again
	} 
	
	if (select == 2) 										//if option 2 (Print List)
	{
		print_list(list); 									//calls function to print the list, passing it the vector
		menu(list); 										//calls the menu function again
	}	 

	if (select == 3)										//if option 3 (Exit) 
	{
	
		return;  											//does nothing except exit the function
	}
}






/*****************************************
*Function: enter_item
*Description: Allows the user to enter an item and a location in the store
*Parameters: vector type grocery
*Pre-Conditions: list contains x items
*Post-Conditions:  list contains x+1 items
******************************************/ 
void enter_item(std::vector<grocery> &list)
{
	grocery item; 											//variable of type grocery, to store the item data
	
	cin.ignore(INT_MAX, '\n');								//gets ready to accept the line of data 

	cout<<"Enter item name: "; 								//prompts to enter an item name
	std::getline(cin, item.name); 							//gets the entire line and stores it as the item name 

	cout<<"Enter store section: "; 							//prompts to enter the location
	std::getline(cin, item.location); 						//gets the entire line and stores it as the location

	
	item.location = check_zones(item.location); 			//calls a function that checks the location to make sure it is valid
	
	list.push_back(item); 									//adds the item to the list

}


/*****************************************
*Function: check selection
*Description:makes sure that the user entered a 1, 2 or 3. 
*Parameters: an int
*Pre-Conditions: the number could be anything
*Post-Conditions:  the number is a 1, 2, or 3
******************************************/ 
int check_selection(int choice)
{
		
		while(!cin || choice > 3 || choice < 1) 			//while size is not an int, or less than 1, or greater than 3 
			{ 			
	   			cin.clear();								//clear line
	   			cin.ignore(INT_MAX, '\n'); 					//ignore characters
	   			cout<<"Please select option 1, 2 or 3: ";	//reminds user of the valid selections 
				cin>>choice; 								//accepts new choice
			}
	
	return choice;											//once the choice is valid, returns it

}


/*****************************************
*Function: print_list
*Description: prints the shopping list, sorting by location in the store
*Parameters: vector of type grocery
*Pre-Conditions: nothing is displayed
*Post-Conditions: list is printed, sorted by item 
******************************************/ 


void print_list(std::vector<grocery> &list)
{

	int item_count; 										//number of items in each location
	
	
	/*******************************************
	*It would have been a good idea to make the zones and count arrays a struct, so that they are really connected
	*However, I did not forsee the need for this and made zones an array everywhere else. 
	*For consistancy's sake, I left zones as it was and added the mirror array, since it is a small funciton
	*and having the two disconnected doesn't actually cause any functional problems. 
	********************************************/ 
	
	string zones[10] = {"produce", "bakery", "dairy", "frozen", "deli", "canned goods", "dry goods", "meat", "household", "other"};
	int count[10] = {0,0,0,0,0,0,0,0,0,0}; 				//array that mirrors the array of strings above
	
	for (int i = 0; i < list.size(); i++) 				//for each item in the vector 
	{
		for (int j = 0; j < 10; j++)					//for each vector, for each item in the list
		{
			if (list[i].location == zones[j]) 			//if the location matches the zone
			{
				count[j] = 1; 							//changes the value in the mirrored array to a 1
														//indicating that there is at least 1 item in that location
			
			}

		}	 
		
	} 
	
	for (int k = 0; k < 10; k++) 						//for each location in the store
	{
		if (count[k] > 0) 								//if the mirror array indicates that there are any items in that location
		{
			cout<<endl<<"-"<<zones[k]<<"-"<<endl; 		//print the name of the location
			
			for (int l = 0; l < list.size(); l++) 		//for each item on the list
			{
				if (zones[k] == list[l].location) 		//if the location of the item, matches the zone on the list...
				{
					cout<<list[l].name<<endl; 			//print the name of the item
				
				}
			
			}
		}
	
	}

}



/*****************************************
*Function: make_lower
*Description: takes a string and makes all the letters lower case
*Parameters: a string 
*Pre-Conditions:
*Post-Conditions:  
******************************************/ 
string make_lower(string word)
{
		for (int i = 0; i < word.length(); i++) 	//for each letter in the word
		{
			word.at(i) = tolower(word.at(i)); 		//make that letter lower-case
		}
	

	return word;									//return the lower-case word
} 






/**************************************
*
*Penalty Block
*

This is where I store code that is too complex
to bother commenting out, line by line
while I try to fix the problem 	   



*****************************************/

