//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Reflected field entries for erased class and struct types
//
//-------------------------------------------------------------------------------------------------
// @@LICENSE TEXT@@


#ifndef __ERASED_TYPE_INCLUDE_GUARD__
#	include "../erasedtype.h"	//< this include is only for supporting the indexer.
#	error do not include this file directly, include erasedtype.h instead.
#endif


namespace dstd {
namespace Erased {


//-------------------------------------------------------------------------------------------------
// forward declarations
//-------------------------------------------------------------------------------------------------
struct Field;								//< field entry of type erased class
struct FieldList;							//< field entry list of type erased class
struct StaticVariable;						//< static variable entry of type erased class
struct StaticVariableList;					//< static variable entry list of type erased class

	
//-------------------------------------------------------------------------------------------------
// field entry of type erased class
//-------------------------------------------------------------------------------------------------
struct Field
{
	// returns the type trait of this field
	const Type& getType() const;

	// get access modifier for this field
	Access getAccess() const;
	
	// returns the byte offset of this field
	off_t getBaseOffset() const;
};


//-------------------------------------------------------------------------------------------------
// field entry list of type erased class
//-------------------------------------------------------------------------------------------------
struct FieldList
{
	// get size of field list
	size_t size() const;

	// access field list via iterators
	FieldIterator begin() const;
	FieldIterator end() const;
};


//-------------------------------------------------------------------------------------------------
// static variable entry of type erased class
//-------------------------------------------------------------------------------------------------
struct StaticVariable
{
	// returns the type trait of this static variable
	const Type& getType() const;

	// get access modifier for this static variable
	Access getAccess() const;

	// returns the opaque pointer to this static variable
	void* getPointer() const;
};


//-------------------------------------------------------------------------------------------------
// static variable entry list of type erased class
//-------------------------------------------------------------------------------------------------
struct StaticVariableList
{
	// get size of static variable list
	size_t size() const;

	// access static variable list via iterators
	StaticVariableIterator begin() const;
	StaticVariableIterator end() const;
};


} // namespace Erased
} // namespace