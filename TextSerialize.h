// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#pragma once

void Padding( std::ostream& os );
void TextSerialize( std::ostream& os, RefVariant var );

template <typename T>
void TextSerializePrim( std::ostream& os, RefVariant prim )
{
  Padding( os );
  os << prim.GetValue<RemQual<T>::type>( ) << std::endl;
}