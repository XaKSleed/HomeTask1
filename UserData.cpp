
#include "UserData.h"

UserData::UserData(std::string nOwnerId, int nRegionCode, int nMNC) {
	m_OwnerId = nOwnerId;
	m_RegionCode = nRegionCode;
	m_MNC = nMNC;
}

std::ostream& operator << (std::ostream& out, const UserData& data) {

	out << "OwnerId: " << data.m_OwnerId << '\n';
	out << "RegionCode: " << data.m_RegionCode << '\n';
	out << "MNC: " << data.m_MNC << '\n';

	return out;
}