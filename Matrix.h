#ifndef MAT_MATRIX_H
#define MAT_MATRIX_H

namespace mat {
  enum class MatrixOrdering {
    RowMajor,
    ColMajor,
  };

  template<typename Type, int RowCount, int ColCount, MatrixOrdering order = MatrixOrdering::RowMajor>
  class Matrix {
  public:
    // Rows count
    static constexpr int Rows = /* implementation defined */;

    // Columns count
    static constexpr int Cols = /* implementation defined */;

    // Elements count
    static constexpr int Size = /* implementation defined */;

    // Matrix order
    static constexpr MatrixOrdering Order = /* implementation defined */;

    // Default constructor
    constexpr Matrix() {
    }

    // Initialisation constructor
    template<int DataLength>
    constexpr Matrix(const Type(&data)[DataLength]) {
    }

    // Conversion constructor
    constexpr Matrix(const Matrix<Type, Rows, Cols, Order>& other) {
    }

    // Affectation from a matrix with different ordering
    constexpr auto& operator=(const Matrix<Type, Rows, Cols, Order>& other) {
    }

    // Retrun the transposed matrix
    constexpr Matrix<Type, Cols, Rows, Order> transpose() {
    }

    // Get the value at specified row and col
    constexpr const Type& operator() (int row, int col) const {
    }

    constexpr Type& operator() (int row, int col) {
    }

    // Addition - in place
    template<typename OtherType, MatrixOrdering otherOrder>
    auto& operator+=(const Matrix<OtherType, Rows, Cols, otherOrder>& other) {
    }

    // Addition - classic
    template<typename OtherType, MatrixOrdering otherOrder>
    constexpr Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> operator+(const Matrix<OtherType, Rows, Cols, otherOrder>& other) const {
    }

    // Substration - in place
    template<typename OtherType, MatrixOrdering otherOrder>
    auto& operator-=(const Matrix<OtherType, Rows, Cols, otherOrder>& other) {
    }

    // Substraction - classic
    template<typename OtherType, MatrixOrdering otherOrder>
    constexpr Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> operator-(const Matrix<OtherType, Rows, Cols, otherOrder>& other) const {
    }

    // Product - in place
    template<typename OtherType, MatrixOrdering otherOrder>
    auto& operator*=(const Matrix<OtherType, Rows, Cols, otherOrder>& other) {
      Matrix<Type, Rows, Cols, Order> tmp;
      tmp = *this * other;

      *this = tmp;

      return *this;
    }

    // Product - classic
    template<typename OtherType, int OtherCols, MatrixOrdering otherOrder>
    constexpr Matrix<std::common_type_t<Type, OtherType>, Rows, OtherCols, Order> operator*(const Matrix<OtherType, Cols, OtherCols, otherOrder>& other) const {
    }

    // Equality
    template<typename OtherType, int OtherRows, int OtherCols, MatrixOrdering otherOrder>
    constexpr bool operator==(const Matrix<OtherType, OtherRows, OtherCols, otherOrder>& other) const {
    }

    // Difference
    template<typename OtherType, int OtherRows, int OtherCols, MatrixOrdering otherOrder>
    constexpr bool operator!=(const Matrix<OtherType, OtherRows, OtherCols, otherOrder>& other) const {
    }

  public:
    /**
     * Define here the iterator classe
     * iterator must be allow to modify the values
     * const_iterator must be point to constant value
     */

    constexpr iterator begin() {
    }

    constexpr iterator end() {
    }

    constexpr const_iterator begin() const {
    }

    constexpr const_iterator end() const {
    }
  };

  /**
   * Define here the VecR and VecC classes
   */

  template<typename Type, int Cols>
  constexpr VecR<Type, Cols> vecRow(const Type(&data)[Cols]) {
  }

  template<typename Type, int Rows>
  constexpr VecC<Type, Rows> vecCol(const Type(&data)[Rows]) {
  }

  // Convert the matrix to the opposite ordering
  template<typename Type, int Rows, int Cols, MatrixOrdering Order>
  constexpr auto convert(const Matrix<Type, Rows, Cols, Order>& mat) {
  }

  // Retrun the identity matrix
  template<typename Type, int Size>
  constexpr Matrix<Type, Size, Size> identity() {
  }
}

#endif // MAT_MATRIX_H
