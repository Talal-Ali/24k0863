#include <iostream>
#include <vector>
using namespace std;

int passwordgen(string& pass) {
    int hash = 5381;
    for (char c : pass) hash = hash * 33 + c;
    return hash;
}

class User {
protected:
    string name, id, email;
    vector<string> permissions;
    int hashedPass;
public:
    User(string n, string i, string e, string p, vector<string> perms)
        : name(n), id(i), email(e), permissions(perms) {
        hashedPass = passwordgen(p);
    }

    bool authenticate(string& p) {
        return passwordgen(p) == hashedPass;
    }

    virtual void display() {
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << endl;
    }

    bool hasPermission(const string& action) {
        for (string& perm : permissions)
            if (perm == action) return true;
        return false;
    }

    void accessLab() {
        if (hasPermission("full_lab_access"))
            cout << "Lab Access: Full Access Granted\n";
        else if (hasPermission("manage_students"))
            cout << "Lab Access: Partial Access Granted\n";
        else
            cout << "Lab Access: Access Denied\n";
    }
};

class Student : public User {
protected:
    int assignments[5] = {0};
public:
    Student(string n, string i, string e, string p)
        : User(n, i, e, p, {"submit_assignment"}) {}

    void submitAssignment(int index) {
        if (index >= 0 && index < 5) assignments[index] = 1;
    }

    void display() override {
        User::display();
        cout << "Assignments:\n";
        for (int i = 0; i < 5; ++i)
            cout << "  Assignment " << (i + 1) << ": " << (assignments[i] ? "Done" : "Not Done") << endl;
    }
};

class TA : public Student {
    vector<Student*> assigned;
    vector<string> projects;
public:
    TA(string n, string i, string e, string p)
        : Student(n, i, e, p) {
        permissions.push_back("view_projects");
        permissions.push_back("manage_students");
    }

    void display() override {
        User::display();
        cout << "Projects:\n";
        for (size_t i = 0; i < projects.size(); ++i)
            cout << "  Project " << (i + 1) << ": " << projects[i] << endl;
    }

    void addProject(string& proj) {
        if (projects.size() < 2) {
            projects.push_back(proj);
            cout << "Project '" << proj << "' added.\n";
        } else {
            cout << "Max project limit reached.\n";
        }
    }

    void assignStudent(Student* s) {
        if (hasPermission("manage_students")) {
            if (assigned.size() < 10) {
                assigned.push_back(s);
                cout << "Student assigned to TA.\n";
            } else {
                cout << "TA has max number of students.\n";
            }
        } else {
            cout << "Permission denied to assign students.\n";
        }
    }
};

class Professor : public User {
public:
    Professor(string n, string i, string e, string p)
        : User(n, i, e, p, {"assign_projects", "full_lab_access"}) {}

    void display() override {
        User::display();
    }

    void assignProjectToTA(TA& ta, string& proj) {
        if (hasPermission("assign_projects")) {
            ta.addProject(proj);
        } else {
            cout << "Permission denied to assign project.\n";
        }
    }
};

void authenticateAndPerformAction(User* user, string& action) {
    if (user->hasPermission(action)) {
        cout << "Action '" << action << "' performed.\n";
    } else {
        cout << "Permission denied for '" << action << "'.\n";
    }
}

int main() {
    Student s("Alice", "S1", "alice@uni.edu", "pass123");
    TA t("Bob", "T1", "bob@uni.edu", "tapass");
    Professor p("Dr. Ray", "P1", "ray@uni.edu", "propass");

    s.display();
    t.display();
    p.display();

    cout << "\nAuthentication Test:\n";
    string input;
    cout << "Enter password for Alice: ";
    cin >> input;
    if (s.authenticate(input)) cout << "Access Granted\n";
    else cout << "Access Denied\n";

    cout << "\nLab Access:\n";
    s.accessLab();
    t.accessLab();
    p.accessLab();

    cout << "\nAssigning Project to TA:\n";
    string proj = "AI Lab";
    p.assignProjectToTA(t, proj);

    cout << "\nSubmitting Assignment:\n";
    s.submitAssignment(2);
    s.display();

    cout << "\nTA Assigns Student:\n";
    t.assignStudent(&s);

    cout << "\nPerforming Actions:\n";
    string action1 = "submit_assignment";
    string action2 = "manage_students";
    string action3 = "assign_projects";
    authenticateAndPerformAction(&s, action1);
    authenticateAndPerformAction(&t, action2);
    authenticateAndPerformAction(&p, action3);
}
