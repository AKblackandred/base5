#pragma once

#include <string>
#include "Dean.h"

namespace cst {

	class School {

		std::string name;
		Dean* headOfSchool = nullptr;

	public:

		School(std::string name, Dean* headOfSchool = nullptr) {

			this->name = name;
			this->headOfSchool = headOfSchool;
		}

		void setHeadOfSchool(Dean* newDean) {

			headOfSchool = newDean;
		}

		std::string getName() {

			return name;
		}

		Dean* getHeadOfSchool() {

			return headOfSchool;
		}
	};
}
