#ifndef IHASH_H
#define IHASH_H
#include <string>
#include <QFile>
#include <QDir>
#include <QByteArray>

class Ihash
{
public:

    virtual std::string operator()(const std::string& text) = 0;
    virtual void add(const void* data, size_t numBytes) = 0;

    virtual void start_hash(QDir * dir2, std::string hash_data, std::string elem_name, QString filename){
        if (!(hashFile.isOpen()))
        {
            hashFile.setFileName(dir2->absolutePath() + "/" + filename);
            hashFile.open(QIODevice::WriteOnly);
        }
        this->add(hash_data.c_str(), hash_data.size());
        hashFile.write(QByteArray::fromStdString(this->getHash() + " " + elem_name + "\n"));
        hashFile.flush();
        this->reset();
    }
    virtual std::string getHash() = 0;
    virtual void reset() = 0;
    virtual QString getFileName() = 0;

    virtual ~Ihash() {
        hashFile.close();
    }

QFile hashFile;

};



#endif // IHASH_H
