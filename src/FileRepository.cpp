#include "FileRepository.h"
#include <fstream>
#include <iostream>

void FileRepository::writeScore(unsigned int score) {
    checkFileExists();
    std::ofstream file{scoreFilename};
    if (!file) {
        throw std::runtime_error("Unable to open file for writing: " + scoreFilename);
    }

    file << score;
    file.close();

    if (!file) {
        throw std::runtime_error("Error occurred while writing to file: " + scoreFilename);
    }
}

unsigned int FileRepository::readScore() {
    checkFileExists();
    unsigned int score = 0;
    std::ifstream inputFile{scoreFilename};

    if (!inputFile) {
        throw std::runtime_error("Unable to open file for reading: " + scoreFilename);
    }
    inputFile >> score;
    inputFile.close();

    return score;
}

void FileRepository::checkFileExists() {
    std::ifstream checkFile(scoreFilename);
    if (!checkFile) {
        std::ofstream createFile(scoreFilename);
        if (!createFile) {
            throw std::runtime_error("Unable to create a file: " + scoreFilename);

        }
        createFile << 0;  // Upisi 0 za score
        createFile.close();
    } else {
        checkFile.close();
    }
}

