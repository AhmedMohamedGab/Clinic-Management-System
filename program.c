/**
	******************************************
	Author			: Ahmed Mohamed Elsayed
	Project_Name	: Clinic Management System
	Date			: 11 / 8 / 2024
	******************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "std_types.h"
#include "interface.h"

extern u32 index_of_array ;
u8  system_termination_flag = false ;

u32 Restore_Old_Data (patient_record arr_data [])
{
	if ((Data = fopen ("Patients_Database.txt", "rb")) != NULL) /// open file
    {
        while ( !feof (Data))
        {
			fread ( arr_data [index_of_array].Name			, sizeof (arr_data [index_of_array].Name			), 1, Data) ;
            fread (&arr_data [index_of_array].Age			, sizeof (arr_data [index_of_array].Age				), 1, Data) ;
            fread (&arr_data [index_of_array].Gender		, sizeof (arr_data [index_of_array].Gender			), 1, Data) ;
            fread (&arr_data [index_of_array].ID			, sizeof (arr_data [index_of_array].ID				), 1, Data) ;
			
            index_of_array ++ ;
        }
    }
	return index_of_array ;
}

/**        *******************************************************************************
*/

void Admin_Mode (void)
{
	Enter_Password();
	if (system_termination_flag == true)
	{
		return ;
	}
	
	u8  chosen_action ;
	
	printf ("Select action :\n") ;
	
	while (INFINITE_LOOP)
	{
		printf ("1 -> Add new patient record\n") ;
		printf ("2 -> Edit patient record\n") ;
		printf ("3 -> Reserve a slot with the doctor\n") ;
		printf ("4 -> Cancel reservation\n") ;
		printf ("5 -> Return to Main Window\n") ;
		printf ("*****************\n\n") ;
		printf ("Enter your choice : ") ;
	
		fflush (stdin) ;
		scanf  ("%s", &chosen_action) ;
		fflush (stdin) ;
		
		if (chosen_action == FIRST_CHOICE)
		{
			printf ("OK, You are in \"Add new patient record\" selection\n\n") ;
			Add_New_Patient_Record (arr_data) ;
		}
		else if (chosen_action == SECOND_CHOICE)
		{
			printf ("OK, You are in \"Edit patient record\" selection\n\n") ;
			Edit_Patient_Record (arr_data) ;
		}
		else if (chosen_action == THIRD_CHOICE)
		{
			printf ("OK, You are in \"Reserve a slot with the doctor\" selection\n\n") ;
			Reserve_Slot (arr_data) ;
		}
		else if (chosen_action == FOURTH_CHOICE)
		{
			printf ("OK, You are in \"Cancel reservation\" selection\n\n") ;
			Cancel_Reservation () ;
		}
		else if (chosen_action == FIFTH_CHOICE)
		{
			printf ("You are in Main window \n\n") ;
			break ;
		}
		else
		{
			printf ("\nPlease enter valid choise\n\n\n") ;
		}
	}
}

/**        *******************************************************************************
*/

void Add_New_Patient_Record (patient_record arr_data []){
	if (index_of_array == MAX_PATIENTS_NUMBER)
	{
		printf ("Sorry you can not add a new record\n")	;
		printf ("Maximum number of records reached\n")	;
	}
	else
	{
	    u32 Iteration_Array	;
	    u64 National_ID		;
		u8	Check_Gender	;
	    
	    printf ("Enter Patient National ID : ")	;
	    scanf  ("%llu" , & National_ID )		;
	    
	    for (Iteration_Array = STARTING_OF_ARRAY ; Iteration_Array < index_of_array ; Iteration_Array ++)
	    {
	    	if (arr_data [Iteration_Array].ID == National_ID)
	    	{
	    		printf ("This patient already exits in the database\n") ;
	    		break ;
	    	}
	    }
	    
	    if (Iteration_Array >= index_of_array)
	    {
	    	arr_data [index_of_array].ID = National_ID ;
	    	
	        printf ("Enter Patient Name : ");
	    	fflush (stdin) ;
	        gets   (arr_data [index_of_array].Name) ;
	        fflush (stdin) ;
	    	
	        printf ("Enter Patient Age : ") ;
	        scanf  ("%d", &arr_data [index_of_array].Age ) ;
	        
			printf ("Enter Patient Gender :\n") ;
			while (INFINITE_LOOP)
			{
				printf ("1 -> Male\n") ;
				printf ("2 -> Female\n") ;
				scanf  ("%u" , &Check_Gender) ;
				if (Check_Gender != MALE && Check_Gender != FEMALE)
				{
					printf ("Enter Correct Gender :\n") ;
				}
				else
				{
					arr_data [index_of_array].Gender = Check_Gender ;
					break ;
				}
			}
	        
			printf ("\nOperation accomplished successfully\n") ;
			printf ("Patient data :\n\n") ;
			
			printf ("Name	: %s\n"		, arr_data [index_of_array].Name	);
			printf ("Age	: %u\n"		, arr_data [index_of_array].Age		);
			arr_data [index_of_array].Gender == MALE ? printf ("Gender	: Male\n") : printf ("Gender	: Female\n") ;
	        printf ("ID	: %llu\n\n"		, arr_data [index_of_array].ID		);
	        
	        index_of_array ++ ;
	    }
	}
}

/**        *******************************************************************************
*/

void Edit_Patient_Record (patient_record arr_data []){
	u8  chosen_action ;
	u64 Check_ID ;
	u8 Check_Gender ;
	u32 MY_Iteration_Array ;
	
	printf ("Enter Patient National ID : ") ;
	scanf  ("%llu" , &Check_ID) ;
	
	for (MY_Iteration_Array = STARTING_OF_ARRAY; MY_Iteration_Array < index_of_array; MY_Iteration_Array ++)
	{
		if (arr_data [MY_Iteration_Array].ID == Check_ID)
		{
			break ;
		}
	}
	if (MY_Iteration_Array >= index_of_array)
	{
		printf ("Can not find this record\n") ;
	}
	else
	{
	    printf ("Select action :\n") ;
	    
	    while (INFINITE_LOOP)
	    {
	        printf ("1 -> Edit Name\n") ;
	        printf ("2 -> Edit Age\n") ;
	        printf ("3 -> Edit Gender\n") ;
	        printf ("4 -> Edit National ID\n") ;
	        printf ("5 -> Return to Main Window\n") ;
	        printf ("*****************\n\n") ;
	        printf ("Enter your choice : ") ;
	    
	        fflush (stdin) ;
	        scanf  ("%s" , &chosen_action) ;
	        fflush (stdin) ;
			
	    	if (chosen_action == FIRST_CHOICE)
	        {
				printf ("Enter the New Name : ") ;
				fflush (stdin) ;
				gets   (arr_data [MY_Iteration_Array].Name) ;
				fflush (stdin) ;
	        }
	        else if (chosen_action == SECOND_CHOICE)
	        {
				printf ("Enter the New Age : ") ;
	        	scanf("%u", &arr_data [MY_Iteration_Array].Age);
	        }
	        else if (chosen_action == THIRD_CHOICE )
	        {
				printf ("Enter the New Gender :\n") ;
				while (INFINITE_LOOP)
				{
					printf ("1 -> Male\n") ;
					printf ("2 -> Female\n") ;
					scanf  ("%u" , &Check_Gender) ;
					if (Check_Gender != MALE && Check_Gender != FEMALE)
					{
						printf ("Enter Correct Gender :\n") ;
					}
					else
					{
						arr_data [MY_Iteration_Array].Gender = Check_Gender ;
						break ;
					}
				}
	        }
	    	else if (chosen_action == FOURTH_CHOICE)
	        {
				printf ("Enter the New National ID : ") ;
	        	scanf("%llu", &arr_data [MY_Iteration_Array].ID);
	        }
	    	else if (chosen_action == FIFTH_CHOICE)
	        {
				printf ("\nOperation accomplished successfully\n") ;
				printf ("Patient data :\n\n") ;
				
				printf ("Name	: %s\n"		, arr_data [MY_Iteration_Array].Name	);
				printf ("Age	: %u\n"		, arr_data [MY_Iteration_Array].Age		);
				arr_data [MY_Iteration_Array].Gender == MALE ? printf ("Gender	: Male\n") : printf ("Gender	: Female\n") ;
				printf ("ID	: %llu\n\n"	, arr_data [MY_Iteration_Array].ID		);
				printf ("You are in Admin Window \n\n") ;
				break ;
	        }
	        else
	        {
	        	printf ("\nPlease enter valid choice\n\n\n") ;
	        }
	    }
	}
}

/**        *******************************************************************************
*/

void Reserve_Slot (patient_record arr_data []){
	u64	Check_ID ;
	u32	MY_Iteration_Array ;
	u8 	SLOTS_ITERATION;
	u8	selected_slot ;
	
	printf ("Enter Patient National ID : ") ;
	scanf  ("%llu", &Check_ID) ;
	
	for (MY_Iteration_Array = STARTING_OF_ARRAY; MY_Iteration_Array < index_of_array; MY_Iteration_Array ++)
	{
		if (arr_data [MY_Iteration_Array].ID == Check_ID)
		{
			break ;
		}
	}
	if (MY_Iteration_Array >= index_of_array)
	{
		printf ("Can not find this record\n") ;
	}
	else
	{
		if (AVAILABLE_SLOTS == 0)
		{
			printf("There are No Available Slots\n");
		}
		else
		{
			printf("There are %d Available Slots\n", AVAILABLE_SLOTS);
			if (slots [SLOTS_ITERATION ++] == 0)
			{
				printf("1 -> %s\n", SLOT_1);
			}
			if (slots [SLOTS_ITERATION ++] == 0)
			{
				printf("2 -> %s\n", SLOT_2);
			}
			if (slots [SLOTS_ITERATION ++] == 0)
			{
				printf("3 -> %s\n", SLOT_3);
			}
			if (slots [SLOTS_ITERATION ++] == 0)
			{
				printf("4 -> %s\n", SLOT_4);
			}
			if (slots [SLOTS_ITERATION ++] == 0)
			{
				printf("5 -> %s\n", SLOT_5);
			}
			printf("Select the desired slot :\n");
			while (INFINITE_LOOP)
			{
				scanf("%d", &selected_slot);
				if (selected_slot <= MAX_SLOTS_NUM	&&	slots [selected_slot - 1] == 0)
				{
					slots [selected_slot - 1] = arr_data [MY_Iteration_Array].ID ;
					AVAILABLE_SLOTS -- ;
					printf ("\nOperation accomplished successfully\n") ;
					printf ("Patient reserved slot number %d\n\n", selected_slot) ;
					break ;
				}
				else
				{
					printf ("Please enter valid choice : ") ;
				}
			}
		}
	}
}

/**        *******************************************************************************
*/

void Cancel_Reservation (void){
	u64 Check_ID ;
	u8 SLOTS_ITERATION;
	
	printf ("Enter Patient National ID : ") ;
	scanf  ("%llu", &Check_ID) ;
	
	for (SLOTS_ITERATION = STARTING_OF_ARRAY; SLOTS_ITERATION < MAX_SLOTS_NUM; SLOTS_ITERATION ++)
	{
		if (slots [SLOTS_ITERATION] == Check_ID)
		{
			slots [SLOTS_ITERATION] = 0 ;
			AVAILABLE_SLOTS ++ ;
			break ;
		}
	}
	if (SLOTS_ITERATION >= MAX_SLOTS_NUM)
	{
		printf ("Can not find this reservation\n") ;
	}
	else
	{
		printf ("\nOperation accomplished successfully\n") ;
		printf ("Patient canceled reservation\n\n") ;
	}
}

/**        *******************************************************************************
*/
 
void User_Mode (void)
{
	u8 chosen_action;
	
	printf ("Select action :\n") ;
	
	while (INFINITE_LOOP)
	{
		printf ("1 -> View patient record\n") ;
		printf ("2 -> View todays reservations\n") ;
		printf ("3 -> Return to main Window\n") ;
		printf ("*****************\n\n") ;
		printf ("Enter your choice : ") ;
	
		fflush (stdin) ;
		scanf  ("%s" , &chosen_action) ;
		fflush (stdin) ;
		
		if (chosen_action == FIRST_CHOICE)
		{
			printf ("OK , You are in \"View patient record\" selection\n\n") ;
			View_Patient_Record(arr_data) ;
		}
		else if (chosen_action == SECOND_CHOICE)
		{
			printf ("OK , You are in \"View todays reservations\" selection\n\n") ;
			View_Todays_Reservations () ;
		}
		else if (chosen_action == THIRD_CHOICE )
		{
			printf ("OK , You are in Main Window\n\n") ;
			break ;
		}
		else
		{
			printf ("Please enter valid choice\n\n\n") ;
		}
	}
}

/**        *******************************************************************************
*/

void Enter_Password (void){
	u8 Password [MAX_PASSWORD_SIZE] ;
	u8 Counter ;
	
	printf ("Enter password (You have three attempts) : ") ;
	
	for (Counter = STARTING_OF_LOOP; Counter <= MAX_TRY_AGAIN; Counter ++)
	{
		fflush (stdin)		;
		gets   (Password)	;
		fflush (stdin)		;
		
		if (!strcmp (Password, DEFAULT_ADMIN_PASSWORD))
		{
			break ;
		}
		else if (Counter < MAX_TRY_AGAIN)
		{
			printf ("Incorrect password entered\n")	;
			printf ("Try again\n") 					;
		}
		else
		{
			printf ("You are out of attempts\n");
			printf ("System Exited\n")			;
			system_termination_flag = true		;
			break								;
		}
	}
}

/**        *******************************************************************************
*/

void View_Patient_Record (patient_record arr_data []){
	u64 Check_ID ;
	u32 My_Iteration_Array ;
	
	printf ("Enter Your National ID : ") ;
	scanf  ("%llu" , &Check_ID) ;
	
	for (My_Iteration_Array = STARTING_OF_ARRAY; My_Iteration_Array < index_of_array; My_Iteration_Array ++)
	{
		if (arr_data [My_Iteration_Array].ID == Check_ID)
		{
			break ;
		}
	}
	if (My_Iteration_Array >= index_of_array)
	{
		printf ("can not find this record\n") ;
	}
	else
	{
		printf ("Patient data :\n\n") ;
		
		printf ("Name	: %s\n"		, arr_data [My_Iteration_Array].Name	);
		printf ("Age	: %u\n"		, arr_data [My_Iteration_Array].Age		);
		arr_data [My_Iteration_Array].Gender == MALE ? printf ("Gender	: Male\n") : printf ("Gender	: Female\n") ;
		printf ("ID	: %llu\n\n"	, arr_data [My_Iteration_Array].ID		);
	}
}

/**        *******************************************************************************
*/

void View_Todays_Reservations (void){
	u8 SLOTS_ITERATION = STARTING_OF_ARRAY ;
	
	if (AVAILABLE_SLOTS == MAX_SLOTS_NUM)
	{
		printf("There are No Reservations Today\n");
	}
	else
	{
		printf("There are %d Available Slots\n", AVAILABLE_SLOTS);
		if (slots [SLOTS_ITERATION ++] != 0)
		{
			printf("%s	slot is reserved\n", SLOT_1);
		}
		if (slots [SLOTS_ITERATION ++] != 0)
		{
			printf("%s	slot is reserved\n", SLOT_2);
		}
		if (slots [SLOTS_ITERATION ++] != 0)
		{
			printf("%s	slot is reserved\n", SLOT_3);
		}
		if (slots [SLOTS_ITERATION ++] != 0)
		{
			printf("%s	slot is reserved\n", SLOT_4);
		}
		if (slots [SLOTS_ITERATION ++] != 0)
		{
			printf("%s	slot is reserved\n", SLOT_5);
		}
	}
}

/**        *******************************************************************************
*/

void Restore_New_Data (patient_record arr_data [])
{
	u32 Iteration_Array ;
	
	Data = fopen ("Patients_Database.txt" , "wb") ;
	
	for (Iteration_Array = STARTING_OF_ARRAY ; Iteration_Array < index_of_array ; Iteration_Array ++)
    {
		fwrite ( arr_data [Iteration_Array].Name			, sizeof (arr_data [Iteration_Array].Name)			, 1, Data) ;
        fwrite (&arr_data [Iteration_Array].Age				, sizeof (arr_data [Iteration_Array].Age)			, 1, Data) ;
        fwrite (&arr_data [Iteration_Array].Gender			, sizeof (arr_data [Iteration_Array].Gender)		, 1, Data) ;
        fwrite (&arr_data [Iteration_Array].ID				, sizeof (arr_data [Iteration_Array].ID)			, 1, Data) ;
    }
    fclose(Data) ;
}

/**        *******************************************************************************
*/
