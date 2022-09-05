//#include "stdafx.h"
#include <iostream>
#include <string>

void makenot(int *firstemp, int *secondtemp, int &notnum){
	if (notnum == 1 || notnum == 3){
		for (int i = 0; i < 6; i++){
			if (firstemp[i]) firstemp[i] = 0;
			else firstemp[i] = 1;
		}
	}
	if (notnum == 2 || notnum == 3){
		for (int i = 0; i < 6; i++){
			if (secondtemp[i]) secondtemp[i] = 0;
			else secondtemp[i] = 1;
		}
	}
}

void makebool(float *firstarr, float *secondarr, int *firstemp, int *secondtemp, int &notnum){
	for (int i = 0; i < 6; i++){
		if (firstarr[i]) firstemp[i] = 1;
		else firstemp[i] = 0;
		if (secondarr[i]) secondtemp[i] = 1;
		else secondtemp[i] = 0;
	}
	if (notnum) makenot(firstemp, secondtemp, notnum);
}

void show(int *result, int size){
	std::cout << "Answer is :\n";
	for (int i = 0; i < size; i++){
		printf("%d", result[i]);
	}
	std::cout << std::endl;
}

short int operation(float *firstarr, float *secondarr, int *result, int op, int &notnum){
	int firstemp[6], secondtemp[6];
	makebool(firstarr, secondarr, firstemp, secondtemp, notnum);
	for (int i = 0; i < 6; i++){
		switch (op){
			case (1): 
				result[i] = firstemp[i] && secondtemp[i];
				break;
			case (2):
				result[i] = firstemp[i] || secondtemp[i];
				break;
			default:
				return 87;
		}
	}
	return 1;
}


int main(){
	float table[7][6] = {
		{ 5.25, 3.18, 0, 0, 0, 0.35 },
		{ 1.21, 6.1, 0, 1, 0, 0 },
		{ 8.59, 2.54, 0, 1.51, 0.25, 0 },
		{ 0, 1.54, 0, 0, 0, 0 },
		{ 2.85, 0, 0, 0, 0, 0 },
		{ 1.51, 0, 1.9, 0.12, 5.25, 0.88 },
		{ 1.37, 0, 0.11, 4.15, 0.25, 1.95 }
	};
	int counts[7], count = 0, counter = 0, first, second, op, notnum = 0;
	float firstarr[6], secondarr[6];
	int result[6];
	std::string a;
	
	while (true){
	std::cout << "List :\n1-Antony\n2-Brutus\n3-Caesar\n4-Calprunia\n5-Cleopatra\n6-Mercy\n7-Worser\n";
	std::cout << "\nEnter name numbers (put \"-\" before number if its NOT(Compliment))" << std::endl;
	std::cin >> first >> second;

	if (first < 0 && second < 0) notnum = 3;
	else if (first < 0) notnum = 1;
	else if (second < 0) notnum = 2;

	std::cout << "\nDefine Operation (1 for AND, 2 for OR): \n";
	std::cin >> op;
	if (first == 0 || second == 0 || first < -7 || first > 7 || second < -7 || second >7){
		std::cout << "Sorry ! Wrong numbers ... \n";
		return 99;
	}

	for (auto &i : table){
		count = 0;
		for (auto &j : i){
			if (counter == first - 1 || counter == (first + 1)*(-1)) { firstarr[count] = j; count++; }
			if (counter == second - 1 || counter == (second + 1)*(-1)) {
				secondarr[count] = j; count++;
			}
		}
		counts[counter] = count;
		counter++;
	}

	short int opresult = operation(firstarr, secondarr, result, op, notnum);
	switch (opresult){
		case (1):
			show(result, sizeof(result) / sizeof(result[0]));
			break;
		case (87):
			std::cout << "Wrong operation number.\nTry Again !\n";
			break;
	}		
	
	std::cout << "\n\n\n\nEnter 1 to try again or -1 to exit ...";
	short int exitcode;
	std::cin >> exitcode;
	if (exitcode == -1) return 91;
	else if (exitcode == 1) system("cls");
	else {
		std::cout << "Wrong input";
		return 101;
	}
}
	return 0;
}
