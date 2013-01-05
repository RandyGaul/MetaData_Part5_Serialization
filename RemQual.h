// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#pragma once

// Used to check if a type is a pointer or not
template<typename T>
struct isPointer       { static const bool value = false; };
template<typename T>
struct isPointer<T *>  { static const bool value = true;  };
template<typename T>
struct isPointer<T&>   { static const bool value = false; };

//
// RemQual
// Strips down qualified types/references/pointers to a single unqualified type, for passing into
// a templated type as a typename parameter.
//
 
template <typename T>
struct RemQual
{
  typedef T type;
};
 
template <typename T>
struct RemQual<const T>
{
  typedef typename RemQual<T>::type type;
};
 
template <typename T>
struct RemQual<T&>
{
  typedef typename RemQual<T>::type type;
};
 
template <typename T>
struct RemQual<const T&>
{
  typedef typename RemQual<T>::type type;
};
 
template <typename T>
struct RemQual<T&&>
{
  typedef typename RemQual<T>::type type;
};
 
template <typename T>
struct RemQual<const T *>
{
  typedef typename RemQual<T *>::type type;
};
