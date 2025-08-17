/**
	******************************************
	Author			: Ahmed Mohamed Elsayed
	Project_Name	: Clinic Management System
	Date			: 11 / 8 / 2024
	******************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "program.c"

u32 index_of_array = STARTING_OF_ARRAY ;

void main (void)
{
	u8  chosen_mode ;
	
	index_of_array = Restore_Old_Data (arr_data) ;
	
    printf ("\n\n\t ************ Welcome to Clinic ************ \n\n") ;
	printf ("You are in Main window \n\n") ;
	while (INFINITE_LOOP)
	{
	    printf ("Select mode :\n") ;
	    printf ("1 -> Admin mode\n") ;
	    printf ("2 -> User mode\n") ;
	    printf ("3 -> Exit system\n") ;
	    printf ("*****************\n\n") ;
	    printf ("Enter your choice : ") ;
		
		fflush (stdin);
	    scanf  ("%c" , &chosen_mode) ;
		
		if (chosen_mode == FIRST_CHOICE)
		{
			printf ("OK , You are in Admin mode \n\n") ;
			Admin_Mode () ;
			if (system_termination_flag == true)
			{
				break ;
			}
		}
		else if (chosen_mode == SECOND_CHOICE)
		{
			printf ("OK , You are in User mode \n\n") ;
			User_Mode () ;
		}
		else if (chosen_mode == THIRD_CHOICE)
		{
			printf ("OK , Thank you for using our service\n") ;
            printf ("System Exited \n\n") ;
			Restore_New_Data (arr_data) ;
			break ;
		}
		else
		{
			printf ("\nPlease enter valid choice\n\n\n") ;
		}
	}
}
