/*******************************************************************************
Lab 2 
Bushra Dajam 2110054
Bushra Ghanem Alzeghabi 2110066
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

void fillArray (int array[],int size);
int linearSearch (int array[],int size, int key);
int binarySearch (int array[], int size, int key);

int main ()
{
  int test[1000000];
  int key;
  int linear;
  int binary;
  int size;
  
  size = sizeof (test) / sizeof (test[0]);
  fillArray (test,size);
  cout<<"pls enter the key (number you want to search about it) :";
  cin >> key;
  cout <<"\n";

  sort (test, test + size);

  clock_t start = clock ();
  linear = linearSearch (test,size, key);
  if (linear == -1 )
    {				//-1
      cout << "The key is not found" << endl;
    }
  else
    {
      cout << "The key is found at index "<<linear<< endl;
    }
  clock_t stop = clock ();
  double totalTimeL = (double (stop) - double (start)) /CLOCKS_PER_SEC;
  cout << "Total Time for linearSearch =" << totalTimeL<<endl;

  clock_t begin = clock ();
  binary = binarySearch (test,size, key);
  if (binary == -1)
    {				//-1
      cout << "The key is not found" << endl;
    }
  else
    {
      cout << "The key is found at index "<<binary<< endl;
    }
  clock_t end = clock ();
  double totalTimeB = (double (end) - double (begin)) /CLOCKS_PER_SEC;
  cout << "Total Time for binarySearch =" << totalTimeB<<endl;

  
  return 0;
}

void fillArray (int array[], int size)
{
  for (int i = 0; i < size; i++)
    {
      array[i] = (rand () % size);
    }
}


int linearSearch (int array[],int size, int key)
{
  for (int i = 0; i < size; i++)
    {
      if (key == array[i])
	return i;		//If found, return index of that element
    }
  return -1;			//if not found, return -1
}

int binarySearch (int array[], int size, int key)
{
  int low = 0, high = size - 1, mid = 0;
  while (low <= high)
    {
      mid = (low + high) / 2;
      if (key == array[mid])
	      return mid;
      else if (key < array[mid])	// change
	      high = mid - 1;
      else			// change low
	      low = mid + 1;
    }
  return -1;			// if key not found above
}
