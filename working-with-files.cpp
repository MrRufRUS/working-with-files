// working-with-files.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
struct note
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
    else {
        std::getline(fin, s);
        size_q = stoi(s);
        note* notes = new note[size_q];
        std::string date_buff;
        std::cout << "Count of notes: " << size_q << std::endl;
        int i = 0;
        while (i < size_q && !fin.eof()) {
            std::getline(fin, notes[i].name);
            std::getline(fin, notes[i].tele);

            std::getline(fin, date_buff);

            if (date_buff[4] != '.' && date_buff[7] != '.') {
                std::cout << "You are stupid, check your date format" << std::endl;
            }
            else {
                int y, m, d;
                y = (date_buff[0] - '0') * 1000 + (date_buff[1] - '0') * 100 + (date_buff[2] - '0') * 10 +
                    (date_buff[3] - '0');
                m = (date_buff[5] - '0') * 10 + (date_buff[6] - '0');
                d = (date_buff[8] - '0') * 10 + (date_buff[9] - '0');
                notes[i].birthday = { std::chrono::year(y), std::chrono::month(m), std::chrono::day(d) };
            }

            i++;
        }
        fin.close();

        std::cout << "Notes: " << std::endl;
        for (int i = 0; i < size_q; i++)
            std::cout << i + 1 << ". " << notes[i].name << ' ' << notes[i].tele << ' ' << (unsigned)notes[i].birthday.day() << '.' << (unsigned)notes[i].birthday.month()<< '.' << (int)notes[i].birthday.year() << std::endl;

        std::chrono::month month_search;
        int m_s;
        bool flag = false;
        while (!flag) {
            std::cout << "Enter number of month: ";
            std::cin >> m_s;
            month_search = std::chrono::month(m_s);
            for (int i = 0; i < size_q; i++) {
                if (notes[i].birthday.month() == month_search) {
                    std::cout << i + 1 << ". " << notes[i].name << ' ' << notes[i].tele << ' ' << (unsigned)notes[i].birthday.day() << '.' << (unsigned)notes[i].birthday.month() << '.' << (int)notes[i].birthday.year() << std::endl;
                    flag = true;
                }
            }
            if (!flag)
                std::cout << "ReEnter your month" << std::endl;
        }
        delete[] notes;
    }
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
