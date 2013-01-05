// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#pragma once

class MetaData;

class VariantBase
{
public:
  const MetaData *Meta( void ) const;

  template <typename T>
  T& GetValue( void );
  void *Data( void ) const;
  template <typename T>
  const T& GetValue( void ) const;
  void Serialize( std::ostream& os ) const;

protected:
  VariantBase( );
  VariantBase( const MetaData* meta, void* data );
  const MetaData *meta;
  void *data;
};

template <typename T>
T& VariantBase::GetValue( void )
{
  return *reinterpret_cast<T *>(data);
}

template <typename T>
const T& VariantBase::GetValue( void ) const
{
  return *reinterpret_cast<T *>(data);
}
