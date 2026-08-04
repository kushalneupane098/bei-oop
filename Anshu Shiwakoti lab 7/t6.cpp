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
        cout << "MediaFile Destructor Called" << endl;
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
        cout << "Playing Audio File" << endl;
    }

    string getInfo()
    {
        return "Audio: Duration = " + to_string(duration) +
               " sec, Bitrate = " + to_string(bitrate) + " kbps";
    }

    int getBitrate()
    {
        return bitrate;
    }

    ~AudioFile()
    {
        cout << "AudioFile Destructor Called" << endl;
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
        cout << "Playing Video File" << endl;
    }

    string getInfo()
    {
        return "Video: Duration = " + to_string(duration) +
               " sec, Resolution = " + resolution;
    }

    string getResolution()
    {
        return resolution;
    }

    ~VideoFile()
    {
        cout << "VideoFile Destructor Called" << endl;
    }
};


class ImageFile : public MediaFile
{
private:
    int width, height;

public:
    ImageFile(int w, int h)
    {
        width = w;
        height = h;
    }

    void play()
    {
        cout << "Displaying Image File" << endl;
    }

    string getInfo()
    {
        return "Image: Width = " + to_string(width) +
               ", Height = " + to_string(height);
    }

    ~ImageFile()
    {
        cout << "ImageFile Destructor Called" << endl;
    }
};

int main()
{
    vector<MediaFile *> media;
    media.push_back(new AudioFile(180, 320));
    media.push_back(new VideoFile(240, "1920x1080"));
    media.push_back(new ImageFile(1920, 1080));

    for (int i = 0; i < media.size(); i++)
    {
        cout << "\nObject " << i + 1 << endl;
        cout << "Runtime Type: " << typeid(*media[i]).name() << endl;
        media[i]->play();
        cout << media[i]->getInfo() << endl;
        VideoFile *v = dynamic_cast<VideoFile *>(media[i]);

        if (v != nullptr)
        {
            cout << "Resolution = " << v->getResolution() << endl;
        }
        AudioFile *a = dynamic_cast<AudioFile *>(media[i]);

        if (a != nullptr)
        {
            cout << "Bitrate = " << a->getBitrate() << " kbps" << endl;
        }
    }

    cout << "\nDeleting Objects...\n";

    for (int i = 0; i < media.size(); i++)
    {
        delete media[i];
    }

    media.clear();
    return 0;
}