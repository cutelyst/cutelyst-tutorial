file(GLOB_RECURSE MyApp_SRCS *.cpp *.h)

set(MyApp_SRCS
    ${MyApp_SRCS}
    ${TEMPLATES_SRC}
)

# Create the application
add_library(MyApp SHARED ${MyApp_SRCS})

# Link to Cutelyst
target_link_libraries(MyApp
    Cutelyst::Core
    Cutelyst::StaticSimple
    Cutelyst::View::Grantlee
    Cutelyst::Utils::Sql
    Qt5::Core
    Qt5::Network
    Qt5::Sql
)

