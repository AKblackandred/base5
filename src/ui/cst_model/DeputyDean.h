#pragma once

#include <string>
#include "Department.h"

namespace cst {

	class DeputyDean : public StaffMember {

		std::vector<Department*> departments;

	public:

		DeputyDean(std::string name, std::string room) : StaffMember(name, room) {
		}

		void addDepartment(Department* newDepartment) {

			departments.push_back(newDepartment);
		}

		int numberOfDepartments() {

			return departments.size();
		}

		Department* getDepartmentAtIndex(int i) {

			if (i >= 0 && i < departments.size())
				return departments[i];
			else
				return nullptr;
		}
	};

}
