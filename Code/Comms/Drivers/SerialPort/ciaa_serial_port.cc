/*! \brief This file gives a ciaaSerialPort functionality.
    \file ciaa_serial_port.cc
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is for the ethernet communication in the Comms module.
    \brief This file become from: Comms/Drivers/SerialPort/ciaa_serial_port.cc

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>
      This file is part of
      <a class="el" href="http://proyecto-ciaa.com.ar">
        <h3>
          CIAA project (Computadora Industrial Argentina Abierta).
        </h3>
      </a>
    </h3>
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
 

#include "Comms/Drivers/SerialPort/ciaa_serial_port.h"
ciaaSerialPort::ciaaSerialPort(std::string device)
  : serial_{new ciaaQSerialPortAdapter{device}}
{
}

ciaaSerialPort::~ciaaSerialPort()
{
  delete serial_;
}