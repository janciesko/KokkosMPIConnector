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

#include <Kokkos_Core.hpp>
//#include <mdspan/mdspan.hpp> /*TODO*/
#include <mpi.h>

#include <helpers.hpp>

namespace MPIConnector
{

template<typename T>
class SupportedTypes
{
    //support only these two for now
    static_assert(Is_mdspan<T>::value || Is_View<T>::const_value_type);
};

template<typename T>
 std::enable_if_t<Is_View<T>::value, int> 
 MPI_IRecv(T &view, int dest, int tag, MPI_Comm comm)
 {
    /*some code*/
    return 0;
}

template<typename T>
std::enable_if_t<!Is_View<T>::value, int> 
MPI_IRecv(T &view, int dest, int tag, MPI_Comm comm)
{
    /*some code*/
    return 0;
}

 template<typename T>
 std::enable_if_t<Is_View<T>::value, int> 
 MPI_Isend(T &view, int dest, int tag, MPI_Comm comm)
 {
    /*some code*/
    return 0;
}

template<typename T>
std::enable_if_t<!Is_View<T>::value, int> 
MPI_Isend(T &view, int dest, int tag, MPI_Comm comm)
{
     /*some code*/
    return 0;
}

 template<typename T>
 std::enable_if_t<Is_View<T>::value, int> 
 MPI_Send(T &view, int dest, int tag, MPI_Comm comm)
 {
    /*some code*/
    return 0;
}

template<typename T>
std::enable_if_t<!Is_View<T>::value, int> 
MPI_Send(T &view, int dest, int tag, MPI_Comm comm)
{
    /*some code*/
    return 0;
}

 template<typename T>
 std::enable_if_t<Is_View<T>::value, int> 
 MPI_Recv(T &view, int dest, int tag, MPI_Comm comm)
 {
    /*some code*/
    return 0;
}

template<typename T>
std::enable_if_t<!Is_View<T>::value, int> 
MPI_Recv(T &view, int dest, int tag, MPI_Comm comm)
{
     /*some code*/
    return 0;
}


} //namespace MPIConnector
