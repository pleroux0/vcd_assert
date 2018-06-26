#ifndef LIBVCD_TYPES_VARIABLE_HPP
#define LIBVCD_TYPES_VARIABLE_HPP

#include "./enums.hpp"

#include <string>
#include <string_view>

#include <cstddef>

namespace VCD {

struct VariableView {
  VarType type;
  std::size_t size;
  std::string_view identifier_code;
  std::string_view reference;
};

class Variable {
  std::size_t id_code_;
  std::string ref_;

public:
  Variable(std::size_t id_code, std::string reference);

  std::size_t get_id_code_index();
  std::string_view get_reference();
};

} // namespace

#endif //LIBVCD_TYPES_VARIABLE_HPP
