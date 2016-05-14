#include <iostream>
using namespace std;

int max_common_divider(int n, int m);
void enter_num(int & n, char * name);


void main() {
	int n, m;

	enter_num(n, "n");
	enter_num(m, "m");

	cout << "Min common divider of numbers "
		<< n << " and " << m << ": " 
		<< max_common_divider(n, m) << endl;
}

void enter_num(int & n, char * name){
	cout << "Enter number " << name << ": ";
	cin >> n;

	while (cin.fail() || n <= 0) {
		cout << "Enter proper number!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
}

int max_common_divider(int n, int m){
	if (m == 0)
		return n;
	
	if (n % 2 == 0 && m % 2 == 0)
		return 2 * max_common_divider(n / 2, m / 2);
	else if (n % 2 == 0 && m % 2 != 0)
		return max_common_divider(n / 2, m);
	else if (n % 2 != 0 && m % 2 == 0)
		return max_common_divider(n, m / 2);
	else
		return max_common_divider(m, abs(n - m));
}