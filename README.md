# KokkosMPIConnector

This project implements the Kokkos MPI Connector.

## Building

Example:
cmake .. -DKMC_ENABLE_TESTS=Off -DKokkos_ROOT=${PATH_TO_KOKKOS_INSTALL} -DMDSPAN_ROOT=${PATH_TO_MDSPAN_INSTALL} -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_EXTENSIONS=Off
