#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <random>
#include <iomanip>
#include <set>
#include <thread>
#include <chrono>
#include <utility>


using namespace std;

// Color codes (ANSI)
#define RESET   "\033[0m"
#define BLUE    "\033[34m"   // 1★
#define YELLOW  "\033[33m"   // 2★
#define PURPLE  "\033[35m"   // 3★

void mainmenu();

void yes() {
    char i;
    cout << "Return menu now? (type 'y' if you wish to go back, if no, don't type it yet): ";
    cin >> i;

    if(i == 'y') {
        mainmenu();
    }
}

void quote() {
    char z;
    cout << "Have you ever heard of 'All Blue'? (y/n)" << endl;
    cin >> z;
    if (z == 'y') {
        cout << "You heard that? Great! I'm sure one day you will experiencing it!" << endl;
        yes();
    } else if (z == 'n') {
        cout << "No? It's okay, you will experiencing it soon." << endl;
        yes();
    }
}

void onlyVIEWonwedList() {
    string filename{"list/blue_archive_your_current_owned_student.txt"};
    ifstream input{filename};

  if (!input.is_open()) {
    cerr << "Couldn't read file: " << filename << "\n";
    return; 
  }

  std::vector<std::string> lines;
  for (string line; getline(input, line);) {
    // Move the value of line into lines
    lines.push_back(std::move(line)); 
  }

  for (const auto& line : lines) {
    cout << line << "\n";
  }

  yes();

}

void display1() {
    ifstream file("list/point_count.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();

    // Only use the last 10 pulls
    int start = lines.size() > 1 ? lines.size() - 1 : 0;

    //RARITIES with color
    cout << "\n      ===== Rarity Reveal =====" << endl;

    int count = 0;
    for (int i = start; i < lines.size(); i++) {
        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << "[Blue]" << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '2') {
            cout << YELLOW << "[Yellow]" << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '3') {
            cout << PURPLE << "[Purple]" << RESET << "  ";
            cout << " " << endl;
        }

        count++;
    }

    // Step 2: Wait 2 seconds
    cout << "\nRevealing students in 2 seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    // Step 3: Show student names
    cout << "\n              ===== Student Names =====" << endl;
    cout << " " << endl;

    count = 0;
    for (int i = start; i < lines.size(); i++) {
        size_t pos = lines[i].find("★");
        string name = lines[i].substr(pos + 3);

        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << name << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '2') {
            cout << YELLOW << name << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '3') {
            cout << PURPLE << name << RESET << "  ";
            cout << " " << endl;
        }

        count++;
    }

    cout << endl;
}

void display5perRow() {
    ifstream file("list/point_count.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();

    // Only use the last 10 pulls
    int start = lines.size() > 10 ? lines.size() - 10 : 0;

    //RARITIES with color
    cout << "\n      ===== Rarity Reveal =====" << endl;
    cout << " " << endl;

    int count = 0;
    for (int i = start; i < lines.size(); i++) {
        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << "[Blue]" << RESET << "  ";
        }
        else if (rarity == '2') {
            cout << YELLOW << "[Yellow]" << RESET << "  ";
        }
        else if (rarity == '3') {
            cout << PURPLE << "[Purple]" << RESET << "  ";
        }

        count++;
        if (count % 5 == 0) {
            cout << endl;
        }
    }

    // Step 2: Wait 2 seconds
    cout << "\nRevealing students in 2 seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    // Step 3: Show student names
    cout << "\n              ===== Student Names =====" << endl;
    cout << " " << endl;

    count = 0;
    for (int i = start; i < lines.size(); i++) {
        size_t pos = lines[i].find("★");
        string name = lines[i].substr(pos + 3);

        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << name << RESET << "  ";
        }
        else if (rarity == '2') {
            cout << YELLOW << name << RESET << "  ";
        }
        else if (rarity == '3') {
            cout << PURPLE << name << RESET << "  ";
        }

        count++;
        if (count % 5 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}

void createOwnedList() {
    ifstream input("list/point_count.txt");
    ofstream output("list/blue_archive_your_current_owned_student.txt");

    if (!input.is_open()) {
        cout << "Error: Cannot open point_count.txt" << endl;
        return;
    }

    // Use a set to automatically remove duplicates
    set<string> uniqueStudents;

    string line;
    while (getline(input, line)) {
        if (line.empty()) continue;

        // Example line from point_count.txt: "3★  Hina (Swimsuit)"
        // We need to extract the name and rarity

        // Find the position of "★"
        size_t starPos = line.find("★");
        if (starPos == string::npos) continue;

        // Rarity is the number before ★
        int rarity = line[0] - '0';   // simple way for 1,2,3

        // Name starts after "★  "
        string name = line.substr(starPos + 3);  // skip "★  "

        // Make a string like "Hina (Swimsuit) 3"
        string full = name + " " + to_string(rarity);

        // set will ignore if this student is already added
        uniqueStudents.insert(full);
    }

    input.close();

    // Write unique students to the new file
    for (const string& student : uniqueStudents) {
        output << student << endl;
    }

    output.close();

}

void pickUPrecruitment();

void setupRateUp();

void redeemStudent();

int getCurrentPoints() {
    ifstream inputFile("list/point_count.txt");
    if (!inputFile.is_open()) return 0;

    string line;
    int points = 0;
    while (getline(inputFile, line)) {
        if (!line.empty()) points++;
    }
    inputFile.close();
    return points;
}

void removePoints(int amount) {
    ifstream inputFile("list/point_count.txt");
    if (!inputFile.is_open()) return;

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    inputFile.close();

    if (static_cast<int>(lines.size()) <= amount) {
        //wipe everything
        ofstream out("list/point_count.txt", ios::trunc);
        out.close();
        return;
    }

    //Keep only the lines AFTER the first "amount" (oldest pulls removed)
    ofstream out("list/point_count.txt", ios::trunc);
    for (size_t i = amount; i < lines.size(); ++i) {
        out << lines[i] << endl;
    }
    out.close();

}

// change this one later
void countLine() {
    int points = getCurrentPoints();
    // Output the final tally
    cout << " " << endl;
    cout << "Total recruitment points: " << points << endl;

}

// Simple student structure
struct Student {
    string name;
    int rarity;
};

// Three pools
vector<Student> oneStar;
vector<Student> twoStar;
vector<Student> threeStar;

// Rate-up (featured) students - each gets more 0.7% rate
vector<Student> rateUpList;

// Random engine (true random)
mt19937 rng;

// Load students from file
void loadStudents(string filename) {

    //Clear old data so repeated recruits don't stack duplicates
    oneStar.clear();
    twoStar.clear();
    threeStar.clear();

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // Find last space
        size_t lastSpace = line.find_last_of(' ');
        if (lastSpace == string::npos) continue;

        string name = line.substr(0, lastSpace);
        int rarity = stoi(line.substr(lastSpace + 1));

        Student s;
        s.name = name;
        s.rarity = rarity;

        if (rarity == 1) oneStar.push_back(s);
        else if (rarity == 2) twoStar.push_back(s);
        else if (rarity == 3) threeStar.push_back(s);
    }

    file.close();

    cout << "Loaded!" << endl;
    cout << "1 Star: " << oneStar.size() << endl;
    cout << "2 Star: " << twoStar.size() << endl;
    cout << "3 Star: " << threeStar.size() << endl;
}

// Pick random student from a list
Student getRandom(vector<Student>& list) {
    if (list.empty()) {
        return Student{"Unknown", 1};
    }
    uniform_int_distribution<int> dist(0, static_cast<int> (list.size()) - 1);
    return list[dist(rng)];
}

//Helper: is this student currently a rate-up?
bool isRateUp(const Student& s) {
    for (const auto& r : rateUpList) {
        if (r.name == s.name && r.rarity == s.rarity) return true;
    }
    return false;
}

// Single pull with rate-up support
//Each rate-up student gets 0.7% individual rate.
//Remaining 3 start rate = max(0, 3.0 - 0.7 * N) shared among non-rate-up 3 star
Student singlePull() {
    uniform_real_distribution<double> dist(0.0, 100.0);
    double roll = dist(rng);

    const double oneStarRate = 78.5;
    const double twoStarRate = 18.5;
    const double baseThree   = 3.0;
    const double rateUpEach  = 0.7;

    double rateUpTotal = rateUpEach * rateUpList.size();  //0.7 * N
    double otherThree = max(0.0, baseThree - rateUpTotal); // remaining for non-rate-up


    Student result;

    if (roll < oneStarRate) {
        result = getRandom(oneStar);      // 78.5%
    }
    else if (roll < oneStarRate + twoStarRate) {
        result = getRandom(twoStar);      // 18.5%
    }
    else {

        //Into the 3 star selection (last ~3% or more if rate-up push it)
        double threeRoll = roll - (oneStarRate + twoStarRate); //0 .. ~3+
        
        if (!rateUpList.empty() && threeRoll < rateUpTotal) {
            //Laned on a rate-up slot >> pick uniformly among rate-up students
            result = getRandom(rateUpList);
        }
        else {
            //Other 3 star (or fallback if no rate-up)
            //Build a temporary pool that excludes current rate-ups
            vector<Student> otherPool;
            for (const auto& s : threeStar) {
                if (!isRateUp(s)) otherPool.push_back(s);
            }
            if (otherPool.empty()) {
                //Safety: if every 3 star is rate-up, just pick any 3 star
                result = getRandom(threeStar);
            } else {
                result = getRandom(otherPool);
            }

        }

    }

    return result;
}

// Save one student to file (APPEND mode)
void saveStudent(string filename, const Student& s) {
    // ios::app = append (does not erase old content)
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        file << s.rarity << "★  " << s.name << endl;
        file.close();
    }
}

void recruit10() {
    // True random seed (that contain all blue, for real)
    random_device rd;
    rng.seed(rd());

    // Load the student list
    loadStudents("list/blue_archive_banner_student list A-Z.txt");

    //Pull a 10 recruitment
    for (int i = 0; i < 10; i++) {
        Student s = singlePull();

        // Save every pull (including duplicates) for counting recruitment point
        saveStudent("list/point_count.txt", s);
    }

    display5perRow();
    countLine();
    createOwnedList();

    cout << "\nAll pulls are saved to point_count.txt for counting points" << endl;
    cout << "Just recruited (just owned) students will be added in your current ownned list" << endl;

}

void recruit1() {
    // True random seed
    random_device rd;
    rng.seed(rd());

    // Load the student list
    loadStudents("list/blue_archive_banner_student list A-Z.txt");

    //Pull a single recruitment
    for (int i = 0; i < 1; i++) {
        Student s = singlePull();

        // Save this pull (including duplicate if it is) for counting recruitment point
        saveStudent("list/point_count.txt", s);
    }

    display1();
    countLine();
    createOwnedList();

    cout << " " << endl;
    cout << "\nAll pulls are saved to point_count.txt for counting points" << endl;
    cout << "Just recruited (just owned) student will be added in your current ownned list" << endl;
}


int optionSelect;

void select() {
    cout << "[1]: Go back main menu" << endl;
    cout << "[2]: Stay and change some setting" << endl;
    cin >> optionSelect;
}

int pryoBl = 0;

void pryo() {


    string inputFileName = "list/pryo_balance.txt";
    string outputFileName = "list/pryo_balance.txt";

    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Couldn't read file: " << inputFileName << "\n";
    } else {
        inputFile >> pryoBl;
        inputFile.close(); //I got struggle with this one
    }

    cout << "Enter or change your balance, Sensei" << endl;
    cout << "I am rich so you can ask unlimited Pryo :)" << endl;
    cout << "*If you don't want to change the balance, type same value*" << endl;
    cout << "Current balance:  " << pryoBl << ".\n";
    cin >> pryoBl;

    if (pryoBl == 0 || pryoBl <= 2000) {
        cout << "Current balance:  " << pryoBl << "   ~Poor Sensei~~~" << ".\n";
    }
    else {
        cout << "Current balance:  " << pryoBl << ".\n";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open " << outputFileName << endl;
        std::exit(4);
    }
    outputFile << pryoBl;
    outputFile.close(); //I got struggle with this one, too

    cout << "[1]: Go back main menu" << endl;
    cout << "[2]: Stay and change balance" << endl;
    cin >> optionSelect;

    if (optionSelect == 1) {
        mainmenu();
    }
    else if (optionSelect == 2) {
        pryo();
    }
    else {
        cout << "Invalid number/typing, choose either 1 or 2" << endl;
        select();
    }
}


void student_list() {
    string inputFileName = "list/blue_archive_all_student list A-Z.txt";
    string outputFileName = "list/blue_archive_your_current_owned_student.txt";

    //Open and read the input file into memory
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open " << inputFileName << " Make sure you have the file ready" << endl;
        std::exit(4);
    }

    std::vector<std::string> lines;
    string currentLine;
    while (std::getline(inputFile, currentLine)) {
        lines.push_back(currentLine);
    }
    inputFile.close();

    if (lines.empty()) {
        cout << "The input file is empty. Please giving it some content" << endl;
        std::exit(4);
    }

    //Display file content with line numbers
    cout << "--- File Content (" << inputFileName << ") ---" << endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << "[" << (i + 1) << "] " << lines[i] << endl;
    }
    cout << "-----------------------------------" << endl;

    //Clean lefover newline from previous cin >> so getline work correctly
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Prompt user for multiple line numbers
    cout << "\nEnter line numbers to export your current owned student (separated by spaces, e.g., '1 3 5'): " << endl;
    cout << "*WARNING: YOU ONLY DO THIS ONCE IF YOU DON'T HAVE OR WANTED TO CHANGE YOUR OWNED LIST (running this program first time)" << endl;
    cout << " " << endl;
    string inputBuffer;
    std::getline(cin, inputBuffer);

    stringstream ss(inputBuffer);
    std::vector<int> selectedIndices;
    int lineNumber;

    while (ss >> lineNumber) {
        // Convert 1-based line number to 0-based vector index
        int index = lineNumber - 1;
        if (index >= 0 && static_cast<size_t>(index) < lines.size()) {
            selectedIndices.push_back(index);
        } else {
            cout << "Warning: Line number " << lineNumber << " is out of bounds. Skipping." << endl;
        }
    }

    if (selectedIndices.empty()) {
        cout << "No valid lines selected. Exiting." << endl;
        return;
    }

    //Export selected lines to the output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open " << outputFileName << endl;
        std::exit(4);
    }

    for (int idx : selectedIndices) {
        outputFile << lines[idx] << endl;
    }
    outputFile.close();

    cout << "Success! Exported " << selectedIndices.size() 
              << " your student list to " << outputFileName << " | Sensei~" << endl;
    
    select();
    
    if (optionSelect == 1) {
        mainmenu();
    } else if(optionSelect == 2) {
         student_list();
    } else {
        cout << "Invalid number/typing, choose either 1 or 2" << endl;
         select();
    }
}


void menuloop() {

    int select;
    cin >> select;

     if (select == 1) {
        pryo();
    } else if (select == 2) {
        student_list();
    } else if (select == 5) {
        cout << "Press Enter to close the window..." << endl;
        cin.get(); // Waits for the user to press Enter before continuing to exit
    } else {
        cout << " " << endl;
        cout << "Inviald number/typing. Please choose either from the range 1-6" << endl;
        cout << " " << endl;
        cout << "[1]: View or add Pryo balance " << endl;
        cout << "[2]: Create current owned student list (banner only)" << endl;
        cout << "[3]: Recruitment (Spark system)" << endl;
        cout << "[4]: View your current owned student list" << endl;
        cout << "[5]: Exit" << endl;
        cout << "[6]: Quote" << endl;
        menuloop();
    }
}

void askOPi() {

    int select;
    cout << " " << endl;
    cout << "[1] Exit recruitment" << endl;
    cout << "[2] Stay" << endl;
    cout << " " << endl;

    cin >> select;

    if (select == 1) {
        mainmenu();
    } else if (select == 2) {
        pickUPrecruitment();
    } else {
        cout << "Inviald number/typing, please choose either 1 or 2" << endl;
        askOPi();
    }
}

// Rate-up selection: choose 2, 3, or 4 three star students
// Each selected student gains +0.7% individual rate
void setupRateUp() {
    string inputFileName = "list/blue_archive_banner_student list A-Z.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open " << inputFileName << endl;
        return;
    }

    vector<string> lines;
    string currentLine;
    while (getline(inputFile, currentLine)) {
        if (!currentLine.empty()) lines.push_back(currentLine);
    }
    inputFile.close();

    //Show only 3 star student with their original line numbers
    cout << "\n===== 3-Star Student (choose rate-up) =====" << endl;
    vector<int> threeStarIndices; //0-based indices into 'lines'
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t lastSpace = lines[i].find_last_of(' ');
        if (lastSpace == string::npos) continue;
        int rarity = stoi(lines[i].substr(lastSpace + 1 ));
        if (rarity == 3) {
            threeStarIndices.push_back(static_cast<int>(i));
            cout << "[" << (i + 1) << "] " << lines[i] << endl;
        }
    }
    cout << "----------------------------------------------" << endl;

    int howMany = 0;
    cout << "\nHow many rate-up students? (2, 3, or 4): ";
    cin >> howMany;
    if (howMany < 2 || howMany > 4) {
        cout << "Invalid number/typing. the selection MUST be 2, 3, or 4" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter " << howMany << " line numbers (separated by spaces): ";
    string inputBuffer;
    getline(cin, inputBuffer);

    stringstream ss(inputBuffer);
    vector<int> selected;
    int num;
    while (ss >> num) selected.push_back(num);

    if (static_cast<int>(selected.size()) != howMany) {
        cout << "You MUST enter exactly " << howMany << " numbers." << endl;
        return;
    }

    rateUpList.clear();
    for (int lineNum : selected) {
        int idx = lineNum - 1;
        if (idx < 0 || static_cast<size_t>(idx) >= lines.size()) {
            cout << "Line " << lineNum << " out of bounds. Skipping." << endl;
            continue;
        }
        size_t lastSpace = lines[idx].find_last_of(' ');
        if (lastSpace == string::npos) continue;

        string name = lines[idx].substr(0, lastSpace);
        int rarity = stoi(lines[idx].substr(lastSpace + 1));

        if (rarity != 3) {
            cout << "Warning: " << name << " is not 3 star. Skipped." << endl;
            continue;
        }

        Student s;
        s.name = name;
        s.rarity = 3;
        rateUpList.push_back(s);
        cout << " Rate-up added: " << name << " (+0.7)" << endl;

    }

    if (rateUpList.empty()) {
        cout << "No valid rate-up students selected." << endl;
    } else {
        cout << "\nRate-up list set! Total bonus rate: " 
        << fixed << setprecision(1) << (0.7 * rateUpList.size()) << "%" << endl;
    }
}


bool isAlreadyOwned(const string& name, int rarity) {
    ifstream in("list/blue_archive_your_current_owned_student.txt");
    if (!in.is_open()) return false;

    string line;
    string target = name + " " + to_string(rarity);
    while (getline(in, line)) {
        // trim possible trailing spaces/newlines already handled by getline
        if (line == target) {
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}

void appendOwnedIfNew(const Student& s) {
    if (isAlreadyOwned(s.name, s.rarity)) {
        cout << s.name << " is already in your owned list. Skipping append." << endl;
        return;
    }

    ofstream out("list/blue_archive_your_current_owned_student.txt", ios::app);
    if (out.is_open()) {
        out << s.name << " " << s.rarity << endl;
        out.close();
        cout << s.name << " added to owned list." << endl;
    }
}

//Redeem (spark) a rate-up student for 200 recruitment points
void redeemStudent() {
    int points = getCurrentPoints();
    cout << "\nCurrent recruitment points: " << points << endl;

    if (points < 200) {
        cout << "Sensei, you have " << points << " recruitment point. You need at least 200 recruitment points to redeem a student." << endl;
        return; 
    }

    if (rateUpList.empty()) {
        cout << "No rate-up students set. Please set rate-up first." << endl;
        return;
    }

    cout << "\n===== Redeemable Rate-up Students =====" << endl;
    for (size_t i = 0; i < rateUpList.size(); ++i) {
        cout << "[" << (i + 1) << "] " << rateUpList[i].name << " 3 STAR" << endl;
    }
    cout << "---------------------------------------" << endl;

    int choice = 0;
    cout << "Choose which student to redeem (1-" << rateUpList.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(rateUpList.size())) {
        cout << "Invalid choice." << endl;
        return;
    }

    Student redeemed = rateUpList[choice - 1];

    //Spend 200 points (remove oldest 200 puuls) giving you a free point
    removePoints(200);

    //Record the pull in point_count (append)
    saveStudent("list/point_count.txt", redeemed);

    //Append to owned list ONLY if not already there (prevent wipe existing content)
    appendOwnedIfNew(redeemed);

    cout << "\n*** REDEEMED: " << PURPLE << redeemed.name << RESET 
        << " Purple, 3 star ***" << endl;
    cout << "200 recruitment points have been consumed." << endl;
    cout << "Points remaining: " << getCurrentPoints() << endl;

}

void savePryoBalance() {
    ofstream outputFile("list/pryo_balance.txt");
    if (outputFile.is_open()) {
        outputFile << pryoBl << endl;
        outputFile.close();
    }
}

void pickUPrecruitment() {

    int select;

    ifstream inputFile("list/pryo_balance.txt");

    if (!inputFile.is_open()) {
    cerr << "Couldn't read file: list/pryo_balance.txt\n";
    } else {
        inputFile >> pryoBl;
        inputFile.close();
    }

    //Show current rate-up status
    cout << "\n========== RECRUITMENT MENU ==========" << endl;
    if (rateUpList.empty()) {
        cout << "Rate-up: (none set)" << endl;
    } else {
        cout << "Rate-up students (+0.7% each):" << endl;
        for (const auto& s : rateUpList) {
            cout << " - " << PURPLE << s.name << RESET << " 3 STAR" << endl;
        }

        cout << "Total rate-up rate: " << fixed << setprecision(1) 
        << (0.7 * rateUpList.size()) << "%" << endl;

    }

    cout << "Recruitment points: " << getCurrentPoints() << endl;
    cout << "Pryo balance: " << pryoBl << endl;
    cout << "--------------------------------------" << endl;

    cout << " " << endl;
    cout << "Please select 1 or 2 to roll" << endl;
    cout << "[1] Recruit 1: 120 Pryo" << endl;
    cout << "[2] Recruit 10: 1200 Pryo" << endl;
    cout << "[3] Set rate-up students (2/3/4)" << endl;
    cout << "[4] Redeem a rate-up student (cost 200 points)" << endl;
    cout << "[5] Back to main menu" << endl;
    cout << " " << endl;

    cin >> select;

    if (select == 1 && pryoBl >= 120) {
        pryoBl -=120;
        savePryoBalance();
        recruit1();
        cout << "Pryo left: " << pryoBl << endl;
        askOPi();

    } else if (select ==1 && pryoBl < 120) {
        cout << "You are broke, Sensei" << endl;
        cout << "Pryo left: " << pryoBl << endl;
        askOPi();

    } else if (select == 2 && pryoBl >= 1200) {
        pryoBl -=1200;
        savePryoBalance();
        recruit10();
        cout << "Pryo left: " << pryoBl << endl;
        askOPi();

    } else if (select == 2 && pryoBl < 1200) {
        cout << "You are broke, Sensei, choose the single pull one instead" << endl;
        cout << "Pryo left: " << pryoBl << endl;
        askOPi();

    } else if(select == 3) {
        setupRateUp();
        pickUPrecruitment();  //return to menu after setting

    } else if(select == 4) {
        redeemStudent();
        pickUPrecruitment(); //return to menu after redeem

    } else if(select == 5) {
        mainmenu();

    } else {
        cout << "Invalid number/typing choose either 1 or 2" << endl;
        pickUPrecruitment();
    }
}

void mainmenu() {
    cout << "" << endl;
    cout << " This program is make by Kat 1307 and written in C++ " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "                     Hello, Sensei" << endl;
    cout << "           Welcome to the gacha system simulator" << endl;
    cout << "             Please choose a funtion below:" << endl;
    cout << " " << endl;
    cout << "[1]: View or add Pryo balance " << endl;
    cout << "[2]: Create current owned student list" << endl;
    cout << "[3]: Recruitment (Spark system)" << endl;
    cout << "[4]: View your current owned student list" << endl;
    cout << "[5]: Exit" << endl;
    cout << "[6]: Quote" << endl;

    int select;
    cin >> select;

    if (select == 1) {
        pryo();
    } else if (select == 2) {
        student_list();
    } else if (select == 3) {
        pickUPrecruitment();
    } else if (select == 4) {
        onlyVIEWonwedList();
    } else if (select == 5) {
        cout << "Press Enter to close the window..." << endl;
        cin.get(); // Waits for the user to press Enter before continuing to exit (it didn't work)
    } else if(select == 6) {
        quote();
    } else {
        cout << " " << endl;
        cout << "Invalid number/typing. Please choose either from the range 1-6" << endl;
        cout << " " << endl;
        cout << "[1]: View or add Pryo balance " << endl;
        cout << "[2]: Create current owned student list" << endl;
        cout << "[3]: Recruitment (Spark system)" << endl;
        cout << "[4]: View your current owned student list" << endl;
        cout << "[5]: Exit" << endl;
        cout << "[6]: Quote" << endl;
        menuloop();
    }

}


int main() {

    mainmenu();

    return 0;
}
