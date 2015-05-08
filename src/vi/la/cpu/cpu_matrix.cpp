#include "vi/la/cpu/cpu_matrix.h"
#include <cassert>
#include <cstring>

namespace vi {
namespace la {
namespace cpu {

matrix::matrix(cpu_context& context, size_t rows, size_t columns,
               const double* initial_values)
    : _context(context), _row_count(rows), _column_count(columns) {
  size_t value_count = rows * columns;
  assert(value_count > 0);
  double* values = new double[value_count];
  if (initial_values) {
    memcpy((void*)values, (const void*)initial_values,
           value_count * sizeof(double));
  }
  _buffer = values;
}

matrix::~matrix() { delete[] _buffer; }

size_t matrix::row_count() const { return _row_count; }

size_t matrix::column_count() const { return _column_count; }

vi::la::context& matrix::owning_context() const {
  return _context;
}

double* matrix::raw_data() { return _buffer; }

double* matrix::get() { return _buffer; }

}
}
}

