#pragma once

#include <tinyxml2.h>
#include <cst_model/StaffMember.h>
#include <cst_model/HoD.h>
#include <cst_model/Department.h>
#include <cst_model/DeputyDean.h>
#include <cst_model/School.h>

// Declare model classes
class cst::School;
class cst::Dean;
class cst::DeputyDean;

class CSTParser {

public:
	static cst::School* ParseSchool(tinyxml2::XMLElement* element);
	static cst::Dean* ParseDean(tinyxml2::XMLElement* element);
	static cst::DeputyDean* ParseDeputyDean(tinyxml2::XMLElement* element);

	static cst::Department* ParseDepartment(tinyxml2::XMLElement* element);

	static cst::HoD* ParseHoD(tinyxml2::XMLElement* element);
	static cst::StaffMember* ParseStaffMember(tinyxml2::XMLElement* element);

	static cst::ADSE* ParseADSE(tinyxml2::XMLElement* element);
	static cst::ADP* ParseADP(tinyxml2::XMLElement* element);
	static cst::ADR* ParseADR(tinyxml2::XMLElement* element);
	static cst::SROM* ParseSROM(tinyxml2::XMLElement* element);

	template <class T>
	static T* ParsePerson(tinyxml2::XMLElement* element);
};