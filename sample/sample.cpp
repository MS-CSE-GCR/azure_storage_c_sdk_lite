
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
    std::string account_name = "testzwj";
    //std::string account_key = "vaDY8xu+u0iqSZBcdsNwjAULSFXLaFd7LXT3sV8PsFPI4cla7y1k026KNqve401OuRGTosO5q4z/sm2oodTYRg==";
    std::string m_sas_token = "sv=2017-04-17&sig=ABJdLYXhtXeJu8sxB4jXaPjuPoke11opVP1Q%2FJ3GvwE%3D&spr=https&se=2018-03-06T03%3A14%3A19Z&srt=co&ss=b&sp=racupwdl";
    std::shared_ptr<storage_credential>  cred = std::make_shared<shared_access_signature_credential>(m_sas_token);
    //std::cout << "hahahha" << std::endl;
    //std::shared_ptr<storage_credential>  cred = std::make_shared<shared_key_credential>(account_name, account_key);
    std::shared_ptr<storage_account> account = std::make_shared<storage_account>(account_name, cred, true);
    auto bC = std::make_shared<blob_client>(account, 10);
    //auto f1 = bc.list_containers("");
    //f1.wait();
    //
    std::string containerName = "jasontest1";
    std::string blobName = "blob";
    std::string destContainerName = "jasontest1";
    std::string destBlobName = "blob.copy";
    std::string uploadFileName = "test.txt";
    std::string downloadFileName = "../../download.ts";
    std::string appendblobName = "appendblob";
    std::string appendFileName1 = "../../test1.ts";
    std::string appendFileName2 = "../../test2.ts";
    std::string appenddownloadFile = "../../appendownload.ts";

    bool exists = true;
    blob_client_wrapper bc(bC);
 
    exists = bc.container_exists(containerName);

    if(!exists)
    {
        bc.create_container(containerName);
        assert(errno == 0);
    }
    
    assert(errno == 0);
    exists = bc.blob_exists(containerName, "testsss.txt");
    assert(errno == 0);
    assert(!exists);
    std::cout <<"Start upload Blob: " << blobName << std::endl;
    
    bc.upload_file_to_blob(appendFileName1, containerName, blobName);
    auto blobProperty = bc.get_blob_property(containerName, blobName);
    assert(errno == 0);
    std::cout <<"Content type of BLob: " << blobProperty.content_type << std::endl;
    
    //std::cout <<"Error upload Blob: " << errno << std::endl;
    //assert(errno == 0);

    exists = bc.blob_exists(containerName, blobName);
    assert(errno == 0);
    assert(exists);

    blobProperty = bc.get_blob_property(containerName, blobName);
    assert(errno == 0);
    std::cout <<"Size of BLob: " << blobProperty.size << std::endl;

    auto blobs = bc.list_blobs_hierarchical(containerName, "/", "", "");
    //std::cout <<"Size of BLobs: " << blobs.size() << std::endl;
    std::cout <<"Error Size of BLobs: " << errno << std::endl;
    assert(errno == 0);

    bc.download_blob_to_file(containerName, blobName, downloadFileName);
    std::cout <<"Download Blob done: " << errno << std::endl;
    assert(errno == 0);

    // copy blob
    /* 
    bc.start_copy(containerName, blobName, destContainerName, destBlobName);
    auto property = bc.get_blob_property(destContainerName, destBlobName);
    std::cout << "Copy status: " << property.copy_status <<std::endl;
    exists = bc.blob_exists(destContainerName, destBlobName);
    assert(errno == 0);
    */
    //assert(exists);
    /*
    bc.delete_blob(containerName, blobName);
    bc.delete_blob(destContainerName, destBlobName);
    assert(errno == 0);
    exists = bc.blob_exists(containerName, blobName);
    assert(errno == 0);
    assert(!exists);
    */

    //-------------------
    //create append blob
    exists = bc.blob_exists(containerName, appendblobName);
    std::cout << "exists" << exists << std::endl;
    //create an append blob
    if(!exists) {
        bc.create_append(containerName, appendblobName);
    }
    blobProperty = bc.get_blob_property(containerName, appendblobName);
    assert(errno == 0);
    std::cout <<"Content type of BLob: " << blobProperty.content_type << std::endl;

    //---------------------
    //append block to blobs
    std::cout << "start append file" << std::endl;
    bc.append_file_to_blob(appendFileName1, containerName, appendblobName);
    bc.append_file_to_blob(appendFileName2, containerName, appendblobName);
    std::cout << "end append file" << std::endl;

    //download append blob
    bc.download_blob_to_file(containerName, appendblobName, appenddownloadFile);
    std::cout <<"Download Blob done: " << errno << std::endl;
    assert(errno == 0);

    //bc.delete_container(containerName);
    //assert(errno == 0);
    //std::this_thread::sleep_for(std::chrono::seconds(5));


}
