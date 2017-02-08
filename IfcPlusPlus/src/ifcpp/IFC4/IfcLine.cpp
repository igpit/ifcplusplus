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

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcLine.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

// ENTITY IfcLine 
IfcLine::IfcLine() { m_entity_enum = IFCLINE; }
IfcLine::IfcLine( int id ) { m_id = id; m_entity_enum = IFCLINE; }
IfcLine::~IfcLine() {}
shared_ptr<IfcPPObject> IfcLine::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcLine> copy_self( new IfcLine() );
	if( m_Pnt ) { copy_self->m_Pnt = dynamic_pointer_cast<IfcCartesianPoint>( m_Pnt->getDeepCopy(options) ); }
	if( m_Dir ) { copy_self->m_Dir = dynamic_pointer_cast<IfcVector>( m_Dir->getDeepCopy(options) ); }
	return copy_self;
}
void IfcLine::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCLINE" << "(";
	if( m_Pnt ) { stream << "#" << m_Pnt->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_Dir ) { stream << "#" << m_Dir->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcLine::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcLine::readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 2 ){ std::stringstream err; err << "Wrong parameter count for entity IfcLine, expecting 2, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReference( args[0], m_Pnt, map );
	readEntityReference( args[1], m_Dir, map );
}
void IfcLine::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcCurve::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "Pnt", m_Pnt ) );
	vec_attributes.push_back( std::make_pair( "Dir", m_Dir ) );
}
void IfcLine::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcCurve::getAttributesInverse( vec_attributes_inverse );
}
void IfcLine::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcCurve::setInverseCounterparts( ptr_self_entity );
}
void IfcLine::unlinkFromInverseCounterparts()
{
	IfcCurve::unlinkFromInverseCounterparts();
}
