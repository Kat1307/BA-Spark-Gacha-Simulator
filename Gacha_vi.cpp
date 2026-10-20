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
#include <algorithm>


using namespace std;

// Color codes (ANSI)
#define RESET   "\033[0m"
#define BLUE    "\033[34m"   // 1★
#define YELLOW  "\033[33m"   // 2★
#define PURPLE  "\033[35m"   // 3★

void mainmenu();

void Invalid_choice() {
    cout << "Không hợp lệ, chỉ nhận đầu vào 'y' " << endl;
}

void Invalid_choice2() {
    cout << "Không hợp lệ, chỉ nhận đầu vào 'y' và 'n'" << endl;
}

void yes() {
    char i;
    cout << "Quay lại menu? (nhập 'y' nếu bạn muốn quay lại, nếu không thì đừng nhập vội): ";
    cin >> i;

    if(i == 'y') {
        mainmenu();
    } else {
        Invalid_choice();
        cout << " " << endl;
        yes();
    }
}

void quote() {
    char z;
    cout << "Sensei đã bao giờ nghe về 'All Blue' chưa? (y/n)" << endl;
    cin >> z;
    if (z == 'y') {
        cout << "Thầy nghe rồi à? Ngon! Tôi chắc chắn một ngày bạn sẽ trải nghiệm nó thôi!" << endl;
        yes();
    } else if (z == 'n') {
        cout << "Không ư? Chẳng sao cả, bạn sẽ trải nghiệm nó sớm thôi." << endl;
        yes();
    } else {
        Invalid_choice2();
        cout << " " << endl;
        quote();
    }
}

void onlyVIEWonwedList() {
    string filename{"list/blue_archive_your_current_owned_student_vi.txt"};
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
    ifstream file("list/point_count_vi.txt");

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
    cout << "\n      ===== Peek Độ Hiếm Roll =====" << endl;

    int count = 0;
    for (int i = start; i < lines.size(); i++) {
        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << "[Xanh]" << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '2') {
            cout << YELLOW << "[Vàng]" << RESET << "  ";
            cout << " " << endl;
        }
        else if (rarity == '3') {
            cout << PURPLE << "[Tím]" << RESET << "  ";
            cout << " " << endl;
        }

        count++;
    }

    // Step 2: Wait 2 seconds
    cout << "\n Tiết lộ học sinh trong 2 giây..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    // Step 3: Show student names
    cout << "\n              ===== Tên Học Sinh =====" << endl;
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
    ifstream file("list/point_count_vi.txt");

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
    cout << "\n      ===== Peek Độ Hiếm Roll =====" << endl;
    cout << " " << endl;

    int count = 0;
    for (int i = start; i < lines.size(); i++) {
        char rarity = lines[i][0];

        if (rarity == '1') {
            cout << BLUE << "[Xanh]" << RESET << "  ";
        }
        else if (rarity == '2') {
            cout << YELLOW << "[Vàng]" << RESET << "  ";
        }
        else if (rarity == '3') {
            cout << PURPLE << "[Tím]" << RESET << "  ";
        }

        count++;
        if (count % 5 == 0) {
            cout << endl;
        }
    }

    // Step 2: Wait 2 seconds
    cout << "\n Tiết lộ học sinh trong 2 giây..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    // Step 3: Show student names
    cout << "\n              ===== Tên Học Sinh =====" << endl;
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
    ifstream input("list/point_count_vi.txt");
    ofstream output("list/blue_archive_your_current_owned_student_vi.txt");

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
    ifstream inputFile("list/point_count_vi.txt");
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
    ifstream inputFile("list/point_count_vi.txt");
    if (!inputFile.is_open()) return;

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    inputFile.close();

    if (static_cast<int>(lines.size()) <= amount) {
        //wipe everything
        ofstream out("list/point_count_vi.txt", ios::trunc);
        out.close();
        return;
    }

    //Keep only the lines AFTER the first "amount" (oldest pulls removed)
    ofstream out("list/point_count_vi.txt", ios::trunc);
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
    cout << "Tổng Điểm Chiêu Mộ: " << points << endl;

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

    cout << "Đã Load Danh Sách Học Sinh!" << endl;
    cout << "1 Sao: " << oneStar.size() << endl;
    cout << "2 Sao: " << twoStar.size() << endl;
    cout << "3 Sao: " << threeStar.size() << endl;
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
    loadStudents("list/blue_archive_banner_student list A-Z_vi.txt");

    //Pull a 10 recruitment
    for (int i = 0; i < 10; i++) {
        Student s = singlePull();

        // Save every pull (including duplicates) for counting recruitment point
        saveStudent("list/point_count_vi.txt", s);
    }

    display5perRow();
    countLine();
    createOwnedList();

    cout << "\n Tất Cả ROLL đều được lưu vào file point_count_vi.txt dành riêng cho việc đếm điểm chiêu mộ." << endl;
    cout << "Học sinh vừa được chiêu mộ sẽ được thêm vào danh sách học sinh đã sở hữu hiện tại của bạn." << endl;

}

void recruit1() {
    // True random seed
    random_device rd;
    rng.seed(rd());

    // Load the student list
    loadStudents("list/blue_archive_banner_student list A-Z_vi.txt");

    //Pull a single recruitment
    for (int i = 0; i < 1; i++) {
        Student s = singlePull();

        // Save this pull (including duplicate if it is) for counting recruitment point
        saveStudent("list/point_count_vi.txt", s);
    }

    display1();
    countLine();
    createOwnedList();

    cout << " " << endl;
    cout << "\n Tất Cả ROLL đều được lưu vào file point_count_vi.txt dành riêng cho việc đếm điểm chiêu mộ" << endl;
    cout << "Học sinh vừa được chiêu mộ sẽ được thêm vào danh sách học sinh đã sở hữu hiện tại của bạn." << endl;
}


int optionSelect;

void select() {
    cout << "[1]: Về Menu" << endl;
    cout << "[2]: Ở lại và thay đổi gì đó" << endl;
    cin >> optionSelect;
}

int pryoBl = 0;

void pryo() {


    string inputFileName = "list/pryo_balance_vi.txt";
    string outputFileName = "list/pryo_balance_vi.txt";

    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Couldn't read file: " << inputFileName << "\n";
    } else {
        inputFile >> pryoBl;
        inputFile.close(); //I got struggle with this one
    }

    cout << "Sensei à, hãy nhập số đá Pryo thầy cần" << endl;
    cout << "Tôi giàu mà nên xin tôi bao nhiêu đá cũng được :)" << endl;
    cout << "*Nếu Sensei không muốn thay đổi giá trị số đá, hãy nhập số đá y hệt*" << endl;
    cout << "Số dư đá Pryo hiện tại:  " << pryoBl << ".\n";
    cin >> pryoBl;

    if (pryoBl == 0 || pryoBl <= 2000) {
        cout << "Số dư đá Pryo hiện tại:  " << pryoBl << "   ~ Sensei khiêm tốn ghê~~~" << ".\n";
    }
    else {
        cout << "Số dư đá Pryo hiện tại:  " << pryoBl << ".\n";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open " << outputFileName << endl;
        std::exit(4);
    }
    outputFile << pryoBl;
    outputFile.close(); //I got struggle with this one, too

    cout << "[1]: Về lại Menu" << endl;
    cout << "[2]: Ở lạy và xin thêm đá (hoặc thay đổi)" << endl;
    cin >> optionSelect;

    if (optionSelect == 1) {
        mainmenu();
    }
    else if (optionSelect == 2) {
        pryo();
    }
    else {
        cout << "Số/chữ được nhập không hợp lệ, chỉ chọn số 1 or 2" << endl;
        select();
    }
}


void student_list() {
    string inputFileName = "list/blue_archive_all_student list A-Z_vi.txt";
    string outputFileName = "list/blue_archive_your_current_owned_student_vi.txt";

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
        cout << "File nhập trống, hãy viết danh sách học sinh vào" << endl;
        std::exit(4);
    }

    //Display file content with line numbers
    cout << "--- Nội dung File (" << inputFileName << ") ---" << endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << "[" << (i + 1) << "] " << lines[i] << endl;
    }
    cout << "-----------------------------------" << endl;

    //Clean lefover newline from previous cin >> so getline work correctly
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Prompt user for multiple line numbers
    cout << "\n Nhập số dòng cụ thể để xuất danh sách học sinh đã sở hữu hiện tại của bạn (cách nhau bởi dấu cách, Ví dụ: '1 3 5'): " << endl;
    cout << "*Lưu ý: Thầy giáo chỉ nên làm một lần duy nhất (nếu chạy chương trình này lần đầu tiên hoặc thay đổi danh sách học sinh)," << endl;
    cout << " vì việc này SẼ GHI ĐÈ danh sách nếu danh sách đấy nếu có nội dung bên trong!" << endl;
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
            cout << "Lưu ý: dòng số " << lineNumber << " đã ra khỏi vùng nhập cho phép. Skip dòng đấy." << endl;
        }
    }

    if (selectedIndices.empty()) {
        cout << "Không dòng nào hợp lệ. Thoát chương trình" << endl;
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

    cout << "Thành công! Đã xuất " << selectedIndices.size() 
              << " danh sách sở hữu học sinh hiện tại vào file " << outputFileName << " | Sensei à~" << endl;
    
    select();
    
    if (optionSelect == 1) {
        mainmenu();
    } else if(optionSelect == 2) {
         student_list();
    } else {
        cout << "Số/chữ được nhập không hợp lệ, chỉ chọn số 1 hoặc 2" << endl;
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
        cout << "Số/chữ được nhập không hợp lệ, chỉ chọn số từ khoảng 1-6" << endl;
        cout << " " << endl;
        cout << "[1]: Xem hoặc thêm số dư đá Pryo " << endl;
        cout << "[2]: Tạo danh sách học sinh đã sở hữu hiện tại" << endl;
        cout << "[3]: Chiêu Mộ Học Sinh! (Cơ chế Spark)" << endl;
        cout << "[4]: Xem danh sách học sinh đã sở hữu hiện tại" << endl;
        cout << "[5]: Thoát" << endl;
        cout << "[6]: Nghe tôi bảo này" << endl;
        menuloop();
    }
}

void askOPi() {

    int select;
    cout << " " << endl;
    cout << "[1] Thoát chiêu mộ học sinh (về Menu)" << endl;
    cout << "[2] Ở lại chiêu mộ tiếp" << endl;
    cout << " " << endl;

    cin >> select;

    if (select == 1) {
        mainmenu();
    } else if (select == 2) {
        pickUPrecruitment();
    } else {
        cout << "Số/chữ được nhập không hợp lệ, chỉ chọn 1 hoặc 2" << endl;
        askOPi();
    }
}

// Rate-up selection: choose 2, 3, or 4 three star students
// Each selected student gains +0.7% individual rate
void setupRateUp() {
    string inputFileName = "list/blue_archive_banner_student list A-Z_vi.txt";
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
    cout << "\n===== Học Sinh 3 Sao (hãy chọn học sinh để rate-up) =====" << endl;
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
    cout << "\nSensei muốn bao nhiêu học sinh vào chạy banner? (2, 3, 4, hay 5): ";
    cin >> howMany;
    if (howMany < 2 || howMany > 5) {
        cout << "Số/chữ được nhập không hợp lệ, chỉ CHỌN SỐ 2, 3, 4, hoặc 5" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhập " << howMany << " dòng số cụ thể (cách nhau bởi dấu cách): ";
    string inputBuffer;
    getline(cin, inputBuffer);

    stringstream ss(inputBuffer);
    vector<int> selected;
    int num;
    while (ss >> num) selected.push_back(num);

    if (static_cast<int>(selected.size()) != howMany) {
        cout << "Thầy phải nhập CHÍNH XÁC " << howMany << " dòng cụ thể!." << endl;
        return;
    }

    rateUpList.clear();
    for (int lineNum : selected) {
        int idx = lineNum - 1;
        if (idx < 0 || static_cast<size_t>(idx) >= lines.size()) {
            cout << "Dòng số " << lineNum << " ra khỏi biên. Skip dòng đó." << endl;
            continue;
        }
        size_t lastSpace = lines[idx].find_last_of(' ');
        if (lastSpace == string::npos) continue;

        string name = lines[idx].substr(0, lastSpace);
        int rarity = stoi(lines[idx].substr(lastSpace + 1));

        if (rarity != 3) {
            cout << "Cảnh báo: " << name << " không phải là học sinh 3 sao. Skip học sinh này." << endl;
            continue;
        }

        Student s;
        s.name = name;
        s.rarity = 3;
        rateUpList.push_back(s);
        cout << "  Đã thêm học sinh vào banner (Rate-up): " << name << " (+0.7% tỉ lệ roll)" << endl;

    }

    if (rateUpList.empty()) {
        cout << "Không có học sinh hợp lệ dược chọn." << endl;
    } else {
        cout << "\n Các banner đã được thiết lập! Tổng tỉ lệ bonus: " 
        << fixed << setprecision(1) << (0.7 * rateUpList.size()) << "%" << endl;
    }
}


bool isAlreadyOwned(const string& name, int rarity) {
    ifstream in("list/blue_archive_your_current_owned_student_vi.txt");
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

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Insert student into owned list in alphabetical order
void appendOwnedIfNew(const Student& s) {
    string target = s.name + " " + to_string(s.rarity);

    // Read all existing entries (normalized / trimmed whitespaces)
    vector<string> owned;
    ifstream in("list/blue_archive_your_current_owned_student_vi.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            string cleaned = trim(line);
            if (!cleaned.empty()) {
                owned.push_back(cleaned);
            }
        }
        in.close();
    }

    // Already owned? skip
    for (const string& entry : owned) {
        if (entry == target) {
            cout << s.name << " đã có trong danh sách sở hữu." << endl;
            return;
        }
    }

    // Add the new student
    owned.push_back(target);

    // Sort alphabetically by full "Name Rarity" string
    sort(owned.begin(), owned.end());

    // Rewrite the whole file in sorted order (clean format, no leading spaces <== the txt file is fine is 2 whitespace before the name)
    ofstream out("list/blue_archive_your_current_owned_student_vi.txt", ios::trunc);
    if (!out.is_open()) {
        cerr << "Lỗi: Không thể mở file danh sách học sinh sở hữu để ghi." << endl;
        return;
    }
    for (const string& entry : owned) {
        out << entry << endl;
    }
    out.close();

    cout << s.name << " đã thêm vào danh sách học sinh đã sở hữu (Theo thứ tự A-Z)." << endl;
}

//Redeem (spark) a rate-up student for 200 recruitment points
void redeemStudent() {
    int points = getCurrentPoints();
    cout << "\n Điểm Chiêu Mộ Hiện Tại: " << points << endl;

    if (points < 200) {
        cout << "Sensei, thầy có " << points << " điểm chiêu mộ. Thầy cần 200 điểm để đổi lấy 1 học sinh." << endl;
        return; 
    }

    if (rateUpList.empty()) {
        cout << "Không có banner học sinh nào được thiết lập. Hãy thiết lập trước." << endl;
        return;
    }

    cout << "\n===== Đổi Điểm BANNER Học Sinh =====" << endl;
    for (size_t i = 0; i < rateUpList.size(); ++i) {
        cout << "[" << (i + 1) << "] " << rateUpList[i].name << " 3 STAR" << endl;
    }
    cout << "---------------------------------------" << endl;

    int choice = 0;
    cout << "Hãy chọn học sinh để đổi điểm (1-" << rateUpList.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(rateUpList.size())) {
        cout << "Lựa chọn không hợp lệ." << endl;
        return;
    }

    Student redeemed = rateUpList[choice - 1];

    //Spend 200 points (remove oldest 200 pulls)
    removePoints(201);

    //Record the pull in point_count (append)
    saveStudent("list/point_count_vi.txt", redeemed);

    //Trunc sort to owned list ONLY if not already there
    appendOwnedIfNew(redeemed);

    cout << "\n*** ĐÃ ĐỔI: " << PURPLE << redeemed.name << RESET 
        << " Tím, 3 Sao ***" << endl;
    cout << "200 điểm chiêu mộ đã được đổi." << endl;
    cout << "Điểm Chiêu Mộ Còn Lại: " << getCurrentPoints() << endl;

}

void savePryoBalance() {
    ofstream outputFile("list/pryo_balance_vi.txt");
    if (outputFile.is_open()) {
        outputFile << pryoBl << endl;
        outputFile.close();
    }
}

void pickUPrecruitment() {

    int select;

    ifstream inputFile("list/pryo_balance_vi.txt");

    if (!inputFile.is_open()) {
    cerr << "Couldn't read file: list/pryo_balance_vi.txt\n";
    } else {
        inputFile >> pryoBl;
        inputFile.close();
    }

    //Show current rate-up status
    cout << "\n========== MENU CHIÊU MỘ HỌC SINH ==========" << endl;
    if (rateUpList.empty()) {
        cout << "Banner hiện tại: (chưa thiết lập)" << endl;
    } else {
        cout << "Banner Học Sinh (+0.7% tỉ lệ roll mỗi banner):" << endl;
        for (const auto& s : rateUpList) {
            cout << " - " << PURPLE << s.name << RESET << " 3 SAO" << endl;
        }

        cout << "Tổng tỉ lệ roll: " << fixed << setprecision(1) 
        << (0.7 * rateUpList.size()) << "%" << endl;

    }

    cout << "Điểm Chiêu Mộ: " << getCurrentPoints() << endl;
    cout << "Số DƯ ĐÁ Pryo: " << pryoBl << endl;
    cout << "--------------------------------------" << endl;

    cout << " " << endl;
    cout << "Hãy chọn số 1 hoặc 2 để roll" << endl;
    cout << "[1] Chiêu Mộ 1: 120 Pryo" << endl;
    cout << "[2] Chiêu Mộ 10: 1200 Pryo" << endl;
    cout << "[3] Thiết Lập Banner Học Sinh (2/3/4/5)" << endl;
    cout << "[4] Đổi Banner Học Sinh (tốn 200 điểm chiêu mộ)" << endl;
    cout << "[5] Về Menu Chính" << endl;
    cout << " " << endl;

    cin >> select;



char choose;
char choose2;

    if (select == 1) {
        cout << " "<< endl;
        cout << "Sensei, thầy có chắc là thầy muốn chi tiêu 120 Pryo cho một lần chiêu mộ? (y/n)" << endl;
        cout << "Thầy còn " << pryoBl << " Pryo" << endl;
        cin >> choose;
	} else if (select == 2) {
        cout << " "<< endl;
        cout << "Sensei, thầy có chắc là thầy muốn chi tiêu 1200 Pryo cho một lần chiêu mộ 10? (y/n)" << endl;
        cout << "Thầy còn " << pryoBl << " Pryo" << endl;
        cin >> choose2;

    }

     if (choose == 'y' && pryoBl >= 120) {  //This is the single pull option
		pryoBl -=120;
        savePryoBalance();
        recruit1();
        cout << "Pryo còn lại: " << pryoBl << endl;
        cin.ignore();
        askOPi();
        cin.ignore();

	} else if (choose == 'y' && pryoBl < 120) {
		cout << "Thầy nghèo quá, Sensei" << endl;
        cout << "Pryo còn lại: " << pryoBl << endl;
        cin.ignore();
        askOPi();
        cin.ignore();

	} else if (choose == 'n' ) {
        pickUPrecruitment();
        cin.ignore();

    }

      if (choose2 == 'y' && pryoBl >= 1200) { //This is the ten pull option
		pryoBl -=1200;
        savePryoBalance();
        recruit10();
        cout << "Pryo còn lại: " << pryoBl << endl;
        cin.ignore();
        askOPi();
        cin.ignore();

	} else if (choose2 == 'y' && pryoBl < 1200) {
		cout << "Thầy nghèo quá, Sensei, hãy chọn lần chiêu mộ đơn thay vì 10" << endl;
        cout << "Pryo còn lại: " << pryoBl << endl;
        cin.ignore();
        askOPi();
        cin.ignore();

	}  else if (choose2 == 'n') {
        pickUPrecruitment();
        cin.ignore();

    } 

    if(select == 3) {
        setupRateUp();
        pickUPrecruitment();  //return to menu after setting

    } else if(select == 4) {
        redeemStudent();
        pickUPrecruitment(); //return to menu after redeem

    } else if(select == 5) {
        mainmenu();

    } else {
        cout << " " << endl;
        cout << "Lựa chọn không hợp lệ, vui lòng chọn một chức năng trong khoảng 1-5" << endl;
        pickUPrecruitment();
    }
}

void mainmenu() {
    cout << "" << endl;
    cout << " Chương trình này được viết trong C++ bởi Kat 1307" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "                     Xin chào, Sensei" << endl;
    cout << "           Chào mừng đến với giả lập gacha Blue Archive" << endl;
    cout << "             Hãy chọn một chức năng bên dưới:" << endl;
    cout << " " << endl;
    cout << "[1]: Xem hoặc thêm số dư đá Pryo " << endl;
    cout << "[2]: Tạo danh sách học sinh đã sở hữu hiện tại" << endl;
    cout << "[3]: Chiêu Mộ Học Sinh! (Cơ chế Spark)" << endl;
    cout << "[4]: Xem danh sách học sinh đã sở hữu hiện tại" << endl;
    cout << "[5]: Thoát" << endl;
    cout << "[6]: Nghe tôi bảo này" << endl;

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
        cout << "Nhấn Enter để đóng cửa sổ..." << endl;
        cin.get(); // Waits for the user to press Enter before continuing to exit (it didn't work)
    } else if(select == 6) {
        quote();
    } else {
        cout << " " << endl;
        cout << "Số/chữ được nhập không hợp lệ, hãy chọn một chức năng chỉ trong khoảng tầm số 1-6" << endl;
        cout << " " << endl;
        cout << "[1]: Xem hoặc thêm số dư đá Pryo " << endl;
        cout << "[2]: Tạo danh sách học sinh đã sở hữu hiện tại" << endl;
        cout << "[3]: Chiêu Mộ Học Sinh! (Cơ chế Spark)" << endl;
        cout << "[4]: Xem danh sách học sinh đã sở hữu hiện tại" << endl;
        cout << "[5]: Thoát" << endl;
        cout << "[6]: Nghe tôi bảo này" << endl;
        menuloop();
    }

}


int main() {

    mainmenu();

    return 0;
}
