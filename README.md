
# azure_storage_c_sdk_lite

The azure_storage_c_sdk_lite is a lite version of azure storage sdk in C language, allows you to build applications against [Microsoft Azure Blob Storage](https://docs.microsoft.com/zh-cn/azure/storage/blobs/storage-blobs-introduction). 
This sdk can be used in the embedded equipment for azure storage operation.

## About how to set up

1. clone the project using Git:<br>
    git clone https://github.com/MS-CSE-GCR/azure_storage_c_sdk_lite.git<br>

2. build the SDK in release type:<br>

    cd Storage_blob_sdk_c_light  
    mkdir build  
    cd build  
    cmake .. -DCMAKE_BUILD_TYPE=Release  
    make  

3. run the sample code<br>

copy the libazure-storage.so to the /usr/lib  
    cd sample  
    make  
    ./run  

## Reference
https://github.com/Azure/azure-storage-fuse  
https://github.com/Azure/azure-storage-cpp  
https://curl.haxx.se/libcurl/


