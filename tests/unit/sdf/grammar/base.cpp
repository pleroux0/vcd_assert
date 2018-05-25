#include "./base.hpp"


using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;


TEST_CASE("SDF.Grammar.Base", "[SDF][Grammar][Base]") {

  SECTION("Blank Space") {

    //single
    CHECK(match_exactly<blank>(blank_1_str));
    CHECK(match_exactly<blank>(tab_1_str));
    CHECK(match_exactly<blank>(newline_1_str));

    //multi
    CHECK(match_exactly<plus_blank>(blank_2_str));
    CHECK(match_exactly<plus_blank>(blank_3_str));
    CHECK(match_exactly<plus_blank>(newline_2_str));
    CHECK(match_exactly<plus_blank>(newline_3_str));
    CHECK(match_exactly<plus_blank>(tab_2_str));
    CHECK(match_exactly<plus_blank>(tab_3_str));
  }

  SECTION("Comments") {
    CHECK(match_exactly<comment>(comment_line_str));
    CHECK(match_exactly<comment>(comment_block_str));
  }

  SECTION("Token Separators") {
    CHECK(match_exactly<sp>(comment_line_str));
    CHECK(match_exactly<sp>(comment_block_str));
    CHECK(match_exactly<sps>(comment_line_str));
    CHECK(match_exactly<sps>(comment_block_str));
    CHECK(match_exactly<sps>(fmt::format(" {}",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format(" {} ",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format("{} ",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format("{} {}",comment_block_str, comment_block_str)));

    //single
    CHECK(match_exactly<sp>(blank_1_str));
    CHECK(match_exactly<sp>(tab_1_str));
    CHECK(match_exactly<sp>(newline_1_str));

    //multi
    CHECK(match_exactly<sps>(blank_2_str));
    CHECK(match_exactly<sps>(blank_3_str));
    CHECK(match_exactly<sps>(newline_2_str));
    CHECK(match_exactly<sps>(newline_3_str));
    CHECK(match_exactly<sps>(tab_2_str));
    CHECK(match_exactly<sps>(tab_3_str));
  }

  SECTION("Decimals") {
    for(auto&& a : decimal_range_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<decimal_digit>(fmt::format("{}",a)));
      }
    }
  }

  SECTION("Alphanumeric Characters") {
    for(auto&& a : alphanumeric_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<alphanumeric>(fmt::format("{}",a)));
      }
    }
  }

  SECTION("Escaped Alphanumerics Characters") {
    for(auto&& a : escaped_alphanumeric_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<escaped_character>(fmt::format("{}",a)));
      }
    }
  }

  SECTION("Special Characters") {
    for(auto&& a : special_character_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<special_character>(fmt::format("{}",a)));
      }
    }
  }

  SECTION("Escaped Special Characters") {
    for(auto&& a : escaped_special_character_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<escaped_character>(fmt::format("{}",a)));
      }
    }
  }
  
  SECTION("Normal Characters") {
    for(auto&& a : character_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<character>(fmt::format("{}",a)));
      }
    }
  }

  SECTION("All Characters") {
    for(auto&& a : any_character_str){ 
      SECTION(fmt::format("Checking : {}",a)){
        CHECK(match_exactly<any_character>(fmt::format("{}",a)));
      }
    }
  }
  

  SECTION("Signs") {
    CHECK_FALSE(match_exactly<sign>(empty_str));
    CHECK(match_exactly<sign>(positive_sign_str));
    CHECK(match_exactly<sign>(negative_sign_str));
  }


  SECTION("Quoted Characters") {

    SECTION(fmt::format("Checking : \"\\\"")){
      CHECK_THROWS(match_exactly<qstring>(fmt::format(R"("\")")));
    }
    for(auto&& a : any_character_str){ 
      SECTION(fmt::format("Checking : \"{}\"",a)){
        CHECK(match_exactly<qstring>(fmt::format(R"("{}")",a)));
      }
    }
  }

  SECTION("Quoted Strings") {
    CHECK(match_exactly<qstring>(qstring_str));
    CHECK(match_exactly<qstring>(qstring_str_2));
    CHECK(match_exactly<qstring>(fmt::format(R"("4.0")")));
  }

  SECTION("General Identifier") {
    SECTION(fmt::format("Checking : {}",ident_str)){      
      CHECK(match_exactly<identifier>(fmt::format("{}",ident_str)));
    }
  }
  SECTION("Hierarchical Identifier") {
    using hi =  hierarchical_identifier;
    SECTION(fmt::format("Checking : {}",hident_str)){  
      CHECK(match_exactly<hi>(fmt::format("{}",hident_str)));
    }
  }
}

TEST_CASE("SDF.Grammar.Base.Extra", "[SDF][Grammar][Base][Extra]") {

  SECTION("Bracket Matching -- Correct Cases") {
    CHECK(match_exactly<bracket_pairs>(fmt::format("()")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("(())")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("( (()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("(( ()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((( )))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((() ))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((()) )")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((()) )")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("( ( ( ) ) )")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("()()")));     
    CHECK(match_exactly<bracket_pairs>(fmt::format("(()())")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("(())()")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("(())(())")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("((()()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("( (()()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("(( ()()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((( )()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((() ()))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((() ( )))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((() () ))")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("((() () ) )")));
    CHECK(match_exactly<bracket_pairs>(fmt::format("()()()")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("( )()()")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("() ()()")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("() () ()")));    
    CHECK(match_exactly<bracket_pairs>(fmt::format("( ) ( ) ( )")));   
  }

  SECTION("Bracket Matching -- Incorrect Cases (Unbalanced LHS)") {

    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("(()")));    
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("((())")));    
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("((()())")));    
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("(()(()())")));   
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("(()(()()())")));   
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("((((() () ) ))")));
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("((((((() () ) ))")));
    CHECK_FALSE(match_exactly<bracket_pair>(fmt::format("(()) (((((( ()() )))")));

    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("(()")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((())")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((()())")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("(()(()())")));   
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("(()(()()())")));   
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((((() () ) ))")));
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((((((() () ) ))")));
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("(()) (((((( ()() )))")));
  }
  SECTION("Bracket Matching -- Incorrect Cases (Unbalanced RHS)") { 
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("())")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("()())")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("(()()))")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("()()())")));    
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((() () ) ))")));
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((() () )) ))")));
    CHECK_FALSE(match_exactly<bracket_pairs>(fmt::format("((()) () ) ))")));
  }
}