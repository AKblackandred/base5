

#include "CSTParser.h"

using namespace std;
using namespace tinyxml2;
using namespace cst;


School* CSTParser::ParseSchool(XMLElement* element) {

	// At the root of the CST tree, ensure element is a <School> element
	if (strcmp(element->Name(), "School") != 0)
		return nullptr;

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory

	// 2. Create School model object
	School* school = new School(name);

	// 3. Look for and iterate through relevant child nodes
	XMLElement* childNode = element->FirstChildElement();

	while (childNode != nullptr) {

		if (string(childNode->Name()).compare("Dean") == 0) {

			Dean* dean = CSTParser::ParseDean(childNode);
			school->setHeadOfSchool(dean);
		}

		// go to next child node
		childNode = childNode->NextSiblingElement();
	}

	// 4. Return School object
	return school;
}

Dean* CSTParser::ParseDean(XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create Dean model object
	Dean* dean = new Dean(name, room ? string(room) : string("F block"));

	// 3. Look for and iterate through relevant child nodes
	XMLElement* childNode = element->FirstChildElement();

	while (childNode != nullptr) {

		if (string(childNode->Name()).compare("Deputy-Dean") == 0) {

			DeputyDean* deputyDean = CSTParser::ParseDeputyDean(childNode);
			dean->setDeputy(deputyDean);
		}
		else if (string(childNode->Name()).compare("ADSE") == 0) {

			ADSE* adse = CSTParser::ParseADSE(childNode);
			dean->setADSE(adse);
		}
		else if (string(childNode->Name()).compare("ADP") == 0) {

			ADP* adp = CSTParser::ParseADP(childNode);
			dean->setADP(adp);
		}
		else if (string(childNode->Name()).compare("ADR") == 0) {

			ADR* adr = CSTParser::ParseADR(childNode);
			dean->setADR(adr);
		}
		else if (string(childNode->Name()).compare("SROM") == 0) {

			SROM* srom = CSTParser::ParseSROM(childNode);
			dean->setSROM(srom);
		}

		// go to next child node
		childNode = childNode->NextSiblingElement();
	}

	// 4. Return Dean object
	return dean;
}

DeputyDean* CSTParser::ParseDeputyDean(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create DeputyDean model object
	DeputyDean* deputyDean = new DeputyDean(name, room ? string(room) : string("F block"));

	// 3. Look for and iterate through relevant child nodes
	XMLElement* childNode = element->FirstChildElement();

	while (childNode != nullptr) {

		if (string(childNode->Name()).compare("Department") == 0) {

			Department* dept = CSTParser::ParseDepartment(childNode);
			deputyDean->addDepartment(dept);
		}

		// go to next child node
		childNode = childNode->NextSiblingElement();
	}

	// 4. Return DeputyDean object
	return deputyDean;
}

Department* CSTParser::ParseDepartment(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory

	// 2. Create Department model object
	Department* dept = new Department(name);

	// 3. Look for and iterate through relevant child nodes
	XMLElement* childNode = element->FirstChildElement();

	while (childNode != nullptr) {

		if (string(childNode->Name()).compare("HoD") == 0) {

			HoD* hod = CSTParser::ParseHoD(childNode);
			dept->setHoD(hod);
		}
		else if (string(childNode->Name()).compare("StaffMember") == 0) {

			StaffMember* staff = CSTParser::ParseStaffMember(childNode);
			dept->addTeamMember(staff);
		}

		// go to next child node
		childNode = childNode->NextSiblingElement();
	}

	// 4. Return Department object
	return dept;
}

HoD* CSTParser::ParseHoD(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create HoD model object
	HoD* hod = new HoD(name, room ? string(room) : string("F block"));

	// 3. Return HoD object
	return hod;
}

StaffMember* CSTParser::ParseStaffMember(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create StaffMember model object
	StaffMember* staff = new StaffMember(name, room ? string(room) : string("F block"));

	// 3. Return StaffMember object
	return staff;
}

ADSE* CSTParser::ParseADSE(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create ADSE model object
	ADSE* adse = new ADSE(name, room ? string(room) : string("F block"));

	// 3. Return ADSE object
	return adse;
}

ADP* CSTParser::ParseADP(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create ADP model object
	ADP* adp = new ADP(name, room ? string(room) : string("F block"));

	// 3. Return ADP object
	return adp;
}

ADR* CSTParser::ParseADR(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create ADR model object
	ADR* adr = new ADR(name, room ? string(room) : string("F block"));

	// 3. Return ADR object
	return adr;
}

SROM* CSTParser::ParseSROM(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create SROM model object
	SROM* srom = new SROM(name, room ? string(room) : string("F block"));

	// 3. Return SROM object
	return srom;
}

// Alternative for common element structures...
template <class T>
T* CSTParser::ParsePerson(tinyxml2::XMLElement* element) {

	// 1. Get attributes
	string name(element->Attribute("name")); // mandatory
	const char* room = element->Attribute("room"); // optional

	// 2. Create and return model object from given xml element
	T* obj = new T(name, room ? string(room) : string("F block"));

	// 3. Return model object
	return obj;
}
