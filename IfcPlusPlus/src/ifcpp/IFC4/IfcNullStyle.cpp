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
#include "include/IfcPresentationStyleSelect.h"
#include "include/IfcNullStyle.h"

// TYPE IfcNullStyle = ENUMERATION OF	(NULL);
IfcNullStyle::IfcNullStyle() {}
IfcNullStyle::~IfcNullStyle() {}
shared_ptr<IfcPPObject> IfcNullStyle::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcNullStyle> copy_self( new IfcNullStyle() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcNullStyle::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCNULLSTYLE("; }
	if( m_enum == ENUM_ENUM_NULL )
	{
		stream << ".ENUM_NULL.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcNullStyle> IfcNullStyle::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcNullStyle>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcNullStyle>(); }
	shared_ptr<IfcNullStyle> type_object( new IfcNullStyle() );
	if( boost::iequals( arg, L".ENUM_NULL." ) )
	{
		type_object->m_enum = IfcNullStyle::ENUM_ENUM_NULL;
	}
	return type_object;
}
