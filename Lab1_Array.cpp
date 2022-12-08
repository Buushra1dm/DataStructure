/******************************************************************************
Bushra Ghanem Alzeghabi 2110066
Bushra Abdulkhaleg Dajam 2110054
*******************************************************************************/
#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

void fillArray_1D( int array[],int size);
void fillArray_2D(int array[3][3]);
void printArray_1D (int array[],int size);
void printArray_2D (int array[3][3]);
double belowAboveAvg ( int array[],int size );
void swapLargestSmallest( int array[],int size);
void sumRowsColumns(int array[3][3]);
void repeatedElementsRow (int array[3][3]);

int main(){
    
	int size;
	int array1D [size];
	int array2D [3][3];
	
	cout<<"**************************************************"<<endl;
	cout<<"******************Array Exercise******************"<<endl;
	cout<<"**************************************************"<<endl;
	cout<< "\n\nHow mnay elemnts of the 1D array(Size of Array)? ";
	cin>>size;
	fillArray_1D(array1D,size);
	fillArray_2D(array2D);
	printArray_1D(array1D,size);
	printArray_2D(array2D);
	cout<<"\nTask 1---------------------------------------"<<endl;
	belowAboveAvg(array1D,size);
	cout<<"\n\nTask 2---------------------------------------"<<endl;
	swapLargestSmallest(array1D,size);
	printArray_2D(array2D);
	cout<<"\nTask 3---------------------------------------"<<endl;
	sumRowsColumns(array2D);
	cout<<"\n\nTask 4---------------------------------------\n";
	printArray_2D(array2D);
	repeatedElementsRow(array2D);
}
// 1 mothed
void fillArray_1D(int array[], int size)
{ 
	
	for(int i = 0; i < size; i++) {
		array[i] =(rand() % 100);
	}
}

// 2 mothed
void fillArray_2D(int array[3][3])
{ 
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) { 
			array[i][j] = (rand() % 100);
		}
	}
}

// 3 mothed
void printArray_1D (int array[], int size){
	cout<<"\nElements of the array 1D are :"<<endl;
	for(int i=0;i<size;i++){
		cout<<array[i]<<",";
	}
}

// 4 mothed
void printArray_2D (int array[3][3]){
	cout<<"\n\nElements of the Array 2D [matrix] of 3 row and 3 columns :"<<endl;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) { 
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// 5 mothed
double belowAboveAvg (int array[], int size){
	int below_count=0;
	int above_count=0;
	int Total=0;
	double ave;
	for(int i=0;i<size;i++){
		Total+=array[i];
	}
	ave=(double)Total/size;
	cout<<"The average of all elements of the array is: "<<ave<<endl;
	for(int i=0;i<size;i++){
		if(array[i]>ave)
			above_count++;
		else if(array[i]<ave)
			below_count++;
	}
	cout<<"The number of elements above the average is : "<<endl<<above_count<<endl;
	cout<<"The elements above the average are as follow: "<<endl;
	for(int i=0;i<size;i++){
		if(array[i]>ave)
			cout<<array[i]<<" ";	
	}
	cout<<"\nThe number of elements below the average is: "<<endl<<below_count<<endl;
	cout<<"The elements below the average are as follow: "<<endl;
	for(int i=0;i<size;i++){
		if(array[i]<ave)
			cout<<array[i]<<" ";	
	}
	return ave;
}

// 6 mothed
void swapLargestSmallest(int array[], int size)
{
	int largest_index=0,smallest_index=0,large_value,small_value;
	cout<<"Before swapping largest and smallest";
	printArray_1D (array,size);
	small_value=array[0];
	large_value=array[0];
	for(int i=0;i<size;i++){
		if(array[i]>large_value){
			large_value=array[i];
			largest_index=i;
		}
		if(array[i]<small_value){
			small_value=array[i];
			smallest_index=i;
		}
	}
	cout<<"\nLargest elements of the array is :"<<large_value<<endl;
	cout<<"Smallest elements of the array is :"<<small_value<<endl;
	int temp;
	temp=array[largest_index];
	array[largest_index]=array[smallest_index];
	array[smallest_index]=temp;
	cout<<"After swapping largest and smallest";
	printArray_1D (array,size);
}

// 7 mothed
void sumRowsColumns(int array[3][3]){
	for(int i=0;i<3;i++){
		int sum_row=0;
		cout<<"\t";
		for(int j=0;j<3;j++){
			cout<<array[i][j]<<"\t";
			sum_row+=array[i][j];
		}
		cout<<"Sum row : "<<sum_row<<endl;
	}
	cout<<"\nsum columns : ";
	for(int i = 0; i < 3; i++){  
        int sum_columns = 0;  
        for(int j = 0; j < 3; j++){  
          sum_columns +=  array[j][i];  
        }  
        cout<<sum_columns<<"\t";
        
    }  
}

// 8 mothed
void repeatedElementsRow (int array[3][3]){
	bool test=false;
	for (int row = 0; row < 3; row++)
    {
        for (int columns = 0; columns < 3; columns++)
        {
            int num = array[row][columns];
            for (int otherCol = columns + 1; otherCol < 3; otherCol++)
            {
                if (num == array[row][otherCol])
                {
                     for(int i=0;i<3;i++){
                     	cout<<array[row][i]<<"\t";
					 }
					 cout<<endl;
                     test=true;
                }
            }
        }
    }
    if(!test){
    	cout<<"no row contains duplicate elements"<<endl;
	}
}

