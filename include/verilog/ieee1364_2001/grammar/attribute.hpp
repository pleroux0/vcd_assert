// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP

#include "./base.hpp"
#include "./constants.hpp"
#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct attr_name : alias<identifier> {};

struct attr_spec : sor <
  attr_name,
  op_sep_must<
    attr_name,
    one<'='>,
    constant_expression
  >
> {};

struct attribute_instance : if_must<
  seq<one<'('>,one<'*'>>,
  list<
    seq<attr_spec, opt<separator>>, 
    one<','>
  >,
  seq<one<'*'>,one<')'>>,
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP
