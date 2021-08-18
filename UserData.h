#pragma once

#include <string>
#include <iostream>

class UserData {


public:

    UserData(std::string nOwnerId, int nRegionCode, int nMNC);

    friend std::ostream& operator << (std::ostream& out, const UserData& data);


	private:

	    std::string m_OwnerId;
		int m_RegionCode = 0;
		int m_MNC = 0;


};


