#include<bits/stdc++.h>
using namespace std;

//Count Sum
//Factorial
//sumArray

void countSum(int n){

	if(n == 0) //Base Case or Terminating Condition
	{
		return ;
	}

	cout<< n << " ";
	countSum(n-1); 
}

int main(){
	
	int n = 5 ; 
	cout<< countSum(n) <<endl;
	return 0;
}