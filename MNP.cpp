
#include "MNP.h"
#include "UserData.h"
#include "WorkData.h"
#include <sstream>
#include <cstdlib>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

using namespace std;

bool MNP::readCSV() {
	try {

		string filename;
		cout << "Please enter the path to the file .csv : " << endl;
		cin >> filename;

		ifstream file (filename);

		if (!file) {

			throw "invalid filename";

		}

		string str;
		bool flag = false;
		short counter = 0;
		vector<string> tmp(6);

		while (getline(file, str)) {

			stringstream ss(str);

			if (flag) {
				m_dataTable.emplace_back();

				while (ss.good()) {
					string substr;
					getline(ss, substr, ',');
					if (counter == 0) {
						m_numberList.push_back(strToInt(substr));
					}
					tmp[counter] = substr;
					counter++;
				}

				counter = 0;

				long long numberFrom = strToInt(tmp[0]);
				long long numberTo = strToInt(tmp[1]);
				string ownerId = tmp[2];
				int region = stoi(tmp[3]);
				int mnc = stoi(tmp[4]);
				WorkData w1(numberTo, numberFrom, ownerId, region, mnc);
				m_dataset.push_back(w1);
			}
			flag = true;
		}
	}
	catch (const char* exception) {
		cerr << "Error readCSV(): " << exception << " "  << '\n';
	}

	return true;
}

UserData MNP::findNumber(const string& number) {

    long long inputNumber = strToInt(number);
    vector<string> portAllResult = findNumberInPortAll(inputNumber);

    if(!portAllResult.empty()){
        UserData result (portAllResult[1], stoi(portAllResult[4]), stoi(portAllResult[2]));
        return result;
    }

    auto lower = std::lower_bound(m_numberList.begin(), m_numberList.end(), inputNumber);
    auto index = lower - m_numberList.begin() - 1;

    UserData result(m_dataset[index].m_OwnerId, m_dataset[index].m_RegionCode, m_dataset[index].m_MNC);

    return result;
}

 vector<string> MNP::findNumberInPortAll(long long number) {

    vector<string> values;

    try{

        string filename;
        cout << "Please enter the path to the file Port_all.csv : " << endl;
        cin >> filename;
        int fd = open(filename.c_str(), O_RDONLY, 0);

        if(fd < 0){
            throw "invalid filename";
        }

        struct stat st{};
        fstat(fd, &st);
        auto fsize = (size_t)st.st_size;
        auto* dataPtr = (unsigned char*) mmap(nullptr, fsize, PROT_READ, MAP_PRIVATE, fd, 0);

        const char *begin = (const char*) dataPtr;
        const char *end = begin + fsize;
        const char *now = begin;
        bool flag = false;

        for(begin; now <= end; now++ ){
            if(*now == '\r'){

                string rowValues(begin, now);
                stringstream  ss(rowValues);
                string substr;
                if(flag){
                    while(ss.good()){
                        getline(ss, substr, ',');
                        values.push_back(substr);
                    }
                    long long numberFrom = strToInt(values[0]);
                    if(numberFrom == number){
                        return values;
                    }
                    values.clear();
                }
                flag = true;
                begin = now + 2;
                now++;
            }

        }
        return values;
    }

    catch (const char* exception) {
        cerr << "Error readCSV(): " << exception << " "  << '\n';
    }

    return values;
}

long long MNP::strToInt(const string& str) {

	const char* c = str.c_str();
	char* end;
	int base = 10;
	long long num = strtoll(c, &end, base);
	return num;

}
