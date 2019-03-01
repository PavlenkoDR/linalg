#include <iostream>
#include <cmath>
#include <vector>
#include <linalg.h>


int main(int argc, char** argv)
{
    Matrix a( { { 0, 1, 2 } } );
    Matrix b( { { 3 }, { 3 }, { 3 } } );
    Matrix c( { { 3, 6, 9 } } );
    Vector d( { 0, 1, 2 } );
    Vector e( { 7, 7, 7 } );
    Vector f( { 3, 6, 9 } );

    std::cout << "\nMatrix\n" << std::endl;

    std::cout << a.T() << std::endl;
    std::cout << b.T() << std::endl;
    std::cout << c.T() << std::endl;
    std::cout << b * a << std::endl;
    std::cout << ( b * a ).T() << std::endl;
    std::cout << a + c << std::endl;
    std::cout << a - c << std::endl;
    std::cout << c - a << std::endl;
    std::cout << a * 2 << std::endl;
    std::cout << b * -3 << std::endl;
    std::cout << c * 0 << std::endl;
    std::cout << ( c * 3 + a ) * b << std::endl;

    std::cout << "\nVector\n" << std::endl;

    std::cout << d.T() << std::endl;
    std::cout << e.T() << std::endl;
    std::cout << f.T() << std::endl;
    std::cout << e * d << std::endl;
    std::cout << ( e * d ).T() << std::endl;
    std::cout << d + f << std::endl;
    std::cout << d - f << std::endl;
    std::cout << f - d << std::endl;
    std::cout << d * 2 << std::endl;
    std::cout << e * -3 << std::endl;
    std::cout << f * 0 << std::endl;
    std::cout << ( f * 3 + d ) * e << std::endl;

    std::cout << "\nMatrix & Vector\n" << std::endl;

    std::cout << e * d.T() << std::endl;
    std::cout << d * e.T() << std::endl;
    std::cout << e.T() * d << std::endl;
    std::cout << d.T() * e << std::endl;

    std::cout << a + d << std::endl;
    std::cout << b + e.T() << std::endl;
    std::cout << c + f << std::endl;
    std::cout << e * a << std::endl;
    std::cout << ( e * a ).T() << std::endl;
    std::cout << d + f << std::endl;
    std::cout << d - f << std::endl;
    std::cout << f - a << std::endl;
    std::cout << a * 2 << std::endl;
    std::cout << e * -3 << std::endl;
    std::cout << f * 0 << std::endl;
    std::cout << ( f * 3 + a ) * e << std::endl;

    //std::cout << Matrix::LogGet() << std::endl;
	return 0;
}
