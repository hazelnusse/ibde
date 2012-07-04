add_definitions(${QT_DEFINITIONS})

set(ibde_sources ${IBDE_SOURCE_DIR}/src/main.cc 
                 ${IBDE_SOURCE_DIR}/src/mainwindow.cc
                 ${IBDE_SOURCE_DIR}/src/gyrostatparameterform.cc
                 ${IBDE_SOURCE_DIR}/src/meijaardparameterform.cc
                 ${IBDE_SOURCE_DIR}/src/vtkisosurfacewidget.cc
                 ${IBDE_SOURCE_DIR}/src/vtkHolonomicConstraint.cc
                 ${IBDE_SOURCE_DIR}/src/parameterwidget.cc)

# These headers will be moc'd
set(ibde_qt_headers ${IBDE_SOURCE_DIR}/inc/parameterwidget.h
                    ${IBDE_SOURCE_DIR}/inc/gyrostatparameterform.h
                    ${IBDE_SOURCE_DIR}/inc/meijaardparameterform.h
                    ${IBDE_SOURCE_DIR}/inc/vtkisosurfacewidget.h
                    ${IBDE_SOURCE_DIR}/inc/mainwindow.h )

qt4_wrap_cpp(ibde_qt_headers_moc ${ibde_qt_headers})

add_executable(ibde ${ibde_sources}
                    ${ibde_qt_headers_moc})

target_link_libraries(ibde QVTK ${QT_LIBRARIES})

add_executable(configurationSurface
               testConfigurationSurface.cc
               vtkHolonomicConstraint.cc)

#target_link_libraries(configurationSurface ${VTK_LIBRARIES})
target_link_libraries(configurationSurface QVTK vtkHybrid)
