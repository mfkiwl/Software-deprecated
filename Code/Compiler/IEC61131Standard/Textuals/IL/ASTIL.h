#ifndef COMPILER_IEC_IL_ASTIL_H
#define COMPILER_IEC_IL_ASTIL_H
/*! \brief Do not include this file directly in external modules.
    \file ASTIL.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 21 15:24:08 UTC 2014

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
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler/IL module.\n
    \brief This file become from: Code/Compiler/IEC61131Standard/IL/ASTIL.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#include <cinttypes>

#include <list>

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant.hpp>
#include <boost/optional.hpp>

#include "Code/Compiler/IEC61131Standard/Textuals/Common/AST.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {
/*
 *     typedef boost::variant<
            nil
          , unsigned int
          , variable
          , boost::recursive_wrapper<signed_>
          , boost::recursive_wrapper<expression>
        >
    operand;
 */
//struct VarType {
//  std::uint8_t _type;
//};

//struct VarDcl {
//  VarType _var_type;
//};

//struct ASTIL {
//  VarDcl _var_dcl;
//};


struct label {
//  ciaa::compiler::identifier _identifier;
  std::string _identifier;
//  std::uint8_t _list_position;
};

struct il_operand {
  std::string _operand;
};

struct il_expr_operator {
  std::string _exp;
};

struct il_simple_operator{
  using simple_operator_type = boost::variant<il_expr_operator, std::string>;
  simple_operator_type op;
};

struct il_simple_operation {
  // FIXME(denisacostaq/@gmail.com): primero que todo chequear esto sobre la estrcuctura de datos
  typedef struct {
    il_simple_operator _operator;
    boost::optional<il_operand> _operand;
  }variant1;
  typedef struct {
    char s;
  } variant2;
  using variants = boost::variant<variant1, variant2>;
  variants  data;
};

struct il_expression {
};

struct il_jump_operation {
};

struct il_fb_call {
};

struct il_formal_funct_call {
};

struct il_return_operator {
};

using il_instruction =  boost::variant<il_simple_operation::variant1,
                                       il_expression,
                                       il_jump_operation,
                                       il_fb_call,
                                       il_formal_funct_call,
                                       il_return_operator>;

struct instruction_list {
  std::list<il_instruction> il;
};

}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespace ciaa

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::instruction_list,
    (std::list<ciaa::compiler::iec61131_3::text::il::il_instruction>, il)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::label,
    (std::string, _identifier)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_operand,
    (std::string, _operand)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_simple_operation,
    (ciaa::compiler::iec61131_3::text::il::il_simple_operation::variants , data)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_simple_operation::variant1,
    (ciaa::compiler::iec61131_3::text::il::il_simple_operator, _operator)
    (boost::optional<ciaa::compiler::iec61131_3::text::il::il_operand>, _operand)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_simple_operation::variant2,
    (char, s)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_simple_operator,
    (ciaa::compiler::iec61131_3::text::il::il_simple_operator::simple_operator_type, op)
)

BOOST_FUSION_ADAPT_STRUCT(
  ciaa::compiler::iec61131_3::text::il::il_expr_operator,
    (std::string, _exp)
)

//BOOST_FUSION_ADAPT_STRUCT(
//    ciaa::compiler::il::VarType,
//    (std::uint8_t, _type)
//)

//BOOST_FUSION_ADAPT_STRUCT(
//    ciaa::compiler::il::VarDcl,
//    (ciaa::compiler::il::VarType, _var_type)
//)

//BOOST_FUSION_ADAPT_STRUCT(
//    ciaa::compiler::il::ASTIL,
//    (ciaa::compiler::il::VarDcl, _var_dcl)
//)

#endif  // COMPILER_IEC_IL_ASTIL_H