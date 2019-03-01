#include "matrix.h"
#include <cassert>
#include <iostream>


std::stringstream Matrix::m_log;

Matrix::Matrix()
{
    matSize.width = 0;
    matSize.height = 0;
}

Matrix::Matrix( const std::initializer_list<std::initializer_list<double> >& mat ) :
    Matrix()
{
    Set( mat );
    m_log << "Matrix(list<list<>>): " << *this << "\n";
}

Matrix::Matrix( const Matrix& mat ) :
    Matrix()
{
    Set( mat );
    m_log << "Matrix(Matrix): " << *this << "\n";
}

Matrix::Matrix( const size_t& n, const size_t& m ) :
    Matrix()
{
    Resize( n, m );
}

Matrix::~Matrix()
{
}

double& Matrix::Get( const size_t& n, const size_t& m )
{
    return m_mat[n * matSize.width + m];
}

void Matrix::Resize( const size_t& n, const size_t& m )
{
    m_log << "Resize( " << n << ", " << m << " )" << "\n";
    matSize.width = n;
    matSize.height = m;
    m_mat.resize( matSize.width * matSize.height, 0 );
}

const Size& Matrix::GetSize() const
{
    return matSize;
}

bool Matrix::ValidateRowSize( const size_t& width ) const
{
    m_log << "ValidateRowSize( ";
    m_log << "ValidateRowSize( " << width << " ) ?= " << matSize.width << "\n";
    return matSize.width == width;
}

void Matrix::Set( const std::initializer_list<std::initializer_list<double> >& mat )
{
    Resize( ( mat.size() > 0 ) ? mat.begin()->size() : 0, mat.size() );
    size_t idx = 0;
    for ( const auto& row : mat )
    {
        assert( ValidateRowSize( row.size() ) );
        for ( const auto& item : row )
        {
            m_log << "Set: push " << item << "\n";
            m_mat[idx] = item;
            ++idx;
        }
    }
}

void Matrix::Set( const Matrix& mat )
{
    Resize( mat.GetSize().width, mat.GetSize().height );
    std::copy( mat.m_mat.begin(), mat.m_mat.end(), m_mat.begin() );
}

Matrix Matrix::T() const
{
    Matrix result( matSize.height, matSize.width );
    for ( size_t i = 0; i < matSize.height; ++i )
    {
        for ( size_t j = 0; j < matSize.width; ++j )
        {
            result[j * matSize.height + i] = m_mat[i * matSize.width + j];
        }
    }
    return result;
}

Matrix Matrix::operator+( const Matrix& mat )
{
    assert( ( matSize.height == mat.GetSize().height ) &&
            ( matSize.width == mat.GetSize().width ) );
    Matrix tmp( mat );
    const size_t matLen = matSize.width * mat.GetSize().height;
    for ( size_t i = 0; i < matLen; ++i )
    {
        m_log << "operator+: " << tmp[i] << " + " << m_mat[i] << "\n";
        tmp[i] += m_mat[i];
    }
    return tmp;
}

Matrix Matrix::operator-( const Matrix& mat )
{
    assert( ( matSize.height == mat.GetSize().height ) &&
            ( matSize.width == mat.GetSize().width ) );
    Matrix tmp( mat );
    const size_t matLen = matSize.width * mat.GetSize().height;
    for ( size_t i = 0; i < matLen; ++i )
    {
        m_log << "operator-: " << m_mat[i] << " - " << tmp[i] << "\n";
        tmp[i] = m_mat[i] - tmp[i];
    }
    return tmp;
}

Matrix Matrix::operator*( const Matrix& mat )
{
    assert( mat.GetSize().width == matSize.height );
    Matrix result( mat.GetSize().width, matSize.height );
    for ( size_t i = 0; i < matSize.height; ++i )
    {
        for ( size_t j = 0; j < mat.GetSize().width; ++j )
        {
            for ( size_t k = 0; k < matSize.width; ++k )
            {
                m_log << "operator*: " << m_mat[i * matSize.width + k] << " * " << mat[k * mat.GetSize().width + j] << "\n";
                result[i * mat.GetSize().width + j] += m_mat[i * matSize.width + k] * mat[k * mat.GetSize().width + j];
            }
            m_log << "operator*: sum " << result[i * mat.GetSize().width + j] << "\n";
        }
    }

    return result;
}

Matrix Matrix::operator*( const double& val )
{
    Matrix tmp( matSize.width, matSize.height );
    const size_t matLen = matSize.width * matSize.height;
    for ( size_t i = 0; i < matLen; ++i )
    {
        m_log << "operator+: " << tmp[i] << " + " << m_mat[i] << "\n";
        tmp[i] = m_mat[i] * val;
    }
    return tmp;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
    for ( size_t i = 0; i < mat.GetSize().height; ++i )
    {
        for ( size_t j = 0; j < mat.GetSize().width; ++j )
        {
            out << mat[i * mat.GetSize().width + j] << " ";
        }
        out << "\n";
    }
    return out;
}

double& Matrix::operator[]( const size_t& n )
{
    return m_mat[n];
}

const double& Matrix::operator[]( const size_t& n ) const
{
    return m_mat[n];
}

const std::string Matrix::LogGet()
{
    return m_log.str();
}

void Matrix::LogReset()
{
    m_log.str("");
}
