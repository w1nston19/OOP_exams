#ifndef OOP_EXAMS_MATRIX_HPP
#define OOP_EXAMS_MATRIX_HPP
#include <iostream>
template <typename T>
class Matrix {
    T** elements;
    unsigned int sizeX,sizeY;
public:
    Matrix();
    Matrix( int x,  int y);

    Matrix(const Matrix<T>& to_copy);
    Matrix& operator=(const Matrix& tmp);

    void setAt(unsigned int x, unsigned int y, T newT);
    T getAt(unsigned int x, unsigned int y) const;

    void transpose();
    friend std::ostream& operator <<(std::ostream& o , const Matrix<T>& tmp){
        for(int i=0;i<tmp.sizeX;i++){
            for(int j=0;j<tmp.sizeY;j++){
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
Matrix<T>::Matrix() : sizeX(2),sizeY(2){
    create();
}

template<typename T>
Matrix<T>::Matrix( int x,  int y) : sizeX(x),sizeY(y){
    create();
}

template<typename T>
void Matrix<T>::setDefault() {
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            elements[i][j] = T();
        }
    }
   // setDefault();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &to_copy) {
    sizeY = to_copy.sizeY;
    sizeX = to_copy.sizeX;
    this->create();
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            elements[i][j] = to_copy.elements[i][j];
        }
    }
    setDefault();
}

template<typename T>
void Matrix<T>::create() {
    elements = new T*[sizeX];
    for(int i=0;i<sizeY;i++){
        elements[i]= new T[sizeY];
    }

}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix& tmp) {
    if(this!=&tmp){
        sizeY = tmp.sizeY;
        sizeX = tmp.sizeX;
        this->create();
        for(int i=0;i<sizeX;i++){
            for(int j=0;j<sizeY;j++){
                elements[i][j] = tmp.elements[i][j];
            }
        }
    }
    return *this;
}

template<typename T>
bool Matrix<T>::isInit(unsigned int x, unsigned int y) const {
    return x<=sizeX&&x>0&&y<=sizeY&&y>0;
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
    Matrix<T> tmp;
    tmp.sizeY= sizeY;
    tmp.sizeX = sizeX;
    tmp.create();
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            tmp.elements[i][j] = this->elements[i][j];
        }
    }
    for(int i=0;i<sizeY;i++){
        delete[] elements[i];
    }
    delete[] elements;
    sizeX = tmp.sizeY;
    sizeY = tmp.sizeX;
    this->create();
    for(int i=0;i<tmp.sizeY;i++){
        for(int j=0;j<tmp.sizeX;j++){
            this->elements[j][i]= tmp.elements[i][j];
        }
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for(int i=0;i<sizeY;i++){
        delete[] elements[i];
    }
    delete[] elements;
}

template<typename T>
void Matrix<T>::print() const {
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            std::cout<<getAt(i+1,j+1)<<" ";
        }
        std::cout<<std::endl;
    }
}


#endif //OOP_EXAMS_MATRIX_HPP
