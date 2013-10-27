


#include <iostream>
#include <string>
#include <vector>

void error(std::string s){

	throw std::runtime_error(s);
}


class day{

static const int min = 1;
static const int max = 31;
public:
	class Invalid{}; // place holder or type class
	day(int d): d(d){if(d<min || d > max) throw Invalid(); } // if the day is outside of reason, then throw exception
	int printDay();
private : 
	int d;
};

int day::printDay(){
		
	return d; // return day value

}



class year{

static const int min = 1800;
static const int max = 2200;

public : 
	class Invalid{};
	year (int y) : y(y){if(y<min || y>max) throw Invalid();}
	int printYear();
private :
	int y;
};

int year::printYear(){

	return y;
}



class Date{
public : 
	enum Month {jan, feb,mar,apr,may,june,july,aug,sep,oct,nov,dec};
	Date(year y, Month m, day d): y(y),m(m),d(d){};
	void printDate();


private:
	year y;
	Month m;
	day d;

};

// accessor function, will have access into the actual object without prior declaration
void Date::printDate(){

	int day = d.printDay();
	int year = y.printYear();

std::cout<< "My date is : "<<std::endl<<"Year : "<<year<<std::endl<<"Day : "<<day<<std::endl;
	
}


int main(void){

	Date testDate(2012, Date::jan, 10);
	testDate.printDate();
	//std::cout<< "My date is : "<<std::endl<<"Year : "<<myDate.y<<std::endl<<"Month : "<<myDate.m<<std::endl<<"Day : "<<myDate.d<<std::endl;
	
	

	return 0;
}