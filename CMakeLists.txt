cmake_minimum_required(VERSION 3.5)
set(AZURE_STORAGE_HEADER
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_EXPORTS.h

  azure-storage-fuse/azure-storage-cpp-lite/include/base64.h
  azure-storage-fuse/azure-storage-cpp-lite/include/common.h
  azure-storage-fuse/azure-storage-cpp-lite/include/constants.h
  azure-storage-fuse/azure-storage-cpp-lite/include/constants.dat
  azure-storage-fuse/azure-storage-cpp-lite/include/executor.h
  azure-storage-fuse/azure-storage-cpp-lite/include/hash.h
  azure-storage-fuse/azure-storage-cpp-lite/include/retry.h
  azure-storage-fuse/azure-storage-cpp-lite/include/utility.h

  azure-storage-fuse/azure-storage-cpp-lite/include/tinyxml2.h
  azure-storage-fuse/azure-storage-cpp-lite/include/xml_parser_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/tinyxml2_parser.h
  azure-storage-fuse/azure-storage-cpp-lite/include/xml_writer.h

  azure-storage-fuse/azure-storage-cpp-lite/include/storage_account.h
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_credential.h
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_outcome.h
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_stream.h
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_url.h
  azure-storage-fuse/azure-storage-cpp-lite/include/storage_errno.h

  azure-storage-fuse/azure-storage-cpp-lite/include/storage_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_blob_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/put_blob_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/delete_blob_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/copy_blob_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/create_container_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/delete_container_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/list_containers_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/list_blobs_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_block_list_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/put_block_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_blob_property_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_container_property_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/put_block_list_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_container_property_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/append_block_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/put_page_request_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/get_page_ranges_request_base.h

  azure-storage-fuse/azure-storage-cpp-lite/include/http_base.h
  azure-storage-fuse/azure-storage-cpp-lite/include/http/libcurl_http_client.h

  azure_storage_c_sdk_blob_lite/include/blob/blob_client.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/download_blob_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/create_block_blob_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/delete_blob_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/copy_blob_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/create_container_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/delete_container_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/list_containers_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/list_blobs_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/get_blob_property_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/get_container_property_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/get_block_list_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/put_block_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/put_block_list_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/append_block_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/put_page_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/blob/get_page_ranges_request.h

  azure-storage-fuse/azure-storage-cpp-lite/include/todo/get_blob_metadata_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/todo/get_blob_properties_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/todo/query_entities_request.h
  azure-storage-fuse/azure-storage-cpp-lite/include/todo/set_blob_metadata_request.h
)

set(AZURE_STORAGE_SOURCE
  azure-storage-fuse/azure-storage-cpp-lite/src/base64.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/constants.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/hash.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/utility.cpp

  azure-storage-fuse/azure-storage-cpp-lite/src/tinyxml2.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/tinyxml2_parser.cpp

  azure-storage-fuse/azure-storage-cpp-lite/src/storage_account.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/storage_credential.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/storage_url.cpp

  azure-storage-fuse/azure-storage-cpp-lite/src/get_blob_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/put_blob_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/delete_blob_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/copy_blob_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/create_container_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/delete_container_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/list_containers_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/list_blobs_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/get_blob_property_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/get_block_list_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/get_container_property_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/put_block_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/put_block_list_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/append_block_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/put_page_request_base.cpp
  azure-storage-fuse/azure-storage-cpp-lite/src/get_page_ranges_request_base.cpp

  azure-storage-fuse/azure-storage-cpp-lite/src/http/libcurl_http_client.cpp

  azure_storage_c_sdk_blob_lite/blob/blob_client.cpp
  azure_storage_c_sdk_blob_lite/blob/blob_client_wrapper.cpp
)

if(MSVC)
  add_definitions(-DNOMINMAX)
  include_directories(${CMAKE_SOURCE_DIR}/azure_storage_c_sdk_blob_lite/include ${CMAKE_SOURCE_DIR}/azure-storage-fuse/azure-storage-cpp-lite/include  
${CMAKE_CURRENT_SOURCE_DIR}/../local/include)
  link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../local/lib)
else(MSVC)
  find_package(Threads REQUIRED)
  find_package(CURL REQUIRED)
  find_package(OpenSSL REQUIRED)
  add_definitions(-std=c++11)
  set(WARNING "-Wall -Wextra -Werror -pedantic -pedantic-errors")
  set(CMAKE_CXX_FLAGS "${CMAKE_THREAD_LIBS_INIT} ${WARNING} ${CMAKE_CXX_FLAGS}")
  include_directories(${CMAKE_SOURCE_DIR}/azure_storage_c_sdk_blob_lite/include ${CMAKE_SOURCE_DIR}/azure-storage-fuse/azure-storage-cpp-lite/include ${CURL_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
endif(MSVC)

set(CMAKE_MACOSX_RPATH ON)
add_library(azure-storage SHARED ${AZURE_STORAGE_HEADER} ${AZURE_STORAGE_SOURCE})

if(MSVC)
  target_link_libraries(azure-storage bcrypt libcurl)
else(MSVC)
  target_link_libraries(azure-storage ${CURL_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY})
endif(MSVC)
