/*
**Name: Jonathan Jensen
**SSID: G03567847
**CRN: 16692
**Assignment: Functions and Relations Application Problem !
**/

#include <iostream>
#include <string>

using namespace std;

int main(){

	string    setA;
	string    setB;
	string    setC;
	int       map[26] = {0};
	int       map2[26] = { 0 };
	bool      funcCondition;
	bool      funcInject;
	bool      funcSurject;

	//user input here
	cout << "Enter first set please use only lower case letters "
		<< "with no blanks or other characters(ie. 'abcdefg'): ";
	cin >> setA;
	cout << endl;

	cout << "You may now enter set #2. Keep in mind, improper input "
		<< "may yield unexpected results: ";
	cin >> setB;
	cout << endl;

	cout << "Finally, enter a subset of the cartesian product produced "
		<< "when crossing the first two sets. Please do not input any \n "
		<< "brackets, commas, or spaces. (ie. if the proper notation "
		<< "is '{(a,b),(c,d),(e,f)}', enter 'abcdef':";
	cin >> setC;
	cout << endl;

	//compares elements of seA with the proper elements of setC
	for (unsigned int i = 0; i < setA.length(); i++){
		for (unsigned int j = 0; j <= (setC.length() / 2); j++){
			if (setA.at(i) == setC.at(j)){
				map[i]++;
			}
			j++;
		}
	}

	//uses the values stored in map to determine if C is function
	for (unsigned int i = 0; i < setA.length(); i++){
		if (map[i] == 1){
			funcCondition = true;
		}
		//function condition #1 = "every element in X is 
		//related to some element in Y."
		else if (map[i] == 0){
			funcCondition = false;
			cout << "Function condition 1 Violated. "
				<< "Incomplete domain. " << endl;
			break;
		}
		//function condition #2 = "no element in X is related
		//to more than one element in Y."
		else if (map[i] > 1){
			funcCondition = false;
			cout << "Function condition 2 violated. "
				<< "Domain element mapped to multiple "
				<< "codomain elements." << endl;
			break;
		}
	}

	if (funcCondition == true){
		for (unsigned int i = 0; i < setB.length(); i++){
			for (unsigned int j = 1; j <= ((setC.length() / 2) + 1); j++){
				if (setB.at(i) == setC.at(j)){
					map2[i]++;
				}
				j++;
			}
		}

		for (unsigned int i = 0; i < setB.length(); i++){
			if (map2[i] <= 1){
				funcInject = true;
			}
			else if (map2[i] > 1){
				funcInject = false;
				break;
			}
		}

		for (unsigned int i = 0; i < setB.length(); i++){
			if (map2[i] >= 1){
				funcSurject = true;
			}
			else if (map2[i] < 1){
				funcSurject = false;
				break;
			}
		}
		cout << "C is a function" << endl;
		if (funcInject == true){
			cout << "C is injective" << endl;
		}
		if (funcSurject == true){
			cout << "C is surjective" << endl;
		}
	}

	return 0;
}
