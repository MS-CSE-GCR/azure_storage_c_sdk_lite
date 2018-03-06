
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
    //std::string account_key = "";

    //---------shared access signature-------------------
    std::string m_sas_token = "";

    //----------------become credential------------------
    std::shared_ptr<storage_credential>  cred = std::make_shared<shared_access_signature_credential>(m_sas_token);
    //std::shared_ptr<storage_credential>  cred = std::make_shared<shared_key_credential>(account_name, account_key);
    std::shared_ptr<storage_account> account = std::make_shared<storage_account>(account_name, cred, true);
    auto bC = std::make_shared<blob_client>(account, 10);
    
    //------------------parameters-----------------------
    std::string containerName = "containertest";
    std::string blobName = "blob.txt";
    std::string destContainerName = "containertest";
    std::string destBlobName = "blob.copy.txt";
    std::string uploadFileName = "../test_txt_file/test.txt";
    std::string downloadFileName = "../test_txt_file/download.txt";
    std::string appendblobName = "appendblob.ts";
    std::string appendFileName1 = "../test_ts_file/test1.ts";
    std::string appendFileName2 = "../test_ts_file/test2.ts";
    std::string appenddownloadFile = "../test_ts_file/appendownload.ts";
    
    //--------------Container exist----------------------
    bool exists = true;
    blob_client_wrapper bc(bC);
    std::cout << "Test container exist or not: " << std::endl;
    exists = bc.container_exists(containerName);
    
    //--------------Create Container---------------------
    if(!exists)
    {
        std::cout << "Container " << containerName << " is not exist." << std::endl;
        std::cout << "Become create container: " << containerName << std::endl;
        bc.create_container(containerName);
        assert(errno == 0);
        std::cout << "Create Container " << containerName << " done." << std::endl;
    }
    
    //-------------upload file to blob-------------------
    std::cout <<"Start upload Blob: " << blobName << std::endl;
    bc.upload_file_to_blob(uploadFileName, containerName, blobName);
    std::cout << "Create Blob " << blobName << " done." << std::endl;

    //-------------Blob exist---------------------------
    exists = bc.blob_exists(containerName, blobName);
    std::cout << "exist" << exists << std::endl;
    if(exists) {
        std::cout << "Blob " << blobName << " exist." << std::endl;
    }
    else {
        std::cout << "Blob " << blobName << " is not exist." <<std::endl;
    }

    //-------------get blob property---------------------
    std::cout << "Start get blob property" << std::endl;
    auto blobProperty = bc.get_blob_property(containerName, blobName);
    assert(errno == 0);
    std::cout <<"Content type of BLob: " << blobProperty.content_type << std::endl;
    std::cout <<"Size of BLob: " << blobProperty.size << std::endl;
    
    //-------------list blobs---------------------------
    auto blobs = bc.list_blobs_hierarchical(containerName, "/", "", "");
    
    //--------------download blob to file----------------
    bc.download_blob_to_file(containerName, blobName, downloadFileName);
    std::cout << "Download Blob " << blobName << " done." << std::endl;
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
        std::cout << "Blob " << appendblobName << " exist." << std::endl;
    }
    else {
        std::cout << "Blob " << appendblobName << " is not exist." <<std::endl;
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
