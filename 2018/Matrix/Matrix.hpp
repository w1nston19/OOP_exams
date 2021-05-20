#ifndef OOP_EXAMS_MATRIX_HPP
#define OOP_EXAMS_MATRIX_HPP
#include <iostream>
template <typename T>
class Matrix {
    T** elements;
    unsigned int width,height;
public:
    Matrix();
    Matrix( int x,  int y);

    Matrix(const Matrix<T>& to_copy);
    Matrix& operator=(const Matrix& tmp);

    void setAt(unsigned int x, unsigned int y, T newT);
    T getAt(unsigned int x, unsigned int y) const;

    void transpose();
    friend std::ostream& operator <<(std::ostream& o , const Matrix<T>& tmp){
        for(int i=0;i<tmp.width;i++){
            for(int j=0;j<tmp.height;j++){
                o<<tmp.elements[i][j]<<" ";
            }
            o<<"\n";
        }
        return o;
    }

    void print() const;
    ~Matrix();


private:
    void setDefault();
    void create();
    bool isInit(unsigned int x, unsigned int y) const;

};

template<typename T>
Matrix<T>::Matrix() : height(2),width(2){
    create();
}

template<typename T>
Matrix<T>::Matrix( int x,  int y) : height(x),width(y){
    create();
}

template<typename T>
void Matrix<T>::setDefault() {
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            elements[i][j] = T();
        }
    }
   // setDefault();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &to_copy) {
    height = to_copy.height;
    width = to_copy.width;
    this->create();
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            elements[i][j] = to_copy.elements[i][j];
        }
    }
    setDefault();
}

template<typename T>
void Matrix<T>::create() {
    elements = new T*[height];
    for(int i=0;i<height;i++){
        elements[i]= new T[width];
    }

}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix& tmp) {
    if(this!=&tmp){
        height = tmp.height;
        width = tmp.width;
        this->create();
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                elements[i][j] = tmp.elements[i][j];
            }
        }
    }
    return *this;
}

template<typename T>
bool Matrix<T>::isInit(unsigned int x, unsigned int y) const {
    return x<=height&&x>0&&y<=width&&y>0;
}

template<typename T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, T newT) {
    if(isInit(x,y)){
        elements[x-1][y-1] = newT;
    }
}

template<typename T>
T Matrix<T>::getAt(unsigned int x, unsigned int y) const {
    if(isInit(x,y)){
        return elements[x-1][y-1];
    }
    return 0;
}

template<typename T>
void Matrix<T>::transpose() {

    T** newMatrix;
    newMatrix = new T*[width];
    for(int i=0;i<width;i++){
        newMatrix[i] = new T[height];
    }
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            newMatrix[i][j] = elements[j][i];
        }
    }
    std::swap(height,width);
    this->elements = newMatrix;
}

template<typename T>
Matrix<T>::~Matrix() {
    for(int i=0;i<height;i++){
        delete[] elements[i];
    }
    delete[] elements; //sigsegv
}

template<typename T>
void Matrix<T>::print() const {
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            std::cout<<elements[i][j]<<" ";
        }
        std::cout<<std::endl;

    }
    std::cout<<std::endl;
}


#endif //OOP_EXAMS_MATRIX_HPP
