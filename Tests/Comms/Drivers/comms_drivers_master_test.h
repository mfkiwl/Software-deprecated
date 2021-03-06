/*! \brief Do not include this file in external modules.
    \file comms_drivers_master_test.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 15:53:23 CDT 2014

    \brief This file is part of Tests Comms/Divers module.
    \brief This file become from: Tests/Comms/Drivers/comms_drivers_master_test.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <a class="el" href="http://proyecto-ciaa.com.ar">
      This file is part of CIAA Project.
      ==================================
    </a>

    Copyright (C) 2014 $(Entidad que patenta)

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

#include <cstdio>

#include <QtCore/QThread>

#include <Code/Comms/Drivers/ciaa_drivers_facade.h>

using namespace ciaa::comms::drivers;

const std::int32_t kDataBufferSize{256};
const std::int32_t kIters{10};
class CommsDriversMaster : public QThread {
 public:
  CommsDriversMaster(const std::string host, std::uint16_t port);
  explicit  CommsDriversMaster(std::string device);
  ~CommsDriversMaster();

  CommsDriversMaster(const CommsDriversMaster&) = delete;
  CommsDriversMaster& operator=(const CommsDriversMaster&) = delete;

  CommsDriversMaster(const CommsDriversMaster&&) = delete;
  CommsDriversMaster& operator=(const CommsDriversMaster&&) = delete;

  bool is_correct() {
    return correct_;
  }

 protected:
  void run() override;

 private:
  ciaaDriversFacade *dev_;
  std::string host_;
  std::uint16_t port_{0};
  std::string serial_device_name_;
  bool correct_;
};
