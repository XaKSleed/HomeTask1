#include "MNP.h"
#include "UserData.h"

using namespace std;

int main()
{
	try {

		MNP check;
		check.readCSV();

		string number;
		cout << "Please input your number: " << endl;
		cin >> number;

		if ((number.length() < 10) || (number.length() > 10)) {

			throw "wrong number size";

		}

		for (char i : number) {
			if (!isdigit(i)) {
				throw "the string contains forbidden characters";
			}
		}

		UserData result = check.findNumber(number);
		cout << result << endl;
		
	}
	catch (const char* exception) {
		cerr << "Error main(): " << exception << " " << '\n';
		return 0;
	}
	return 0;
}
