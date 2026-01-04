/*
In a GenAI app (like a wrapper for GPT-4 or a local Llama model), you have two distinct needs:
    - Individual Needs (Non-Static): Each user has their own Chat History and Context.
    - Global Needs (Static): The API Key, the Total Cost ($), and the Loaded Model (if local) should be shared.


The Architecture: "The LLM Wrapper"
We will build a class LLMSession.
    Static Member (totalTokensUsed): Tracks the bill for all users combined.
    Static Function (estimateCost): Calculates price without needing to start a chat.
    Instance Member (chatHistory): Stores the conversation for one specific user.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LLMSession
{

    // INSTANCE DATA (Unique to each user)
    string Username;
    vector<string> ChatHistory;

    // STATIC DATA (Shared by the entire App)
    // 1. We only want ONE bill counter for the whole company.
    static int globalTokenUsage;

    // 2. We only want ONE API Key loaded in memory.
    static string apiKey;

public:
    LLMSession(string username) : Username(username) {};

    // INSTANCE FUNCTION: Requires a specific user
    void sendMessage(string prompt)
    {
        ChatHistory.push_back(prompt);
        int tokens = prompt.length() * 1.3;
        globalTokenUsage += tokens;
        cout << "   -> " << Username << " used " << tokens << " tokens." << endl;
    }

    // STATIC FUNCTION: Utility / Admin Tool
    // "I don't need a specific user to tell me the total company bill."

    static void printGlobalReport()
    {
        cout << "\n--- ADMIN REPORT ---" << endl;
        cout << "Global Tokens Consumed: " << globalTokenUsage << endl;
        cout << "Total Cost (@ $0.01/token): $" << globalTokenUsage * 0.01 << endl;
        cout << "Using API Key: " << apiKey << endl;
        cout << "--------------------\n"
             << endl;
    }

    // STATIC FUNCTION: Helper
    // "I don't need to open a session just to do simple math."
    static int estimateCost(int words)
    {
        return words * 1.3;
    }

    static void setApiKey(string key)
    {
        apiKey = key;
    }
};

int LLMSession::globalTokenUsage = 0;
string LLMSession::apiKey = "unset";

int main()
{

    // 1. App Startup: Configure Global Settings
    LLMSession::setApiKey("sk-12345-SECRET");

    // 2. Feature: Cost Estimator (No object needed!)
    // User checks price before buying.
    int est = LLMSession::estimateCost(100);
    cout << "Estimated tokens for 100 words: " << est << endl;

    // 3. User 1 starts chatting
    LLMSession user_1("Raj");
    LLMSession user_2("Raman");

    user_1.sendMessage("Hello, how are you?");
    // globalTokenUsage goes up.

    user_2.sendMessage("Write me a poem about C++.");
    // globalTokenUsage goes up.

    // 5. Admin checks the bill
    // Notice we call this on the CLASS, not on user1 or user2.

    LLMSession::printGlobalReport();

    return 0;
}