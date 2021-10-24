#include <iostream>
#include <locale>
#include <string>
#include <vector>

class Date
{
    int month;
    int day;
    int year;
public:
    Date() : month(0), day(0), year(0){}
    Date(const int month, const int day, const int year) : month(month), day(day), year(year){}

    int GetMonth() const
    {
        return month;   
    }

    void SetMonth(int value)
    {
        this->month = value;
    }
    
    int GetDay() const
    {
        return day;   
    }

    void SetDay(int value)
    {
        this->day = value;
    }
    
    int GetYear() const
    {
        return year;   
    }

    void SetYear(int value)
    {
        this->year = value;
    }

    void Print() const
    {
        std::cout << "Month, Day, Year: " << month << ", " << day << ", " << year << std::endl;
    }
};

class Time
{
    int hour;
    int minute;
public:
    Time() : hour(0), minute(0){}
    Time(int hour, int minute) : hour(hour), minute(minute){}

    int GetHour() const
    {
        return hour;   
    }

    void SetHour(int value)
    {
        this->hour = value;
    }
    
    int GetMinute() const
    {
        return minute;   
    }

    void SetMinute(int value)
    {
        this->minute = value;
    }

    void Print() const
    {
        std::cout << "Hour, Minute: " << hour << ", " << minute << std::endl;
    }
};

class Invitee
{
    std::string email;
public:
    Invitee(const std::string& email) : email(email){}
    bool IsValid()
    {
        // checks if first char is alphabetical, and if there is more than 3 starting character
        if(!isalpha(email[0]) || email.length() < 17)
        {
            return false;
        }

        // checks that the end of the email is from "@csufresno.edu" 
        std::string fresnoEmail = "@csufresno.edu";
        for(int i = 0; i < 13; i++)
        {
            if(email[email.length() - 1 - i] != fresnoEmail[13 - i])
            {
                return false;
            }
        }

        // check that the starting characters are alpha numeric, ignoring the first char because that has already been checked
        for(int i = 0; i < email.length() - 1 - fresnoEmail.length(); i++)
        {
            if(!std::isalnum(email[email.length() - 1 - fresnoEmail.length() - i]))
            {
                return false;
            }
        }
        
        return true;
    }

    std::string GetEmail() const
    {
        return email;
    }
};

class Event
{
    std::string title;
    Date date;
    Time start;
    Time end;
    std::vector<Invitee> invitees;
    int duration;
    std::string location;
public:
    Event(){}
    Event(const std::string& title, const Date& date, const Time& start, const Time& end, const std::vector<Invitee>& invitees, const std::string& location)
        : title(title),
          date(date),
          start(start),
          end(end),
          invitees(invitees),
          location(location)
    {
        duration = end.GetHour() * 60 + end.GetMinute() - (start.GetHour() * 60 + start.GetMinute());
    }

    void Print() const
    {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Date: " << std::endl;
        date.Print();
        std::cout << "Start Time - ";
        start.Print();
        std::cout << "End Time - ";
        end.Print();
        for(int i = 0; i < invitees.size(); i++)
        {
            std::cout << "Invitee" << i << ": " << invitees[i].GetEmail() << std::endl;
        }
        
        std::cout << "Duration: " << duration << " Minutes" << std::endl;
        std::cout << "Location: " << location << std::endl;
    }

    std::string GetTitle() const
    {
        return title;
    }

    Date GetDate() const
    {
        return date;
    }

    Time GetStart() const
    {
        return start;
    }

    Time GetEnd() const
    {
        return end;
    }

    std::vector<Invitee> GetInvitees() const
    {
        return invitees;
    }

    int GetDuration() const
    {
        return duration;
    }

    std::string GetLocation() const
    {
        return location;
    }
};

class Calender
{
    Event* events;
    int count;
public:
    Calender()
    {
        events = new Event[0];
        count = 0;
    }
    
    void AddEvent(Event e)
    {
        Event* temp = new Event[++count];
        for (int i = 0; i < count - 1; i++)
        {
            temp[i] = events[i];
        }
        temp[count - 1] = e;

        events = temp;
    }

    void DropEvent(int month, int day)
    {
        Event* temp = new Event[--count];
        int i = 0;
        int eventIndex = 0;
        while (i < count - 1)
        {
            Date eventDate = events[i].GetDate();
            if(!(eventDate.GetMonth() == month && eventDate.GetDay() == day))
            {
                temp[i] = events[eventIndex++];
            }
            i++;
        }
    }
    
    void SearchEvent(int month)
    {
        for(int i = 0; i < count; i++)
        {
            if(events[i].GetDate().GetMonth() == month)
            {
                events[i].Print();
                std::cout << std::endl;
            }
        }
    }
};

int main()
{
    Calender c = Calender();
    c.AddEvent(Event("Event 1", Date(1, 2, 2021), Time(4, 0), Time(4, 30), std::vector<Invitee>{ Invitee("abc@csufresno.edu") }, "Fresno"));
    c.AddEvent(Event("Event 2", Date(3, 4, 2022), Time(5, 0), Time(5, 30), std::vector<Invitee>{ Invitee("abc@csufresno.edu") }, "Fresno"));
    c.AddEvent(Event("Event 3", Date(5, 6, 2023), Time(6, 0), Time(6, 30), std::vector<Invitee>{ Invitee("abc@csufresno.edu") }, "Fresno"));
    c.AddEvent(Event("Event 4", Date(3, 7, 2024), Time(7, 0), Time(7, 30), std::vector<Invitee>{ Invitee("abc@csufresno.edu") }, "Fresno"));
    c.SearchEvent(3);
    std::cout << "dropped event" << std::endl;
    c.DropEvent(3, 7);
    c.SearchEvent(3);
    
    Invitee i1 = Invitee("abc@csufresno.edu");
    Invitee i2 = Invitee("1bc@csufresno.edu");
    Invitee i3 = Invitee("ab@csufresno.edu");
    Invitee i4 = Invitee("abc@ssufresno.edu");
    
    std::cout << i1.GetEmail() << (i1.IsValid() ? " is a valid email" : " is not a valid email") << std::endl;
    std::cout << i2.GetEmail() << (i2.IsValid() ? " is a valid email" : " is not a valid email") << std::endl;
    std::cout << i3.GetEmail() << (i3.IsValid() ? " is a valid email" : " is not a valid email") << std::endl;
    std::cout << i4.GetEmail() << (i4.IsValid() ? " is a valid email" : " is not a valid email") << std::endl;
    return 0;
}
