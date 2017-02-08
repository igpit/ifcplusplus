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
#include "include/IfcWallTypeEnum.h"

// TYPE IfcWallTypeEnum = ENUMERATION OF	(MOVABLE	,PARAPET	,PARTITIONING	,PLUMBINGWALL	,SHEAR	,SOLIDWALL	,STANDARD	,POLYGONAL	,ELEMENTEDWALL	,USERDEFINED	,NOTDEFINED);
IfcWallTypeEnum::IfcWallTypeEnum() {}
IfcWallTypeEnum::~IfcWallTypeEnum() {}
shared_ptr<IfcPPObject> IfcWallTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcWallTypeEnum> copy_self( new IfcWallTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcWallTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCWALLTYPEENUM("; }
	if( m_enum == ENUM_MOVABLE )
	{
		stream << ".MOVABLE.";
	}
	else if( m_enum == ENUM_PARAPET )
	{
		stream << ".PARAPET.";
	}
	else if( m_enum == ENUM_PARTITIONING )
	{
		stream << ".PARTITIONING.";
	}
	else if( m_enum == ENUM_PLUMBINGWALL )
	{
		stream << ".PLUMBINGWALL.";
	}
	else if( m_enum == ENUM_SHEAR )
	{
		stream << ".SHEAR.";
	}
	else if( m_enum == ENUM_SOLIDWALL )
	{
		stream << ".SOLIDWALL.";
	}
	else if( m_enum == ENUM_STANDARD )
	{
		stream << ".STANDARD.";
	}
	else if( m_enum == ENUM_POLYGONAL )
	{
		stream << ".POLYGONAL.";
	}
	else if( m_enum == ENUM_ELEMENTEDWALL )
	{
		stream << ".ELEMENTEDWALL.";
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
shared_ptr<IfcWallTypeEnum> IfcWallTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcWallTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcWallTypeEnum>(); }
	shared_ptr<IfcWallTypeEnum> type_object( new IfcWallTypeEnum() );
	if( boost::iequals( arg, L".MOVABLE." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_MOVABLE;
	}
	else if( boost::iequals( arg, L".PARAPET." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_PARAPET;
	}
	else if( boost::iequals( arg, L".PARTITIONING." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_PARTITIONING;
	}
	else if( boost::iequals( arg, L".PLUMBINGWALL." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_PLUMBINGWALL;
	}
	else if( boost::iequals( arg, L".SHEAR." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_SHEAR;
	}
	else if( boost::iequals( arg, L".SOLIDWALL." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_SOLIDWALL;
	}
	else if( boost::iequals( arg, L".STANDARD." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_STANDARD;
	}
	else if( boost::iequals( arg, L".POLYGONAL." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_POLYGONAL;
	}
	else if( boost::iequals( arg, L".ELEMENTEDWALL." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_ELEMENTEDWALL;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcWallTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
