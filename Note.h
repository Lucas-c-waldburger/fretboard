//
// Created by Lower School Music on 3/30/23.
//

#ifndef LINKEDLISTS_NOTE_H
#define LINKEDLISTS_NOTE_H
#include <iostream>
#include <memory>
#include <vector>

enum NoteNames {
    a = 0,
    aSharp = 1,
    b = 2,
    c = 3,
    cSharp = 4,
    d = 5,
    dSharp = 6,
    e = 7,
    f = 8,
    fSharp = 9,
    g = 10,
    gSharp = 11
};

struct Note {
    Note(int name, int row, int column) : name{name}, row{row}, column{column} {};

    int name;
    int row;
    int column;

    Note* rowNext = nullptr;
    Note* colNext = nullptr;
    Note* next = nullptr;

    static std::string nameIntToAlpha(int name) {
        std::string nameAlpha;
        switch (name) {
            case 0: nameAlpha = "A"; break;
            case 1: nameAlpha = "A#"; break;
            case 2: nameAlpha = "B"; break;
            case 3: nameAlpha = "C"; break;
            case 4: nameAlpha = "C#"; break;
            case 5: nameAlpha = "D"; break;
            case 6: nameAlpha = "D#"; break;
            case 7: nameAlpha = "E"; break;
            case 8: nameAlpha = "F"; break;
            case 9: nameAlpha = "F#"; break;
            case 10: nameAlpha = "G"; break;
            case 11: nameAlpha = "G#"; break;
            default: nameAlpha = "A"; break;
        }
        return nameAlpha;
    }

    static int nameAlphaToInt(std::string name) {
        int nameInt;
        if (name == "A") {return 0;}
        if (name == "A#") {return 1;}
        if (name == "B") {return 2;}
        if (name == "C") {return 3;}
        if (name == "C#") {return 4;}
        if (name == "D") {return 5;}
        if (name == "D#") {return 6;}
        if (name == "E") {return 7;}
        if (name == "F") {return 8;}
        if (name == "F#") {return 9;}
        if (name == "G") {return 10;}
        if (name == "G#") {return 11;}
        else {return -1;}
    }

    static std::unique_ptr<std::vector<int>> getChordVec(int numOfNotes) {
        std::cout << "hello";
        std::unique_ptr<std::vector<int>> chordVec;

        for (int i = 0; i < numOfNotes; i++) {
            std::cout << "{ ";

//            for (int j = 0; j < chordVec->size(); j++) { std::cout << (*chordVec)[j] << ", "; }

            std::cout << "}\n";

            std::string note;
            std::cout << "Enter a note to add to the Chord: ";
            std::cin >> note;
            chordVec->push_back(nameAlphaToInt(note));
            std::cout << '\n';
        }
        return chordVec;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Note* note) {
        stream << nameIntToAlpha(note->name);
        return stream;

    }
};

struct Path {
    int rowDistance;
    int colDistance;
    bool rowFirst;
};

struct Tuning {
    Tuning(int numStrings, int numFrets) : numStrings{numStrings}, numFrets{numFrets} {};
//    Tuning(int numStrings, int numFrets) : numStrings{numStrings}, numFrets{numFrets} {
//        setOffsets(numStrings);
//    };

    int numStrings;
    int numFrets;
    std::vector<int> halfStepOffsets;

    void setOffsets(int numStrs) {
        if (!halfStepOffsets.empty()) {halfStepOffsets.clear();}
        for (int i = 1; i < numStrs; i++) {
            int offset;
            std::cout << "How many half-steps between string " << i << " and string " << (i + 1) << "? : ";
            std::cin >> offset;
            halfStepOffsets.push_back(offset);
        }
    };

};






//std::unique_ptr<std::vector<int>> getChordVec(int first, int second, int third, int fourth, int fifth, int sixth)
//{
//    std::vector<int> chordVec {first, second, third, fourth, fifth, sixth};
//    return make_unique<std::vector<int>>(chordVec);
//}

#endif //LINKEDLISTS_NOTE_H
