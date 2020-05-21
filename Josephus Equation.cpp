/*Written by Beau Robinette started 4/15/2020
This program iteratively computes the index left over for 
Josephus equation, it takes the size of the circle and the 
number to skip by from the user*/

/*The program may be stopped if the user enters 0 for the size 
of the circle or number to skip by*/

#include<iostream>

using namespace std;

//Function header to determine Josephuses number
int josephuses_equation(int, int);

int main() {

	int size_of_circle, skipping_number, preserved_index;

	//Run the program on a loop while the user doesn't enter one
	do {
		//Get circle size 
		cout << "Enter the size of the circle: ";
		cin >> size_of_circle;

		//Get number to skip by
		cout << "Enter number to skip by: ";
		cin >> skipping_number;

		//Calculate and tell the user the preserved index
		if (size_of_circle != 0 && skipping_number != 0) {
			preserved_index = josephuses_equation(skipping_number, size_of_circle);

			//Since the problem states 1 -n and c++ starts at zero one needs to be added to the index
			cout << "The index preserved is: " << preserved_index + 1 << endl;
		}

	} while (size_of_circle != 0 && skipping_number != 0);
}

//Function definition to determine the index that is preseverved
//Function header to determine Josephuses number
int josephuses_equation(int number_to_skip, int size_of_circle) {

	//Counter variable (to kill or not kill)
	int kill_countdown = 0;

	//Total kills variable
	int total_kills = 0;

	//Index tracker
	int index_tracker;

	//Dynamically allocate two arrays the size of the circles
	bool* dead_or_alive;
	int* index;
	dead_or_alive = new bool[size_of_circle];
	index = new int[size_of_circle];

	//Fill the first array with all trues (everyone is alive initially)
	for (int i = 0; i < size_of_circle; i++) {
		dead_or_alive[i] = true;
	}

	//Fill the second array with index numbers
	for (int i = 0; i < size_of_circle; i++) {
		index[i] = i;
	}

	//Run this on a loop until there is only one survivor
	do {

		//Iterate through the entire circle
		for (int i = 0; i < size_of_circle; i++) {

			//Increment the kill countdown if the person is still alive
			if (dead_or_alive[i]) {
				kill_countdown += 1;

			}

			//If the kill countdown matches the number to be skipped, kill the person
			if (kill_countdown == number_to_skip) {
				kill_countdown = 0;
				dead_or_alive[i] = false;
				total_kills += 1;
			}
		}


	} while (total_kills < size_of_circle - 1);

	//Find the last person
	for (int i = 0; i < size_of_circle; i++) {
		if (dead_or_alive[i]) {
			index_tracker = i;
		}
	}
	return index_tracker;
}
