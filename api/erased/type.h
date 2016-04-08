//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Runtime type informations for erased types.
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
struct Type;									//< trait for type erased types
struct TypeList;								//< list of class type traits


//-------------------------------------------------------------------------------------------------
// trait for type erased types
//-------------------------------------------------------------------------------------------------
struct Type
{
	// get type from reference
	template<class T> __inline static const Type* getTypeFromValue(T& t);


	//---------------------------------------------------------------------------------------------
	// returns the class name without any qualifiers.
	const char* getTypeName() const;

	// returns the namespace or the fully qualified name of the surrounding class 
	// when defined inside an other an other class.
	const char* getNamespaceName() const;

	// returns a const char pointer containing a fully qualified list of template arguments.
	// returns NULL if this type is no template type.
	const char* getTemplateParameters() const;


	//---------------------------------------------------------------------------------------------
	// returns the storage size of this type in bytes.
	size_t getStorageSize() const;

	// return the minimum alignment of this type in bytes.
	size_t getAlignment() const;


	//---------------------------------------------------------------------------------------------
	// returns true if this type is declared as const
	bool isConst() const;

	// add const type modifier
	const Type& asConst() const;

	// remove const type modifier
	const Type& asNonConst() const;

	// returns true if this type is declared as volatile
	bool isVolatile() const;

	// add volatile type modifier
	const Type& asVolatile() const;

	// remove volatile type modifier
	const Type& asNonVolatile() const;


	//---------------------------------------------------------------------------------------------
	// returns true if this type is void.
	bool isVoidType() const;

	// returns true if this type is a pointer.
	bool isPointerType() const;

	// returns true if this type is a plain data type - i.e. it needs not construction, destruction
	//    or assignment operators. The type can assigned by easy assigned by memory copy.
	bool isPlainData() const;

	// returns true if this type is primitive.
	bool isPrimitive() const;

	// returns true if this type is a class or struct.
	bool isComplex() const;

	// returns true if this type is a template type.
	bool isTemplateType() const;

	// returns true if this type is a class.
	bool isClass() const;

	// returns true if this type is a struct.
	bool isStruct() const;

	// returns true if this type is abstract.
	bool isAbstract() const;

	// returns true if this type is an enum.
	bool isEnum() const;


	//---------------------------------------------------------------------------------------------
	// only for PointerType's:
	//
	//    returns the resulting type of dereferencing this type as pointer.
	//    returns Type<void> if this Type is no pointer.
	const Type& dereference() const;


	//---------------------------------------------------------------------------------------------
	//    returns the the reference type of this type as pointer.
	//
	const Type& reference() const;


	//---------------------------------------------------------------------------------------------
	// only for classes and structures:
	//
	//    if this type is a class or struct, a list containing all parent classes will be returned.
	//    if this type is primitive, an empty list will be returned.
	// the returned list is in declaration order.
	const BaseList& getParents() const;


	//---------------------------------------------------------------------------------------------
	// only for classes and structures:
	//
	//    - if this type is a class or struct, a list will be return containing all fields declared
	//      by this class. Fields of parent classes are only included when recursive is set.
	//    - if this type is primitive, an empty list will be returned.
	//
	//    - recursive mode: collects also all fields declared inside parent classes. Ambiguous
	//      field's (i.e. two parent classes implement a field with the same name) are not
	//      included in the list.
	//
	//    - the returned list is strictly ordered by field name.
	const FieldList& getFields(bool recursive = false) const;


	//---------------------------------------------------------------------------------------------
	// only for classes and structures:
	//
	//    - if this type is a class or struct, a list will be return containing all static 
	//      variables declared by this class. Fields of parent classes are only included when
	//      recursive is set.
	//    - if this type is primitive, an empty list will be returned.
	//
	//    - recursive mode: collects also all static variables declared inside parent classes.
	//      Ambiguous fields (i.e. two parent classes implement a field with the same name) are
	//      not included in the list.
	//
	//    - the returned list is strictly ordered by field name.
	const StaticVariableList& getStaticVariables(bool recursive = false) const;


	//---------------------------------------------------------------------------------------------
	// only for classes and structures:
	//
	//    - if this type is a class or struct, a list will be return containing all rpc methods
	//      declared by this class. Rpc methods of parent classes are only included when recursive
	//      is set.
	//    - if this type is primitive, an empty list will be returned.
	//
	//    - recursive mode: collects also all rpc methods declared inside parent classes. 
	//      Ambiguous methods (i.e. two parent classes implement a field with the same name) are
	//      not included in the list.
	//
	//    - the returned list is strictly ordered by method name.
	const RpcMethodList& getMethods(bool recursive = false) const;


	//---------------------------------------------------------------------------------------------
	// only for classes and structures:
	//
	//    - if this type is a class or struct, a list will be return containing all static 
	//      rpc methods declared by this class. Static rpc methods of parent classes are only
	//      included when recursive is set.
	//    - if this type is primitive, an empty list will be returned.
	//
	//    - recursive mode: collects also all static rpc methods declared inside parent classes.
	//      Ambiguous methods (i.e. two parent classes implement a method with the same name) are
	//      not included in the list.
	//
	//    - the returned list is strictly ordered by method name.
	const StaticRpcMethodList& getStaticMethods(bool recursive = false) const;


	//---------------------------------------------------------------------------------------------
	// access static known types list
	//
	//    - returns a list of all known types
	//
	//    - the returned list is strictly ordered by fully qualified class name including template 
	//    parameters. 
	static const TypeList& getKnownTypes();


private:

	//---------------------------------------------------------------------------------------------
	// internal data: opaque pointer to type trait && type flags
	const void* opaqueTrait;
};


//-------------------------------------------------------------------------------------------------
// list of erased type traits
//-------------------------------------------------------------------------------------------------
struct TypeList
{
	// get size of type list
	size_t size() const;

	// access type list via iterators
	TypeIterator begin() const;
	TypeIterator end() const;
};


} // namespace Erased
} // namespace































// TODO: mode to private headers
/*
// deduce qualifiers from type
template<class T, bool isConst, bool IsVolatile> class TypeDeducer {
public:
__inline static const Type* getType() { 0; } // return getTypeNonConstNonVolatile<T>(); }
};
template<class T> class TypeDeducer < T, true, false > {
__inline static const Type* getType() { 0; } // return getTypeConstNonVolatile<T>(); }
};
template<class T> class TypeDeducer < T, false, true > {
__inline static const Type* getType() { 0; } // return getTypeNonConstVolatile<T>(); }
};
template<class T> class TypeDeducer < T, true, true > {
__inline static const Type* getType() { 0; } // return getTypeConstVolatile<T>(); }
};


// get type from reference
template<class T> __inline static const Type* getTypeFromValue(T& t)
{
return TypeDeducer<T, std::is_const<T>, std::is_volatile<T> >::getType();
}
*/