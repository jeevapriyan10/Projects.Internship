#include <bits/stdc++.h>
using namespace std;

void rightAngleTriangle(int n, bool out, ofstream &file);
void invertedTriangle(int n, bool out, ofstream &file);
void numberSquare(int n, bool out, ofstream &file);
void pyramid(int n, bool out, ofstream &file);
void diamond(int n, bool out, ofstream &file);

int main() {
    cout << "=== Welcome to Pattern Printer Program ===\n";
    vector<string> patterns = {
        "Right Angle Triangle",
        "Inverted Triangle",
        "Number Square",
        "Pyramid",
        "Diamond"
    };

    cout << "\nSelect a pattern to print:\n";
    for (int i = 0; i < patterns.size(); ++i)
        cout << i + 1 << ". " << patterns[i] << endl;

    int choice;
    cout << "\nEnter your choice (1-5): ";
    cin >> choice;
    if (choice < 1 || choice > 5) {
        cerr << "Invalid choice!" << endl;
        return 1;
    }

    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    if (n <= 0) {
        cerr << "Invalid number of rows!" << endl;
        return 1;
    }

    bool out;
    cout << "Do you want to save pattern to file? (1 for Yes / 0 for No): ";
    cin >> out;

    ofstream file;
    if (out)
        file.open("pattern.txt", ios::app);  // Append mode

    cout << "\nGenerating pattern...\n\n";

    switch (choice) {
        case 1:
            rightAngleTriangle(n, out, file);
            break;
        case 2:
            invertedTriangle(n, out, file);
            break;
        case 3:
            numberSquare(n, out, file);
            break;
        case 4:
            pyramid(n, out, file);
            break;
        case 5:
            diamond(n, out, file);
            break;
    }

    if (out) {
        file << "\n----------------------------------------\n";
        file.close();
        cout << "\nPattern saved successfully in 'pattern.txt'.\n";
    }
cout << "\nProgram finished. Press Enter to exit...";
cin.get();


    return 0;
}

void rightAngleTriangle(int n, bool out, ofstream &file) {
    cout << "Right Angle Triangle:\n";
    if (out) file << "Right Angle Triangle:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << "* ";
        cout << endl;

        if (out) {
            for (int j = 1; j <= i; ++j) file << "* ";
            file << endl;
        }
    }
}

void invertedTriangle(int n, bool out, ofstream &file) {
    cout << "Inverted Triangle:\n";
    if (out) file << "Inverted Triangle:\n";
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) cout << "* ";
        cout << endl;

        if (out) {
            for (int j = 1; j <= i; ++j) file << "* ";
            file << endl;
        }
    }
}

void numberSquare(int n, bool out, ofstream &file) {
    cout << "Number Square:\n";
    if (out) file << "Number Square:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << j << " ";
        cout << endl;

        if (out) {
            for (int j = 1; j <= n; ++j) file << j << " ";
            file << endl;
        }
    }
}

void pyramid(int n, bool out, ofstream &file) {
    cout << "Pyramid:\n";
    if (out) file << "Pyramid:\n";
    for (int i = 1; i <= n; ++i) {
        for (int s = i; s < n; ++s) cout << " ";
        for (int k = 1; k <= 2 * i - 1; ++k) cout << "*";
        cout << endl;

        if (out) {
            for (int s = i; s < n; ++s) file << " ";
            for (int k = 1; k <= 2 * i - 1; ++k) file << "*";
            file << endl;
        }
    }
}

void diamond(int n, bool out, ofstream &file) {
    cout << "Diamond:\n";
    if (out) file << "Diamond:\n";
    
    for (int i = 1; i <= n; ++i) {
        for (int s = i; s < n; ++s) cout << " ";
        for (int k = 1; k <= 2 * i - 1; ++k) cout << "*";
        cout << endl;

        if (out) {
            for (int s = i; s < n; ++s) file << " ";
            for (int k = 1; k <= 2 * i - 1; ++k) file << "*";
            file << endl;
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int s = n; s > i; --s) cout << " ";
        for (int k = 1; k <= 2 * i - 1; ++k) cout << "*";
        cout << endl;

        if (out) {
            for (int s = n; s > i; --s) file << " ";
            for (int k = 1; k <= 2 * i - 1; ++k) file << "*";
            file << endl;
        }
    }
}
