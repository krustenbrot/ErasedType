//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Include file for erased types.
//
//-------------------------------------------------------------------------------------------------
// @@LICENSE TEXT@@


#pragma once


#include "erased/access.h"
#include "erased/iterator.h"
#include "erased/flags.h"


namespace dstd {
namespace Erased {


//-------------------------------------------------------------------------------------------------
// Types
//-------------------------------------------------------------------------------------------------

//------------------------------------------------------------
// trait for type erased classes
// @see Type in "class.h"
//------------------------------------------------------------
struct Type;

//------------------------------------------------------------
// list of erased type traits
//    valid for C++11 range based loops
// @see TypeList in "class.h"
//------------------------------------------------------------
struct TypeList;

//------------------------------------------------------------
// iterator for erased type traits
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < Type > TypeIterator;



//-------------------------------------------------------------------------------------------------
// Base classes
//-------------------------------------------------------------------------------------------------

//------------------------------------------------------------
// base class entry of type erased class
// @see Base in "base.h"
//------------------------------------------------------------
struct Base;

//------------------------------------------------------------
// base class entry list of type erased class
//    valid for C++11 range based loops
// @see BaseList in "base.h"
//------------------------------------------------------------
struct BaseList;

//------------------------------------------------------------
// base class entry list iterator
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < Base > BaseIterator;



//-------------------------------------------------------------------------------------------------
// Fields
//-------------------------------------------------------------------------------------------------

//------------------------------------------------------------
// field entry of type erased class
// @see Field in "field.h"
//------------------------------------------------------------
struct Field;

//------------------------------------------------------------
// field entry list of type erased class
//    valid for C++11 range based loops
// @see FieldList in "field.h"
//------------------------------------------------------------
struct FieldList;

//------------------------------------------------------------
// field entry list iterator
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < Field > FieldIterator;

//------------------------------------------------------------
// static variable entry of type erased class
// @see StaticVariable in "field.h"
//------------------------------------------------------------
struct StaticVariable;

//------------------------------------------------------------
// static variable entry list of type erased class
//    valid for C++11 range based loops
// @see StaticVariableList in "field.h"
//------------------------------------------------------------
struct StaticVariableList;

//------------------------------------------------------------
// static field entry list iterator
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < StaticVariable > StaticVariableIterator;



//-------------------------------------------------------------------------------------------------
// RPC Methods
//-------------------------------------------------------------------------------------------------

//------------------------------------------------------------
// RPC method entry of type erased class
// @see RpcMethod in "rpcmethod.h"
//------------------------------------------------------------
struct RpcMethod;

//------------------------------------------------------------
// RPC method entry list of type erased class
//    valid for C++11 range based loops
// @see RpcMethodList in "rpcmethod.h"
//------------------------------------------------------------
struct RpcMethodList;

//------------------------------------------------------------
// RPC method entry list iterator
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < RpcMethod > RpcMethodIterator;

//------------------------------------------------------------
// static RPC method entry of type erased class
// @see StaticRpcMethod in "rpcmethod.h"
//------------------------------------------------------------
struct StaticRpcMethod;

//------------------------------------------------------------
// static RPC method entry list of type erased class
//    valid for C++11 range based loops
// @see StaticRpcMethodList in "rpcmethod.h"
//------------------------------------------------------------
struct StaticRpcMethodList;

//------------------------------------------------------------
// static RPC method entry list iterator
//    compatible to std::iterator< std::random_access_iterator_tag >
//------------------------------------------------------------
typedef ConstIterator < StaticRpcMethod > StaticRpcMethodIterator;


} // namespace Erased
} // namespace dstd


//-------------------------------------------------------------------------------------------------
// include erased type structures
//-------------------------------------------------------------------------------------------------
#define __ERASED_TYPE_INCLUDE_GUARD__
#include "erased/type.h"
#include "erased/base.h"
#include "erased/field.h"
#include "erased/rpcmethod.h"
#undef __ERASED_TYPE_INCLUDE_GUARD__
