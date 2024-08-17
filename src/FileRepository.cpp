#include "FileRepository.h"
#include <fstream>
#include <iostream>

void FileRepository::writeScore(unsigned int score) {
    checkScoreFileExists();
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
    checkScoreFileExists();
    unsigned int score = 0;
    std::ifstream inputFile{scoreFilename};

    if (!inputFile) {
        throw std::runtime_error("Unable to open file for reading: " + scoreFilename);
    }
    inputFile >> score;
    inputFile.close();

    return score;
}

void FileRepository::checkScoreFileExists() {
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
std::set<std::string> FileRepository::readAllPokemonSpecies() const {
    std::ifstream inputFile{pokemonListFilename};
    std::set<std::string> pokemonSpeciesSet;

    if (!inputFile) {
        throw std::runtime_error("Unable to open file for reading: " + pokemonListFilename);
    }

    std::string line{};
    while (std::getline(inputFile, line)) {
        pokemonSpeciesSet.insert(line);
    }
    inputFile.close();

    return pokemonSpeciesSet;
}

