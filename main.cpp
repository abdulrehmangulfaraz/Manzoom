#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <unordered_map>
#include <windows.h>
#include <cstdlib> // For system("CLS") and color changes
#include <unordered_map>
using namespace std;
const char BLOCK = 219;
string PADDING = "                    ";
string PADDING1 = "                               ";
string I_S = "\033[48;2;160;0;0m\033[38;2;255;242;225m";
string I_E = "\033[48;2;255;242;225m\033[38;2;160;0;0m";

void manzoomheader() {
    // Display "Manzoom" header
    cout << PADDING << " ________________________________________________________\n";
    cout << PADDING << "|                                                        |\n";
    cout << PADDING << "| " << BLOCK << "     " << BLOCK << " " << "   " << BLOCK << "   " << " " << BLOCK << "    " << BLOCK << " " << " " << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << " " << "  " << BLOCK << "" << BLOCK << "" << BLOCK << "  " << "  " << BLOCK << "" << BLOCK << "" << BLOCK << "  " << " " << BLOCK << "     " << BLOCK << "   |\n";
    cout << PADDING << "| " << BLOCK << "" << BLOCK << "   " << BLOCK << "" << BLOCK << " " << "  " << BLOCK << " " << BLOCK << "  " << " " << BLOCK << "" << BLOCK << "   " << BLOCK << " " << "     " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "" << BLOCK << "   " << BLOCK << "" << BLOCK << "   |\n";
    cout << PADDING << "| " << BLOCK << " " << BLOCK << " " << BLOCK << " " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << " " << BLOCK << "  " << BLOCK << " " << "    " << BLOCK << "  " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << " " << BLOCK << " " << BLOCK << " " << BLOCK << "   |\n";
    cout << PADDING << "| " << BLOCK << "  " << BLOCK << "  " << BLOCK << " " << " " << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << " " << " " << BLOCK << "  " << BLOCK << " " << BLOCK << " " << "   " << BLOCK << "   " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "  " << BLOCK << "  " << BLOCK << "   |\n";
    cout << PADDING << "| " << BLOCK << "     " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << "" << BLOCK << " " << "  " << BLOCK << "    " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "     " << BLOCK << "   |\n";
    cout << PADDING << "| " << BLOCK << "     " << BLOCK << " " << " " << BLOCK << "   " << BLOCK << " " << " " << BLOCK << "    " << BLOCK << " " << " " << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << "" << BLOCK << " " << "  " << BLOCK << "" << BLOCK << "" << BLOCK << "  " << "  " << BLOCK << "" << BLOCK << "" << BLOCK << "  " << " " << BLOCK << "     " << BLOCK << "   |\n";
    cout << PADDING << "|________________________________________________________|\n\n";
    cout << PADDING << I_S << "   --- Abhi Kuch log bki hain jo urdu bol skta hain ---   " << I_E << " "<< endl;
    cout << endl;
}

void clearScreen() {
    system("CLS"); // Clear screen
    manzoomheader();
}

string getPassword() {
    string password;
    char ch;

    while (true) {
        ch = _getch(); // Get character input without echoing it on console
        if (ch == '\r') { // Check for Enter key
            cout << endl;
            break;
        }
        else if (ch == '\b') { // Check for Backspace
            if (!password.empty()) {
                cout << "\b \b"; // Erase the last '*' from console
                password.pop_back();
            }
        }
        else {
            cout << '*'; // Display '*' on console
            password += ch;
        }
    }
    return password;
}

void emptyFile(const char* filename) {
    // Open the file in write mode to empty it
    ofstream file(filename, ios::out | ios::trunc); // 'ios::trunc' ensures the file is cleared
    if (file.is_open()) {
        file.close(); // Simply close the file, which has already been emptied
    }
    else {
        cout << "Error opening file." << endl;
    }
}

class PoetryNode {
public:
    string title;
    string content;
    string genre;
    string mood;
    PoetryNode* left;
    PoetryNode* right;

    PoetryNode(string t, string c, string g, string m) : title(t), content(c), genre(g), mood(m), left(NULL), right(NULL) {}
};

string toLower(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

class PoetTree {

private:

    PoetryNode* root;

    void insertPoetryNode(PoetryNode*& node, string title, string content, string genre, string mood) {
        if (!node) {
            node = new PoetryNode(title, content, genre, mood);
        }
        else if (title < node->title) {
            insertPoetryNode(node->left, title, content, genre, mood);
        }
        else {
            insertPoetryNode(node->right, title, content, genre, mood);
        }
    }

    void displayPoemWithPadding(const string& title, const string& genre, const string& mood, const string& content, const string& padding = "    ") {
        cout << "\n" << padding << "Title: " << title << endl;
        cout << padding << "Genre: " << genre << endl;
        cout << padding << "Mood: " << mood << endl;
        cout << padding << "Content:" << endl;

        // Add padding to each line of the content
        stringstream contentStream(content);
        string line;
        while (getline(contentStream, line)) {
            cout << PADDING1 << line << endl; // Double padding for content lines
        }
    }

    void displayPoems(PoetryNode* node) {
        if (node) {
            displayPoems(node->left);
            cout << PADDING << "Title: " << node->title << endl;
            cout << PADDING << "Genre: " << node->genre << endl;
            cout << PADDING << "Mood: " << node->mood << endl;
            cout << PADDING << "Content: \n";
            // Add padding to each line of the content
            stringstream contentStream(node->content);
            string line;
            while (getline(contentStream, line)) {
                cout << PADDING1 << line << endl; // Double padding for content lines
            }
            cout << "\n" << PADDING << "--------------------------------------------------------------\n";
            displayPoems(node->right);
        }
    }

    void saveToFile(PoetryNode* node, ofstream& file) {
        if (node) {
            saveToFile(node->left, file);
            file << node->title << "\n" // Title
                << node->genre << "\n" // Genre
                << node->mood << "\n"  // Mood
                << node->content << "\n" << "<<END_CONTENT>>\n"; // Content delimiter
            saveToFile(node->right, file);
        }
    }

    void loadFromFile(PoetryNode*& node, ifstream& file) {
        string line, title, genre, mood, content;

        while (getline(file, title)) { // Read title
            if (!getline(file, genre) || !getline(file, mood)) break; // Read genre & mood

            // Read poetry content until `<<END_CONTENT>>`
            content.clear();
            while (getline(file, line)) {
                if (line == "<<END_CONTENT>>") break;
                if (!content.empty()) content += "\n"; // Preserve line breaks
                content += line;
            }

            // Insert parsed data into the tree
            insertPoetryNode(node, title, content, genre, mood);
        }
    }

    void clearTree(PoetryNode*& node) {
        if (node) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
        node = NULL;
    }

public:
    PoetTree() : root(NULL) {}

    void addPoem(string title, string content, string genre, string mood) {
        insertPoetryNode(root, title, content, genre, mood);
    }

    void displayPoems() {
        if (!root) {
            cout << PADDING << "No poems to display." << endl;
        }
        else {
            displayPoems(root);
        }
    }

    // New method for displaying poems matching a keyword
    void displayPoemsMatching(const string& keyword) {
        if (!root) {
            cout << PADDING << "No poems to search.\n";
            return;
        }
        searchAndDisplay(root, keyword);
    }


    void searchAndDisplay(PoetryNode* node, const string& keyword) {
        if (!node) return;

        // Traverse left subtree
        searchAndDisplay(node->left, keyword);

        // Check if keyword matches title, genre, or mood (case-insensitive)
        string lowerTitle = toLower(node->title);
        string lowerGenre = toLower(node->genre);
        string lowerMood = toLower(node->mood);
        string lowerKeyword = toLower(keyword);

        if (lowerTitle.find(lowerKeyword) != string::npos ||
            lowerGenre.find(lowerKeyword) != string::npos ||
            lowerMood.find(lowerKeyword) != string::npos) {
            displayPoemWithPadding(node->title, node->genre, node->mood, node->content, PADDING);
        }

        // Traverse right subtree
        searchAndDisplay(node->right, keyword);
    }


    void savePoems(string filename) {
        ofstream file(filename, ios::trunc); // Overwrite existing file
        if (file.is_open()) {
            saveToFile(root, file);
            file.close();
            if (filename != "AllReader_poetry.txt")
            {
                cout << PADDING << "Poems saved successfully!" << endl;
            }
        }
        else {
            cout << PADDING << "Error: Unable to open file for saving." << endl;
        }
    }
        void savePoems_admin(string filename) {
        ofstream file(filename, ios::app); // Overwrite existing file
        if (file.is_open()) {
            saveToFile(root, file);
            file.close();
            if (filename != "AllReader_poetry.txt")
            {
                cout << PADDING << "Poems saved successfully!" << endl;
            }
        }
        else {
            cout << PADDING << "Error: Unable to open file for saving." << endl;
        }
    }

    void loadPoems(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << PADDING << "No existing poems to load." << endl;
            return;
        }
        clearTree(root); // Clear existing tree to avoid duplication
        loadFromFile(root, file);
        file.close();
        cout << PADDING << "Poems loaded successfully!" << endl;
    }
};

class SearchNode {
public:
    string keyword;
    SearchNode* next;

    SearchNode(string kw) : keyword(kw), next(NULL) {}
};

class SearchHistory {
private:
    SearchNode* head;

public:
    SearchHistory() : head(NULL) {}

    void addKeyword(string keyword, const string& username) {
        // Add keyword to the linked list
        SearchNode* newNode = new SearchNode(keyword);
        newNode->next = head;
        head = newNode;

        // Append keyword to the user's history file
        ofstream file(username + "_history.txt", ios::app); // Open in append mode
        if (file.is_open()) {
            file << keyword << endl;
            file.close();
        }
    }

    void displayHistory(const string& username) {
        // Clear current in-memory history
        while (head) {
            SearchNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Load history from file into linked list
        ifstream file(username + "_history.txt");
        string keyword;
        while (getline(file, keyword)) {
            SearchNode* newNode = new SearchNode(keyword);
            newNode->next = head;
            head = newNode;
        }
        file.close();

        // Display history
        cout << PADDING << "Search History: \n";
        SearchNode* current = head;
        while (current) {
            cout << PADDING << current->keyword << " \n";
            current = current->next;
        }
        cout << endl;
    }
};

class PoetUser {
private:
    string username;
    string password;
    PoetTree poetryTree;
    SearchHistory searchHistory;

public:
    PoetUser(string u, string p) : username(u), password(p) {
        clearScreen();
        cout << PADDING << "Loading poetry collection for " << username << "...\n";
        poetryTree.loadPoems(username + "_poetry.txt");
    }

    void submitPoetry() {
        string title, content, genre, mood;
        cout << PADDING << "Enter Poetry Title: ";
        cin.ignore();
        getline(cin, title);
        cout << PADDING << "Enter Poetry Genre: ";
        getline(cin, genre);
        cout << PADDING << "Enter Poetry Mood (happy, sad, romantic, etc.): ";
        getline(cin, mood);
        cout << PADDING << "Enter Poetry Content (end with a single period '.'): \n";
        string line;
        ostringstream poemContent;
        while (true) {
            getline(cin, line);
            if (line == ".") break;
            poemContent << line << "\n";
        }
        poetryTree.addPoem(title, poemContent.str(), genre, mood);
    }

    void displayMyPoems() {
        clearScreen();
        cout << PADDING1 << "--- Your Poems ---\n";
        poetryTree.displayPoems();
    }

    void displayMyPoems_R() {
        clearScreen();
        cout << PADDING1 << "\n";
        poetryTree.displayPoems();
    }

    void savePoetry() {
        poetryTree.savePoems(username + "_poetry.txt");
        poetryTree.savePoems("AllReader_poetry.txt");
    }
};

class LoginManager {
private:
    string filename = "usersP.txt";
    unordered_map<string, string> users;

    void loadUsers() {
        ifstream file(filename);
        if (file.is_open()) {
            string line, username, password;
            while (getline(file, line)) {
                stringstream ss(line);
                getline(ss, username, '|');
                getline(ss, password, '|');
                users[username] = password;
            }
            file.close();
        }
    }

    void saveUsers() {
        ofstream file(filename);
        if (file.is_open()) {
            for (auto& pair : users) {
                file << pair.first << "|" << pair.second << endl;
            }
            file.close();
        }
    }

public:
    LoginManager() {
        loadUsers();
    }

    bool signUp(string username, string password) {
        if (users.find(username) != users.end()) {
            cout << PADDING << "Username already exists. Try a different one.\n";
            return false;
        }
        users[username] = password;
        saveUsers();
        return true;
    }

    bool login(string username, string password) {
        if (users.find(username) != users.end() && users[username] == password) {
            return true;
        }
        cout << PADDING << "Invalid credentials. Please try again.\n";
        return false;
    }

    bool changePassword(string username, string oldPassword, string newPassword) {
        if (users.find(username) != users.end() && users[username] == oldPassword) {
            users[username] = newPassword;
            saveUsers();
            return true;
        }
        cout << PADDING << "Incorrect Credidentials. Please try again.\n";
        return false;
    }
};

class LoginManager_R {
private:
    string filename = "usersR.txt";
    unordered_map<string, string> users;

    void loadUsers() {
        ifstream file(filename);
        if (file.is_open()) {
            string line, username, password;
            while (getline(file, line)) {
                stringstream ss(line);
                getline(ss, username, '|');
                getline(ss, password, '|');
                users[username] = password;
            }
            file.close();
        }
    }

    void saveUsers() {
        ofstream file(filename);
        if (file.is_open()) {
            for (auto& pair : users) {
                file << pair.first << "|" << pair.second << endl;
            }
            file.close();
        }
    }

public:
    LoginManager_R() {
        loadUsers();
    }

    bool signUp(string username, string password) {
        if (users.find(username) != users.end()) {
            cout << PADDING << "Username already exists. Try a different one.\n";
            return false;
        }
        users[username] = password;
        saveUsers();
        return true;
    }

    bool login(string username, string password) {
        if (users.find(username) != users.end() && users[username] == password) {
            return true;
        }
        cout << PADDING << "Invalid credentials. Please try again.\n";
        return false;
    }

    bool changePassword(string username, string oldPassword, string newPassword) {
        if (users.find(username) != users.end() && users[username] == oldPassword) {
            users[username] = newPassword;
            saveUsers();
            return true;
        }
        cout << PADDING << "Incorrect Credidentials. Please try again.\n";
        //etColor(4, 7);
        return false;
    }
};

class ReaderUser {
private:
    string username;
    string password;
    PoetTree poetryTree1; // For accessing poems
    SearchHistory searchHistory;

public:
    ReaderUser(string u, string p) : username(u), password(p) {
        clearScreen();
        cout << PADDING << "Loading poetry collection for you!\n";
        poetryTree1.loadPoems("AllReader(approved)_poetry.txt");
    }
    void displayMyPoems() {
        clearScreen();
        cout << PADDING1 << "--- Your Poems ---\n";
        poetryTree1.displayPoems();
    }

    void browsePoetry() {
        clearScreen();
        cout << PADDING1 << "--- Browse Poetry ---\n";
        poetryTree1.displayPoems();
        system("pause");
    }

    void searchPoetry() {
        clearScreen();
        cout << PADDING1 << "--- Search Poetry ---\n";
        string keyword;
        cout << PADDING << "Enter a keyword (title, genre, or mood): ";
        cin.ignore();
        getline(cin, keyword);

        searchHistory.addKeyword(keyword, username);
        clearScreen();
        cout << PADDING1 << "--- Search Results ---\n";

        // Display poems matching the keyword
        poetryTree1.displayPoemsMatching(keyword);
        system("pause");
    }

    void viewSearchHistory() {
        clearScreen();
        cout << PADDING1 << "--- Search History ---\n";
        searchHistory.displayHistory(username);
        system("pause");
    }
};

int main() {
    clearScreen();
    LoginManager loginManager;
    LoginManager_R loginManager_R;
    PoetUser* currentPoet = nullptr;
    ReaderUser* currentReader = nullptr;
    int choice;

    while (true) {
        clearScreen();        
        cout << PADDING << I_S << "                      USER MENU                           " << I_E << " " << endl;
        cout << PADDING << "|1. Sign Up as Poet                                      |\n";
        cout << PADDING << "|2. Sign up as Reader                                    |\n";
        cout << PADDING << "|3. Login as Poet                                        |\n";
        cout << PADDING << "|4. Login as Reader                                      |\n";
        cout << PADDING << "|5. Exit                                                 |\n";
        cout << PADDING << I_S << "                                                          " << I_E << " " << endl;
        cout << PADDING << "Enter your choice: ";
        cin >> choice;

        if ((cin.fail() || choice < 1 || choice > 5) && choice != 10) {
            cin.clear();
            string invalidInput;
            getline(cin, invalidInput);
            cout << PADDING << "Invalid input. Please enter a valid option (1-5).\n";
            Sleep(1500);
            continue;
        }
        else if (choice == 10) {
            clearScreen(); string c, admin = "AbdulRehman";
            cout << PADDING1 << "Enter Password to Login as Admin: "; c = getPassword();
            if (c != admin) {
                cout << PADDING << "Wrong Password! You cannot access this part of the software." << endl;
            }
            else {
                PoetTree poetryTree2;
                poetryTree2.loadPoems("AllReader_poetry.txt");
                int c = 0;
                while (true)
                {
                    clearScreen();
                    cout << PADDING << I_S << "                 --- Admin Dashboard ---                  " << I_E << " " << endl;
                    cout <<PADDING<< "|1. Display the Unapproved Poetry                        |" << endl;
                    cout <<PADDING<< "|2. Approve all the Pending Poetries                     |" << endl;
                    cout <<PADDING<< "|3. Delete all the Pending Poetries                      |" << endl;
                    cout <<PADDING<< "|4. Exit                                                 |" << endl;
                    cout << PADDING << I_S << "                                                          " << I_E << " " << endl;
                    cout << PADDING << "Enter your choice: ";
                    cin >> c;
                    if (c == 1)
                    {
                        poetryTree2.displayPoems();
                        system("pause");
                    }
                    else if (c == 2)
                    {
                        poetryTree2.savePoems_admin("AllReader(approved)_poetry.txt");
                        emptyFile("AllReader_poetry.txt");
                        cout << PADDING << "All the Pending poetry has been approved and now visible to Readers" << endl;
                        Sleep(1500);
                        continue;
                    }
                    else if (c == 3)
                    {
                        emptyFile("AllReader_poetry.txt");
                        cout << PADDING << "All the Pending poetry has been rejected" << endl;
                        Sleep(1500);
                        continue;
                    }
                    else if (c == 4)
                    {
                        break;
                    }
                    else {
                        cout << PADDING << "\nInvalid Choice! Chose an option from 1-4" << endl;
                        Sleep(1500);
                        continue;
                    }
                }
            }
            Sleep(1500);
            continue;
        }
        else if (choice == 1) {
            clearScreen();
            string username, password; 
            cout << PADDING << I_S << "                     --- Sign Up ---                      " << I_E << " " << endl << endl;
            cout << PADDING << "Enter username: ";
            cin >> username;
            cout << PADDING << "Enter password: ";
            password = getPassword();
            if (loginManager.signUp(username, password)) {
                cout << PADDING << "Sign-up successful! You can now log in.\n";
            }
            Sleep(1500);
        }
        else if (choice == 3) {
            clearScreen();
            string username, password;
            cout << PADDING << I_S << "                      --- Log In ---                      " << I_E << " " << endl << endl;
            cout << PADDING << "Enter username: ";
            cin >> username;
            cout << PADDING << "Enter password: ";
            password = getPassword();

            if (loginManager.login(username, password)) {
                currentPoet = new PoetUser(username, password);
                while (true) {
                    clearScreen();
                    cout << PADDING << I_S << "                  --- Poet Dashboard ---                  " << I_E << " " << endl;
                    cout << PADDING << "|1. Submit New Poetry                                    |\n";
                    cout << PADDING << "|2. View My Poetry Collection                            |\n";
                    cout << PADDING << "|3. Save Poetry                                          |\n";
                    cout << PADDING << "|4. Change Password                                      |\n";
                    cout << PADDING << "|5. Logout                                               |\n";
                    cout << PADDING << I_S << "                                                          " << I_E << " " << endl;
                    cout << PADDING << "Enter your choice: ";
                    cin >> choice;

                    if (cin.fail() || choice < 1 || choice > 5) {
                        cin.clear();
                        string invalidInput;
                        getline(cin, invalidInput); // Consume the invalid input
                        cout << PADDING << "48;2;251;255;110m Invalid input. Please enter a valid option (1-5).\n";
                        Sleep(1500);
                        continue;
                    }

                    if (choice == 1) {
                        clearScreen();
                        currentPoet->submitPoetry();
                    }
                    else if (choice == 2) {
                        clearScreen();
                        currentPoet->displayMyPoems();
                        system("pause");
                    }
                    else if (choice == 3) {
                        clearScreen();
                        currentPoet->savePoetry();
                        Sleep(1500);
                    }
                    else if (choice == 4) {
                        clearScreen();
                        string oldPassword, newPassword;
                        cout << PADDING << I_S << "                --- Change Password ---                  " << I_E << " " << endl << endl;
                        cout << PADDING << "Enter old password: ";
                        oldPassword = getPassword();
                        cout << PADDING << "Enter new password: ";
                        newPassword = getPassword();

                        if (loginManager.changePassword(username, oldPassword, newPassword)) {
                            cout << PADDING << "Password changed successfully.\n";
                        }
                        Sleep(1500);
                    }
                    else if (choice == 5) {
                        clearScreen();
                        cout << PADDING << "Logging out...\n";
                        delete currentPoet;
                        currentPoet = nullptr;
                        Sleep(1500);
                        break;
                    }
                }
            }
            Sleep(1500);
        }
        else if (choice == 2) {
            clearScreen();
            string username, password;
            cout << PADDING << I_S << "                     --- Sign Up ---                      " << I_E << " " << endl << endl;
            cout << PADDING << "Enter username: ";
            cin >> username;
            cout << PADDING << "Enter password: ";
            password = getPassword();
            if (loginManager_R.signUp(username, password)) {
                cout << PADDING << "Sign-up successful! You can now log in.\n";
            }
            Sleep(1500);
        }
        else if (choice == 4) {
            clearScreen();
            string username, password;
            cout << PADDING << I_S << "                      --- Log In ---                      " << I_E << " " << endl << endl;
            cout << PADDING << "Enter username: ";
            cin >> username;
            cout << PADDING << "Enter password: ";
            password = getPassword();

            if (loginManager_R.login(username, password)) {
                currentReader = new ReaderUser(username, password);
                while (true) {
                    clearScreen();
                    cout << PADDING << I_S << "                --- Reader Dashboard ---                  " << I_E << " " << endl;
                    cout << PADDING << "|1. Browse Poetry                                        |\n";
                    cout << PADDING << "|2. Search Poetry                                        |\n";
                    cout << PADDING << "|3. View Search History                                  |\n";
                    cout << PADDING << "|4. Change Password                                      |\n";
                    cout << PADDING << "|5. Exit                                                 |\n";
                    cout << PADDING << I_S << "                                                          " << I_E << " " << endl;
                    cout << PADDING << "Enter your choice: ";
                    cin >> choice;

                    if (cin.fail() || choice < 1 || choice > 5) {
                        cin.clear();
                        string invalidInput;
                        getline(cin, invalidInput);
                        cout << PADDING << "Invalid input. Please enter a valid option (1-4).\n";
                        Sleep(1500);
                        continue;
                    }

                    if (choice == 1) {
                        currentReader->browsePoetry();
                    }
                    else if (choice == 2) {
                        currentReader->searchPoetry();
                    }
                    else if (choice == 3) {
                        currentReader->viewSearchHistory();
                    }
                    else if (choice == 4) {
                        clearScreen();
                        string oldPassword, newPassword;
                        cout << PADDING1 << "--- Change Password ---\n";
                        cout << PADDING << "Enter old password: ";
                        oldPassword = getPassword();
                        cout << PADDING << "Enter new password: ";
                        newPassword = getPassword();

                        if (loginManager.changePassword(username, oldPassword, newPassword)) {
                            cout << PADDING << "Password changed successfully.\n";
                        }
                        Sleep(1500);
                    }
                    else if (choice == 5) {
                        clearScreen();
                        cout << PADDING << "Exiting Reader Mode...\n";
                        delete currentReader;
                        currentReader = nullptr;
                        Sleep(1500);
                        break;
                    }
                }
            }
            else if (choice == 5) {
                clearScreen();
                cout << PADDING << "Thank you for using Manzoom Poetry Collection! Goodbye!\n";
                break;
            }
        }

    }

    return 0;
}