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
      if constexpr (Order == MatrixOrdering::RowMajor)
      for (int i = 0; i < DataLength; ++i) {
        m_data[i] = data[i];
      }
      else if constexpr (Order == MatrixOrdering::ColMajor)
      {

        for (int i = 0; i < DataLength; ++i) {
          int row = i / Cols;
          int col = i % Cols;
         this->operator()(row, col) = data[i];
        }
          
      }
      for(int i = 0; i < Size; ++i) {
         std::cout << m_data[i] << " ";
      }
      std::cout << std::endl;

    }


    // conversion constructor
    template<MatrixOrdering OtherOrder>
    constexpr Matrix(const Matrix<Type, Rows, Cols, OtherOrder>& other) {
      for(int i = 0; i < Size; ++i) {
        m_data[i] = other.m_data[i];
      }
    }
    


    // Affectation from a matrix with different ordering
    constexpr auto& operator=(const Matrix<Type, Rows, Cols, Order>& other) {
    }

    // Retrun the transposed matrix
    constexpr Matrix<Type, Cols, Rows, Order> transpose() {
      Matrix<Type, Cols, Rows, Order> result;

      for(int i = 0; i < Rows; ++i)
      {
        for(int j = 0; j < Cols; ++j)
        {
          result(j, i) = this->operator()(i, j);
        }
      }

      return result;
    

    }

    // Get the value at specified row and col
    constexpr const Type& operator() (int row, int col) const {

        return m_data[row * Cols + col];
 
    }

    constexpr Type& operator() (int row, int col) {
        return m_data[row * Cols + col];

    }

    // Addition - in place
    template<typename OtherType, MatrixOrdering otherOrder>
    auto& operator+=(const Matrix<OtherType, Rows, Cols, otherOrder>& other) {
      for (int i = 0; i < Size; ++i) {
        m_data[i] += other.m_data[i];
      }
      return *this;
    }

    // Addition - classic
    template<typename OtherType, MatrixOrdering otherOrder>
    constexpr Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> operator+(const Matrix<OtherType, Rows, Cols, otherOrder>& other) const {
      Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> result;
      for (int i = 0; i < Size; ++i) {
        result.m_data[i] = m_data[i] + other.m_data[i];
      }
      return result;
    }

    // Substration - in place
    template<typename OtherType, MatrixOrdering otherOrder>
    auto& operator-=(const Matrix<OtherType, Rows, Cols, otherOrder>& other) {
      for (int i = 0; i < Size; ++i) {
        m_data[i] -= other.m_data[i];
      }
      return *this;
    }

    // Substraction - classic
    template<typename OtherType, MatrixOrdering otherOrder>
    constexpr Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> operator-(const Matrix<OtherType, Rows, Cols, otherOrder>& other) const {
      Matrix<std::common_type_t<Type, OtherType>, Rows, Cols, Order> result;
      for (int i = 0; i < Size; ++i) {
        result.m_data[i] = m_data[i] - other.m_data[i];
      }
      return result;
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
      Matrix<std::common_type_t<Type , OtherType>, Rows, OtherCols, Order> result;
      for( int i = 0; i < Rows; ++i)
      {
        for(int j = 0; j < OtherCols; ++j)
        {
          result(i, j) = 0;
          for(int k = 0; k < Cols; ++k)
          {
            result(i, j) += this->operator()(i, k) * other(k, j);
          }
        }
            
      }
      return result;


    }

    // Equality
    template<typename OtherType, int OtherRows, int OtherCols, MatrixOrdering otherOrder>
    constexpr bool operator==(const Matrix<OtherType, OtherRows, OtherCols, otherOrder>& other) const {
      return m_data == other.m_data;
    }

    // Difference
    template<typename OtherType, int OtherRows, int OtherCols, MatrixOrdering otherOrder>
    constexpr bool operator!=(const Matrix<OtherType, OtherRows, OtherCols, otherOrder>& other) const {
      return m_data != other.m_data;
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



   
      iterator() :
        m_ptr(nullptr)
      {
        pos_ref = 0;
        col_ref = 0;
        col_counter = 0;
        m_begin = m_ptr;
        m_end = m_ptr + Size;
      }
      iterator(pointer ptr) : m_ptr(ptr) {
        m_begin = m_ptr;
        m_end = m_ptr + Size;
        pos_ref = 0;
        col_ref = 0;
        col_counter = 0;
      }


      reference operator*() const {
        return *(m_ptr  );
      }
      pointer operator->() {  return m_ptr ; }
      iterator& operator++()
      { 
        
        if(order == MatrixOrdering::RowMajor)
        {
          
            ++m_ptr;
        }
        else
        {
        // std::cout << "curr pos : " << col_ref << std::endl;

          if(pos_ref < Size)
          {
            col_ref =  (col_ref + Cols  ) % Size;

            if(col_ref % Rows  == 0)
            {

              col_counter +=1 ;
             
            }
            col_ref = (col_ref ) % Size ;
            m_ptr = m_begin + col_ref + col_counter;
        
          }
          else
          {
            m_ptr = m_end;
          }
          if(col_counter == Cols)
          {
            m_ptr = m_end;
            return *this;
          }
        
        }


        pos_ref++;


        return *this;
         
      }
      iterator operator++(int)
      {
        iterator tmp = *this;
        ++*this;
        return tmp;
      }
      iterator& operator--()
      {
        m_ptr--;
        return *this;
      }
      iterator operator--(int) { iterator tmp(*this); --(*this); return tmp; }
      bool operator==(const iterator& other) const { return m_ptr == other.m_ptr; }
      bool operator!=(const iterator& other) const { return m_ptr != other.m_ptr; }





    private:
      pointer m_ptr;
      pointer m_end;
      pointer m_begin;
      int pos_ref;
      int col_ref;
      int col_counter;



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

  
  template<typename Type, int lenght>
  using  VecR = Matrix<Type ,lenght, 1, MatrixOrdering::RowMajor>;
  template<typename Type, int lenght>
  using VecC = Matrix<Type,1, lenght,  MatrixOrdering::ColMajor>;


  template<typename Type, int Cols>
  constexpr VecR<Type, Cols> vecRow(const Type(&data)[Cols]) {
    return VecR<Type, Cols>(data);
  }

  template<typename Type, int Rows>
  constexpr VecC<Type, Rows> vecCol(const Type(&data)[Rows]) {
    return VecC<Type, Rows>(data);
  }

  // Convert the matrix to the opposite ordering
  template<typename Type, int Rows, int Cols, MatrixOrdering Order>
  constexpr auto convert(const Matrix<Type, Rows, Cols, Order>& mat) {

  }

  

  // Return the identity matrix
  template<typename Type, int Size>
  constexpr Matrix<Type, Size, Size> identity() {
    Matrix<Type, Size, Size> result;
    for (int i = 0; i < Size; ++i) {
      result.m_data[i * Size + i] = 1;
    }
    return result;
  }

  
}

#endif // MAT_MATRIX_H
