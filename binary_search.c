	//Created by Moris Frances on 21.12.2021
	//Binary search explanation:
	//we search for x
	//Sorted Array; but we start from the middle and:
	//case 1: x==arr[(sizeof(arr)/2)] - found
	//case 2: x<arr[(sizeof(arr)/2)] -. we search on the left side
	//case 3: x>arr[(sizeof(arr)/2)] -. we search on the right side
	//and we repeat, excluding the right/left side

#include <stdio.h>
#include <stdlib.h>

//we search for x in *parr, which has n elements
int binary_search(int *parr,int n,int x){

	int start = 0;
	int end = n-1;

	while(start<=end){
		int mid = (start+ end)/2;

		if (*(parr+mid) == x) return mid;
		else if(*(parr+mid) > x) end=mid-1;
		else start=mid+1;
	}
	return -1;
}

int main(){

	//dinamically allocated array of 9 elements
	int *arr;
	void *create_arr = malloc(sizeof(int)*9);
	arr = create_arr;

	//fills the array with
	for(int i =0; i<10; i++){

		*(arr+i)=i;
		printf(" %d \n",*(arr+i));
	}

	//init arr end
	//will print the array index of the element, that we are searching for
	//if the  element is not present, -1 will be printed
	printf("\n\nRESULT: %d \n",binary_search(arr, 10, 20));

	return 0;
}


