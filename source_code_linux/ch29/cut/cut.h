/*
 * cut.h
 * CUT 2.0
 *
 * Copyright (c) 2001 Samuel A. Falvo II, William D. Tanksley
 * See LICENSE.TXT for details.
 *
 * Based on WDT's "TestAssert" package.
 *
 * $Log$
 */

#ifndef CUT_CUT_H_INCLUDED
#define CUT_CUT_H_INCLUDED

typedef void CUTTakedownFunction( void );

void cut_start            ( char *, CUTTakedownFunction * );
void cut_init             ( int breakpoint );
void cut_break_formatting ( void );
void cut_resume_formatting( void );

#define cut_end(t)       __cut_end( __FILE__, __LINE__, t )
#define cut_mark_point() __cut_mark_point(__FILE__,__LINE__)
#define ASSERT(X,msg)    __cut_assert(__FILE__,__LINE__,msg,#X,X)

#define ASSERT_EQUALS(X,Y,msg)   __cut_assert_equals( __FILE__, __LINE__, msg, #X " == " #Y, ( (X) == (Y) ), X )

/*
 * These functions are not officially "public".  They exist here because they
 * need to be for proper operation of CUT.  Please use the aforementioned
 * macros instead.
 */

void __cut_end          ( char *, int, char * );
void __cut_mark_point   ( char *, int );
void __cut_assert       ( char *, int, char *, char *, int );
void __cut_assert_equals( char *, int, char *, char *, int, int );

#endif

