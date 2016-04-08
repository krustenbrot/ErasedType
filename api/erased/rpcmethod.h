//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Reflected rpc method entries for erased class and struct types
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
struct RpcMethod;							//< rpc method declaration
struct RpcMethodList;						//< rpc method entry list of type erased class
struct StaticRpcMethod;						//< static rpc method declaration
struct StaticRpcMethodList;					//< static rpc method entry list of type erased class

	
//-------------------------------------------------------------------------------------------------
// rpc method declaration
//-------------------------------------------------------------------------------------------------
struct RpcMethod
{
	// returns the type trait of this field
	const Type& getType() const;

	// get access modifier for this field
	Access getAccess() const;
	
	// returns the byte offset of this field
	off_t getBaseOffset() const;
};


//-------------------------------------------------------------------------------------------------
// rpc method entry list of type erased class
//-------------------------------------------------------------------------------------------------
struct RpcMethodList
{
	// get size of field list
	size_t size() const;

	// access field list via iterators
	RpcMethodIterator begin() const;
	RpcMethodIterator end() const;
};


//-------------------------------------------------------------------------------------------------
// static rpc method declaration
//-------------------------------------------------------------------------------------------------
struct StaticRpcMethod
{
	// returns the type trait of this rpc method's return type
	const Type& getReturnType() const;

	// returns the type trait of this rpc method's parameter type
	const Type& getParameterType() const;

	// get access modifier for this rpc method
	Access getAccess() const;

	// returns the member function pointer for this rpc function
	void* getFunctionPtr() const;
};


//-------------------------------------------------------------------------------------------------
// static rpc method entry list of type erased class
//-------------------------------------------------------------------------------------------------
struct StaticRpcMethodList
{
	// get size of rpc method list
	size_t size() const;

	// access rpc method list via iterators
	StaticRpcMethodIterator begin() const;
	StaticRpcMethodIterator end() const;
};


} // namespace Erased
} // namespace