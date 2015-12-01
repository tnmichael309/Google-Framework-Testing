#include "hw1.h"

// Return expected sells
// 1 <= nLock <= 70 or nLock = -1
// 1 <= nBarrel <= 80
// 1 <= nStock <= 90
// lock: $45, barrel: $25, stock: $30
// commission rate: 10%
const char* Commission(int nLock, int nBarrel, int nStock){

	if(nLock < -1 || nLock == 0 || nLock > 70) return "Invalid input";
	if(nBarrel == 0 || nBarrel > 80) return "Invalid input";
	if(nStock == 0 || nStock > 90) return "Invalid input";
	
	if(nLock == -1) return "Program terminates";
	
	int sell = nLock*45 + nBarrel*25 + nStock*30;
	sell/=10;
	
	static char buffer[50];
	int n = 0;
	n = sprintf(buffer, "%d", sell);
	
	buffer[n] = '\0';
	
	return buffer;
}


// Returns next date
const char* NextDate(int year, int month, int day){
	
	int errorCount = 0;
	
	if(year < 0) errorCount++;
	if(month < 1 || month > 12) errorCount++;
	if(day < 1 || day > 31) errorCount++;
	
	if(errorCount > 0) return "Invalid input";
	
	
	//check whether it is a special year
	bool isSpecialYear = ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0);
	static char buffer[50];
	int n = 0;
	
	if(isSpecialYear && month == 2){
		if(day > 29) return "Invalid input";
		else{
			if(day == 29) n = sprintf(buffer, "%d/%d/%d", year, month+1, 1);
			else n = sprintf(buffer, "%d/%d/%d", year, month, day+1);
		}
	}else if(month == 2){
		if(day > 28) return "Invalid input";
		else{
			if(day == 28) n = sprintf(buffer, "%d/%d/%d", year, month+1, 1);
			else n = sprintf(buffer, "%d/%d/%d", year, month, day+1);
		}
	}else{
		
		if((month <= 7 && month % 2 == 1) || (month >= 8 && month % 2 == 0) ){
			if(day > 31) return "Invalid input";
			else{
				if(month == 12 && day == 31) n = sprintf(buffer, "%d/%d/%d", year+1, 1, 1);
				else if(day == 31) n = sprintf(buffer, "%d/%d/%d", year, month+1, 1);
				else n = sprintf(buffer, "%d/%d/%d", year, month, day+1);
			}
		}else{
			if(day > 30) return "Invalid input";
			else{
				if(day == 30) n = sprintf(buffer, "%d/%d/%d", year, month+1, 1);
				else n = sprintf(buffer, "%d/%d/%d", year, month, day+1);
			}
		}
	}
	
	buffer[n] = '\0';
	
	return buffer;
	
};

// Returns type of the triangle
const char* Triangle(int a, int b, int c){

	if(a <= 0 || b <= 0 || c <= 0){
		return "Invalid length input";
	}
	
	if(a == b && b == c){
		return "Equilateral";
	}
	
	if(a == b || b == c || a == c){
		return "Isosceles";
	}
	
	if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b){
		return "Scalene";
	}
	
	if( (a+b > c && a+c > b && b+c > a) == false ){
		return "Not a triangle";
	}
	
	return "Non-special triangle";
};