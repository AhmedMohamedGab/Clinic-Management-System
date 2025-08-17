/**
	******************************************
	Author			: Ahmed Mohamed Elsayed
	Project_Name	: Clinic Management System
	Date			: 11 / 8 / 2024
	******************************************
*/

#ifndef	INTERFACE_H
#define	INTERFACE_H

#include "std_types.h"

#define INFINITE_LOOP				1

#define STARTING_OF_ARRAY			0
#define STARTING_OF_LOOP			1

#define MAX_SLOTS_NUM				5
u8	AVAILABLE_SLOTS = 5 ;
u64 slots [MAX_SLOTS_NUM] = {0} ;

#define	SLOT_1						"2pm	to	2:30pm"
#define	SLOT_2						"2:30pm	to	3pm"
#define	SLOT_3						"3pm	to	3:30pm"
#define	SLOT_4						"4pm	to	4:30pm"
#define	SLOT_5						"4:30pm	to	5pm"

#define MALE						1
#define FEMALE						2

#define true						1
#define false						0

#define FIRST_CHOICE				'1'
#define SECOND_CHOICE				'2'
#define THIRD_CHOICE				'3'
#define FOURTH_CHOICE				'4'
#define FIFTH_CHOICE				'5'

FILE *Data ;
patient_record	arr_data			[MAX_PATIENTS_NUMBER]		;
// patient_record	slot			[AVAILABLE_SLOTS]			;

/**
	*Function Name			:	Restore_Old_Data
	*Function Arguments		:	Array of structs
	*Function Return Type	:	u32	(unsigned long int)
	*Function Description	:	This function restores old records for pre-stored patients
*/
u32  Restore_Old_Data			(patient_record arr_data [])	;

/**
	*Function Name			:	Enter_Password
	*Function Arguments		:	void
	*Function Return Type	:	void
	*Function Description	:	This function asks for password
								* The default password is "1234"
								* It allows 3 trails for the password entry
								* If the entered password was incorrect for 3 consecutive times,
								* the system shall close
*/
void Enter_Password				(void) ;

/**
	*Function Name			:	Add_New_Patient_Record
	*Function Arguments		:	Array of structs
	*Function Return Type	:	void
	*Function Description	:	This function adds a new patient record
								* it asks admin to enter these basic information:
								* name, age, gender and ID
								* The ID shall be unique for the user
								* If the entered ID already exists,
								* the system shall reject the entry
*/
void Add_New_Patient_Record		(patient_record arr_data []) ;

/**
	*Function Name			:	Edit_Patient_Record
	*Function Arguments		:	Array of structs
	*Function Return Type	:	void
	*Function Description	:	This function edits a patient record
								* It asks patient to enter ID
								* If the ID exists,
								* it shall allow the user to edit the patient information
								* If not, it shall display incorrect ID message
*/
void Edit_Patient_Record		(patient_record arr_data []) ;

/**
	*Function Name			:	Reserve_Slot
	*Function Arguments		:	Array of structs
	*Function Return Type	:	void
	*Function Description	:	This function reserves a slot with doctor
								* It shall display the available slots
								* The admin shall enter the patient ID and the desired slot
								* The reserved slot shall not appear again in the next patient reservation
*/
void Reserve_Slot				(patient_record arr_data []) ;

/**
	*Function Name			:	Cancel_Reservation
	*Function Arguments		:	void
	*Function Return Type	:	void
	*Function Description	:	This function cancels reservation
								* The admin can cancel a reservation by entering the patient ID
								*  This reservation shall be shown again in the available slots window
*/
void Cancel_Reservation			(void) ;

/**
	*Function Name			:	Admin_Mode
	*Function Arguments		:	void
	*Function Return Type	:	void
	*Function Description	:	This function gets the system in Admin Mode
								* It asks admin to enter the password
								* Admin can perform any of the following actions:
								* 1 -> Add new patient record
								* 2 -> Edit patient record
								* 3 -> Reserve a slot with the doctor
								* 4 -> Cancel reservation
								* 5 -> Return to main Window
*/
void Admin_Mode					(void) ;

/**
	*Function Name			:	View_Patient_Record
	*Function Arguments		:	Array of structs
	*Function Return Type	:	void
	*Function Description	:	This function views patient record
								* By entering the patient ID,
								* the system shall show the basic information for the patient
*/
void View_Patient_Record		(patient_record arr_data []) ;

/**
	*Function Name			:	View_Todays_Reservations
	*Function Arguments		:	void
	*Function Return Type	:	void
	*Function Description	:	This function views today’s reservations
								* It shall print all reservations
								* with the patient ID attached to each reservation slot
*/
void View_Todays_Reservations	(void) ;

/**
	*Function Name			:	User_Mode
	*Function Arguments		:	void
	*Function Return Type	:	void
	*Function Description	:	This function gets the system in User Mode
								* User can perform any of the following actions:
								* 1 -> View patient record
								* 2 -> View today’s reservations
								* 3 -> Return to main Window
*/
void User_Mode					(void) ;

/**
	*Function Name			:	Restore_New_Data
	*Function Arguments		:	Array of structs
	*Function Return Type	:	void
	*Function Description	:	This function restores old records for pre-stored and new patients
*/
void Restore_New_Data			(patient_record arr_data []) ;

#endif	/*INTERFACE_H*/