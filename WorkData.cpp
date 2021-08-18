
#include "WorkData.h"


WorkData::WorkData(long long nNumberFrom, long long nNumberTo, std::string nOwnerId, int nRegionCode, int nMNC) {
	m_NumberFrom = nNumberFrom;
	m_NumberTo = nNumberTo;
	m_OwnerId = nOwnerId;
	m_RegionCode = nRegionCode;
	m_MNC = nMNC;
}

