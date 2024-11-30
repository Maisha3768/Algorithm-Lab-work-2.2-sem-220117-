#include <iostream>
using namespace std;

void towers(int num, char fromPeg, char toPeg, char auxPeg) {
    if (num == 1) {
        cout << "\nMove disk 1 from peg " << fromPeg << " to peg " << toPeg;
        return;
    }
    towers(num - 1, fromPeg, auxPeg, toPeg);
    cout << "\nMove disk " << num << " from peg " << fromPeg << " to peg " << toPeg;
    towers(num - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int num;
    cout << "Enter the number of disks: ";
    cin >> num;
    cout << "The sequence of moves involved in the Tower of Hanoi are:\n";
    towers(num, 'A', 'C', 'B');
    return 0;
}
