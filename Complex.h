/* 
 * File:   Complex.h
 * Author: nightduck
 *
 * Created on July 11, 2015, 11:58 AM
 */

#ifndef COMPLEX_H
#define	COMPLEX_H

#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

const static double PI = 3.141592653589793238462643383279502884;

template <class E>
class Complex {
public:

    //Constructors
    Complex() {
        real = E(0);
        imag = E(0);
    }

    Complex(E real) {
        this->real = E(real);
        imag = E(0);
    }

    Complex(E real, E imag) {
        this->real = E(real);
        this->imag = E(imag);
    }

    /*
      Returns a pair of numbers used in the Gaussian representation.
      Returns the same variable type used in the complex number.
	  The real component is index 0 and the imaginary in index 1
      @return 
     */
    E * getValueRect() {
		E answer[2];
		answer[0] = real;
		answer[1] = imag;

		return answer;
    }

    /*
      Returns a pair of numbers used to represent the complex number in polar
      form, in degrees. It returns the same variable type used in the complex
      number, so using int type will return VERY inaccurate results.
	  The length of the vector is in index 0, the angle in index 1
      @return 
     */
    E * getValuePolar() {
        E length = sqrt(real * real + imag * imag);
        E angle = tan(imag / real);
        angle *= 180 / PI;

		E answer[2];
		answer[0] = length;
		answer[1] = angle;

		return answer;
    }
    
    /*
	  Returns a pair of numbers used to represent the complex number in polar
      form, in radians. It returns the same variable type used in the complex
      number, so using int type will return VERY inaccurate results.
	  The length of the vector is in index 0, the angle in index 1
      @return 
     */
    E * getValuePolarRad() {
		E length = sqrt(real * real + imag * imag);
        E angle = tan(imag / real);
        
		E answer[2];
		answer[0] = length;
		answer[1] = angle;

		return answer;
    }

    //Returns individual components
	/* Returns real component as same variable type used in complex number @return */
    E getReal() {
        return real;
    }

	/* Returns imaginary component as same variable type used in compolex number @return*/
    E getImag() {
        return imag;
    }
    
	/*
	  Returns the conjugate of the number
	  @return
	*/
    Complex<E> conjugate() {
		return Complex<E>(real, -1 * imag);
    }

    //Basic arithmetic operators

    Complex<E> operator+(E n) {
        return Complex<E>(real + n, imag);
    }

    Complex<E> operator-(E n) {
        return Complex<E>(real - n, imag);
    }

    Complex<E> operator*(E n) {
        return Complex<E>(real * n, imag * n);
    }

    Complex<E> operator/(E n) {
        return Complex<E>(real / n, imag / n);
    }

////ERROR: modulo arithmetic doesn't work with doubles, use fmod() fn
//   Complex<E> operator%(E n) {
//       return Complex<E>(real % n, imag % n);
//   }

////ERROR: these operations aren't allowed. Maybe require typecasting for first argument?
//    E operator+(Complex<E> c) {
//        return Complex<E>(this + c.returnReal(), c.returnImag());
//    }
//
//    E operator-(Complex<E> c) {
//        return Complex<E>(this - c.returnReal(), c.returnImag());
//    }
//
//    E operator*(Complex<E> c) {
//        return Complex<E>(this * c.returnReal(), this * c.returnImag());
//    }
//
//    E operator/(Complex<E> c) {
//        E r = c.returnReal();
//        E i = c.returnImag();
//        
//        Complex<E> cmplx = Complex<E>(r * this, -1 * this * i);
//        
//        return cmplx / (pow(r,2) + pow(i,2));
//    }
//
//////ERROR: not smart enough to figure this out. Also mods don't work with doubles
////    E operator%(Complex<E> c);

    Complex<E>& operator+=(E n) {
		real += n;
		return *this;
    }

    Complex<E>& operator-=(E n) {
		real -= n;
		return *this;
    }

    Complex<E>& operator*=(E n) {
		real *= n;
		imag *= n;
		return *this;
    }

    Complex<E>& operator/=(E n) {
		real /= n;
		imag /= n;
		return *this;
    }

////ERROR: modulo arithmetic doesn't work with doubles
//    Complex<E> operator%=(E n) {
//        return Complex<E>(real % n, imag % n);
//    }

////ERROR: boolean operations don't like doubles
//   //Basic boolean operators
//	/* If no imaginary component is given, the operation is carried out as if it
//	/were equal to 0*/
//
//   Complex<E> operator ^(E n) {
//       return Complex<E>(real ^ n, imag);
//   }
//
//   Complex<E> operator &(E n) {
//       return Complex<E>(real & n, 0);
//   }
//
//   Complex<E> operator |(E n) {
//       return Complex<E>(real | n, imag);
//   }
//
//   Complex<E> operator ~() {
//       return Complex<E>(~real, ~imag);
//   }
//
//    Complex<E> operator^=(E n) {
//        return Complex<E>(real ^ n, imag);
//    }
//
//    Complex<E> operator&=(E n) {
//        return Complex<E>(real ^ n, imag);
//    }
//
//    Complex<E> operator|=(E n) {
//        return Complex<E>(real ^ n, imag);
//    }
//
//    //Bitshift real component
//
//    Complex<E> operator<<(int shift) {
//        return Complex<E>(real << shift, imag);
//    }
//
//    Complex<E> operator>>(int shift) {
//        return Complex<E>(real >> shift, imag);
//    }
//
//    Complex<E> operator<<=(int shift) {
//        return Complex<E>(real >> shift, imag);
//    }
//
//    Complex<E> operator>>=(int shift) {
//        return Complex<E>(real >> shift, imag);
//    }

    //Complex arithmetic operators

    Complex<E> operator+(Complex<E> c) {
        return Complex<E>(real + c.getReal(), imag + c.getImag());
    }

    Complex<E> operator-(Complex<E> c) {
        return Complex<E>(real - c.getReal(), imag - c.getImag());
    }

    Complex<E> operator*(Complex<E> c) {
        E r = c.getReal();
        E i = c.getImag();

        return Complex<E>(real * r - imag*i, real * i + r * imag);
    }

    Complex<E> operator/(Complex<E> c) {
        E r = c.getReal();
        E i = c.getImag();
        
        Complex<E> cmplx = Complex<E>(real*r + imag*i, imag*r - real*i);
        
        return cmplx / (pow(r,2) + pow(i,2));
    }

//    Complex<E> operator%(Complex<E> c);

    Complex<E>& operator+=(Complex<E> c) {
		real += c.getReal();
		imag += c.getImag();
		return *this;
    }

    Complex<E>& operator-=(Complex<E> c) {
		real -= c.getReal();
		imag -= c.getImag();
		return *this;
    }
    Complex<E>& operator*=(Complex<E> c) {
		E r = c.getReal();
		E i = c.getImag();

		E newReal = real * r - imag * i;
		imag = real * i + imag * r;
		real = newReal;

		return *this;
    }
    Complex<E>& operator/=(Complex<E> c) {
		E r = c.getReal();
		E i = c.getImag();

		E newReal = real  *r + imag * i;
		imag = imag * r - real * i;
		real = newReal / (r * r + i * i);
		imag /= r * r + i * i;
		
		return *this;
    }

//    Complex<E> operator%=(Complex<E> c);

//    //Complex boolean operators
//
//    Complex<E> operator ^(Complex<E> c) {
//        return Complex<E>(real ^ c.returnReal(), imag ^ c.returnImag());
//    }
//
//    Complex<E> operator&(Complex<E> c) {
//        return Complex<E>(real & c.returnReal(), imag & c.returnImag());
//    }
//
//    Complex<E> operator|(Complex<E> c) {
//        return Complex<E>(real | c.returnReal(), imag | c.returnImag());
//    }
//
//    Complex<E> operator^=(Complex<E> c) {
//        return Complex<E>(real ^ c.returnReal(), imag ^ c.returnImag());
//    }
//
//    Complex<E> operator&=(Complex<E> c) {
//        return Complex<E>(real & c.returnReal(), imag ^ c.returnImag());
//    }
//
//    Complex<E> operator|=(Complex<E> c) {
//        return Complex<E>(real & c.returnReal(), imag ^ c.returnImag());
//    }
//
//    //Complex bitshift operators
//
//    Complex<E> operator<<(Complex<int> shift) {
//        return Complex<E>(real << shift.returnReal(), real << shift.returnImag());
//		//Also define this for I/O
//    }
//
//    Complex<E> operator>>(Complex<int> shift) {
//        return Complex<E>(real >> shift.returnReal(), imag >> shift.returnImag());
//    }
//
//    Complex<E> operator<<=(Complex<int> shift) {
//        return Complex<E>(real << shift.returnReal(), imag << shift.returnImag());
//    }
//
//    Complex<E> operator>>=(Complex<int> shift) {
//        return Complex<E>(real >> shift.returnReal(), imag >> shift.returnImag());
//    }
//
//    //Complex equality and inequality operators
//
//    bool operator!=(Complex<E> c) {
//        return !(this == c);
//    }
////    bool operator<(Complex<E> n2);
////    bool operator>(Complex<E> n2);
////    bool operator<=(Complex<E> n2);
////    bool operator>=(Complex<E> n2);


	//NOTE: increment and decrement not compatible with doubles
    ////Increment and decrement

    //Complex<E> operator++() {
    //    return Complex<E>(real++, imag);
    //}

    //Complex<E> operator--() {
    //    return Complex<E>(real--, imag);
    //}


    ////Type conversion

    //operator Complex(int n) {
    //    return Complex<int>(n);
    //}

    //operator Complex(double n) {
    //    return Complex<double>(n);
    //}

    //operator Complex(float n) {
    //    return Complex<float>(n);
    //}

    //operator Complex(short n) {
    //    return Complex<short>(n);
    //}

    //operator Complex(long n) {
    //    return Complex<long>(n);
    //}

    //operator Complex(long double n) {
    //    return Complex<long double>(n);
    //}

    //operator Complex(long long n) {
    //    return Complex<long long>(n);
    //}

    //operator Complex(unsigned short n) {
    //    return Complex<unsigned short>(n);
    //}

    //operator Complex(unsigned n) {
    //    return Complex<unsigned>(n);
    //}

    //operator Complex(unsigned long n) {
    //    return Complex<unsigned long>(n);
    //}

    //operator Complex(unsigned long long n) {
    //    return Complex<unsigned long long>(n);
    //}

    //ostream& operator<<(const Complex<E>& obj) {
    //    this << obj.toString();
    //}

    string toString() const {
        ostringstream out;
        if (real != 0 ) out << real;
        else out << "";
        
        if (real != 0 && imag > 0) out << "+";
        
        if (imag != 0) {
            if (imag == 1) out << "i";
            else if (imag == -1) out << "-i";
            else out << imag << "i";
        }
        
        return out.str();
    }

	virtual ~Complex() {}
private:
    E real;
    E imag;
};

#endif	/* COMPLEX_H */