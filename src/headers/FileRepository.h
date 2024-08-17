#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#include <string>

class FileRepository
{
private:
    std::string scoreFilename;

    void checkFileExists();

public:
    explicit FileRepository(const std::string &scoreFilename) : scoreFilename(scoreFilename) {}

    void writeScore(unsigned int score);
    unsigned int readScore();
};


#endif //FILEREPOSITORY_H
