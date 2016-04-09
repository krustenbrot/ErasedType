//-------------------------------------------------------------------------------------------------
//
//   project:               dstd::Erased - An erased type and runtime reflection frame work.
//   author:                Julian Dessecker
//
//   description:           Basic iterator implementation
//
//-------------------------------------------------------------------------------------------------
// @@LICENSE TEXT@@


#include <iterator>


namespace dstd {
namespace Erased {


//-------------------------------------------------------------------------------------------------
// basic const iterator class
//-------------------------------------------------------------------------------------------------
template <class DataT> 
struct ConstIterator 
: public std::iterator < std::random_access_iterator_tag, ConstIterator<DataT> >
{
    // constructor for iterator
    ConstIterator(const DataT* ptr) : ref(ptr) {}

    // own iterator type
    typedef ConstIterator<DataT> IteratorT;

    // access value
    __inline const DataT& operator*() const { return *ref; }
    __inline const DataT* operator->() const { return ref; }

    // increment / decrement / offset functions
    __inline IteratorT& operator++() { ref++; return *this; }
    __inline IteratorT operator++(int) { IteratorT t(ref); ref++; return t; }
    __inline IteratorT& operator--() { ref--; return *this; }
    __inline IteratorT operator--(int) { IteratorT t(ref); ref--; return t; }

    // add / sub operators
    __inline IteratorT operator+(off_t i) const { return IteratorT(&(ref[i])); }
    __inline IteratorT operator-(off_t i) const { return IteratorT(&(ref[-i])); }

    // comparison operators
    __inline bool operator == (const IteratorT& o) const { return ref == o.ref; }
    __inline bool operator != (const IteratorT& o) const { return ref != o.ref; }
    __inline bool operator < (const IteratorT& o) const { return ref < o.ref; }
    __inline bool operator <= (const IteratorT& o) const { return ref <= o.ref; }
    __inline bool operator > (const IteratorT& o) const { return ref > o.ref; }
    __inline bool operator >= (const IteratorT& o) const { return ref >= o.ref; }

    // calculate distance to other iterator (returns other - this;
    //    i.e. begin().distance(end) will return the lists size)
    __inline off_t distance(const IteratorT& other) const
    {
        off_t dist = ((off_t)other.ref) - ((off_t)ref);
        return dist / sizeof(DataT);
    }

private:
    const DataT* ref;
};


} // namespace Erased
} // namespace