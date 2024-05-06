#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
private:
    char name[80];
    short course;
    short mark;

public:
    void getData(int& first, int& second, int& third, int& four)
    {
        cout << "Введите ФИО: ";
        cin.getline(name, sizeof(name));

        cout << "Введите курс: ";
        cin >> course;
        cin.get();
        cout << "Введите средний балл: ";
        cin >> mark;
        cin.get();

        if (course == 1 && mark < 4)
            first++;

        if (course == 2 && mark < 4)
            second++;

        if (course == 3 && mark < 4)
            third++;

        if (course == 4 && mark < 4)
            four++;
    }

    void showData()
    {
        cout << "ФИО: " << name << endl;
        cout << "Курс: " << course << endl;
        cout << "Средний балл: " << mark << endl;
        cout << endl;
    }

    void input(Student& person, fstream& stud, char& ch)
    {
        int first = 0, second = 0, third = 0, four = 0;
        do {
            cout << "Введите данные о студенте:" << endl << endl;
            person.getData(first, second, third, four);
            stud << person.name << endl;
            stud << person.course << endl;
            stud << person.mark << endl;
            stud.flush();
            cout << "Продолжить ли ввод?(y/n):";
            cin >> ch;
            cin.get();
        } while (ch == 'y');

        cout << "Студенты имеющие неудовлетворительные отметки по курсу:" << endl;
        cout << "Введите курс:";
        cin >> course;
        if (course == 1) {
            cout << "Кол-во неуспевающих на 1 курсе:";
            cout << first;
        }
        if (course == 2) {
            cout << "Кол-во неуспевающих на 2 курсе:";
            cout << second;
        }
        if (course == 3) {
            cout << "Кол-во неуспевающих на 3 курсе:";
            cout << third;
        }
        if (course == 4) {
            cout << "Кол-во неуспевающих на 4 курсе:";
            cout << four;
        }
        cout << endl;

    }

    void output(Student& person, fstream& stud)
    {
        cout << endl;
        cout << "Список введеных студентов:";
        cout << endl;
        while (!stud.eof())
        {
            cout << "Person:" << endl;
            person.showData();
            stud >> person.name >> person.course >> person.mark;
        }
    }

    void first(Student& person, fstream& stud)
    {
        stud >> person.name >> person.course >> person.mark;
    }
};

int main()
{
    int course;
    short mark;
    char ch;
    Student person;
    setlocale(LC_ALL, "RU");
    fstream stud;
    stud.open("students.txt", ios::in | ios::out | ios::app);
    while (!stud.is_open())
    {
        cout << "Ошибка 1";
        return 1;
    }

    person.input(person, stud, ch);

    stud.seekg(0);
    person.first(person, stud);
    person.output(person, stud);

    stud.close();

    return 0;
}