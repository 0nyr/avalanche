#pragma once

#include <iostream>
#include <type_traits>

/** This is a 1D array proxy class.
 * WARN: It is not meant to be used manually. This object 
 * is used by Array2D's Subscripting operator [].
 */
template<typename T> // templace<class T> == template<typename T>: https://stackoverflow.com/questions/5307036/what-is-difference-between-template-typename-t-and-template-class-t-for-me
class ProxyArray1D
{
    private:
        T * ptr; // this pointer is a copy, don't delete it here.
    
    public:
        ProxyArray1D(
            T * ptr
        ): ptr(ptr) {}

        T & operator [](int index)
        {
            return this->ptr[index];
        }
};

template<typename T>
class Array2D
{
    private:
        T * array; 
        int const width;
        int const height;


    public:
        Array2D(
            int const height, int const width
        );

        // delegating constructor: https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c 
        Array2D(
            int const height, int const width, T initValue
        );

        ~Array2D();

        T & at(int row, int col);
        void fill(T value);
        void log();

        ProxyArray1D<T> operator [](int row);

        int getWidth() {return this->width;}
        int getHeight() {return this->height;}

};

template<typename T>
Array2D<T>::Array2D(
    int const height, int const width
): height(height), width(width)
{
    // WARN: Not like C, new T[][] not allowed: https://stackoverflow.com/questions/44998478/c-array-size-in-new-expression-must-be-constant 
    this->array = new T[this->height*this->width];
}

template<typename T>
Array2D<T>::Array2D(
    int const height, int const width, T initValue
): Array2D(height, width)
{
    this->fill(initValue);
}

template<typename T>
Array2D<T>::~Array2D()
{
    // delete pointers inside the array (if it's the case)
    //if(std::is_pointer<T>::value == true)
    // "if constexpr" evaluates at compile time.
    if constexpr(std::is_pointer<T>::value)
    {
        for(int i = 0; i < this->height; i++)
        {
            for(int j = 0; j < this->width; j++)
            {
                delete this->at(i, j);
            }
        }
    }


    // delete array
    delete[] this->array;
}

/*template<class T>
Array2D<T *>::~Array2D()
{
    // delete pointers inside the array (if it's the case)
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            delete this->at(i, j);
        }
    }


    // delete array
    delete[] this->array;
}*/

template<typename T>
void Array2D<T>::fill(T value)
{
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            this->at(i, j) = value;
        }
    }
}

template<typename T>
T & Array2D<T>::at(int row, int col)
{
    return this->array[(row*this->width + col)];
}

template<typename T>
ProxyArray1D<T> Array2D<T>::operator [](int row)
{
    // NOTE: here, the & is used to get an address (pointer)
    // this is not the same as for a reference
    // (See ProxyArray1D constructor, takes in a pointer of T)
    return ProxyArray1D<T>(&this->array[row*this->width]);
}

template<typename T>
void Array2D<T>::log()
{
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            std::cout << this->at(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
