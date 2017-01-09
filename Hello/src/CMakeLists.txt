file(GLOB_RECURSE Hello_SRCS *.cpp *.h)

set(Hello_SRCS
    ${Hello_SRCS}
    ${TEMPLATES_SRC}
)

# Create the application
add_library(Hello SHARED ${Hello_SRCS})

# Link to Cutelyst
target_link_libraries(Hello
    Cutelyst::Core
    Cutelyst::StaticSimple
    Cutelyst::View::Grantlee
    Qt5::Core
    Qt5::Network
)

