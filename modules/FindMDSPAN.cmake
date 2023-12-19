find_path(KMC_MDSPANHDRS mdspan/mdspan.hpp PATHS ${MDSPAN_ROOT}/include/ NO_DEFAULT_PATHS)

find_package_handle_standard_args(MDSPAN DEFAULT_MSG KMC_MDSPANHDRS)

if (KMC_MDSPANHDRS)
    add_library(MDSPAN INTERFACE)
    set_target_properties(MDSPAN PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${KMC_MDSPANHDRS}
  )
endif()