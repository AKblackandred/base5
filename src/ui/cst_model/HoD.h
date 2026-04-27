#pragma once

#include <string>
#include <cst_model/StaffMember.h>

namespace cst {

	class HoD : public StaffMember {

	public:

		HoD(std::string name, std::string room) : StaffMember(name, room) {
		}
	};

}
