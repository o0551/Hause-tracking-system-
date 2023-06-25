#include <iostream>
#include <fstream>
#include<sstream>
#include <string.h>

using namespace std;


struct Recurring
{
    int fuel = 0;
    int houserent = 0;
};

struct Tracker
{
    int expenses = 0;
    int income = 0;
    Recurring R;
    int save = 0;
    int lose = 0;
    int id = 0;
    int startMonth;
    int numMonth;
};

long long result, reminder;
bool check;
int index;
int count_of_month = 0;
Tracker* p1 = new Tracker[100];


void writefile();
void readfile();
void edit();
void display();
void Add();
void deleteData();
void addrange();
void list_recurring();
void list_income();


int main() {

    int i = 0;
    readfile();
    while (i < 100)
    {


        cout << "Press a specific number to operate with:\n" << "1- Add\n" << "2- edit\n" << "3- Delete\n" << "4- Display\n" << "5- add range \n"
            << "6- list recurring \n" << "7 - list of income \n " << "8- Exit\n" << endl;
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add();
            break;
        case 2:
            edit();
            break;
        case 3:
            deleteData();
            break;
        case 4:
            display();
            break;
        case 5:
            addrange();
            break;
        case 6:
            list_recurring();
            break;
        case 7:
            list_income();
            break;
        case 8:
            writefile();
            exit(0);
            break;
        default:
            exit(0);
            break;
        }

    }
}

void writefile()
{
    fstream myFile("track.csv", ios::out);


    for (int i = 1; i <= count_of_month; i++)
    {
        myFile << p1[i].id << ',' << p1[i].income << ',' << p1[i].expenses << ',' << p1[i].save
            << ',' << p1[i].lose << ',' << p1[i].startMonth << ',' << p1[i].R.fuel << ',' << p1[i].R.houserent << endl;
    }

    myFile.close();
}
void readfile()
{

    fstream fin;
    fin.open("track.csv", ios::in);
    if (!fin.is_open())
    {
        ofstream of;
        of.open("track.csv");
        fin.open("track.csv", ios::in);
    }
    string line, number;
    while (!fin.eof())
    {
        getline(fin, line);

        stringstream s(line);

        int counter = 0;

        while (getline(s, number, ','))
        {
            counter++;
            switch (counter)
            {
            case 1:
                count_of_month++;
                p1[count_of_month].id = stoi(number);
                break;
            case 2:
                p1[count_of_month].income = stoi(number);
                break;
            case 3:
                p1[count_of_month].expenses = stoi(number);
                break;
            case 4:
                p1[count_of_month].save = stoi(number);
                break;
            case 5:
                p1[count_of_month].lose = stoi(number);
                break;
            case 6:
                p1[count_of_month].startMonth = stoi(number);
                break;
            case 7:
                p1[count_of_month].R.fuel = stoi(number);
                break;
            case 8:
                p1[count_of_month].R.houserent = stoi(number);
                break;
            }
        }

    }


}
void list_recurring()
{
    cout << "All list of recurring : \n";
    for (int i = 1; i <= count_of_month; i++)
    {
        cout << "the id :  " << p1[i].id << "   > >   " << "recurring : fuel  " << p1[i].R.fuel
            << "   house rent  " << p1[i].R.houserent << endl;
    }
}

void list_income()
{
    cout << "All list of income : \n";
    for (int i = 1; i <= count_of_month; i++)
    {
        cout << "the id :  " << p1[i].id << "   > >   " << "income  " << p1[i].income << endl;
    }
}
void addrange()
{
    int startmon = 0, endmon = 0;
    int in, out;
    cout << "Enter the range of months for Track this range : \n ";
    cout << "Enter the start month :   \n";
    cin >> startmon;

    cout << "Enter the end month :   \n";
    cin >> endmon;

    for (int i = startmon; i <= endmon; i++)
    {
        cout << "The track for month " << startmon << endl;
        for (int j = 1; j <= count_of_month; j++)
        {
            if (startmon == p1[j].startMonth)
            {
                cout << "income  :   " << p1[j].income << endl;
                cout << "outcome :   " << p1[j].expenses + p1[j].R.fuel + p1[j].R.houserent << endl;
                startmon++;
                break;
            }
        }
    }


}

void Add()
{
    count_of_month++;

    p1[count_of_month].id = p1[count_of_month - 1].id + 1;

    cout << "enter the income\n";
    cin >> p1[count_of_month].income;


    cout << "enter the expenses\n";
    cin >> p1[count_of_month].expenses;

    cout << "enter the recurring costs" << endl << "frist the fuel::";
    cin >> p1[count_of_month].R.fuel;

    cout << endl << "the house rent::";
    cin >> p1[count_of_month].R.houserent;

    cout << "Enter Start month: " << endl;
    cin >> p1[count_of_month].startMonth;

    result = p1[count_of_month].expenses + p1[count_of_month].R.fuel + p1[count_of_month].R.houserent;
    reminder = p1[count_of_month].income - result;

    if (reminder > 0)
    {
        p1[count_of_month].save = reminder;
        cout << " \n Money are saved \n";
    }
    else
    {
        p1[count_of_month].lose = reminder * -1;
        cout << "\n money are lost\n ";
    }

}

void deleteData()
{
    int  newvalue = 0;
    int value = 1;
    cout << " 1 ---Delete monthe  \n 2--- Delete specific value  \n";
    cin >> value;
    int id;
    cout << "Enter ID that you want to delete :   ";
    cin >> id;
    if (value == 1)
    {
        for (int i = 1; i <= count_of_month; i++)
        {
            if (p1[i].id == id)
                id = i;
        }
        for (int i = id; i <= count_of_month; i++)
        {
            p1[i] = p1[i + 1];
        }
        count_of_month--;
    }
    else if (value == 2)
    {
        for (int i = 1; i <= count_of_month; i++)
        {
            if (p1[i].id == id)
            {
                int choose = 1;
                cout << "1-Expenses \n 2-Income\n 3-Car Fuel\n 4-House Rent \n ";
                cin >> choose;

                if (choose == 1)
                    p1[i].expenses = 0;
                else if (choose == 2)
                    p1[i].income = 0;
                else if (choose == 3)
                    p1[i].R.fuel = 0;
                else if (choose == 4)
                    p1[i].R.houserent = 0;
            }
        }
    }



}










void display()
{
    if (count_of_month != 0)
        cout << "The all months : " << endl;
    for (int i = 1; i <= count_of_month; i++)
    {
        cout << "id : " << p1[i].id << endl;
        cout << "income : " << p1[i].income << endl;
        cout << "outcome : \n ";
        cout << "expenses :  " << p1[i].expenses << endl;
        cout << "house rent : " << p1[i].R.houserent << endl;
        cout << "fuel : " << p1[i].R.fuel << endl;
        cout << "lose : " << p1[i].lose << endl;
        cout << "save : " << p1[i].save << endl;
        cout << "Start month : " << p1[i].startMonth << endl;
        cout << "--------------------------------------------------------------\n";
    }
}
void edit()
{

    int type;
    int id;
    int dummy;
    cout << "which kind value do u want to edit" << endl;
    cout << "1-Expenses \n 2-Income\n 3-Car Fuel\n 4-House Rent";
    cin >> type;
    cout << "Enter the ID u want to edit" << endl;
    cin >> id;
    int ind = 0;
    for (int i = 1; i <= count_of_month; i++)
    {
        if (p1[i].id == id)
        {
            cout << "Enter the new value";
            cin >> dummy;
            ind = i;
            break;
        }
    }
    switch (type)
    {
    case 1:
        p1[ind].expenses = dummy;
        break;
    case 2:
        p1[ind].income = dummy;
        break;
    case 3:
        p1[ind].R.fuel = dummy;
        break;
    case 4:
        p1[ind].R.houserent = dummy;
        break;

    }
}