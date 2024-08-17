#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#include <string>
#include <set>
#include "Pokemon.h"

class FileRepository
{
private:
    std::string scoreFilename;
    std::string pokemonListFilename;

    void checkScoreFileExists();

public:
    explicit FileRepository(const std::string &scoreFilename, const std::string &pokemonListFilename) :
        scoreFilename(scoreFilename), pokemonListFilename(pokemonListFilename) {}

    std::set<std::string> readAllPokemonSpecies() const;
    void writeScore(unsigned int score);
    unsigned int readScore();
};


#endif //FILEREPOSITORY_H
