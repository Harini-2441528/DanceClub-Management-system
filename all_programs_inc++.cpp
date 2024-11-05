#include <iostream>
#include <string>
using namespace std;

class DanceClub {
protected:
    string name;
    static int totalMembers;
    string members[5]; 
    int memberCount;

public:
    DanceClub(string clubName) : name(clubName), memberCount(0) {}

    void addMember(const string& memberName) {
        if (memberCount < 5) {
            members[memberCount++] = memberName;
            totalMembers++;
            cout << memberName << " has joined " << name << endl;
        } else {
            cout << "Club " << name << " is full! Cannot add more members." << endl;
        }
    }

    void displayMembers() const {
        cout << "Members of " << name << ":\n";
        for (int i = 0; i < memberCount; i++) {
            cout << "- " << members[i] << endl;
        }
    }

    static int getTotalMembers() {
        return totalMembers;
    }

    void removeMember(const string& memberName) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i] == memberName) {
                for (int j = i; j < memberCount - 1; j++) {
                    members[j] = members[j + 1];
                }
                memberCount--;
                totalMembers--;
                cout << memberName << " has been removed from " << name << endl;
                return;
            }
        }
        cout << memberName << " not found in " << name << endl;
    }
};

int DanceClub::totalMembers = 0;


class DanceClass {
private:
    string className;
    string participants[10]; 
    int participantCount;

public:
    DanceClass(string name) : className(name), participantCount(0) {}

    void addParticipant(const string& name) {
        if (participantCount < 10) {
            participants[participantCount++] = name;
            cout << name << " has been added to " << className << endl;
        } else {
            cout << "Class " << className << " is full! Cannot add more participants." << endl;
        }
    }

    void listParticipants() const {
        cout << "Participants in " << className << ":\n";
        for (int i = 0; i < participantCount; i++) {
            cout << "- " << participants[i] << endl;
        }
    }

    void removeParticipant(const string& name) {
        for (int i = 0; i < participantCount; i++) {
            if (participants[i] == name) {
                for (int j = i; j < participantCount - 1; j++) {
                    participants[j] = participants[j + 1];
                }
                participantCount--;
                cout << name << " has been removed from " << className << endl;
                return;
            }
        }
        cout << name << " not found in " << className << endl;
    }
};

class DanceEvent {
private:
    string eventName;
    string eventDate;

public:
    DanceEvent(string name, string date) : eventName(name), eventDate(date) {}

    void displayEventInfo() const {
        cout << "Event: " << eventName << " on " << eventDate << endl;
    }
};

int main() {
    
    DanceClub hipHop("Hip Hop Enthusiasts");
    DanceClub salsa("Salsa Lovers");
    DanceClub balletClub("Ballet Fans");

    
    hipHop.addMember("Alice");
    hipHop.addMember("Bob");
    salsa.addMember("Charlie");
    balletClub.addMember("Diana");
    
    
    hipHop.displayMembers();
    salsa.displayMembers();
    balletClub.displayMembers();
    
    cout << "Total members across all clubs: " << DanceClub::getTotalMembers() << endl;

    
    hipHop.removeMember("Alice");
    hipHop.displayMembers();

    DanceClass ballet("Ballet Class");
    DanceClass hipHopClass("Hip Hop Class");

    ballet.addParticipant("Eva");
    ballet.addParticipant("Frank");
    hipHopClass.addParticipant("Grace");
    
    ballet.listParticipants();
    hipHopClass.listParticipants();

    ballet.removeParticipant("Eva");
    ballet.listParticipants();

    DanceEvent salsaNight("Salsa Night", "2024-11-01");
    DanceEvent hipHopWorkshop("Hip Hop Workshop", "2024-12-05");
    
    salsaNight.displayEventInfo();
    hipHopWorkshop.displayEventInfo();


    cout << "\nAdding more members to Salsa Lovers..." << endl;
    salsa.addMember("Helen");
    salsa.addMember("Ian");
    salsa.addMember("Jack");
    
    salsa.displayMembers();

    cout << "\nTrying to add a member to a full club..." << endl;
    salsa.addMember("Lucy"); 

    cout << "\nCurrent total members: " << DanceClub::getTotalMembers() << endl;

    cout << "\nSummary of all dance clubs:" << endl;
    hipHop.displayMembers();
    salsa.displayMembers();
    balletClub.displayMembers();

    return 0;
}

