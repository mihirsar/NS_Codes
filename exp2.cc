#include<bits/stdc++.h>

using namespace std;

// Function to encrypt using pure columnar transposition cipher
string encrypt(string plaintext, string key) {
    int cols = key.size();
    int rows = (plaintext.size() + cols - 1) / cols;

    // Pad the plaintext if necessary
    plaintext.append(rows * cols - plaintext.size(), ' ');

    vector<string> grid(rows, string(cols, ' '));

    // Fill the grid with the plaintext
    for (int i = 0; i < plaintext.size(); ++i) {
        grid[i / cols][i % cols] = plaintext[i];
    }

    // Read out the columns according to the key
    string ciphertext;
    for (char c : key) {
        int index = c - '1'; // Convert from char to index
        for (int i = 0; i < rows; ++i) {
            ciphertext += grid[i][index];
        }
    }

    return ciphertext;
}

// Function to decrypt using pure columnar transposition cipher
string decrypt(string ciphertext, string key) {
    int cols = key.size();
    int rows = ciphertext.size() / cols;

    vector<string> grid(rows, string(cols, ' '));

    // Fill the grid with the ciphertext according to the key
    int index = 0;
    for (char c : key) {
        int col = c - '1'; // Convert from char to column index
        for (int i = 0; i < rows; ++i) {
            grid[i][col] = ciphertext[index++];
        }
    }

    // Read out the grid to get the plaintext
    string plaintext;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            plaintext += grid[i][j];
        }
    }

    return plaintext;
}

int main() {
    string message = "FIVEMINUTEENGINEERING";
    string key = "31425"; // Key for the pure columnar transposition cipher

    string encrypted_message = encrypt(message, key);
    string str = encrypted_message;
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return c == ' '; }), str.end());
    cout << "Encrypted message: " << str << endl;

    string decrypted_message = decrypt(encrypted_message, key);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
