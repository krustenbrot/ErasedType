//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Access modifiers for types, fields and methods
//
//-------------------------------------------------------------------------------------------------
// @@LICENSE TEXT@@


namespace dstd {
namespace Erased {


//-------------------------------------------------------------------------------------------------
// access modifiers for base classes, fields and methods
//-------------------------------------------------------------------------------------------------
enum Access {
	kPrivate = 0,
	kProtected,
	kPublic
};


} // namespace Erased
} // namespace