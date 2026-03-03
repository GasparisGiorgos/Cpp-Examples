 #include <iostream>
#include <string> // Required for advanced string features
using namespace std;

// Main Class
class Agent {
private:
    string name;
    string agentCode;
    
    // 2. Static Class Member (Shared by all objects)
    static int totalAgents; 

public:
    // Regular constructor
    Agent(string n); 
    
    // 1. Copy Constructor
    Agent(const Agent& other); 
    
    void showDetails();

    // Static method to access the static variable
    static int getAgentCount(); 
};

// --- Definitions Outside the Class ---

// Initialize the static member outside the class (starts at 0)
int Agent::totalAgents = 0; 

// Regular Constructor
Agent::Agent(string n) {
    name = n;
    
    // 3. String at a "Second Glance" (Using string methods)
    agentCode = "ID-";
    agentCode.append(name); // Appends the name to the end
    
    // Insert the length of the name at index 3 (right after "ID-")
    agentCode.insert(3, to_string(name.length())); 
    
    totalAgents++; // Increase total count when a new agent is made
}

// Copy Constructor definition
Agent::Agent(const Agent& other) {
    // We copy the data from the 'other' agent, but modify it slightly
    name = other.name + "_Clone";
    agentCode = other.agentCode + "-C";
    
    totalAgents++; // A clone is still a new agent, so we increase the count
}

void Agent::showDetails() {
    cout << "Agent Name: " << name << " | Code: " << agentCode << endl;
}

int Agent::getAgentCount() {
    return totalAgents;
}

// --- Main Program ---

int main() {
    string inputName;

    // User Input
    cout << "Enter the new Agent's name (one word): ";
    cin >> inputName;

    cout << "\n--- Creating Original Agent ---" << endl;
    Agent agent1(inputName);
    agent1.showDetails();
    cout << "Total Agents Active: " << Agent::getAgentCount() << endl;

    cout << "\n--- Using Copy Constructor ---" << endl;
    // We create agent2 by copying agent1
    Agent agent2 = agent1; 
    agent2.showDetails();
    cout << "Total Agents Active: " << Agent::getAgentCount() << endl;

    return 0;
}