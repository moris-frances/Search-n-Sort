#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generate random number
int generate_random_number(int min_value, int max_value) {
    return (rand() % (max_value - min_value + 1)) + min_value;
}

// initialize array with a given number of elements
void init_array(int *numbers, int array_elements) {
    srand(time(NULL));
    for (int i = 0; i < array_elements; i++) {
        *(numbers+i) = generate_random_number(-32768, +32767);
        /* printf("loop: %d\n", numbers[i]); */
    }
}
void print_15(int *arr,int el_num){
	printf("\n");
	printf("\n");
	for(int i=0; i<el_num;i++){
		if((i%14==1)&&(i!=1)) printf("\n");
		    printf("num[%d]:%d;  ",i, *(arr+i));
		}

}

int  *bbsort_arr(int *p_arr,int el_num){

	printf("\n\n\n Ascending Bubblesort: \n");
	    //ascending sort
	    for(int i1=0; i1<el_num;i1++){
	        for(int i2=0; i2<el_num; i2++){

	            if(*(p_arr+i2)<=*(p_arr+i2+1)){
	                continue;
	            }

	            else{
	                int n1=*(p_arr+i2);
	                int n2=*(p_arr +i2+1);
	                *(p_arr+i2)=n2;
	                *(p_arr+i2+1)=n1;
	            }

	    }

}
	    return p_arr;
}

	    int main(){
	        //declaring and filling an array with values from 0 to 100

	    	int num_of_elements1 = 8;
	    	int num_of_elements2 = 16;
	    	int num_of_elements3 = 64;

	    	int *num1 = malloc(sizeof(int)*num_of_elements1);
	    	int *num2 = malloc(sizeof(int)*num_of_elements2);
	    	int *num3 = malloc(sizeof(int)*num_of_elements3);

	    	init_array( num1,num_of_elements1);
	    	init_array( num2,num_of_elements2);
	    	init_array( num3,num_of_elements3);

	    	print_15(num1,num_of_elements1);
	    	print_15(num2,num_of_elements2);
	    	print_15(num3,num_of_elements3);

	    	int *result_arr1 = bbsort_arr(num1, num_of_elements1);
	    	int *result_arr2 = bbsort_arr(num2, num_of_elements2);
	    	int *result_arr3 = bbsort_arr(num3, num_of_elements3);

	    	print_15(result_arr1,num_of_elements1);
	    	print_15(result_arr2,num_of_elements2);
	    	print_15(result_arr3,num_of_elements3);

	        return 0;
	    }

