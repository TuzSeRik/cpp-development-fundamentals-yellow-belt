#include <string>

using namespace std;
// Simple educational task to show example hierarchy
class INotifier {
public:
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const string& number) : number(number) {}

    void Notify(const string& message) override {
        SendSms(number, message);
    }

private:
   const string number;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const string& email) : email(email) {}

    void Notify(const string& message) override {
        SendEmail(email, message);
    }

private:
    const string email;
};
