
/*********************
*Program: Lab_9.cpp
*Author: Tracy Stinghen
*Date Created: 4/17/14
*Last Date Modified: 
*Description: 
*Input: 
*Output:  
*Resources: 
***************************/

 



#include <iostream>
#include <climits>

struct suitor 
{
	int number; 
	suitor *link; 

}; 


void sort_suitors(int men); 
int input_check (int number);

int main ()
{
	int suitors;
	std::cout<<"Enter number of suitors: "; 
	std::cin>>suitors; 
	
	suitors = input_check(suitors); 
	
	sort_suitors(suitors); 
	
	return 0; 

} 


/*****************************************
*Function: 
*Description: 
*Parameters:
*Pre-Conditions: 
*Post-Conditions:
******************************************/ 

int input_check (int number)
{
 	   	   	   	   	   	   	   	   	   	   	   	   	   
	
	while(!std::cin || number > INT_MAX || number < 0)	  	  	  	  	  	  	   //while the input is invalid ... 
			{ 			
				std::cin.clear(); 													//clear line
	   			std::cin.ignore(INT_MAX, '\n');										 //ignore characters
	   			std::cout<<"\nWe're working with numbers. Enter a number, please: "; 	   //prompts for new imput
				std::cin>>number; 													//accepts new input	   	   	   	   	   	   
 	   	   	   	   	   	   	   	   	   	 
			}
	
	return number; 

}

void sort_suitors(int men)
{

	suitor *head; 	//first node 
	suitor *this_guy; //the current node 
	suitor *discard; //node to be discarded
	suitor *before; //node before the one to discard
	suitor *print; //node to be printed
	
	//int the_num = 42; 

	int elim;  

	
	head = new suitor; //create a new item
	head->link = NULL;  //it doesn't have a link yet
	head->number = 0; 	//contains the number 0
	
	this_guy = head; 	//set the current node to this one
	
	for (int i = 1; i <= men; i++) 	//for the number of suitors input
	{
		this_guy->link = new suitor; //create a new suitor item
									//and link it to the current node
		this_guy = this_guy->link;  //change the current node
		this_guy->link = 0; 		//set the link to 0
		this_guy->number = i;		//set the number to the iterator
		
		if(this_guy->number == men) //if this is the last node
		{
			this_guy->link = head; 	//link it to the first node, to make a circuit 
		
		}
	}
	
	 
	
	
	this_guy = head; 				//set current node to the start
	if (this_guy->link != NULL) 	//safeguard
	{
		do  						//iterate through the list, printing
		{
			this_guy = this_guy->link;
			std::cout<<"Suitor #"<<this_guy->number<<std::endl;  
		}while  (this_guy->number < men);
		
	}
	
	elim = 1;						//set the elimination parameter to 1	   
	this_guy = head; 
	while (men > 1) 				//while there is more than 1 suitor
	{	 
		if (this_guy != NULL)		//safeguard 
		{
		
				this_guy = this_guy->link;		//adcvance one node
				if(this_guy != head) 			//if the node in question is not the head
				{								//so that the math works...
					elim++; 					//increase the elimination parameter
				}
				if (elim >= 3)					//if the elimination param reaches 3
				{
					
					before = this_guy; 			//the link before the one to be discarded
					discard = before->link; 	//the link to be discarded
					
					if (discard != head) 		//if not trying to discard the head of the list
					{
						std::cout<<"\n\nThe princess has eliminated Suitor #"<<discard->number<<std::endl; 
						before->link = discard->link;		//remove the link from the list  
						
						delete discard;						//delete the node
						elim = 1;							//reset the elimination parameter
						men--;   							//reduce the number of men to reflect the deleted node
						std::cout<<"\nNew Suitor List:\n";	//print the updated list of suitors	   	   	   
						
						print = head; 						//set print to the head of the list
						if (print != NULL) 					//safeguard
						{
							for(int j = men; j > 0; j--) 	//for the number of men left, iterate through
							{
								print = print->link;			
								std::cout<<"Suitor #"<<print->number<<std::endl;  //print the suitors left
							}
							
						}
					}
		
				
			}
				 
		}
	}

	
	
	
	print = head; 	//as above - there ought to be only one suitor printed 
	if (print != NULL) 
	{
		if (print->link !=0) 
		{
			print = print->link;
			std::cout<<"\nSuitor #"<<print->number<<" is the successful suitor"<<std::endl;  
		}
		
	}


}

