#include "DailySchedule.h"

ostream& operator<<(ostream& out, DailySchedule& a)
{
    for (int i = 0; i < a.n; i++) {
        out << "To do " << i + 1 << ":\n";
        out << "Name: " << a.item[i].name << endl;
        out << "Do: " << a.item[i].toDo << endl;
        out << "Start time: " << a.item[i].start << endl;
        out << "Finish time: " << a.item[i].finish << endl;
        if (a.item[i].isDone == 1) {
            out << "Done\n";
        }
        else {
            out << "Not done\n";
        }
        out << endl;
    }
    return out;
    // TODO: вставьте здесь оператор return
}

istream& operator>>(istream& in, DailySchedule& a)
{
    cout << "Enter amount "; in >> a.n;
    a.create();
    for (int i = 0; i < a.n; i++) {
        cout << "To do " << i + 1 << ":\n";
        cout << "Name: "; in >> a.item[i].name;// cout << endl;
        cout << "Do: "; in >> a.item[i].toDo;
        cout << "Start time: "; in >> a.item[i].start;
        cout << "Finish time: "; in >> a.item[i].finish;
        cout << endl;
    }
    if (a.check()) {
        cerr << "Error";
        exit(1);
    }
    return in;
    // TODO: вставьте здесь оператор return
}

void DailySchedule::create()
{
    item = new DaylyItem[n];
    done = new bool[n];
}

void DailySchedule::display()
{
    for (int i = 0; i < n; i++) {
        if (item[i].isDone != 1) {
            cout << "To do " << i + 1 << ":\n";
            cout << "Name: " << item[i].name << endl;
            cout << "Do: " << item[i].toDo << endl;
            cout << "Start time: " << item[i].start << endl;
            cout << "Finish time: " << item[i].finish << endl;
            cout << endl;
        }
    }
}

DailySchedule::DailySchedule()
{
    n = 1;
    create();
    done[0] = 0;
}

DailySchedule::DailySchedule(DaylyItem* it, bool* d, int m)
{
    n = m;
    create();
    for (int i = 0; i < n; i++) {
        item[i].name = it[i].name;
        item[i].isDone = it[i].isDone;
        item[i].finish = it[i].finish;
        item[i].start = it[i].start;
        item[i].toDo= it[i].toDo;
        done[i] = d[i];
    }
}

DailySchedule::DailySchedule(DailySchedule& a)
{
    n = a.n;
    create();
    for (int i = 0; i < n; i++) {
        item[i].name = a.item[i].name;
        item[i].isDone = a.item[i].isDone;
        item[i].finish = a.item[i].finish;
        item[i].start = a.item[i].start;
        item[i].toDo = a.item[i].toDo;
        done[i] = a.done[i];
    }
}

DailySchedule::~DailySchedule()
{
    delete[] item;
    delete[] done;
}

DailySchedule& DailySchedule::operator=(DailySchedule& a)
{
    n = a.n;
    create();
    for (int i = 0; i < n; i++) {
        item[i].name = a.item[i].name;
        item[i].isDone = a.item[i].isDone;
        item[i].finish = a.item[i].finish;
        item[i].start = a.item[i].start;
        item[i].toDo = a.item[i].toDo;
        done[i] = a.done[i];
    }
    return *this;
    // TODO: вставьте здесь оператор return
}

bool DailySchedule::check()
{
    if (n == 1) {
        return false;
    }
    for (int i = 0; i < n-1; i++) {
        if (item[i].start == item[i].finish || !(item[i].finish > item[i + 1].start)) {
            return false;
        }
    }
    return true;
}

bool DailySchedule::check_2()
{
    for (int i = 0; i < n - 1; i++) {
        if ((item[n].start > item[i].start && item[n].start < item[i].finish) || 
            (item[n].finish > item[i].start && item[n].finish < item[i].finish)) {
            return false;
        }
    }
    return true;
}

void DailySchedule::append()
{
    DaylyItem* p = new DaylyItem[n + 1];
    for (int i = 0; i < n; i++) {
        p[i].name = item[i].name;
        p[i].finish = item[i].finish;
        p[i].isDone = item[i].isDone;
        p[i].start = item[i].start;
        p[i].toDo = item[i].toDo;
    }
    cout << "To do " << ":\n";
    cout << "Name: "; cin >> p[n].name;// cout << endl;
    cout << "Do: "; cin >> p[n].toDo;
    cout << "Start time: "; cin >> p[n].start;
    cout << "Finish time: "; cin >> p[n].finish;
    cout << endl;
    if (!check_2()) {
        cerr << "Error";
        exit(1);
    }
    item = new DaylyItem[n + 1];
    
    for (int i = 0; i < n+1 ; i++) {
        //item[i]= p[i] ;
        item[i].name = p[i].name;
        item[i].finish = p[i].finish;
        item[i].isDone = p[i].isDone;
        item[i].start = p[i].start;
        item[i].toDo = p[i].toDo;
    }
    n += 1;
}

void DailySchedule::del(int i)
{
    for (int j = i - 1; j < n-1; j++) {
        item[j] = item[j + 1];
    }
    n -= 1;
}



void DailySchedule::show_free()
{
    cout << "You have free time:\n";
    for (int i = 0; i < n-1; i++) {
        cout << "from " << item[i].finish << " to " << item[i + 1].start << endl;
    }
    cout << "from " << item[n-1].finish << " to " << item[0].start << endl;
    cout << "Huh. You have time to sleep. Pathetic....\n";
}

void DailySchedule::i_done(int i)
{
    item[i-1].isDone = true;
}
