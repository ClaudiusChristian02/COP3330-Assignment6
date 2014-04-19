#include <iostream>

using namespace std;

#include "sieve.h"
#include "bitarray.h"

main()
{
  unsigned int i, max,max2, counter = 0;

   cout << "\nEnter a positive integer for the maximum value: ";
   cin >> max;

   BitArray ba(max);

   Sieve(ba);                    // find the primes (marking the bits)

   cout << "The bit array looks like this: \n"
        << ba
        << '\n'; 

   cout << "\nPrimes less than " << max << ':'<< '\n';
   for (i == 0; i< max; i++)
   {   
       if (ba.Query(i))
       {
	    counter++;
            cout << i;
            if (counter % 8 == 0)
            {
                cout << '\n';
                counter = 0;
            }
            else
                cout << '\t';
       }
   }

    cout << "\nEnter a positive integer for the maximum value: ";
   cin >> max2;

   BitArray ba2(max2);

   Sieve(ba2);                    // find the primes (marking the bits)

   cout << "The bit array looks like this: \n"
        << ba2
       << '\n';
   counter=0; 
   cout << "\nPrimes less than " << max2 << ':'<< '\n';
   
   for (int i = 0; i< max2; i++)
   {   
       if (ba2.Query(i))
       {
	    counter++;
            cout << i;
            if (counter % 8 == 0)
            {
                cout << '\n';
                counter = 0;
            }
            else
                cout << '\t';
       }
   }

   if(ba==ba2) cout <<endl << "They are equal" << endl;
   else cout << endl<< "They are not equal" << endl;

   if(ba!=ba2) cout << endl << "They are not equal" << endl;
   else cout << endl << "They are equal" << endl; 

   

   cout << "\nGoodbye!\n";
  
  
}


