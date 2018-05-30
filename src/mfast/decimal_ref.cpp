// Copyright (c) 2013, 2014, Huang-Ming Huang,  Object Computing, Inc.
// All rights reserved.
//
// This file is part of mFAST.
//
//     mFAST is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     mFAST is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with mFast.  If not, see <http://www.gnu.org/licenses/>.
//


#include <cmath>
#include <cfloat>

#include <iostream>

#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

template class boost::multiprecision::backends::cpp_dec_float<18>;

#if BOOST_VERSION >= 106200

#include <boost/functional/hash.hpp>

#if defined(_MSC_VER) 
#pragma warning(disable: 4667)  //  no function template defined that matches forced instantiation
#else
// This doesn't work in MSVC, but apparently it isn't needed.
template void boost::hash_combine<boost::multiprecision::backends::cpp_dec_float<18u, int, void>::enum_fpclass_type>(unsigned long&, boost::multiprecision::backends::cpp_dec_float<18u, int, void>::enum_fpclass_type const&);
#endif
template void boost::hash_combine<bool>(unsigned long&, bool const&);
template void boost::hash_combine<int>(unsigned long&, int const&);
template void boost::hash_combine<unsigned int>(unsigned long&, unsigned int const&);
#endif