
#include <string>
#include <chrono>
#include <thread>
#include <assert.h>

#include "storage_credential.h"
#include "storage_account.h"
#include "blob/blob_client.h"


using namespace microsoft_azure::storage;

void checkstatus()
{
    if(errno == 0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Fail\n");
    }
}

int main()
{
    //---------account name& account key-----------------
    std::string account_name = "testzwj";
    //std::string account_key = "vaDY8xu+u0iqSZBcdsNwjAULSFXLaFd7LXT3sV8PsFPI4cla7y1k026KNqve401OuRGTosO5q4z/sm2oodTYRg==";

    //---------shared access signature-------------------
    std::string m_sas_token = "sv=2017-04-17&sig=ABJdLYXhtXeJu8sxB4jXaPjuPoke11opVP1Q%2FJ3GvwE%3D&spr=https&se=2018-03-06T03%3A14%3A19Z&srt=co&ss=b&sp=racupwdl";

    //----------------become credential------------------
    std::shared_ptr<storage_credential>  cred = std::make_shared<shared_access_signature_credential>(m_sas_token);
    //std::shared_ptr<storage_credential>  cred = std::make_shared<shared_key_credential>(account_name, account_key);
    std::shared_ptr<storage_account> account = std::make_shared<storage_account>(account_name, cred, true);
    auto bC = std::make_shared<blob_client>(account, 10);
    
    //------------------parameters-----------------------
    std::string containerName = "containertest";
    std::string blobName = "blob";
    std::string destContainerName = "containertest";
    std::string destBlobName = "blob.copy";
    std::string uploadFileName = "../../test1.txt";
    std::string downloadFileName = "../../download.txt";
    std::string appendblobName = "appendblob";
    std::string appendFileName1 = "../../test1.ts";
    std::string appendFileName2 = "../../test2.ts";
    std::string appenddownloadFile = "../../appendownload.ts";
    
    //--------------Container exist----------------------
    bool exists = true;
    blob_client_wrapper bc(bC);
    std::string << "Test container exist or not: " << std::endl;
    exists = bc.container_exists(containerName);
    
    //--------------Create Container---------------------
    if(!exists)
    {
        std::string << "Container " << containerName << "is not exist." << std::endl;
        std::string << "Become create container: " << containerName << std::endl;
        bc.create_container(containerName);
        assert(errno == 0);
        std::string << "Create Container " << containerName << " done." << std::endl;
    }
    
    //-------------upload file to blob-------------------
    std::cout <<"Start upload Blob: " << blobName << std::endl;
    bc.upload_file_to_blob(appendFileName1, containerName, blobName);
    std::cout << "Create Blob " << blobName << " done." << std::endl;

    //-------------Blob exist---------------------------
    exists = bc.blob_exists(containerName, blobName);
    if(exists) {
        std::cout << "Blob " << blobName << "exist." << std::endl;
    }
    else {
        std::cout << "Blob " << blobName << "is not exist." <<std:endl;
    }

    //-------------get blob property---------------------
    std::cout << "Start get blob property" << std::endl;
    auto blobProperty = bc.get_blob_property(containerName, blobName);
    assert(errno == 0);
    std::cout <<"Content type of BLob: " << blobProperty.content_type << std::endl;
    std::cout <<"Size of BLob: " << blobProperty.size << std::endl;
    
    //-------------list blobs---------------------------
    auto blobs = bc.list_blobs_hierarchical(containerName, "/", "", "");
    std::cout <<"Size of BLobs: " << blobs.size() << std::endl;
    
    //--------------download blob to file----------------
    bc.download_blob_to_file(containerName, blobName, downloadFileName);
    std::cout << "Download Blob " << blobName << "done." << std::endl;
    assert(errno == 0);

    //------------------copy blob-----------------------
    bc.start_copy(containerName, blobName, destContainerName, destBlobName);
    auto property = bc.get_blob_property(destContainerName, destBlobName);
    std::cout << "Copy status: " << property.copy_status <<std::endl;
    exists = bc.blob_exists(destContainerName, destBlobName);
    assert(errno == 0);
    
    //assert(exists);
    /*
    //---------------delete blob----------------------
    bc.delete_blob(containerName, blobName);
    bc.delete_blob(destContainerName, destBlobName);
    assert(errno == 0);
    exists = bc.blob_exists(containerName, blobName);
    assert(errno == 0);
    assert(!exists);
    */

    //------------------Append blob------------------
    exists = bc.blob_exists(containerName, appendblobName);
        if(exists) {
        std::cout << "Blob " << appendblobName << "exist." << std::endl;
    }
    else {
        std::cout << "Blob " << appendblobName << "is not exist." <<std:endl;
    }
    //------------create an append blob--------------
    if(!exists) {
        std::cout << "Start create the append blob." << std::endl;
        bc.create_append(containerName, appendblobName);
    }
    blobProperty = bc.get_blob_property(containerName, appendblobName);
    assert(errno == 0);
    std::cout <<"Content type of BLob: " << blobProperty.content_type << std::endl;

    //-------------append block to blobs--------------
    std::cout << "start append file" << std::endl;
    bc.append_file_to_blob(appendFileName1, containerName, appendblobName);
    bc.append_file_to_blob(appendFileName2, containerName, appendblobName);
    std::cout << "end append file" << std::endl;

    //-----------download append blob------------------
    std::cout << "Start download appendblob file." << std::endl;
    bc.download_blob_to_file(containerName, appendblobName, appenddownloadFile);
    std::cout <<"Download Blob " << appendblobName << " done: " << std::endl;
    assert(errno == 0);
    
    //-----------delete container----------------------
    //bc.delete_container(containerName);
    //assert(errno == 0);
    //std::this_thread::sleep_for(std::chrono::seconds(5));


}
