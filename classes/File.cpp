//
// Created by kddny on 10.12.2020.
//

#include "File.h"

const std::string &File::getName() const {
    return name_;
}

File::File(const std::string &name, bool directory, WhichDir whichDir)
: name_(name) , directory_(directory), which_dir_(whichDir){}

const std::vector<std::shared_ptr<File>> &File::getFiles() const {
    return files_;
}

bool File::isDirectory() const {
    return directory_;
}

void File::setParentDir(WhichDir parentDir) {
    which_dir_ = parentDir;
}

const std::string &File::getPath() const {
    return path_;
}

void File::setPath(const std::string &path) {
    File::path_ = path;
}

WhichDir File::getWhichDir() const {
    return which_dir_;
}

const std::string &File::getHash() const {
    return hash_;
}

void File::genHash() {
    std::string *buffer = new std::string;
    buffer->reserve(1024);
    std::fstream fp;

    fp.open(path_ + "/" + name_,std::ios::in);
    if(!(fp.is_open())){
        fprintf(stderr,"Unable to open the file\n");
        exit(EXIT_FAILURE);
    }
    else {
        std::string line;
        while(fp >> line){
            buffer->append(line);
        }
    }
    fp.close();

    std::array<unsigned char,SHA_DIGEST_LENGTH> digest;
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, buffer->c_str(), buffer->size());
    SHA1_Final(digest.data(),&ctx);
    delete buffer;
    std::array<char,SHA_DIGEST_LENGTH * 2 +1> mdString;
    for(int i = 0 ; i < SHA_DIGEST_LENGTH ; ++i) {
        sprintf(&(mdString[i*2]),"%02x",(unsigned int)digest[i]);
    }
    hash_ = mdString.data();
}
