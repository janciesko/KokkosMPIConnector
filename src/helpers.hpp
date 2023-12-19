
//@HEADER
// ************************************************************************
//
//                        Kokkos v. 4.0
//       Copyright (2022) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Part of Kokkos, under the Apache License v2.0 with LLVM Exceptions.
// See https://kokkos.org/LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// Contact: Jan Ciesko (jciesko@sandia.gov)
//
//@HEADER

namespace MPIConnector {

template <class T> struct Is_View {
  enum : bool { value = Kokkos::is_view<T>::value };
};

template <class T> struct Is_mdspan {
  enum : bool {
    value = !Kokkos::is_view<T>::value /*TODO*/
  };
};

} // namespace MPIConnector