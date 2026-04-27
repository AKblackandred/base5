#pragma once

#include <string>
#include "StaffMember.h"

namespace cst {

	class ADP : public StaffMember {

	public:

		ADP(std::string name, std::string room) : StaffMember(name, room) {
		}
	};

}
