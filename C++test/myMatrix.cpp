#include <iostream>
#include <vector>
#include <string>
using namespace std;

class myMatrix{

    private:
    int nrows;
    int ncols;
    double* data;
    double* endPointer;
    vector<double> data2;

    public:
    myMatrix(int, int);
    myMatrix (string* );
    ~myMatrix();

    int nRows() const;
    int nCols() const;
    double get(int, int) const;
    void set(int, int, double);
    int offset(int, int) const;
    const double* begin() const;
    const double* end() const;
};

myMatrix::myMatrix(int nrows, int ncols) : nrows(nrows), ncols(ncols){
    int size = nrows * ncols;
    data = new double[size];
    endPointer = data + size;
    memset(data, 0, sizeof(double) * size);
}

myMatrix::~myMatrix(){
    delete[] data;
}

int myMatrix::nRows() const {
    return nrows;
}

int myMatrix::nCols() const {
    return ncols;
}

double myMatrix::get(int i, int j) const {
    return data[offset(i, j)];
}

void myMatrix::set(int i, int j, double value){
    data[offset(i, j)] = value;
}

int myMatrix::offset(int i, int j) const{
    assert(i >= 0 && i < nrows && j >= 0 && j < ncols);
    return j * nrows + i;
}

const double* myMatrix::begin() const{
    return data;
}

const double* myMatrix::end() const{
    return endPointer;
}



int main(){
cout << "Hello World" << endl;
return 0;

}