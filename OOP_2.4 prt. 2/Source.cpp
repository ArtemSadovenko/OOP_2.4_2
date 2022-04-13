#include "DailySchedule.h"

int main() {
	DailySchedule a;
	cin >> a;
	cout << a;
	int k;
	a.show_free();
	cout << "Would you like to append new task?\nYes(1)\nNo(2)"; cin >> k;
	if (k == 1) {
		a.append();
		cout << a;
	}
	cout << "Would you like to delete task?\nYes(1)\nNo(2)"; cin >> k;
	if (k == 1) {
		cout << "Which of them?"; cin >> k;
		a.del(k);
		cout << a;
	}
	cout << "Which of them you`ve done?"; cin >> k;
	a.i_done(k);

	cout << "You have to do:\n";
	a.display();
}