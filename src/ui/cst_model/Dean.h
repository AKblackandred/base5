#pragma once

#include "DeputyDean.h"
#include "ADSE.h"
#include "ADP.h"
#include "ADR.h"
#include "SROM.h"

namespace cst {

	class Dean : public StaffMember {

		DeputyDean* deputy = nullptr;
		ADSE* adse = nullptr;
		ADP* adp = nullptr;
		ADR* adr = nullptr;
		SROM* srom = nullptr;

	public:

		Dean(std::string name, std::string room) : StaffMember(name, room) {}

		// Deputy-Dean
		void setDeputy(DeputyDean* newDeputy) { deputy = newDeputy; }
		DeputyDean* getDeputy() { return deputy; }

		// ADSE
		void setADSE(ADSE* adse) { this->adse = adse; }
		ADSE* getADSE() { return adse; }

		// ADP
		void setADP(ADP* adp) { this->adp = adp; }
		ADP* getADP() { return adp; }

		// ADR
		void setADR(ADR* adr) { this->adr = adr; }
		ADR* getADR() { return adr; }

		// SROM
		void setSROM(SROM* srom) { this->srom = srom; }
		SROM* getSROM() { return srom; }

	};

}
