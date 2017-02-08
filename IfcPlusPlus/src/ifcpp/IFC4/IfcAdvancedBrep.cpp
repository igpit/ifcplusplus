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
#include "include/IfcAdvancedBrep.h"
#include "include/IfcClosedShell.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

// ENTITY IfcAdvancedBrep 
IfcAdvancedBrep::IfcAdvancedBrep() { m_entity_enum = IFCADVANCEDBREP; }
IfcAdvancedBrep::IfcAdvancedBrep( int id ) { m_id = id; m_entity_enum = IFCADVANCEDBREP; }
IfcAdvancedBrep::~IfcAdvancedBrep() {}
shared_ptr<IfcPPObject> IfcAdvancedBrep::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcAdvancedBrep> copy_self( new IfcAdvancedBrep() );
	if( m_Outer ) { copy_self->m_Outer = dynamic_pointer_cast<IfcClosedShell>( m_Outer->getDeepCopy(options) ); }
	return copy_self;
}
void IfcAdvancedBrep::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCADVANCEDBREP" << "(";
	if( m_Outer ) { stream << "#" << m_Outer->m_id; } else { stream << "*"; }
	stream << ");";
}
void IfcAdvancedBrep::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcAdvancedBrep::readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcAdvancedBrep, expecting 1, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReference( args[0], m_Outer, map );
}
void IfcAdvancedBrep::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcManifoldSolidBrep::getAttributes( vec_attributes );
}
void IfcAdvancedBrep::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcManifoldSolidBrep::getAttributesInverse( vec_attributes_inverse );
}
void IfcAdvancedBrep::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcManifoldSolidBrep::setInverseCounterparts( ptr_self_entity );
}
void IfcAdvancedBrep::unlinkFromInverseCounterparts()
{
	IfcManifoldSolidBrep::unlinkFromInverseCounterparts();
}
