#pragma once

#include <string>
#include "StaffMember.h"

namespace cst {

	class SROM : public StaffMember {

	public:

		SROM(std::string name, std::string room) : StaffMember(name, room) {
		}
	};

}
