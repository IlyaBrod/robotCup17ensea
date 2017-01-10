#ifndef MATHS_HPP
#define MATHS_HPP

#define PI 3.14159265358979323846264338327950288419716939937510582097494

/**
 * Return the maximum between 2 elements
 * @param a
 * @param b
 * @return the max
 */
template<typename T> T min(T a,T b);

/**
 * Return the minimum between 2 elements
 * @param a
 * @param b
 * @return the min
 */
template<typename T> T max(T a,T b);

/**
 * Return absolute value of an element
 * @param value
 * @return |value|
 */
template<typename T> T abs(T value);

/**
 * Return a power of a value : value^n
 * @param value The value to evaluate
 * @param n Exposant
 * @return result
 */
template<typename T> float pwr(T value,int n);

/***
 * Return the square root of value
 * @param value
 * @param n=50 Precision of the result
 * @return result
 */
template<typename T> float sqrt(T value,int n=50);

/**
 * Convert the value to rad
 * @param deg
 * @return deg in rad
 */
template<typename T> T toRad(T deg);

/**
 * Convert the value to degree
 * @param rad
 * @return rad in degree
 */
template<typename T> T toDeg(T rad);

#endif
