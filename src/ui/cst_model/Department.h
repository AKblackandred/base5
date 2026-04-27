#pragma once

#include <vector>
#include <string>
#include "StaffMember.h"
#include "HoD.h"

namespace cst {

	class Department {

		std::string name;
		HoD* headOfDepartment = nullptr;
		std::vector<StaffMember*> team;

	public:

		Department(std::string name) {
		
			this->name = name;
		}

		std::string getName() {

			return name;
		}

		void setHoD(HoD* headOfDepartment) {

			this->headOfDepartment = headOfDepartment;
		}

		HoD* getHoD() {

			return headOfDepartment;
		}

		int teamSize() {

			return team.size();
		}

		void addTeamMember(StaffMember* teamMember) {

			team.push_back(teamMember);
		}

		StaffMember* getTeamMember(int i) {

			return team[i];
		}
	};

}
