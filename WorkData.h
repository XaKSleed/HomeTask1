#pragma once
#include <string>

class WorkData {

public:
    WorkData(long long nNumberTo, long long nNumberFrom, std::string nOwnerId, int nRegionCode, int nMNC);

    friend class MNP;

private:

	long long m_NumberTo = 0;
	long long m_NumberFrom = 0;
	std::string m_OwnerId;
	int m_RegionCode = 0;
	int m_MNC = 0;


};