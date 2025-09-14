#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Skill {
private:
    int id;
    string name;
    string description;

public:
    Skill(int i, string n, string d) : id(i), name(n), description(d) {}

    void showSkillDetails() {
        cout << "Skill Name: " << name << ", Skill ID: " << id << ", Skill Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }

    string getSkillName() const { return name; }
    int getSkillID() const { return id; }
};

class Sport {
private:
    int id;
    string name;
    string description;
    vector<Skill*> requiredSkills;

public:
    Sport(int i, string n, string d) : id(i), name(n), description(d) {}

    void addSkill(Skill* skill) {
        requiredSkills.push_back(skill);
    }

    void removeSkill(Skill* skill) {
        auto it = find(requiredSkills.begin(), requiredSkills.end(), skill);
        if (it != requiredSkills.end()) {
            requiredSkills.erase(it);
            cout << skill->getSkillName() << " has been removed from sport " << name << endl;
        }
    }

    string getSportName() const { return name; }
    int getSportID() const { return id; }
};

class Student;

class Mentor {
private:
    int id;
    string name;
    vector<string> sportsExpertise;
    int maxLearners;
    vector<Student*> assignedLearners;

public:
    Mentor(int i, string n, vector<string> expertise, int maxL) 
        : id(i), name(n), sportsExpertise(expertise), maxLearners(maxL) {}

    void assignLearner(Student* s);
    void removeLearner(Student* s);
    void viewLearners();
    void provideGuidance();

    int getMentorID() const { return id; }
    string getMentorName() const { return name; }
    int getMentorMax() const { return maxLearners; }
    int getMentorLearnerCurrent() const { return assignedLearners.size(); }
    vector<string> getExpertise() const { return sportsExpertise; }
};

class Student {
private:
    int id;
    string name;
    int age;
    vector<Sport*> sportsInterests;
    Mentor* mentor;

public:
    Student(int i, string n, int a) : id(i), name(n), age(a), mentor(nullptr) {}

    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(Sport* s);

    int getStudentID() const { return id; }
    string getStudentName() const { return name; }
    int getStudentAge() const { return age; }
    vector<Sport*> getSportsInterests() const { return sportsInterests; }
};


void Mentor::assignLearner(Student* s) {
    if (assignedLearners.size() < maxLearners) {
        assignedLearners.push_back(s);
        cout << s->getStudentName() << " has been assigned to mentor " << name << endl;
    } else {
        cout << "Mentor " << name << " has reached maximum capacity." << endl;
    }
}

void Mentor::removeLearner(Student* s) {
    auto it = find(assignedLearners.begin(), assignedLearners.end(), s);
    if (it != assignedLearners.end()) {
        assignedLearners.erase(it);
        cout << s->getStudentName() << " has been removed from mentor " << name << endl;
    }
}

void Mentor::viewLearners() {
    for (const auto& learner : assignedLearners) {
        cout << "Name: " << learner->getStudentName() << ", ID: " << learner->getStudentID() << ", Age: " << learner->getStudentAge() << endl;
    }
}

void Mentor::provideGuidance() {
    cout << "Mentor " << name << " is providing guidance to learners." << endl;
}


void Student::registerForMentorship(Mentor* m) {
    
    bool hasMatchingExpertise = false;
    for (Sport* sport : sportsInterests) {
        if (find(m->getExpertise().begin(), m->getExpertise().end(), sport->getSportName()) != m->getExpertise().end()) {
            hasMatchingExpertise = true;
            break;
        }
    }
    
    if (!hasMatchingExpertise) {
        cout << "Cannot register - mentor lacks expertise in student's sports interests!" << endl;
        return;
    }

    if (m->getMentorLearnerCurrent() < m->getMentorMax()) {
        mentor = m;
        m->assignLearner(this);
        cout << name << " has been registered under mentor " << m->getMentorName() << endl;
    } else {
        cout << "Mentor " << m->getMentorName() << " has reached maximum capacity." << endl;
    }
}

void Student::viewMentorDetails() {
    if (mentor != nullptr) {
        cout << "Mentor ID: " << mentor->getMentorID() << endl;
        cout << "Mentor Name: " << mentor->getMentorName() << endl;
        cout << "Mentor Expertise: ";
        for (const auto& expertise : mentor->getExpertise()) {
            cout << expertise << " ";
        }
        cout << endl;
    } else {
        cout << "No mentor assigned." << endl;
    }
}

void Student::updateSportsInterest(Sport* s) {
    if (find(sportsInterests.begin(), sportsInterests.end(), s) == sportsInterests.end()) {
        sportsInterests.push_back(s);
        cout << "Added new sports interest: " << s->getSportName() << endl;
    } else {
        cout << "Sport interest already exists!" << endl;
    }
}

int main() {
    
    Skill dribbling(1, "Dribbling", "Ball control technique");
    Skill shooting(2, "Shooting", "Scoring technique");
    Skill freestyle(3, "Freestyle", "Front crawl swimming style");
    Skill breaststroke(4, "Breaststroke", "Frog-like swimming style");

    Sport basketball(1, "Basketball", "Team ball sport");
    basketball.addSkill(&dribbling);
    basketball.addSkill(&shooting);

    Sport swimming(2, "Swimming", "Water-based sport");
    swimming.addSkill(&freestyle);
    swimming.addSkill(&breaststroke);

    Mentor coachBrown(1, "Coach Brown", {"Basketball"}, 2);
    Mentor coachWilson(2, "Coach Wilson", {"Swimming"}, 2);

    Student john(1, "John", 20);
    Student emma(2, "Emma", 19);

    int choice;
    do {
        cout << "1. Register Student for Mentorship\n";
        cout << "2. View Mentor Details\n";
        cout << "3. Update Student's Sports Interests\n";
        cout << "4. View Assigned Learners\n";
        cout << "5. Remove Student from Mentor\n";
        cout << "6. Show Skill Details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string studentName, mentorName;
                cout << "Enter student name (John/Emma): ";
                getline(cin, studentName);
                cout << "Enter mentor name (Coach Brown/Coach Wilson): ";
                getline(cin, mentorName);

                if (studentName == "John" && mentorName == "Coach Brown") {
                    
                    if (john.getSportsInterests().empty()) {
                        cout << "John has no sports interests. Please update sports interests first!\n";
                    } else {
                        john.registerForMentorship(&coachBrown);
                    }
                } else if (studentName == "Emma" && mentorName == "Coach Wilson") {
                    
                    if (emma.getSportsInterests().empty()) {
                        cout << "Emma has no sports interests. Please update sports interests first!\n";
                    } else {
                        emma.registerForMentorship(&coachWilson);
                    }
                } else {
                    cout << "Invalid combination or expertise mismatch!\n";
                }
                break;
            }
            case 2: {
                string studentName;
                cout << "Enter student name (John/Emma): ";
                getline(cin, studentName);

                if (studentName == "John") {
                    john.viewMentorDetails();
                } else if (studentName == "Emma") {
                    emma.viewMentorDetails();
                } else {
                    cout << "Invalid student name.\n";
                }
                break;
            }
            case 3: {
                string studentName, sportName;
                cout << "Enter student name (John/Emma): ";
                getline(cin, studentName);
                cout << "Enter sport name (Basketball/Swimming): ";
                getline(cin, sportName);

                if (studentName == "John" && sportName == "Basketball") {
                    john.updateSportsInterest(&basketball);
                } else if (studentName == "Emma" && sportName == "Swimming") {
                    emma.updateSportsInterest(&swimming);
                } else {
                    cout << "Invalid input or sport not found!\n";
                }
                break;
            }
            case 4: {
                string mentorName;
                cout << "Enter mentor name (Coach Brown/Coach Wilson): ";
                getline(cin, mentorName);

                if (mentorName == "Coach Brown") {
                    coachBrown.viewLearners();
                } else if (mentorName == "Coach Wilson") {
                    coachWilson.viewLearners();
                } else {
                    cout << "Invalid mentor name.\n";
                }
                break;
            }
            case 5: {
                string studentName, mentorName;
                cout << "Enter student name (John/Emma): ";
                getline(cin, studentName);
                cout << "Enter mentor name (Coach Brown/Coach Wilson): ";
                getline(cin, mentorName);

                if (studentName == "John" && mentorName == "Coach Brown") {
                    coachBrown.removeLearner(&john);
                } else if (studentName == "Emma" && mentorName == "Coach Wilson") {
                    coachWilson.removeLearner(&emma);
                } else {
                    cout << "Invalid combination!\n";
                }
                break;
            }
            case 6: {
                string skillName;
                cout << "Enter skill name (Dribbling/Shooting/Freestyle/Breaststroke): ";
                getline(cin, skillName);

                if (skillName == "Dribbling") dribbling.showSkillDetails();
                else if (skillName == "Shooting") shooting.showSkillDetails();
                else if (skillName == "Freestyle") freestyle.showSkillDetails();
                else if (skillName == "Breaststroke") breaststroke.showSkillDetails();
                else cout << "Invalid skill name!\n";
                break;
            }
            case 7: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 7);

}