//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Reflected base class entries for erased class and struct types
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
struct Base;								//< base class entry of type erased class
struct BaseList;							//< base class entry list of type erased class
	
	
//-------------------------------------------------------------------------------------------------
// base class entry of type erased class
//-------------------------------------------------------------------------------------------------
struct Base
{
	// returns the type trait of this base class
	const Type& getType() const;

	// get access modifier for this base class
	Access getAccess() const;
	
	// returns the byte offset of this base class relative to it's parent
	off_t getBaseOffset() const;
};


//-------------------------------------------------------------------------------------------------
// base class entry list of type erased class
//-------------------------------------------------------------------------------------------------
struct BaseList
{
	// get size of parent list
	size_t size() const;

	// access parent list via iterators
	BaseIterator begin() const;
	BaseIterator end() const;
};


} // namespace Erased
} // namespace
