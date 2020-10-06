#ifndef RING_CONCEPTS_H
#define RING_CONCEPTS_H

#include <concepts>

/**
 * Requirements of RingElement
 * 
 * A RingElement requires elements be closed under addition and multiplication
 */
template<typename T>
concept RingElement = requires(T a, T b){
    {a+b}->std::same_as<T>;
    {a*b}->std::same_as<T>;
    a+=b;
    a*=b;
};

/**
 * Requirements of Ring
 * 
 * A Ring requires elements from RingElement and an additive/multiplicative identity
 */
template<typename R>
concept Ring = requires(R a){
    typename R::element;
    {a.zero()}->std::same_as<typename R::element>;
    {a.one()}->std::same_as<typename R::element>;
} && RingElement<typename R::element>;

/**
 * Requirements of a Rng
 * 
 * A Rng requires elements from RingElement and an additive identity
 */
template<typename R>
concept Rng = requires(R a, R b){
    typename R::element;
    {a.zero()}->std::same_as<typename R::element>;
} && RingElement<typename R::element>;

/**
 * Requirements of a GroupElement
 * 
 * A GroupElement requires the elements to be closed under addition
 */
template<typename T>
concept GroupElement = requires(T a, T b){
    {a+b}->std::convertible_to<T>;
};

/**
 * Requirements of a Group
 * 
 * A Group requires elements from GroupElements and an additive identity
 */
template<typename G>
concept Group = requires(G a){
    typename G::element;
    {a.zero()}->std::same_as<typename G::element>;
} && GroupElement<typename G::element>;

#endif