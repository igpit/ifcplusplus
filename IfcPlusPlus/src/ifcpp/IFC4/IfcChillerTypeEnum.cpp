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

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcChillerTypeEnum.h"

// TYPE IfcChillerTypeEnum = ENUMERATION OF	(AIRCOOLED	,WATERCOOLED	,HEATRECOVERY	,USERDEFINED	,NOTDEFINED);
IfcChillerTypeEnum::IfcChillerTypeEnum() {}
IfcChillerTypeEnum::~IfcChillerTypeEnum() {}
shared_ptr<IfcPPObject> IfcChillerTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcChillerTypeEnum> copy_self( new IfcChillerTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcChillerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCCHILLERTYPEENUM("; }
	if( m_enum == ENUM_AIRCOOLED )
	{
		stream << ".AIRCOOLED.";
	}
	else if( m_enum == ENUM_WATERCOOLED )
	{
		stream << ".WATERCOOLED.";
	}
	else if( m_enum == ENUM_HEATRECOVERY )
	{
		stream << ".HEATRECOVERY.";
	}
	else if( m_enum == ENUM_USERDEFINED )
	{
		stream << ".USERDEFINED.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcChillerTypeEnum> IfcChillerTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
	shared_ptr<IfcChillerTypeEnum> type_object( new IfcChillerTypeEnum() );
	if( boost::iequals( arg, L".AIRCOOLED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_AIRCOOLED;
	}
	else if( boost::iequals( arg, L".WATERCOOLED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_WATERCOOLED;
	}
	else if( boost::iequals( arg, L".HEATRECOVERY." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_HEATRECOVERY;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcChillerTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
