project(map_tests)

add_definitions("-DOMIM_UNIT_TEST_WITH_QT_EVENT_LOOP")

set(
  SRC
  address_tests.cpp
  booking_availability_cache_test.cpp
  booking_filter_test.cpp
  bookmarks_test.cpp
  chart_generator_tests.cpp
  cloud_tests.cpp
  countries_names_tests.cpp
  extrapolator_tests.cpp
  feature_getters_tests.cpp
  framework_light_tests.cpp
  ge0_parser_tests.cpp
  geourl_test.cpp
  gps_track_collection_test.cpp
  gps_track_storage_test.cpp
  gps_track_test.cpp
  kmz_unarchive_test.cpp
  mwm_url_tests.cpp
  notification_tests.cpp
  power_manager_tests.cpp
  search_api_tests.cpp
  tips_tests.cpp
  transliteration_test.cpp
  working_time_tests.cpp
)

omim_add_test(${PROJECT_NAME} ${SRC})

omim_link_libraries(
  ${PROJECT_NAME}
  platform_tests_support
  metrics_tests_support
  search_tests_support
  editor_tests_support
  generator_tests_support
  generator
  map
  drape_frontend
  shaders
  drape
  routing
  traffic
  transit
  tracking
  routing_common
  search
  storage
  metrics
  mwm_diff
  bsdiff
  descriptions
  ugc
  partners_api
  local_ads
  kml
  editor
  indexer
  platform
  geometry
  coding
  base

  agg
  expat
  freetype
  icu
  jansson
  minizip
  oauthcpp
  opening_hours
  protobuf
  pugixml
  sdf_image
  stb_image
  succinct
  tess2
  stats_client
  vulkan_wrapper
  ${Qt5Widgets_LIBRARIES}
  ${Qt5Network_LIBRARIES}
  ${LIBZ}
)

if (PLATFORM_LINUX)
  omim_link_libraries(
    ${PROJECT_NAME}
    dl
  )
endif()

link_opengl(${PROJECT_NAME})
link_qt5_core(${PROJECT_NAME})
