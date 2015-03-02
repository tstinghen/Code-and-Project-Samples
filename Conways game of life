
/*********************
*Program: game_of_life.cpp 
*Author: Tracy Stinghen
*Date Created: 4/8/14
*Last Date Modified: 4/11/14 
*Description: Simulation of Conway's Game of Life
*Input: Choose a starting configuration, choose whether to keep going
*Output: Changing population of cells, generation by generation  
*Resources: Old source code that I wrote for CS 161, to remind me how to use
*'enter' to advance to the next generation
***************************/

#include <iostream>
#include <string>
#include <climits> 


void init_array(char game[][82]); 	                     //creates the initial array, and initializes it to all dead cells 
void print_array(char game[][82]); 	                     //prints the array to the console
void assign_start(char game[][82], int choice);                      //accepts the user's choice of starting arrangement, and assigns it to the array
int neigh_find(char game[][82], int i, int j);                      //searches the array to determine how the rules apply to each cell
void array_changer(char game[][82]); 	                     //modifies the array to reflect the changes made each generation

int main ()
{
	char game[24][82]; 	                     //this is the primary array that holds the game data. 
	std::string quit; 	                      //this determines whether the user wants to advance to the next generation
	int inp_len; 
	int arrangement; 	                     //this allows the user to choose a pre-loaded arrangement of live cells 
	
	init_array(game);	
	std::cout<<"Simulation of Conway's Game of Life\n\nThere are four different starting configurations to choose from \n1:Grows, then dies\n2:Forms stable geometric pattern"; 
	std::cout<<"\n3:Forms stable 4-generation loop\n4:Changes for over 100 generations, then becomes static\n\nPlease make your selection: ";                      //prompts user

	std::cin>>arrangement; 	                     //accepts user input for the starting arrangement 
	while(!std::cin || arrangement > 4 || arrangement < 1)                      //while the input is incorrect
	{
		std::cin.clear();                      //clear the line
		std::cin.ignore(INT_MAX, '\n');                      //ignore characters
		std::cout<<"\nChoose an arrangement by typing a number 1-4: "; 
		std::cin>>arrangement; 
	}
	
	
	assign_start(game, arrangement); 
	print_array(game);
	std::cin.ignore(); 	                     //ignores line after input 
	std::cout<<"Press Enter to continue, or type any other character to exit ";                      //prompts user
	std::getline(std::cin, quit);                      //stores either 'enter' or any other key 
 	inp_len = quit.length();                      //determines whether user pressed enter or typed something
		
	while(inp_len == 0)	                     //continues looping the game until the user chooses to type something 
	{	 
	array_changer(game);                      //adjusts to next generation
	print_array(game); 		                     //prints board
	
	                     //std::cin.ignore(); 	                      //for some reason, we don't need that here
	std::cout<<"Press Enter to continue, or type any other character to exit ";                      //prompts the user
	std::getline(std::cin, quit);                      //stores user input
 	inp_len = quit.length(); 		                     //checks to see if the user typed anything
	
	}


} 



/*****************************************
*Function: init_array
*Description: initializes the array to a specific value, ' '
*Parameters:an array sized [24][82]
*Pre-Conditions: the array is empty
*Post-Conditions: each location in the array now holds a ' '
******************************************/ 


void init_array(char game[][82])                      //initializes the array
{
	int i = 0; 
	int j = 0;	  
	
	for(i == 0; i<24; i++)	                     //loops through the array
	{
		for(j == 0; j<82; j++) 
		{
			game[i][j] = ' ' ;                      //setting all values to the dead cell value

		}
		j = 0; 
	}

}



/*****************************************
*Function: print_array
*Description: prints the array to the console
*Parameters: an array sized [24][82]
*Pre-Conditions: array is not printed on the screen
*Post-Conditions: array is printed
******************************************/ 


void print_array(char game[][82])                      //prints the array
{

	int i = 1; 
	int j = 1; 
	
	
	for(i == 1; i<23; i++)                      //loops through most of the array, ignoring edge cells 
	{
		for(j == 1; j<80; j++) 
		{
		std::cout<<game[i][j]; 	                     //prints each cell
		}
		j = 0; 
		std::cout<<std::endl; 
	}


}




/*****************************************
*Function: assign_start
*Description: assigns specific values to be live cells in the game
*Parameters: accepts an array and a number 1-4
*Pre-Conditions: array is set to ' '
*Post-Conditions: twelve locations have been set to '*' 
******************************************/ 

void assign_start(char game[][82], int choice)                      //creates the initial assortment of live cells 
{


	if(choice == 1)		                     //these are random selections of cells, intended to be grouped close together for best effect 
	{
		game[3][3] = '*';
		game[3][4] = '*';
		game[4][3] = '*'; 
		game[5][4] = '*'; 
		game[4][4] = '*'; 
		game[3][5] = '*'; 
		game[5][5] = '*'; 
		game[4][7] = '*';
		game[5][7] = '*'; 
		game[6][6] = '*'; 
		game[6][8] = '*'; 
		game[7][5] = '*'; 
	}
	
	if(choice == 2) 
	{
		game[15][15] = '*';
		game[15][16] = '*';
		game[15][17] = '*'; 
		game[17][17] = '*'; 
		game[17][15] = '*'; 
		game[13][14] = '*'; 
		game[12][14] = '*'; 
		game[11][14] = '*';
		game[11][13] = '*'; 
		game[13][13] = '*'; 
		game[16][15] = '*'; 
		game[16][12] = '*'; 
	}

		if(choice == 3) 
	{
		game[13][33] = '*';
		game[15][34] = '*';
		game[15][30] = '*'; 
		game[17][31] = '*'; 
		game[17][30] = '*'; 
		game[13][32] = '*'; 
		game[12][31] = '*'; 
		game[11][34] = '*';
		game[11][35] = '*'; 
		game[13][33] = '*'; 
		game[16][35] = '*'; 
		game[16][32] = '*'; 
	}
		if(choice == 4) 
	{
		game[12][15] = '*';
		game[13][16] = '*';
		game[13][17] = '*'; 
		game[14][17] = '*'; 
		game[14][15] = '*'; 
		game[13][14] = '*'; 
		game[11][14] = '*'; 
		game[12][16] = '*';
		game[15][15] = '*'; 
		game[13][17] = '*'; 
		game[14][14] = '*'; 
		game[14][17] = '*'; 
	}

}




/*****************************************
*Function: neigh_find
*Description: determines the number of live neighbors each cell has 
*Parameters: an array, the first number of the coordinate in the array
*and the second number of the coordinate 
*Pre-Conditions: number of neighbors of the cell is not known
*Post-Conditions: number of neighbors of the cell is known
******************************************/ 

int neigh_find(char game[][82], int i, int j) 		                     //determines how many live neighbors each cell has 
{
	int neigh = 0; 		                     		//the number of neighbors a cell has
	
	
	if (i == 0 && j == 0) 	                     //condition for top left corner (limited due to intention not to access values outside of the array) 
	{
		if(game[i+1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i+1][j+1] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i][j+1] == '*')
		{
			neigh = neigh+1; 
		} 
		
	}
		
	if (i == 0 && j == 81) 	                      //condition for bottom left corner
	{
		
		if(game[i+1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i+1][j-1] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
		
		
	}
	
	if (i == 0 && j != 0)	                     //condition for left side
	{
		if(game[i+1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i+1][j+1] == '*') 
		{
			neigh = neigh+1; 
		}
		if(game[i+1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
		
		if(game[i][j+1] == '*')
		{
			neigh = neigh+1; 
		} 
	
		if(game[i][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	
	}
	
	if (i == 81 && j != 81)		                     //condition for right side 
	{
		if(game[i-1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i-1][j+1] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i-1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
		
		if(game[i][j+1] == '*')
		{
			neigh = neigh+1; 
		} 
	
		if(game[i][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	
	}		  
	
	if (i != 81 && j == 81) 	                     //condition for bottom row
	{
		if(game[i-1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i+1][j] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	
		if(game[i+1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
		if(game[i-1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	
	}
	
	if (i == 81 && j == 81) 	                     //condition for bottom right corner
	{
		if(game[i-1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i-1][j-1] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	}
	
	if (i == 81 && j == 0) 	                        //condition for top right corner
	{
		if(game[i-1][j] == '*')
		{
			neigh = neigh+1; 
		}
		if(game[i-1][j+1] == '*') 
		{
			neigh = neigh+1; 
		}
		
		if(game[i][j+1] == '*')
		{
			neigh = neigh+1; 
		} 
	}
	
	if (i != 1 && j != 1 && i != 81 && j != 81) 
	{
		if(game[i][j+1] == '*')	                     //if the cell one to the right of the cell in question is alive, 
		{
			neigh = neigh+1; 	                     //then count that as one neighbor 
		} 
		if(game[i][j-1] == '*')		                     //same as above, repeat for all 8 adjacent cells 
		{
			neigh = neigh+1; 
		} 
		
		if(game[i+1][j+1] == '*') 
		{
			neigh = neigh+1; 
		} 
		if(game[i+1][j] == '*')
		{
			neigh = neigh+1; 
		} 	   
		if(game[i+1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
		if(game[i-1][j+1] == '*')
		{
			neigh = neigh+1; 
		} 	
		if(game[i-1][j] == '*')
		{
			neigh = neigh+1; 
		} 
		if(game[i-1][j-1] == '*')
		{
			neigh = neigh+1; 
		} 
	}
	
	return neigh; 
}




/*****************************************
*Function: array_changer
*Description: copies the array to a second array, tests all of the 
*locations in the array using neigh_find, kills or creates live cells 
*based on the game's rules, and then copies the updated array back to
*it's original location
*Parameters: array sized [24][82]
*Pre-Conditions: generation x of the game of life
*Post-Conditions: generation x+1 of the game of life
******************************************/ 
void array_changer(char game[][82])	                     //updates the array for the next generation
{
	char temp_arr[24][82];                      //temporary array used to store the data for the current gen, without compromising the next gen
	int neigh_num; 			                     //number of live neighbors a cell has	    	

 	int i = 0; 	                     //resets counters
	int j = 0;	  
	
	
	
	for(i == 0; i<24; i++)	                     //assigns the same values as the game array
	{
		for(j == 0; j<82; j++) 
		{
			temp_arr[i][j] = game[i][j] ;                      //for each cell in the array, the temp array equals the game array

		}
		j = 0; 
	}

	i = 0; 	                     //resets counters
	j = 0;	  

	for(i == 0; i<24; i++)	                     //loops through the array
	{
		 
		for(j == 0; j<82; j++) 
		{
			neigh_num = neigh_find(game,i,j);                      //runs the neighbor finder function on each cell
		 
			if (neigh_num == 0)		                     //if the cell has no neighbors, it is dead (regardless of whether it was alive or dead) 
			{
				temp_arr[i][j] = ' '; 
			}
			if(neigh_num == 1) 		                     //if the cell has one neighbor, it remains dead, or dies 
			{
				temp_arr[i][j] = ' '; 
			}
									                     //if a cell has two neighbors it's status doesn't change (so there is no condition for this) 
			
			if (neigh_num == 3)		                     //if a cell has three neighbors, it is born! Or, continues to be alive
			{
				temp_arr[i][j] = '*'; 
			}
			if (neigh_num >=4)		                     //if a cell has four or more neighbors, it dies or stays dead
			{
				temp_arr[i][j] = ' '; 	  	  
			}

		}
		j = 0; 
	}

	i = 0; 	                     //resets counters
	j = 0; 
	
	for(i == 0; i<24; i++)	                     //loops through the array
	{
		for(j == 0; j<82; j++) 
		{
			game[i][j] = temp_arr[i][j];                      //sets all the values of the temp array to the game array 

		}
		j = 0; 
	}


}


