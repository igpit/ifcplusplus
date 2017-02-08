/* -*-c++-*- IfcPlusPlus - www.ifcquery.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "ifcpp/model/IfcPPGlobal.h"

// TYPE IfcLaborResourceTypeEnum = ENUMERATION OF	(ADMINISTRATION	,CARPENTRY	,CLEANING	,CONCRETE	,DRYWALL	,ELECTRIC	,FINISHING	,FLOORING	,GENERAL	,HVAC	,LANDSCAPING	,MASONRY	,PAINTING	,PAVING	,PLUMBING	,ROOFING	,SITEGRADING	,STEELWORK	,SURVEYING	,USERDEFINED	,NOTDEFINED);
class IFCPP_EXPORT IfcLaborResourceTypeEnum : virtual public IfcPPObject
{
public:
	enum IfcLaborResourceTypeEnumEnum
	{
		ENUM_ADMINISTRATION,
		ENUM_CARPENTRY,
		ENUM_CLEANING,
		ENUM_CONCRETE,
		ENUM_DRYWALL,
		ENUM_ELECTRIC,
		ENUM_FINISHING,
		ENUM_FLOORING,
		ENUM_GENERAL,
		ENUM_HVAC,
		ENUM_LANDSCAPING,
		ENUM_MASONRY,
		ENUM_PAINTING,
		ENUM_PAVING,
		ENUM_PLUMBING,
		ENUM_ROOFING,
		ENUM_SITEGRADING,
		ENUM_STEELWORK,
		ENUM_SURVEYING,
		ENUM_USERDEFINED,
		ENUM_NOTDEFINED
	};

	IfcLaborResourceTypeEnum();
	IfcLaborResourceTypeEnum( IfcLaborResourceTypeEnumEnum e ) { m_enum = e; }
	~IfcLaborResourceTypeEnum();
	virtual const char* className() const { return "IfcLaborResourceTypeEnum"; }
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	static shared_ptr<IfcLaborResourceTypeEnum> createObjectFromSTEP( const std::wstring& arg );
	IfcLaborResourceTypeEnumEnum m_enum;
};

