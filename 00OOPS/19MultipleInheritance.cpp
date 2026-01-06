#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LLMClient
{

protected:
    string generatePlan(string goal)
    {
        cout << "\n[LLM BRAIN]: Analyzing goal: '" << goal << "'" << endl;
        return "Plan: Search Google for '" + goal + "', then summarize.";
    }

    string summarizeData(string data)
    {
        cout << "[LLM BRAIN]: Summarizing huge web data..." << endl;
        return ">> SUMMARY: Apple stock is trading at $185.50 (Up 2% today).";
    }
};

class WebBrowser
{

protected:
    string searchGoogle(string query)
    {
        cout << "[WEB TOOL]:  Searching internet for '" << query << "'..." << endl;
        return "<html><body>Data: Apple (AAPL) Price: $185.50 | Trends: Bullish</body></html>";
    }
};

class ContextManager
{

private:
    vector<string> history;

protected:
    void addToHistory(string newHistory)
    {
        history.push_back(newHistory);
        cout << "[MEMORY]:Saved to context window." << endl;
    }

    void showHistory()
    {
        cout << "\n--- INTERNAL MEMORY DUMP ---" << endl;
        for (const string &s : history)
        {
            cout << " * " << s << endl;
        }
        cout << "----------------------------\n"
             << endl;
    }
};

class ResearchAgent : public LLMClient,
                      public WebBrowser,
                      public ContextManager
{

private:
    string agentName;

public:
    ResearchAgent(string name) : agentName(name) {};

    void executeWorkflow(string userGoal)
    {
        cout << "=== Agent '" << agentName << "' Activated ===\n"
             << endl;

        addToHistory("User Goal: " + userGoal);

        string plan = generatePlan(userGoal);
        addToHistory("Thought: " + plan);

        string rawData = searchGoogle(userGoal);
        addToHistory("Observation: " + rawData);

        string finalAnswer = summarizeData(rawData);
        addToHistory("Final Answer: " + finalAnswer);

        cout << "\n>>> FINAL OUTPUT TO USER: " << finalAnswer << "\n"
             << endl;

        showHistory();
    }
};

int main()
{
    ResearchAgent jarvis("Jarvis_Pro");
    jarvis.executeWorkflow("Apple Stock Price");

    return 0;
}