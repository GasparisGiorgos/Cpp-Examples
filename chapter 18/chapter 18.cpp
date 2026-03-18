#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

void formated_IO();
void Manipulators();
void input_streams();
void file_handling();



struct Account {
    int id;
    char name[32]; 
    double balance; 
};


int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. Formated I/O " << endl;
        cout << "2. Manipulators" << endl;
        cout << "3. getilne, ignore, istream" << endl;
        cout << "4. file handling" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // FIX: Clear the Enter key immediately after the menu choice
        cin.ignore(1000, '\n');

        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: formated_IO(); break;
            case 2: Manipulators(); break;
            case 3: input_streams(); break;
            case 4: file_handling(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

void formated_IO() {

    bool isConnected = true;
    int memoryAddress = 4095;
    int elevation = 142;
    double roundTarget = 100.0;

    std::cout << "--- Network Status ---\n";

    // Boolean Alpha (boolalpha)
    // Prints "true" or "false" instead of "1" or "0"
    std::cout.setf(std::ios_base::boolalpha);
    std::cout << "Connected: " << isConnected << '\n';

    // Show Base and Uppercase (showbase, uppercase)
    // showbase adds "0x" for hex (or "0" for octal)
    // uppercase makes the "0x" -> "0X" and "a-f" -> "A-F"
    std::cout.setf(std::ios_base::showbase);
    std::cout.setf(std::ios_base::uppercase);
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    std::cout << "Address:   " << memoryAddress << '\n';

    // Reset back to decimal before the next integer prints
    std::cout.setf(std::ios_base::dec, std::ios_base::basefield);

    std::cout << "\n--- Telemetry ---\n";

    // Show Positive Sign (showpos)
    // Forces a '+' sign in front of positive numbers
    std::cout.setf(std::ios_base::showpos);
    std::cout << "Elevation: " << elevation << " meters\n";

    // Turn off showpos so it doesn't affect our floating point number
    std::cout.unsetf(std::ios_base::showpos);

    // 5. Show Point (showpoint)
    // Forces the decimal point to print, even if the number is a whole number like 100.0
    std::cout.setf(std::ios_base::showpoint);
    std::cout << "Target:    " << roundTarget << '\n';
    
}


void Manipulators() {

    // =========================================================
    // 1. PADDING & ALIGNMENT
    // =========================================================
    std::cout << "1. PADDING & ALIGNMENT\n";
    std::cout << "=========================================\n";
    std::cout << "- setw(15) creates a 15-character box for the next item.\n";
    std::cout << "- left/right push the text to the sides of that box.\n";
    std::cout << "- setfill('.') fills the empty space with dots instead of spaces (can be filled with any character).\n\n";

    std::cout << std::setfill('.') 
              << std::left  << std::setw(15) << "Product" 
              << std::right << std::setw(10) << 42 
              << "\n\n";

    // =========================================================
    // 2. NUMBER BASES
    // =========================================================
    std::cout << "2. NUMBER BASES\n";
    std::cout << "=========================================\n";
    std::cout << "- dec, hex, and oct change how integers are displayed.\n";
    std::cout << "- Once set, the base stays that way until you change it back.\n\n";

    std::cout << "Dec: " << std::dec << 255 << '\n'
              << "Hex: " << std::hex << 255 << '\n'
              << "Oct: " << std::oct << 255 << '\n'
              << std::dec << "\n"; 
              
    std::cout << "(After everything, we just reset back to 'std::dec' so future numbers print normally)\n\n";

    // =========================================================
    // 3. FLOATS & BOOLEANS
    // =========================================================
    std::cout << "3. FLOATS & BOOLEANS\n";
    std::cout << "=========================================\n";
    std::cout << "- scientific forces standard scientific notation.\n";
    std::cout << "- setprecision(3) locks it to 3 decimal places.\n";
    std::cout << "- boolalpha turns 1/0 into true/false text. noboolalpha reverts it.\n\n";

    std::cout << "Scientific: " << std::scientific << std::fixed << std::setprecision(3) << 9.80665 << "\n\n";
    
    std::cout << "Bool (Text):   " << std::boolalpha   << true << '\n'
              << "Bool (Number): " << std::noboolalpha << true << "\n\n";

    // =========================================================
    // 4. LEGACY IOS FLAGS
    // =========================================================
    std::cout << "4. LEGACY IOS FLAGS\n";
    std::cout << "=========================================\n";
    std::cout << "- setiosflags lets you apply multiple format masks at once using bitwise OR (|).\n";
    std::cout << "- showpos forces a '+' on positive numbers. uppercase makes hex letters capital.\n";
    std::cout << "- resetiosflags strips those specific masks away.\n\n";

    std::cout << std::setiosflags(std::ios_base::showpos | std::ios_base::uppercase)
              << "Flags ON: " << std::hex << 255 << " " << std::dec << 42 << '\n';
              
    std::cout << std::resetiosflags(std::ios_base::showpos | std::ios_base::uppercase)
              << "Flags OFF: " << 42 << "\n\n";

    // =========================================================
    // 5. BUFFER FLUSHING
    // =========================================================
    std::cout << "5. BUFFER FLUSHING\n";
    std::cout << "=========================================\n";
    std::cout << "- flush forces the program to print instantly without waiting for a newline.\n\n";

    std::cout << "Processing" << std::flush << " ...Done!\n\n";

    // =========================================================
    // 6. INPUT WHITESPACE
    // =========================================================
    std::cout << "6. INPUT WHITESPACE\n";
    std::cout << "=========================================\n";
    std::cout << "- noskipws stops std::cin from ignoring spaces (reads them as real characters).\n";
    std::cout << "- skipws goes back to the default of ignoring spaces.\n";
    std::cout << "- ws is a vacuum that sucks up all leftover spaces currently sitting in the buffer.\n\n";

    std::cout << "Type exactly (or it breakes due to noskipws): [Space]A[Space]B (and press Enter)\n";
    

    char firstSpace;
    char letterA;
    char letterB;

    // --- STEP 1: Reading raw keystrokes ---
    
    std::cin >> std::noskipws;   // Setting: Tell cin to NOT ignore spaces
    
    std::cin >> firstSpace;      // Action: Grabs the very first [Space]
    std::cin >> letterA;         // Action: Grabs the 'A'
    
    std::cout << "noskipws grabbed: '";
    
    // If it's a space, physically print [ ], otherwise print the letter
    if (firstSpace == ' ') std::cout << "[ space ]"; 
    else std::cout << firstSpace;
    
    std::cout << "' and '";
    
    if (letterA == ' ') std::cout << "[ space ]"; 
    else std::cout << letterA;
    
    std::cout << "'\n\n";

    // --- STEP 2: Returning to normal behavior ---
    
    std::cin >> std::skipws;     // Setting: Tell cin to ignore spaces again
    std::cin >> std::ws;         // Setting: trash out the leftover [Space] waiting in the buffer
    
    std::cin >> letterB;         // Action: Grabs the 'B'
    
    std::cout << "skipws+ws grabbed: '";
    
    if (letterB == ' ') std::cout << "[ space ]"; 
    else std::cout << letterB;
    
    std::cout << "'\n";
}


void input_streams() {
    int age;
    std::string fullName;

    
    std::cout << "Enter your age: ";
    
    // CRITICAL DETAIL: When the user types the age (25) and presses Enter, 
    // the "25" goes into the 'age' variable. But the Enter key press 
    // itself (the newline character, '\n') stays trapped in the input buffer.
    std::cin >> age; 
    
    
    // If we don't clear the buffer right now, the next reading function 
    // (getline) will immediately see that trapped '\n' and skip asking for the name.

    // std::cin.ignore is the garbage collector
    // It says: "Delete up to 10,000 characters from the buffer, OR delete 
    // everything up to the very next newline ('\n'), whichever happens first."
    std::cin.ignore(10000, '\n'); 

    std::cout << "Enter your full name: ";
    
    // std::getline grabs everything typed, including spaces, until the user presses Enter.
    // Because we cleaned up the leftover '\n', getline will wait for the user to type.
    std::getline(std::cin, fullName); 

    
    std::cout << "\n--- User Profile ---" << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Name: " << fullName << "\n" << std::endl;

}


void file_handling() {
    std::cout << "--- 1. TEXT FILE OPERATIONS ---\n";

    // ofstream: Output file stream (creates/writes to text files)
    std::ofstream outText("sample.txt");
    
    outText << "Hello World\n";
    
    // put: Writes a single character
    outText.put('Z'); 
    
    // flush: Forces the program to push data to the hard drive immediately
    outText.flush(); 
    outText.close();

    // ifstream: Input file stream (reads from text files)
    std::ifstream inText("sample.txt");
    
    // peek: Looks at the next character in the file WITHOUT taking it out
    char nextChar = inText.peek();
    std::cout << "Peeked at first char: " << nextChar << "\n";

    // get: Reads exactly one single character
    char c;
    inText.get(c); 
    std::cout << "Got first char: " << c << "\n";

    // putback: Shoves a character back into the file stream so it can be read again
    inText.putback(c);

    // getline: Reads an entire string until it hits a newline
    std::string line;
    std::getline(inText, line);
    std::cout << "Read full line: " << line << "\n";

    // Linear Access & EOF: Reading straight through until the End Of File
    std::cout << "Reading rest of file: ";
    while (inText.get(c)) { 
        std::cout << c;
    }
    
    // Checking the EOF flag to confirm we hit the end
    if (inText.eof()) {
        std::cout << "\n[EOF Reached]\n\n";
    }
    inText.close();


    std::cout << "--- 2. BINARY FILE OPERATIONS ---\n";

    // fstream: Can read AND write. We open it in binary mode.
    std::fstream binFile("data.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    int myNumber = 42;

    // write: Takes a block of raw memory and writes it. 
    // We have to cast it to a char pointer for the binary function to accept it.
    binFile.write(reinterpret_cast<char*>(&myNumber), sizeof(myNumber));
    std::cout << "Wrote " << myNumber << " to binary file.\n";

    // Random Access: seekg moves the 'get' (reading) pointer back to the beginning
    binFile.seekg(0, std::ios::beg);

    int readNumber = 0;

    // read: Grabs a block of raw bytes from the binary file
    binFile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));
    std::cout << "Read " << readNumber << " from binary file using random access.\n";

    binFile.close();
    
}