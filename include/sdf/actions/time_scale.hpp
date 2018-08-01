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

#ifndef LIBSDF_ACTIONS_TIMESCALE_HPP
#define LIBSDF_ACTIONS_TIMESCALE_HPP

#include <sdf/grammar/time_scale.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/time_scale.hpp>

#include <parse/actions/dispatch.hpp>
#include <parse/actions/command/inner_action.hpp>
#include <parse/actions/command/apply0.hpp>
#include <parse/actions/storage/member.hpp>
#include <parse/actions/apply/value.hpp>
#include <parse/actions/apply/rule_value.hpp>

namespace SDF::Actions {

using namespace Parse;

struct TimeScaleNumberAction : all_dispatch<apply0<Apply::rule_value>>
{
  using state = TimeScaleNumber;
};

struct TimeScaleUnitAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = TimeScaleUnit;
};

struct TimeScaleAction : multi_dispatch<
   Grammar::timescale_number, inner_action<
       TimeScaleNumberAction, 
       Storage::member<&TimeScaleView::number>
   >
   ,
  Grammar::timescale_unit, inner_action<
      TimeScaleUnitAction, 
      Storage::member<&TimeScaleView::unit>
  >
> {
  using state = TimeScaleView;
};

} // namespace SDF::Actions

#endif // SDF_ACTIONS_TIME_SCALE_HPP
