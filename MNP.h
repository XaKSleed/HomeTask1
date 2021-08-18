
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "WorkData.h"
#include "UserData.h"


class MNP {

public:
    bool readCSV();
    UserData findNumber(const std::string& number);

private:
	std::vector<std::vector<std::string>> m_dataTable;
	std::vector<long long> m_numberList;
	std::vector<WorkData> m_dataset;

	static std::vector<std::string> findNumberInPortAll(long long number);
	static long long strToInt(const std::string& str);




	


};
