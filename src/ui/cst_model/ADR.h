#pragma once

#include <string>
#include "StaffMember.h"

namespace cst {

	class ADR : public StaffMember {

	public:

		ADR(std::string name, std::string room) : StaffMember(name, room) {
		}
	};

}
