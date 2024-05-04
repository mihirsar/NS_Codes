#include<iostream>
#include<cctype> // For isalpha function

std::string encrypt(const std::string& plaintext, int shift)
{
    std::string ciphertext = "";
    for (char ch : plaintext) 
    {
        if (std::isalpha(ch)) 
        {
            char base = std::isupper(ch) ? 'A' : 'a';
            ciphertext += static_cast<char>((ch - base + shift) % 26 + base);
        } 
        else 
        {
            ciphertext += ch;
        }
    }
    return ciphertext;
}
std::string decrypt(const std::string& ciphertext, int shift) 
{
    return encrypt(ciphertext, -shift);
}
int main() 
{
    std::string plaintext;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    int shift;
    
    std::cout << "Enter shift value for encryption: ";
    std::cin >> shift;

    std::string encryptedText = encrypt(plaintext, shift);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    std::cout << "Enter shift value for decryption: ";
    std::cin >> shift;

    std::string decryptedText = decrypt(encryptedText, shift);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;
    return 0;
}