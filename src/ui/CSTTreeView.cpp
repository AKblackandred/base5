
#include "CSTTreeView.h"

using namespace std;
using namespace cst;

// Build tree - here we exploit knowledge of our object graph to build the tree
void CSTTreeView::buildTree(School* school, wxTreeCtrl* treeView) {

	// Start by adding root (the School object)
	wxTreeItemId schoolNode = treeView->AddRoot(school->getName());

	// Get Dean of school
	Dean* dean = school->getHeadOfSchool();

	if (dean) {

		// Setup Dean node nested within the School
		wxTreeItemId deanNode = treeView->AppendItem(schoolNode, wxString("Dean: ") + dean->getName());

		// Let's get the staff the Dean is responsible for

		//
		// Deputy-Dean
		//
		DeputyDean* deputyDean = dean->getDeputy();

		if (deputyDean) {

			// Setup Deputy-Dean node
			wxTreeItemId deputyNode = treeView->AppendItem(deanNode, wxString("Deputy-Dean: ") + deputyDean->getName());

			// Loop through departments
			for (int deptIndex = 0; deptIndex < deputyDean->numberOfDepartments(); deptIndex++) {

				Department* dept = deputyDean->getDepartmentAtIndex(deptIndex);

				// Setup department node
				wxTreeItemId deptNode = treeView->AppendItem(deputyNode, wxString("Department: ") + dept->getName());

				// Get HoD
				HoD* hod = dept->getHoD();

				if (hod) {

					treeView->AppendItem(deptNode, wxString("HoD: ") + hod->getName());
				}

				// Loop through staff in department
				for (int staffIndex = 0; staffIndex < dept->teamSize(); staffIndex++) {

					StaffMember* staff = dept->getTeamMember(staffIndex);
					if (staff) {

						treeView->AppendItem(deptNode, staff->getName() + wxString("; Located at ") + staff->getRoom());
					}
				}
			}
		}

		//
		// ADSE
		//
		ADSE* adse = dean->getADSE();

		if (adse) {

			// Setup ADSE node.  Don't bother keeping returned node id since we're not 
			// nesting anything withing the ADSE
			treeView->AppendItem(deanNode, wxString("ADSE: ") + adse->getName());
		}

		//
		// ADP
		//
		ADP* adp = dean->getADP();

		if (adp) {

			// Setup ADP node.  Don't bother keeping returned node id since we're not 
			// nesting anything withing the ADP
			treeView->AppendItem(deanNode, wxString("ADP: ") + adp->getName());
		}

		//
		// ADR
		//
		ADR* adr = dean->getADR();

		if (adr) {

			// Setup ADR node.  Don't bother keeping returned node id since we're not 
			// nesting anything withing the ADR
			treeView->AppendItem(deanNode, wxString("ADR: ") + adr->getName());
		}

		//
		// SROM
		//
		SROM* srom = dean->getSROM();

		if (srom) {

			// Setup SROM node.  Don't bother keeping returned node id since we're not 
			// nesting anything withing the SROM
			treeView->AppendItem(deanNode, wxString("SROM: ") + srom->getName());
		}
	}
	
}