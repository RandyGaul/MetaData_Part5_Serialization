// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#pragma once

class Object
{
public:
  Object( int id );
  ~Object( );

  META_DATA( Object );

private:
  int ID;
  bool active;
  double x;
};
