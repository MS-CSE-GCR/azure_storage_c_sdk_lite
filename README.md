
# Storage_blob_sdk_c_light

This is a light version of azure storage sdk in C language. Only include the blob storage function.  
This SDK is light and can be used in the light device.  
The http request is based on the libcurl library.  

# About how to set up

1、 clone the project using Git:

2、 build the SDK in release type:

cd Storage_blob_sdk_c_light  
mkdir build  
cd build  
cmake .. -DCMAKE_BUILD_TYPE=Release  
make  

3 run the sample code

copy the libazure-storage.so to the /usr/lib  
cd sample  
make  
./run  

# Reference
https://github.com/Azure/azure-storage-fuse  
https://github.com/Azure/azure-storage-cpp  
https://curl.haxx.se/libcurl/


