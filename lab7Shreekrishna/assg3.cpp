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

    virtual ~MediaFile() {}
};

class AudioFile : public MediaFile
{
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
        cout << "Playing Audio File" << endl;
    }

    string getInfo()
    {
        return "Duration: " + to_string(duration) + " sec, Bitrate: " + to_string(bitrate) + " kbps";
    }

    int getBitrate()
    {
        return bitrate;
    }

    ~AudioFile()
    {
        cout << "AudioFile Deleted" << endl;
    }
};

class VideoFile : public MediaFile
{
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
        cout << "Playing Video File" << endl;
    }

    string getInfo()
    {
        return "Duration: " + to_string(duration) + " sec, Resolution: " + resolution;
    }

    string getResolution()
    {
        return resolution;
    }

    ~VideoFile()
    {
        cout << "VideoFile Deleted" << endl;
    }
};

class ImageFile : public MediaFile
{
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
        cout << "Displaying Image" << endl;
    }

    string getInfo()
    {
        return "Width: " + to_string(width) + ", Height: " + to_string(height);
    }

    ~ImageFile()
    {
        cout << "ImageFile Deleted" << endl;
    }
};

int main()
{
    vector<MediaFile *> files;

    files.push_back(new AudioFile(240, 320));
    files.push_back(new VideoFile(500, "1920x1080"));
    files.push_back(new ImageFile(1024, 768));

    for (int i = 0; i < files.size(); i++)
    {
        cout << "Type: " << typeid(*files[i]).name() << endl;

        files[i]->play();
        cout << files[i]->getInfo() << endl;

        VideoFile *v = dynamic_cast<VideoFile *>(files[i]);
        if (v)
        {
            cout << "Resolution: " << v->getResolution() << endl;
        }

        AudioFile *a = dynamic_cast<AudioFile *>(files[i]);
        if (a)
        {
            cout << "Bitrate: " << a->getBitrate() << " kbps" << endl;
        }

        cout << endl;
    }

    for (int i = 0; i < files.size(); i++)
    {
        delete files[i];
    }

    files.clear();

    return 0;
}