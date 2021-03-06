#include "./values.hpp"



void SDF::Test::catch_test_triple(SDF::Triple wanted, SDF::Triple test)
{

  SECTION("SDF Triple"){
    
    if(test.min.has_value()){
      REQUIRE(wanted.min.has_value()); 
      REQUIRE(test.min.value() == Approx(wanted.min.value())); 
    }
      
    if(test.typ.has_value()){
      REQUIRE(wanted.typ.has_value()); 
      REQUIRE(test.typ.value() == Approx(wanted.typ.value())); 
    }
      
    if(test.max.has_value()){
      REQUIRE(wanted.max.has_value()); 
      REQUIRE(test.max.value() == Approx(wanted.max.value())); 
    }

  }
}