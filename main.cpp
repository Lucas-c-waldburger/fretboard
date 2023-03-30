#include <iostream>
#include "Node.h"
#include "Note.h"


void printList(Note* note) {
    while (note != nullptr) {
        std::cout << note << " - (" << note->row << ", " << note->column << ")\n";

        note = note->colNext;

    }
}

//void addNode(Node* node, Node* newNode, int position) {
//    for (int i = 0; i < position-1; i++) {
//        node = node->next;
//    }
//    newNode->next = node->next;
//    node->next = newNode;
//}

void getRowNexts(Note* head, int numStrings, int numFrets, std::vector<int>& halfStepOffsets) {
    Note *prevNote = head;
    int prevName = prevNote->name;
    for (int c = 0; c < numStrings; c++) {
        for (int r = 0; r < numFrets; r++) {
            if (c == 0 && r == 0) { r++; }
            Note *note = new Note((prevName + 1) % 12, r, c);
            note->row = r;
            note->column = c;
            prevNote->rowNext = note;
            prevNote = note;
            prevName = prevNote->name;

            if (c < halfStepOffsets.size() && r == (numFrets - 1)) {
                prevName = (prevNote->name + (halfStepOffsets[c] - r)) % 12;
            }
        }
    }
}

void getColNexts(Note* head, int numFrets) {
    Note *firstNote = head;
    Note *note = head;
    int count = 0;
    while (note != nullptr) {
        ++count;
        if (count == numFrets + 1) {
            firstNote->colNext = note;
            getColNexts(firstNote->rowNext, numFrets);
        }
        else {
            note = note->rowNext;
        }
    }
}

int main() {
//    Note* head = new Note(e, 0, 0);
//
//    Tuning tuning(6, 4);
//    tuning.halfStepOffsets = std::vector<int> {4, 4, 4, 3, 4};
//
//    getRowNexts(head, tuning.numStrings, tuning.numFrets, tuning.halfStepOffsets);
//    getColNexts(head, tuning.numFrets);
//    printList(head);

    std::unique_ptr<std::vector<int>> chord = Note::getChordVec(3);

    return 0;
}
