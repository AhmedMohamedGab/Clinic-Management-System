/**
	******************************************
	Author			: Ahmed Mohamed Elsayed
	Project_Name	: Clinic Management System
	Date			: 11 / 8 / 2024
	******************************************
*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "config.h"

typedef  unsigned            char   u8   ;
typedef  unsigned      short int    u16  ;
typedef  unsigned      long  int    u32  ;
typedef  unsigned long long  int    u64  ;
typedef  signed              char   s8   ;
typedef  signed        short int    s16  ;
typedef  signed        long  int    s32  ;
typedef  signed   long long  int    s64  ;
typedef                      float  f32  ;
typedef                      double f64  ;
typedef                long  double f128 ;

typedef  struct
{
	u8  Name			[MAX_NAME_LETTERS]	;
	u8  Age									;
	u8  Gender								;
	u64 ID									;
} patient_record ;

#endif	/*STD_TYPES_H*/