cmake_minimum_required(VERSION 3.16)

project(TemperatureConverter VERSION 0.1 LANGUAGES CXX)

# Configurações do CMake
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar bibliotecas Qt necessárias
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Arquivos principais do projeto
set(PROJECT_SOURCES
    src/main.cpp
    src/temperatureconverter.cpp
    src/utilsfunctions.cpp
)

set(HEADER_FILES
    src/temperatureconverter.h
    src/utilsfunctions.h
)

set(UI_FILES
    src/mainwindow.ui
)

# Criação do executável
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TemperatureConverter
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${HEADER_FILES}
        ${UI_FILES}
    )
else()
    add_executable(TemperatureConverter
        ${PROJECT_SOURCES}
        ${HEADER_FILES}
        ${UI_FILES}
    )
endif()

# Vinculação das bibliotecas Qt
target_link_libraries(TemperatureConverter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Configurações específicas para iOS/macOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TemperatureConverter)
endif()

set_target_properties(TemperatureConverter PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Instalação
include(GNUInstallDirs)
install(TARGETS TemperatureConverter
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalização do executável no Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TemperatureConverter)
endif()
