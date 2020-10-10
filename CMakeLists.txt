cmake_minimum_required(VERSION 3.17)
project(ContactInfo)

find_package(lcm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ContactInfo main.cpp lcmt_contact_results_for_viz.hpp lcmt_hydroelastic_contact_surface_for_viz.hpp
        lcmt_point_pair_contact_info_for_viz.hpp lcmt_hydroelastic_contact_surface_tri_for_viz.hpp
        lcmt_hydroelastic_quadrature_per_point_data_for_viz.hpp)

target_link_libraries(ContactInfo PRIVATE ${LCM_NAMESPACE}lcm)
