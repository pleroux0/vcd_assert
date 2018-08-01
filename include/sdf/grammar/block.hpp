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

#ifndef LIBSDF_GRAMMAR_BLOCK
#define LIBSDF_GRAMMAR_BLOCK

#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace SDF::Grammar {
using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

// Incomplete type !?
// template <typename T, typename... P>
// struct block : delimited_seq < opt<separator>,
//   one<'('>,
//   T,
//   delimited_must<opt<separator>,
//     seq<>, // required for weird template parameter pack rule
//     P...,
//     one<')'>
//   >
// > {};

struct open : seq <
  opt<separator>,
  one< '(' >,
  opt<separator>
> {};

struct close : seq <
  opt<separator>,
  one< ')' >,
  opt<separator>
> {};

template<typename T, typename... P>
struct block: if_must<
  seq< open, T >,
  seq< opt< separator >, P >...,
  close
> {};

} // namespace Grammar

#endif // LIBSDF_GRAMMAR_BLOCK
