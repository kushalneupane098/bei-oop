#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class MediaFile
{
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;

    virtual ~MediaFile()
    {
        cout << "MediaFile Destructor" << endl;
    }
};

class AudioFile : public MediaFile
{
private:
    int duration;
    int bitrate;

public:
    AudioFile(int d, int b)
    {
        duration = d;
        bitrate = b;
    }

    void play()
    {
        cout << "Playing audio file" << endl;
    }

    string getInfo()
    {
        return "Audio Duration: " + to_string(duration) +
               " sec, Bitrate: " + to_string(bitrate);
    }

    int getBitrate()
    {
        return bitrate;
    }

    ~AudioFile()
    {
        cout << "AudioFile Destructor" << endl;
    }
};

class VideoFile : public MediaFile
{
private:
    int duration;
    string resolution;

public:
    VideoFile(int d, string r)
    {
        duration = d;
        resolution = r;
    }

    void play()
    {
        cout << "Playing video file" << endl;
    }

    string getInfo()
    {
        return "Video Duration: " + to_string(duration) +
               " sec, Resolution: " + resolution;
    }

    string getResolution()
    {
        return resolution;
    }

    ~VideoFile()
    {
        cout << "VideoFile Destructor" << endl;
    }
};

class ImageFile : public MediaFile
{
private:
    int width;
    int height;

public:
    ImageFile(int w, int h)
    {
        width = w;
        height = h;
    }

    void play()
    {
        cout << "Displaying image" << endl;
    }

    string getInfo()
    {
        return "Image Size: " + to_string(width) +
               "x" + to_string(height);
    }

    ~ImageFile()
    {
        cout << "ImageFile Destructor" << endl;
    }
};

int main()
{
    /*
    typeid identifies the actual runtime type of an object.
    dynamic_cast safely converts a base pointer to a derived pointer
    and returns nullptr if conversion fails.
    */

    vector<MediaFile*> files;

    files.push_back(new AudioFile(120, 320));
    files.push_back(new VideoFile(300, "1920x1080"));
    files.push_back(new ImageFile(800, 600));

    for(MediaFile *ptr : files)
    {
        cout << "Runtime Type: " << typeid(*ptr).name() << endl;

        ptr->play();
        cout << ptr->getInfo() << endl;

        VideoFile *video = dynamic_cast<VideoFile*>(ptr);

        if(video)
        {
            cout << "Video Resolution: "
                 << video->getResolution() << endl;
        }

        AudioFile *audio = dynamic_cast<AudioFile*>(ptr);

        if(audio)
        {
            cout << "Audio Bitrate: "
                 << audio->getBitrate() << endl;
        }

        cout << endl;
    }

    for(MediaFile *ptr : files)
    {
        delete ptr;
    }

    files.clear();

    return 0;
}