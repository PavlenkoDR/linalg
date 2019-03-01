#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

class Vector : public Matrix
{
public:
    Vector();
    Vector( const std::initializer_list<double>& vec );
    Vector( const Vector& vec );
    Vector( const Matrix& mat );
    Vector( const size_t& n );

    Vector operator+( const Vector& vec );
    Vector operator-( const Vector& vec );
    Vector operator*( const Vector& vec );
    Vector operator*( const double& val );
private:
    Vector( const std::initializer_list<std::initializer_list<double> >& mat ){}
    Vector( const size_t& n, const size_t& m ){}
};

#endif // VECTOR_H
