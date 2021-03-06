/*! \file ciaaLInput_View.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is TODO: see ciaaDriversSerialPort
    \brief This file become from: CIAA_v1_0/Coder/Ladder/Elements/ciaaLInput_View.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>This file is part of CIAA project (Computadora Industrial Argentina Abierta).</h3>
    Copyright (C) 2014 Ezequiel Esposito <ejesposito\@debtech.com.ar>

    This software is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef CIAALINPUT_VIEW_H
#define CIAALINPUT_VIEW_H

#include "ciaaLContact_View.h"

/*! \brief TODO: in one line description. see ciaaDriversSerialPort
 * \brief The ciaaLInput_View class TODO: document here. see ciaaDriversSerialPort
 * \ingroup TODO: see
 */
class ciaaLInput_View : public ciaaLContact_View
{
    public:
        ciaaLInput_View();


    private:
        DISALLOW_COPY_AND_ASSIGN(ciaaLInput_View);
};

#endif // CIAALINPUT_VIEW_H
