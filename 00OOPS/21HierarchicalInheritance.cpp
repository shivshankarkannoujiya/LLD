#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Notification
{
protected:
    string user_id;
    string message;
    time_t timestamp;

    void logToDatabase(string type)
    {
        cout << "[DB LOG]: Saved " << type << " for User " << user_id << " at time " << timestamp << endl;
    }

public:
    Notification(string user_id, string message)
    {
        this->user_id = user_id;
        this->message = message;
        this->timestamp = time(0);
    }
};

class EmailNotification : Notification
{
private:
    string subject;

public:
    EmailNotification(string uid, string msg, string subject) : Notification(uid, msg)
    {
        this->subject = subject;
    }

    void sendEmail()
    {
        cout << "\n--- SENDING EMAIL ---" << endl;
        cout << "To: " << user_id << "@gmail.com" << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << message << endl;

        logToDatabase("EMAIL");
    }
};
class SMSNotification : public Notification
{

public:
    SMSNotification(string uid, string msg) : Notification(uid, msg) {}

    void sendSMS()
    {
        if (message.length() > 160)
        {
            cout << "Error: SMS too long!" << endl;
            return;
        }

        cout << "\n--- SENDING SMS ---" << endl;
        cout << "To: +91-" << user_id << endl;
        cout << "Text: " << message << endl;

        logToDatabase("SMS");
    }
};

class PushNotification : Notification
{
private:
    string appIcon;

public:
    PushNotification(string uid, string msg) : Notification(uid, msg)
    {
        this->appIcon = "default_icon.png";
    }

    void push()
    {
        cout << "\n--- PUSH ALERT ---" << endl;
        cout << "DeviceID: " << user_id << endl;
        cout << "Icon: " << appIcon << " | Msg: " << message << endl;
        logToDatabase("PUSH");
    }
};

int main()
{
    // NOTE: SCENARIO: User registered, we need to alert them in different ways.

    EmailNotification email("user_123", "Welcome!", "Thanks for signing up.");
    email.sendEmail();

    SMSNotification sms("9876543210", "Your OTP is 4492");
    sms.sendSMS();

    PushNotification app("device_xyz", "You have a new friend request.");
    app.push();

    return 0;
}