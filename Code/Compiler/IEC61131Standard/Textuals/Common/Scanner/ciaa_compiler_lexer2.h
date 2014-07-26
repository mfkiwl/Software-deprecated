/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_lexer.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jul 17 21:44:46 UTC 2014

    \attention <h1><center><strong>&copy;COPYRIGHT 2014 </strong>[<strong>ACSE</strong>]
               [ACSE-URL] & [<strong>CADIEEL</strong>][CADIEEL-URL]</center></h1>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    \brief This file is part of [<strong>CIAA Project</strong>][proyecto-ciaa-URL]
    \brief , especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler module.\n
    \brief This file become from: Code/Compiler/IEC61131Standard/Scanner/ciaa_compiler_lexer.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef COMPILER_IEC_LEXER_H
#define COMPILER_IEC_LEXER_H

////////////////////////////////////////////////////////////////////////////////
// Spirit v2.5 allows you to suppress automatic generation
// of predefined terminals to speed up complation. With
// BOOST_SPIRIT_NO_PREDEFINED_TERMINALS defined, you are
// responsible in creating instances of the terminals that
// you need (e.g. see qi::uint_type uint_ below).
#define BOOST_SPIRIT_NO_PREDEFINED_TERMINALS
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Uncomment this if you want to enable debugging
// #define BOOST_SPIRIT_QI_DEBUG
////////////////////////////////////////////////////////////////////////////////

#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/lex_lexertl_position_token.hpp>
#include <boost/mpl/vector.hpp>

#include "Code/Compiler/IEC61131Standard/Textuals/Common/Scanner/ciaa_compiler_symbol_info.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Common/AST.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {

namespace lex = boost::spirit::lex;



///////////////////////////////////////////////////////////////////////////
namespace detail
{
    template <typename BaseIterator>
    struct get_lexer_type
    {
        // Our token needs to be able to carry several token values:
        // std::string, unsigned int, and bool
        typedef boost::mpl::vector<std::string>
            token_value_types;

        // Using the position_token class as the token type to be returned
        // from the lexer iterators allows to retain positional information
        // as every token instance stores an iterator pair pointing to the
        // matched input sequence.
        typedef lex::lexertl::position_token<
            BaseIterator, token_value_types, boost::mpl::false_
        > token_type;

//#if CONJURE_LEXER_DYNAMIC_TABLES != 0
        // use the lexer based on runtime generated DFA tables
        typedef lex::lexertl::actor_lexer<token_type> type;
/*#elif CONJURE_LEXER_STATIC_TABLES != 0
        // use the lexer based on pre-generated static DFA tables
        typedef lex::lexertl::static_actor_lexer<
            token_type
          , boost::spirit::lex::lexertl::static_::lexer_conjure_static
        > type;
#elif CONJURE_LEXER_STATIC_SWITCH != 0
        // use the lexer based on pre-generated static code
        typedef lex::lexertl::static_actor_lexer<
            token_type
          , boost::spirit::lex::lexertl::static_::lexer_conjure_static_switch
        > type;
#else
#error "Configuration problem: please select exactly one type of lexer to build"
#endif*/
    };
}

//enum tk_id_ {
//  LETTER,
//  LINE_JUMP,
//  TYPE,
//  BINARY_INTEGER,
//  OCTAL_INTEGER,
//  HEX_INTEGER,
//  REAL_LITERAL,
//  REAL_RW,
//  LREAL_RW,
//  COMMON_TYPE_LIT,
//  COMMON_TYPE_END_LIT,
//  COMMON_COLON,
//  COMMON_DOCOLON
//};

///*! \brief The ciaaLexer class provide a tocken flow.
// * \brief The ciaaLexer class take a flow of characters and transorm
// * \brief it in a tocken flow.
// * \ingroup CompilerIL
// */
//template <typename Lexer>
//struct ciaaLexer : lex::lexer<Lexer> {
//  ciaaLexer()
//      , _comment{R"***(coment)***"}
//      , _line_jump{R"***(\n)***"}
//      , _real_rw{R"***(REAL)***"}
//      , _lreal_rw{R"***(LREAL)***"}
//      , _common_type_lit {R"***(TYPE)***"}
//      , _common_type_end_lit {R"***(TYPE_END)***"}
//      , _common_colon_lit{R"***(;)***"}
//      , _common_docolon_lit{R"***(:)***"} {
//    this->self.add
//      (_identifier, static_cast<std::size_t>(tk_id_::IDENTIFIER))
//      (_line_jump, static_cast<std::size_t>(tk_id_::LINE_JUMP))
//      (_binary_integer, static_cast<std::size_t>(tk_id_::BINARY_INTEGER))
//      (_octal_integer, static_cast<std::size_t>(tk_id_::OCTAL_INTEGER))
//      (_hex_integer, static_cast<std::size_t>(tk_id_::HEX_INTEGER))
//      (_real_literal, static_cast<std::size_t>(tk_id_::REAL_LITERAL))
//      (_real_rw, static_cast<std::size_t>(tk_id_::REAL_RW))
//      (_lreal_rw, static_cast<std::size_t>(tk_id_::LREAL_RW))
//      (_common_type_lit, static_cast<std::size_t>(tk_id_::COMMON_TYPE_LIT))
//      (_common_type_end_lit, static_cast<std::size_t>(tk_id_::COMMON_TYPE_END_LIT))
//      (_common_colon_lit, static_cast<std::size_t>(tk_id_::COMMON_COLON))
//      (_common_docolon_lit, static_cast<std::size_t>(tk_id_::COMMON_DOCOLON));


//      this->self += _comment [lex::_pass = lex::pass_flags::pass_ignore];
//  }
//  ~ciaaLexer() = default;

//  ciaaLexer(const ciaaLexer&) = delete;
//  ciaaLexer& operator=(const ciaaLexer&) = delete;

//  ciaaLexer(const ciaaLexer&&) = delete;
//  ciaaLexer& operator=(const ciaaLexer&&) = delete;

//  lex::token_def<char> _comment;
//  lex::token_def<char> _line_jump;
//  lex::token_def<std::string> _binary_integer;
//  lex::token_def<std::string> _octal_integer;
//  lex::token_def<std::string> _hex_integer;
//  lex::token_def<double> _real_literal;
//  lex::token_def<std::string> _real_rw;
//  lex::token_def<std::string> _lreal_rw;
//  lex::token_def<std::string> _common_type_lit;
//  lex::token_def<std::string> _common_type_end_lit;
//  lex::token_def<char> _common_colon_lit;
//  lex::token_def<char> _common_docolon_lit;
//};

/*! \brief The ciaaLexer class provide a tocken flow.
 * \brief The ciaaLexer class take a flow of characters and transorm
 * \brief it in a tocken flow.
 * \ingroup CompilerIL
 */
template <typename BaseIterator>
struct ciaaLexer : lex::lexer<typename detail::get_lexer_type<BaseIterator>::type> {
  ciaaLexer()
      : _space{R"***( )***"}
      , _comment{R"***(coment)***"}
      , _identifier{R"***(_(([A-Za-z])|(_([A-Za-z]|[0-9])))(_?([A-Za-z]|[0-9]))*)***"} //FIXME(denisacostaq\@gmail.com) ponerle precedencia a los tokens para que las palabras reservadas no choquen con los identificacadores
      , _signed_integer_type_sint{R"***(SINT)***"}
      , _signed_integer_type_int{R"***(INT)***"}
      , _signed_integer_type_dint{R"***(DINT)***"}
      , _signed_integer_type_lint{R"***(LINT)***"}
      , _unsigned_integer_type_usint{R"***(USINT)***"}
      , _unsigned_integer_type_uint{R"***(UINT)***"}
      , _unsigned_integer_type_udint{R"***(UDINT)***"}
      , _unsigned_integer_type_ulint{R"***(ULINT)***"}
      , _integer{R"***(\d(_?\d)*)***"}
      , _binary_integer{R"***(2#[01](_?[01])*)***"}
      , _octal_integer{R"***(8#[1-8](_?[1-8])*)***"}
      , _hex_integer{R"***(16#[0-9A-Fa-f](_?[0-9A-Fa-f])*)***"}
      , _eol{R"***(\n)***"}  //FIXME(denisacostaq\@gmail.com): EOL != \n


      , _real_literal{R"***((("REAL"|"LREAL")#)?([\+\-])?[0-9](_?[0-9])*\.([0-9])(_?[0-9])*([eE]([\+\-])?[0-9](_?[0-9])*)?)***"}

  {
    lex::_pass_type _pass;

    using tk_id = ciaa::compiler::iec61131_3::text::ciaaSymbolInfo::tk_kind;
    this->self.add
        (_identifier, static_cast<int>(tk_id::identifier))
        (_signed_integer_type_sint, static_cast<int>(tk_id::signed_integer_type_sint))
        (_signed_integer_type_int, static_cast<int>(tk_id::signed_integer_type_int))
        (_signed_integer_type_dint, static_cast<int>(tk_id::signed_integer_type_dint))
        (_signed_integer_type_lint, static_cast<int>(tk_id::signed_integer_type_lint))
        (_unsigned_integer_type_usint, static_cast<int>(tk_id::unsigned_integer_type_usint))
        (_unsigned_integer_type_uint, static_cast<int>(tk_id::unsigned_integer_type_uint))
        (_unsigned_integer_type_udint, static_cast<int>(tk_id::unsigned_integer_type_udint))
        (_unsigned_integer_type_ulint, static_cast<int>(tk_id::unsigned_integer_type_ulint))
        (_integer, static_cast<int>(tk_id::integer))
        (_binary_integer, static_cast<int>(tk_id::binary_integer))
        (_octal_integer, static_cast<int>(tk_id::octal_integer))
        (_hex_integer, static_cast<int>(tk_id::hex_integer))
        (_real_literal, static_cast<int>(tk_id::real_literal))
        (_eol, static_cast<int>(tk_id::eol));

    this->self += _space [_pass = lex::pass_flags::pass_ignore];
    this->self += _comment [_pass = lex::pass_flags::pass_ignore];
  }

  lex::token_def<std::string> _space;
  lex::token_def<std::string> _comment;

  lex::token_def<std::string> _identifier;

  lex::token_def<std::string> _signed_integer_type_sint;
  lex::token_def<std::string> _signed_integer_type_int;
  lex::token_def<std::string> _signed_integer_type_dint;
  lex::token_def<std::string> _signed_integer_type_lint;
  lex::token_def<std::string> _unsigned_integer_type_usint;
  lex::token_def<std::string> _unsigned_integer_type_uint;
  lex::token_def<std::string> _unsigned_integer_type_udint;
  lex::token_def<std::string> _unsigned_integer_type_ulint;

  lex::token_def<std::string> _integer;
  lex::token_def<std::string> _binary_integer;
  lex::token_def<std::string> _octal_integer;
  lex::token_def<std::string> _hex_integer;

  lex::token_def<std::string> _eol;


  lex::token_def<std::string> _real_literal;
};

//typedef ciaaLexer<lex::lexertl::actor_lexer<>> Scanner;
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespace ciaa
#endif   // COMPILER_IEC_LEXER_H
