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
#include "include/IfcIndexedPolygonalFace.h"
#include "include/IfcPolygonalFaceSet.h"
#include "include/IfcPositiveInteger.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

// ENTITY IfcIndexedPolygonalFace 
IfcIndexedPolygonalFace::IfcIndexedPolygonalFace() { m_entity_enum = IFCINDEXEDPOLYGONALFACE; }
IfcIndexedPolygonalFace::IfcIndexedPolygonalFace( int id ) { m_id = id; m_entity_enum = IFCINDEXEDPOLYGONALFACE; }
IfcIndexedPolygonalFace::~IfcIndexedPolygonalFace() {}
shared_ptr<IfcPPObject> IfcIndexedPolygonalFace::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcIndexedPolygonalFace> copy_self( new IfcIndexedPolygonalFace() );
	for( size_t ii=0; ii<m_CoordIndex.size(); ++ii )
	{
		auto item_ii = m_CoordIndex[ii];
		if( item_ii )
		{
			copy_self->m_CoordIndex.push_back( dynamic_pointer_cast<IfcPositiveInteger>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcIndexedPolygonalFace::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCINDEXEDPOLYGONALFACE" << "(";
	stream << "(";
	for( size_t ii = 0; ii < m_CoordIndex.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcPositiveInteger>& type_object = m_CoordIndex[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, false );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ");";
}
void IfcIndexedPolygonalFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcIndexedPolygonalFace::readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcIndexedPolygonalFace, expecting 1, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readSelectList( args[0], m_CoordIndex, map );
}
void IfcIndexedPolygonalFace::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcTessellatedItem::getAttributes( vec_attributes );
	if( m_CoordIndex.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> CoordIndex_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_CoordIndex.begin(), m_CoordIndex.end(), std::back_inserter( CoordIndex_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "CoordIndex", CoordIndex_vec_object ) );
	}
}
void IfcIndexedPolygonalFace::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcTessellatedItem::getAttributesInverse( vec_attributes_inverse );
	if( m_ToFaceSet_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> ToFaceSet_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_ToFaceSet_inverse.size(); ++i )
		{
			if( !m_ToFaceSet_inverse[i].expired() )
			{
				ToFaceSet_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcPolygonalFaceSet>( m_ToFaceSet_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "ToFaceSet_inverse", ToFaceSet_inverse_vec_obj ) );
	}
}
void IfcIndexedPolygonalFace::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcTessellatedItem::setInverseCounterparts( ptr_self_entity );
}
void IfcIndexedPolygonalFace::unlinkFromInverseCounterparts()
{
	IfcTessellatedItem::unlinkFromInverseCounterparts();
}
