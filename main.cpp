#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
struct NOTE
{
    std::string name; // ФИО
    std::string tele; // телефон
    std::chrono::year_month_day birthday; //день рождения
};
int main() {
	std::string s;
	int size_q = 1; 
    std::ifstream fin("notes.txt"); //Предполагается, что такого файла нет
 
    if (!fin.is_open()) 
        std::cout << "Файл не может быть открыт!\n";
    else
    {
        std::string date_time_format = "%Y.%m.%d";
        std::getline(fin, s); 
        size_q = stoi(s);
		NOTE notes[size_q];
        std::cout << size_q << std::endl; 
		int i = 0;
		while(i < size_q && !fin.eof()) {
			std::getline(fin, notes[i].name);
			std::getline(fin, notes[i].tele);

  			std::chrono::year_month_day	date;
			std::getline(fin, s);
			std::istringstream ss{s };
    		ss >> std::chrono::parse(date_time_format, date);
			notes[i].birthday = date;

    		if (!ss) {
     			std::cout << "You are stupid, check your date format" << std::endl;
    		}
		}
		fin.close();
    }
    return 0;

}

