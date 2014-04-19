/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 4/1/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

Implement a class called BitArray, which will simulate a list of bits of any 
size, which can be individually set, cleared, flipped, and queried. You will 
also implement a function that is to be used by a sample test program, which 
uses the Sieve of Eratosthenes technique (with the bit array) to find prime 
numbers.

1. A bit array is to be implemented with an underlying array of type unsigned 
   char. 'Unsigned' because we are only interested in bits, not in negatives, 
   and type char because it is the smallest integer type. The concept of a 
   BitArray object is that it will store an array of bits (in the smallest 
   storage space needed), indexed starting at 0, just like with normal arrays.
2. The array of characters should be created dynamically. The primary 
   constructor has one parameter, which indicates how many bits are needed. 
   The constructor should allocate the minimum number of cells needed for 
   this many bits. Also, have the constructor initialize all bits to 0.

/******************************************************************************/
/*                       Header Files                                         */

#include <iostream>
//#include "sieve.h"
#include "bitarray.h"
using namespace std;

/******************************************************************************/
/*                       Constants                                            */



/******************************************************************************/
/*                       Constructor                                          */

BitArray::BitArray(unsigned int n)
{
	// declare array size
	int ARRAYSIZE;

	// this will give the array enough space depending on the data passed in
	// when dividing n
	if( (n % 8) != 0 )
	{
		ARRAYSIZE = ( n / 8 ) + 1;
	}
	else
	{
		ARRAYSIZE = ( n / 8 );

	}

	barray  = new unsigned char[ ARRAYSIZE ];
	
	for (int i = 0; i < ARRAYSIZE; i++)
		this->barray[i] = 255;

	arraySize = n;

} // end of BitArray::BitArray(unsigned int n) 

/******************************************************************************/
/*                       Copy Constructor                                     */

BitArray::BitArray(const BitArray& ba)
{
	int ARRAYSIZE;

	// converts bit array size to byte array size and makes it the minimum size
	if( (ba.arraySize % 8) != 0 )
	{
		ARRAYSIZE = ( ba.arraySize / 8 ) + 1;
	}
	else
	{
		ARRAYSIZE = ( ba.arraySize / 8 );
	}


	// declares this->barray space
	this->barray    = new unsigned char [ ARRAYSIZE ];

	// makes this->arraySize the same size as ba.arraySize to ensure the array
	// can fit all the data
	this->arraySize = ba.arraySize;

	// copies ba.barray into this->barray
	for( int i = 0; i < ARRAYSIZE; i++ )
	{
	// copies the content brom ba.array int this->barray
	this->barray[ i ]    = ba.barray[ i ];

	} // end of for( int i = 0; i < ARRAYSIZE; i++ )
} // end of BitArray::BitArray(const BitArray&)

/******************************************************************************/
/*                       Destructor                                           */

BitArray::~BitArray()
{
	delete [] barray;
}




/******************************************************************************/
/*                       Set Function                                         */
/*

Description: set bit with given index to 1 

*/

void BitArray::Set (unsigned int index)
{
	switch( index%8 )
	{
		case 7: 
		barray[index/8] = barray[index/8] | 1;
		break;
	case 6: 
		barray[index/8] = barray[index/8] | 2;
		break;
	case 5:
		barray[index/8] = barray[index/8] | 4;
		break;
	case 4:
		barray[index/8] = barray[index/8] | 8;
		break;
	case 3:
		barray[index/8] = barray[index/8] | 16;
		break;
	case 2:
		barray[index/8] = barray[index/8] | 32;
		break;
	case 1:
		barray[index/8] = barray[index/8] | 64;
		break;
	case 0:
		barray[index/8] = barray[index/8] | 128;
		break;
	default: cout << "Error. Index less than 0. Cannot set the bit.";

	} // end of switch( index )
} // end of void BitArray::Set (unsigned int index)

/******************************************************************************/
/*                       Unset Function                                       */
/*

Description: set bit with given index to 0 

*/

void BitArray::Unset (unsigned int index)
{
	switch( index%8 )
	{

	case 7: 
		barray[index/8] = barray[index/8] & ~1;
		break;
	case 6: 
		barray[index/8] = barray[index/8] & ~2;
		break;
	case 5:
		barray[index/8] = barray[index/8] & ~4;
		break;
	case 4:
		barray[index/8] = barray[index/8] & ~8;
		break;
	case 3:
		barray[index/8] = barray[index/8] & ~16;
		break;
	case 2:
		barray[index/8] = barray[index/8] & ~32;
		break;
	case 1:
		barray[index/8] = barray[index/8] & ~64;
		break;
	case 0:
		barray[index/8] = barray[index/8] & ~128;
		/*{
			int j=7;
			while (j>=0)
			{
				if ((barray[index/8]>>j) & 0x01)
					cout << "1";
				else
					cout << "0";
				j--;
			}
			cout << endl;
		}*/
		break;
	default: cout << "Error. Index less than 0. Cannot unset the bit.";
	//cout << "byte is " << byte;

	} // end of switch( index )
} // end of switch( index )

/******************************************************************************/
/*                       Query Function                                       */
/*

Description: return true if the given bit is set to 1, false otherwise 

*/

bool BitArray::Query (unsigned int index) const
{
	char byte;
	
	// finds the location of the byte in the array
	byte = barray[ index / 8 ];

	// shift the index
	index = index%8;


	// if the index equals the byte location
	if( index == 7 )
	{
		// if an or operation is performed on the byte and 1 and the byte 
		// equals 1 the bit is one; return true
		if( (byte | 1) == byte )
		{
			return true;
		}
		else
		{
			return false;
		}
	} // end of if( index == 7 ) 

	if( index == 6 )
	{
		if( (byte | 2) == byte )
		{
			return true;
		}
		else
		{
			return false;
		} 
	} // end of if( index == 6 ) 

	if( index == 5 )
	{
		if( (byte | 4) == byte )
		{
			return true;
		}
		else
		{
			return false;
		} 
	} // end of if( index == 5 )

	if( index == 4 )
	{
		if( (byte | 8) == byte )
		{
			return true;
		}
		else
		{
			return false;
		}
	} // end of if( index == 4 )

	if( index == 3 )
	{
		if( (byte | 16) == byte )
		{
			return true;
		}
		else
		{
			return false;
		}
	} // end of if( index == 2 )

	if( index == 2 )
	{
		if( (byte | 32) == byte )
		{
			return true;
		}
		else
		{
			return false;
		} 
	} // end of if( index == 2 )

	if( index == 1 )
	{
		if( (byte | 64) == byte )
		{
			return true;
		}
		else
		{
			return false;
		} 
	} // end of if( index == 1 )

	if( index == 0 )
	{
		if( (byte | 128) == byte )
		{
			return true;
		}
		else
		{
			return false;
		}
	} // end of if( index == 0 ) 
	return false;
} // end bool BitArray::Query (unsigned int index) const

/******************************************************************************/
/*                       Flip Function                                        */
/*

Description: change bit (with given index) from 1 to 0, or 0 to 1 

*/

void BitArray::Flip( unsigned int index )
{
	char byte;
	
	// finds the location of the byte in the array
	byte = barray[ ((index / 8) + 1 ) ];

	if( index == 7 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 7 )

	if( index == 6 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 6 )
	

	if( index == 5 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 5 )

	if( index == 4 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 4 )

	if( index == 3 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 3 )

	if( index == 2 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 2 )

	if( index == 1 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 1 )

	if( index == 0 )
	{
		if( this->Query( index ) == true )
		{
			this->Unset( index );
		}
		else
		{
			this->Set( index );
		}
	} // end of if( index == 0 )
} // end of void BitArray::Flip(unsigned int index)


ostream& operator<< (ostream& os, const BitArray& a)
{
	int ARRAYSIZE;

	// this will give the array enough space depending on the data passed in
	// when dividing n
	if( (a.arraySize % 8) != 0 )
	{
		ARRAYSIZE = ( a.arraySize / 8 ) + 1;
	}
	else
	{
		ARRAYSIZE = ( a.arraySize / 8 );

	} 
	
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		int j=7;
		while (j>=0)
		{
			if ((a.barray[i]>>j) & 0x01)
				os << "1";
			else
				os << "0";
			j--;
			//if (i==(ARRAYSIZE-1) && (j + 2 + a.arraySize%8)==8 )
				//break;
		}	
	}
	//os << "The array size is: " << a.arraySize << endl;

	return os;
} // end of ostream& operator<< (ostream& os, const BitArray& a) 


bool operator== (const BitArray& a, const BitArray& b)
 {
	 if( a.arraySize == b.arraySize )
	 {
		 // copies ba.barray into this->barray
		 for( int i = 0; i < a.arraySize/8; i++ )
		{
			// a.barray is a pointer to an array 
			if( a.barray[ i ] != b.barray[ i ] )
			{
				return false;
			}
			
		} // end of for( int i = 0; i < ARRAYSIZE; i++ )

		 // the array is equal if none of the index items are found
		 // to be unequal
		 return true;
	 } // end of if( a.arraySize == b.arraySize )

	 return false;

 } // end of bool operator== (const BitArray&, const BitArray&)



bool operator!= (const BitArray& a, const BitArray& b)
 {
	 if( a.arraySize == b.arraySize )
	 {
		 // copies ba.barray into this->barray
		 for( int i = 0; i < a.arraySize/8; i++ )
		{
			// a.barray is a pointer to an array 
			if( a.barray[ i ] != b.barray[ i ] )
			{
				return true;
			}
			
		} // end of for( int i = 0; i < ARRAYSIZE; i++ )

		 // the array is equal if none of the index items are found
		 // to be unequal
		 return false;

	 } // end of if( a.arraySize == b.arraySize )

	 return true;

 } // end of bool operator!= (const BitArray&, const BitArray&)

BitArray& BitArray::operator= (const BitArray& a)
{
	// copies the contents of object a.barray int this->barray
	for( int i = 0; i < a.arraySize; i++ )
	{
		this->barray[ i ] = a.barray[ i ];

	}

	this->arraySize = a.arraySize;
	return *this;

} // end of BitArray& operator= (const BitArray& a) 

unsigned int BitArray::Length() const
{
	return this->arraySize;

} // end of unsigned int Length() const

