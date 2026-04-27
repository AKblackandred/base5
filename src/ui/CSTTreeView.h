#pragma once

// Build wxWidgets tree view from loaded model

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <cst_model/StaffMember.h>
#include <cst_model/HoD.h>
#include <cst_model/Department.h>
#include <cst_model/DeputyDean.h>
#include <cst_model/School.h>

class CSTTreeView {

public:

	static void buildTree(cst::School* school, wxTreeCtrl* treeView);

};