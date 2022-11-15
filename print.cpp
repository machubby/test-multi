#include<iostream>
#include<cstdlib>
#include <unistd.h>
using namespace std;

int main(){

	// Providing a seed value
	srand((unsigned) time(NULL));

	// Get a random number
	int random = rand();

	// Print the random number
	//cout<<random<<endl;
    fprintf(stdout, "PID: %i, Random Number: %i\n",getpid(), random);
	return 1;
}