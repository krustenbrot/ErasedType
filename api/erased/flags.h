//-------------------------------------------------------------------------------------------------
//
//   project:				dstd::Erased - An erased type and runtime reflection frame work.
//   author:				Julian Dessecker
//
//   description:			Global flags for Types, Fields, Rpc methods and Enumerations
//
//-------------------------------------------------------------------------------------------------
// @@LICENSE TEXT@@


namespace dstd {
namespace Erased {


//-------------------------------------------------------------------------------------------------
// Flags for controlling serialization, deserialization, remote procedure calls
//-------------------------------------------------------------------------------------------------
enum Flags {

	// type flags
	kIsVoid = (1 << 0),				// type flag: this type is 'void'
	kIsPointer = (2 << 0),			// type flag: this type is a pointer
	kIsComplex = (3 << 0),			// type flag: this type is defined as class or struct
	kIsClass = (4 << 0),			// type flag: this type is defined as class
	kIsStruct = (5 << 0),			// type flag: this type is defined as struct
	kIsPrimitive = (6 << 0),		// type flag: this type is primitive (bool, char, number-types)
	kIsInteger = (7 << 0),			// type flag: integer number type (char, signed, unsigned, ...)
	kIsSigned = (8 << 0),			// type flag: integer signed number type (char, int8_t, ...)
	kIsFloat = (9 << 0),			// type flag: floating point number (float, double)
	kIsString = (10 << 0),			// type flag: type is dstd::String 
	kIsEnum = (11 << 0),			// type flag: this type is a reflectable enum
	kIsAbstract = (12 << 0),		// type flag: class / struct has abstract methods
	kIsConst = (13 << 0),			// type flag: class / struct has abstract methods
	kIsVolatile = (14 << 0),		// type flag: class / struct has abstract methods

	// serializer flags (2 bits)
	kDontSerialize = (16 << 0),		//!< annotation of class / structure / field:
									//     on classes / structs : class can not be serialized
									//     on fields : no serializing of this field.
	kSerializeOnly = (16 << 1),		//!< annotation of class / structure / field:
									//     on classes / structs : class can not be deserialized
									//     on fields : serialize but don't deserialize field.
	kDeserializeOnly = (16 << 2),	//!< annotation of class / structure / field:
									//     on classes / structs : class can not be serialized
									//     on fields : don't serialize but deserialize field.
	kSerialize = (16 << 3),			//!< annotation of class / structure / field:
									//     on classes / structs : allow (de-) serialization
									//     on fields : serialize / deserialize field.
	k_MaskSerializer = (16 << 3),	//!< mask for serializer flags
	k_SerializerBitShhift = 16		//!< bit shift offset for serializer flags

	// TODO:
	/*
	kNoInitCreate			// trivial create, no init
	kTrivialCreate			// trivial create, init with default value
	kTrivialDestroy			// no destructor call needed
	kTrivialCopy			// can copy via memcpy
	*/
	// member flags
};


} // namespace Erased
} // namespace