#ifndef MAT_MATRIX_H
#define MAT_MATRIX_H

#include <array>

namespace mat {
  enum class MatrixOrdering {
    RowMajor,
    ColMajor,
  };

  template<typename Type, int RowCount, int ColCount, MatrixOrdering order = MatrixOrdering::RowMajor>
  class Matrix {

  private:
    std::array<Type, RowCount * ColCount> m_data;


  public:
    // Rows count
    static constexpr int Rows = RowCount;

    // Columns count
    static constexpr int Cols = ColCount;

    // Elements count
    static constexpr int Size = Rows * Cols;

    // Matrix order
    static constexpr MatrixOrdering Order = order;

    // Default constructor
    constexpr Matrix() {
      for (int i = 0; i < Size; ++i) {
        m_data[i] = 0;
      }
    }

    // Initialisation constructor
    template<int DataLength>
    constexpr Matrix(const Type(&data)[DataLength]) {
      for (int i = 0; i < DataLength; ++i) {
        m_data[i] = data[i];
      }
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
      if constexpr (Order == MatrixOrdering::RowMajor) {
        return m_data[row * Cols + col];
      } else {
        return m_data[col * Rows + row];
      }
    }

    constexpr Type& operator() (int row, int col) {
      if constexpr (Order == MatrixOrdering::RowMajor) {
        return m_data[row * Cols + col];
      } else {
        return m_data[col * Rows + row];
      }
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


    class iterator
    {
      public:

      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = Type;
      using difference_type = std::ptrdiff_t;
      using pointer = Type*;
      using reference = Type&;

      iterator() = default;
      iterator(pointer ptr) : m_ptr(ptr) {}
      reference operator*() const { return *m_ptr; }
      pointer operator->() { return m_ptr; }
      iterator& operator++() { ++m_ptr; return *this; }
      iterator operator++(int) { iterator tmp(*this); ++(*this); return tmp; }
      iterator& operator--() { --m_ptr; return *this; }
      iterator operator--(int) { iterator tmp(*this); --(*this); return tmp; }
      bool operator==(const iterator& other) const { return m_ptr == other.m_ptr; }
      bool operator!=(const iterator& other) const { return m_ptr != other.m_ptr; }





    private:
      pointer m_ptr;


    };

    class const_iterator
    {

    public:

      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = Type;
      using difference_type = std::ptrdiff_t;
      using pointer = const Type*;
      using reference = const Type&;

      const_iterator() = default;
      const_iterator(pointer ptr) : m_ptr(ptr) {}
      reference operator*() const { return *m_ptr; }
      pointer operator->() const { return m_ptr; }
      const_iterator& operator++() { ++m_ptr; return *this; }
      const_iterator operator++(int) { const_iterator tmp(*this); ++(*this); return tmp; }
      const_iterator& operator--() { --m_ptr; return *this; }
      const_iterator operator--(int) { const_iterator tmp(*this); --(*this); return tmp; }
      bool operator==(const const_iterator& other) const { return m_ptr == other.m_ptr; }
      bool operator!=(const const_iterator& other) const { return m_ptr != other.m_ptr; }


    private:
      pointer m_ptr;

    };

    

    constexpr iterator begin() {
      return iterator(m_data.data());
    }

    constexpr iterator end() {
      return iterator(m_data.data() + Size);
    }

    constexpr const_iterator begin() const {
      return const_iterator(m_data.data());
    }

    constexpr const_iterator end() const {
      return const_iterator(m_data.data() + Size);
    }

    constexpr const_iterator cbegin() const {
      return const_iterator(m_data.data());
    }

    constexpr const_iterator cend() const {
      return const_iterator(m_data.data() + Size);
    }

    
  };

  /**
   * Define here the VecR and VecC classes
   */

  /*

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
  
  */

  // Retrun the identity matrix
  template<typename Type, int Size>
  constexpr Matrix<Type, Size, Size> identity() {
    
  }

}

#endif // MAT_MATRIX_H
