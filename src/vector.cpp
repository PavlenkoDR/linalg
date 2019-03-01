#include "Vector.h"
#include <cassert>

Vector::Vector()
{
    Resize( 0, 0 );
}

Vector::Vector( const std::initializer_list<double>& vec )
{
    Set( { vec } );
}

Vector::Vector( const Vector& vec )
{
    Set( vec );
}

Vector::Vector( const size_t& n )
{
    Resize( n, 1 );
}

Vector::Vector( const Matrix& mat ) :
    Matrix( mat )
{
}

Vector Vector::operator+( const Vector& vec )
{
    return Matrix::operator+( vec );
}

Vector Vector::operator-( const Vector& vec )
{
    return Matrix::operator-( vec );
}

Vector Vector::operator*( const double& val )
{
    return Matrix::operator*( val );
}

Vector Vector::operator*( const Vector& vec )
{
    if( matSize.width == vec.GetSize().width )
    {
        Vector tmp( vec );
        const size_t matLen = vec.GetSize().width;
        for ( size_t i = 0; i < matLen; ++i )
        {
            m_log << "operator*: " << tmp[i] << " * " << m_mat[i] << "\n";
            tmp[i] *= m_mat[i];
        }
        return tmp;
    }
    else
    {
        assert( matSize.width == vec.GetSize().height );
        Vector tmp( 1 );
        const size_t matLen = matSize.width;
        for ( size_t i = 0; i < matLen; ++i )
        {
            m_log << "operator*: += " << m_mat[i] << " * " << vec[i] << "\n";
            tmp[0] += m_mat[i]*vec[i];
        }
        return tmp;
    }
}
