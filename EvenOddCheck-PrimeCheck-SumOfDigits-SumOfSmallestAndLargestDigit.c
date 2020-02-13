#include <stdio.h>

int checkError(int);
int checkEven(int);
int checkPrime(int);
int addDigits(int);
int smallestLargestSum(int);

int main (void){//Main
	int number;
	printf("\nEnter a number for even/odd check, prime check, to find the sum of the digits, and to find the sum of the smallest and largest digit\n");
	printf("Enter a positive number: ");
	scanf("%d", &number);

	while (checkError(number)==0){//Error check number
		printf("Error! Enter a positive number only: "); 
		scanf("%d", &number);
	}//End of error check

	int even = checkEven(number);//sets return int from function to even
	if (even==0){
		printf("\n%d is an odd number\n", number);
	}
	else {
	printf("%d is an even number\n", number);
	}//End of check even 
	
	int prime = checkPrime(number);//prime check function 
	if (prime==0){
		printf("%d is not a prime number\n", number);
	}
	else{
		printf("%d is a prime number\n", number);
	}//End of Prime check

	int add = addDigits(number);//sets add digits function to add
	printf("The sum of all the digits in the number %d is %d\n", number, add);

	int smallestLargest = smallestLargestSum(number);
	printf("The sum of the smallest and largest digit in the number %d is %d\n\n", number, smallestLargest); 

return 0;
}//end of main

int checkError(int x){//check to make sure number is positive
	if (x<=0){
		return 0;
	}
	return 1;
}//end of error check

int checkEven(int x){//Check even function
	if (x%2==0){
	return 1;
	}
	return 0;
}//end of check even function

int addDigits(int x){//add digits function
	int temp = 0; 
	int total = 0;
	while (x!=0){
		temp=x%10;
		total+=temp;
		x=x/10;
	}
	return total;
}//end of add digits 

int checkPrime (int x){//check prime function
	int i;
	if (x<1) return 0;
	if(x%2 == 0 && x>2) return 0;
	for (i=3; i<x/2; i+=2){
		if (x%i == 0) return 0;
	}
	return 1;
}//end of check prime

int smallestLargestSum(int x){//adds smallest and largest digits of number
	int high = 0, low = 9, temp = 0; 
	int total = 0;
	while (x!=0){
		temp=x%10;
		
		if(temp > high){
			high = temp;
		} 
		if (temp < low){
			low = temp;
		}
		x=x/10;
	}
	total = high + low;
	return total;
}//end of smallest Largest
