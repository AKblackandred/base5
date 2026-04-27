#pragma once

#include <string>
#include "StaffMember.h"

namespace cst {

	class ADSE : public StaffMember {

	public:

		ADSE(std::string name, std::string room) : StaffMember(name, room) {
		}
	};

}
