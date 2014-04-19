/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 4/01/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

Description: Implement a class called BitArray, which will simulate a list of 
             bits of any size, which can be individually set, cleared, flipped, 
			 and queried. You will also implement a function that is to be used 
			 by a sample test program, which uses the Sieve of Eratosthenes 
			 technique (with the bit array) to find prime numbers.
*/

/******************************************************************************/
/*                       Header Files                                         */

#ifndef _SIEVE_H
#define _SIEVE_H
#include "bitarray.h"

/******************************************************************************/
/*                       Query Function                                       */
/*

Description: return true if the given bit is set to 1, false otherwise 

*/

int Sieve( BitArray& BA ) 
{
	int prime;

	// set array index 0, 1, and 2 to 0
	BA.Unset( 0 );
	BA.Unset( 1 );
	prime = 2;

	while( prime*prime < BA.Length() ) 
	{
		// loop to unset even numbers in the bitArray
		for(int i = prime + 1; i < BA.Length(); i++ )
		{
			//cout << "i" << i << endl;
			//cout << "length" << BA.Length() << endl;
			//cout << "prime" << prime << endl;
			// checks to see if "i" is even
			if( i % prime == 0 )
			{
				BA.Unset( i );
			} // end of if( i % prime == 0 )
		} // end of for( int i = 2; i < BA.arraySize; i++ )
		//cout << BA;
		// for loop to find the next prime
		for( int i = prime + 1; i < BA.Length(); i++ )
		{
			// check to see if the number is prime
			if( BA.Query( i ) == true )
			{
				// reset prime
				prime = i;
				//cout << "prime is " << prime << endl;
				break;

			} // end if if( BA.Query( i ) )
		} // end of for( int i = prime + 1; i < BA.arraySize; i++ ) 
	} // end while( i < BA.arraySize ) 
	return 0;
} // end of int Sieve( BitArray& BA )


#endif

