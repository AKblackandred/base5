#pragma once

#include <string>

namespace cst {

	class StaffMember {

		std::string		name;
		std::string		room;

	public:

		StaffMember(std::string name, std::string room) {

			this->name = name;
			this->room = room;
		}

		std::string getName() {

			return name;
		}

		std::string getRoom() {

			return room;
		}
	};

}
