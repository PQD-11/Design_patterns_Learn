#include <iostream>
#include <list>
#include <string>

class Observer {
    public:
        ~Observer(){};
        virtual void notify() = 0;
};

class Subject {
    public:
        void RegisterObserver(Observer* observer) {
            observers.push_back(observer);
        }
        void UnregisterObserver(Observer* observer) {
        observers.remove(observer);
        }
        void NotifyObservers(){                        
            for (auto observer: observers) observer->notify();
        }

    private:
        std::list<Observer *> observers;
};

class VideoData : public Subject
{
    public:
        std::string GetTitle()
        {
            return _title;
        }

        void SetTitle(std::string value)
        {
            _title = value;
            VideoDataChanged();
        }

        std::string GetDescription()
        {
            return _description;
        }

        void SetDescription(std::string value)
        {
            _description = value;
            VideoDataChanged();
        }

        std::string GetFileName()
        {
            return _fileName;
        }

        void SetFileName(std::string value)
        {
            _fileName = value;
            VideoDataChanged();
        }
    private:
        std::string _title;
        std::string _fileName;
        std::string _description;
        void VideoDataChanged()
        {
            NotifyObservers();
        }
};

class EmailNotifier : public Observer {
    public:
        EmailNotifier(Subject* subject) : _subject(subject) {
            _subject->RegisterObserver(this);
        }
        void notify() override {
            VideoData* videodate = static_cast<VideoData*>(_subject);
            std::cout<<"Notify all subscribers via EMAIL with new data \n\t Name: " + videodate->GetFileName()<<std::endl;
        }
    private: 
        Subject* _subject;                                    // (3)
};

class FacebookNotifier : public Observer {
    public:
        FacebookNotifier(Subject* subject) : _subject(subject) {
            _subject->RegisterObserver(this);
        }
        void notify() override {
            VideoData* videodate = static_cast<VideoData*>(_subject);
            std::cout<<"Notify all subscribers via Facebook with new data \n\t Name: " + videodate->GetFileName()<<std::endl;
        }
    private: 
        Subject* _subject;                                       // (4)
};


int main() {

    std::cout << '\n';

    VideoData videoData;   
    EmailNotifier emailNotifier(&videoData);
    FacebookNotifier facebookNotifier(&videoData);
    std::cout <<"=>Setup Name Video"<<std::endl;
    videoData.SetFileName("Initial Name");

    videoData.UnregisterObserver(&emailNotifier);

    std::cout <<"\n=>Rename Video"<<std::endl;
    videoData.SetFileName("Yepp");
    std::cout << '\n';
}