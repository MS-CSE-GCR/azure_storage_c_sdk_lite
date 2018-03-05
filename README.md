
# azure_storage_c_sdk_lite

The azure_storage_c_sdk_lite is a lite version of azure storage sdk in C language, allows you to build applications against [Microsoft Azure Blob Storage](https://docs.microsoft.com/zh-cn/azure/storage/blobs/storage-blobs-introduction). 
This sdk can be used in the embedded equipment for azure storage operation.

## About how to set up

1. clone the project using Git:

```
    git clone --recursive https://github.com/MS-CSE-GCR/azure_storage_c_sdk_lite.git
```

2. install the libraries following:

```
    install cmake:
    sudo apt install cmake

    install curl:
    sudo apt-get install libcurl4-openssl-dev

    install GnuTLS：
    sudo apt-get install libgnutls28-dev

    install gcrypt:
    sudo apt-get install libgcrypt11-dev

    install fuse:
    sudo apt-get install libfuse-dev

    install openssl:
    sudo apt-get install libssl-dev
```

3. build the SDK in release type:

```
    cd Storage_blob_sdk_c_light
    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release
    make
```

4. run the sample code

    Copy the libazure-storage.so to the /usr/lib
    Check the file size:
```
    du -sh libazure-storage.so
```

    run the sample code:
```
    cd sample 
    make
    ./run 
```

## Reference
* https://github.com/Azure/azure-storage-fuse  
* https://github.com/Azure/azure-storage-cpp  
* https://curl.haxx.se/libcurl/


