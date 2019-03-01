#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>

struct Size
{
    size_t width;
    size_t height;
};

class Matrix
{
public:
    Matrix();
    Matrix( const std::initializer_list<std::initializer_list<double> >& mat );
    Matrix( const Matrix& mat );
    Matrix( const size_t& n, const size_t& m );
    ~Matrix();

    double& Get( const size_t& n, const size_t& m );
    void Set( const std::initializer_list<std::initializer_list<double> >& mat );
    void Set( const Matrix& mat );
    void Resize( const size_t& n, const size_t& m );
    const Size& GetSize() const;
    Matrix T() const;

    static const std::string LogGet();
    static void LogReset();

    Matrix operator+( const Matrix& mat );
    Matrix operator-( const Matrix& mat );
    Matrix operator*( const Matrix& mat );
    Matrix operator*( const double& val );

    friend std::ostream& operator<<( std::ostream& out, const Matrix& mat );
protected:
    bool ValidateRowSize( const size_t& width ) const;

    double& operator[]( const size_t& n );
    const double& operator[]( const size_t& n ) const;

    Size matSize;
    std::vector<double> m_mat;
    static std::stringstream m_log;
};

std::ostream& operator<<(std::ostream& out, const Matrix& mat);

#endif // MATRIX_H
