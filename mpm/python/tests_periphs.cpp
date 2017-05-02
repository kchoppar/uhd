//
// Copyright 2017 Ettus Research (National Instruments)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include "tests_periphs.hpp"
#include <mpm/tests/tests_spi_iface.hpp>
#include <mpm/spi_iface.hpp>
#include <boost/python.hpp>

namespace bp = boost::python;

void export_tests(){
    //Register submodule types
    bp::object tests_module(bp::handle<>(bp::borrowed(PyImport_AddModule("libpyusrp_periphs.tests"))));
    bp::scope().attr("tests") = tests_module;
    bp::scope io_scope = tests_module;

    bp::class_<mpm::tests_spi_iface, bp::bases<mpm::spi_iface>, boost::shared_ptr<mpm::tests_spi_iface> >("test_spi_iface", bp::init<>())
        .def("make", &mpm::tests_spi_iface::make)
        .staticmethod("make")
        ;
}