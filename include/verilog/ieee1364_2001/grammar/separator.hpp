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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./comment.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

template <typename... Rules>
using pad = tao::pegtl::pad<Rules...>;

// struct sep : sor< plus_blank, comment > {};
// struct plus_sep : pad< blank, sep> {};

struct sep : pad< plus_blank, comment > {};
struct plus_sep : plus< sep > {};

template<typename T, typename... P>
struct sep_seq: seq<
  T, seq<plus_sep, P>...
> {};

template<typename T, typename... P>
struct sep_must: must<
  T, seq<plus_sep, P>...
> {};

template<typename T, typename... P>
struct opt_sep_seq: seq<
  T, seq<opt<plus_sep>, P>...
> {};

template<typename T, typename... P>
struct opt_sep_must: must<
  T, seq<opt<plus_sep>, P>...
> {};

template<typename T, typename... P>
struct opt_sep_if_must: if_must<
  T, seq<opt<plus_sep>, P>...
> {};

// template<typename... P>
// struct opt_sep_seq: seq<
//   opt<plus_sep>>,  
//   seq<P,opt<plus_sep>>...
// > {};

// template<typename... P>
// struct opt_sep_must: must<
//   star<sep>,  
//   seq<P,opt<plus_sep>>...
// > {};

struct separator_helper :  plus<
  sor<
    comment,
    blank
  >
> {};

struct separator : sor<
  seq<blank,opt<plus_sep>>,
  seq<opt<plus_sep>,blank>,
  seq<opt<plus_sep>,blank,opt<plus_sep>>
> {};

// struct plus_sep : plus<
//   blank,
//   sor<
//     comment,
//     plus<blank>
//   >
// > {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP
